#!/bin/bash

# Script para compilar las librerías de Realm Dart para Android con soporte de páginas de 16KB
# y copiarlas a la ubicación correcta para el build de Flutter

set -e

echo "========================================="
echo "Building Realm Dart Android Libraries"
echo "with 16KB Page Support for Android 15+"
echo "========================================="

# Directorio base
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
REALM_DART_DIR="$SCRIPT_DIR/packages/realm_dart"
REALM_ANDROID_DIR="$SCRIPT_DIR/packages/realm/android"

# Verificar que existe el directorio de realm_dart
if [ ! -d "$REALM_DART_DIR" ]; then
    echo "Error: Directory $REALM_DART_DIR does not exist"
    exit 1
fi

# Crear directorio para las librerías si no existe
LIB_OUTPUT_DIR="$REALM_ANDROID_DIR/src/main/jniLibs"
mkdir -p "$LIB_OUTPUT_DIR/arm64-v8a"
mkdir -p "$LIB_OUTPUT_DIR/x86_64"
mkdir -p "$LIB_OUTPUT_DIR/armeabi-v7a"
mkdir -p "$LIB_OUTPUT_DIR/x86"

# Configuración del NDK
if [ -z "$ANDROID_NDK_ROOT" ] && [ -n "$ANDROID_NDK_HOME" ]; then
    ANDROID_NDK_ROOT="$ANDROID_NDK_HOME"
fi

if [ -z "$ANDROID_NDK_ROOT" ]; then
    # Intentar encontrar NDK en ubicaciones comunes
    if [ -d "$HOME/Library/Android/sdk/ndk" ]; then
        # Buscar la versión más reciente del NDK
        NDK_VERSION=$(ls -1 "$HOME/Library/Android/sdk/ndk" | grep -E '^[0-9]+\.' | sort -V | tail -n1)
        if [ -n "$NDK_VERSION" ]; then
            ANDROID_NDK_ROOT="$HOME/Library/Android/sdk/ndk/$NDK_VERSION"
        fi
    fi
fi

if [ -z "$ANDROID_NDK_ROOT" ]; then
    echo "Error: ANDROID_NDK_ROOT is not set and could not be found automatically"
    echo "Please set ANDROID_NDK_ROOT environment variable to your Android NDK path"
    exit 1
fi

echo "Using Android NDK: $ANDROID_NDK_ROOT"

# Función para compilar para una arquitectura
build_architecture() {
    local ABI=$1
    local API_LEVEL=23

    echo ""
    echo "Building for $ABI..."
    echo "------------------------"

    cd "$REALM_DART_DIR"

    # Crear directorio de build
    BUILD_DIR="build-android-$ABI"
    rm -rf "$BUILD_DIR"
    mkdir -p "$BUILD_DIR"
    cd "$BUILD_DIR"

    # Configurar flags adicionales para 16KB pages en arquitecturas de 64-bit
    EXTRA_FLAGS=""
    if [ "$ABI" = "arm64-v8a" ] || [ "$ABI" = "x86_64" ]; then
        EXTRA_FLAGS="-DCMAKE_SHARED_LINKER_FLAGS=-Wl,-z,max-page-size=16384"
        echo "Adding 16KB page alignment flags for $ABI"
    fi

    # Configurar CMake
    cmake .. \
        -DCMAKE_TOOLCHAIN_FILE="$ANDROID_NDK_ROOT/build/cmake/android.toolchain.cmake" \
        -DCMAKE_SYSTEM_NAME=Android \
        -DCMAKE_ANDROID_ARCH_ABI="$ABI" \
        -DCMAKE_ANDROID_NATIVE_API_LEVEL=$API_LEVEL \
        -DCMAKE_BUILD_TYPE=Release \
        -DANDROID_ABI="$ABI" \
        -DANDROID_PLATFORM=android-$API_LEVEL \
        -DANDROID_STL=c++_static \
        -DCMAKE_ANDROID_NDK="$ANDROID_NDK_ROOT" \
        $EXTRA_FLAGS

    # Compilar
    cmake --build . --config Release --target realm_dart -j$(nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || echo 4)

    # Buscar la librería compilada
    LIBRARY_PATH=""
    if [ -f "src/librealm_dart.so" ]; then
        LIBRARY_PATH="src/librealm_dart.so"
    elif [ -f "binary/android/$ABI/librealm_dart.so" ]; then
        LIBRARY_PATH="binary/android/$ABI/librealm_dart.so"
    elif [ -f "librealm_dart.so" ]; then
        LIBRARY_PATH="librealm_dart.so"
    fi

    if [ -z "$LIBRARY_PATH" ] || [ ! -f "$LIBRARY_PATH" ]; then
        echo "Warning: Could not find librealm_dart.so for $ABI"
        find . -name "librealm_dart.so" -type f 2>/dev/null | head -5
    else
        # Strip símbolos de debug
        echo "Stripping debug symbols from $LIBRARY_PATH"
        "$ANDROID_NDK_ROOT"/toolchains/llvm/prebuilt/*/bin/llvm-strip "$LIBRARY_PATH"

        # Copiar a la ubicación de JNI
        echo "Copying to $LIB_OUTPUT_DIR/$ABI/"
        cp "$LIBRARY_PATH" "$LIB_OUTPUT_DIR/$ABI/librealm_dart.so"

        # Verificar la alineación de página
        if [ "$ABI" = "arm64-v8a" ] || [ "$ABI" = "x86_64" ]; then
            echo "Verifying 16KB page alignment..."
            readelf -l "$LIB_OUTPUT_DIR/$ABI/librealm_dart.so" | grep LOAD | head -3
        fi
    fi

    cd "$REALM_DART_DIR"
}

# Compilar para cada arquitectura
echo ""
echo "Starting compilation for all architectures..."

# Arquitecturas de 64-bit (con soporte de 16KB)
build_architecture "arm64-v8a"
build_architecture "x86_64"

# Arquitecturas de 32-bit (no necesitan 16KB pero las compilamos para completitud)
build_architecture "armeabi-v7a"
build_architecture "x86"

echo ""
echo "========================================="
echo "Build completed successfully!"
echo "========================================="
echo ""
echo "Libraries with 16KB page support have been placed in:"
echo "  $LIB_OUTPUT_DIR"
echo ""
echo "The following architectures have 16KB page alignment:"
echo "  - arm64-v8a/librealm_dart.so"
echo "  - x86_64/librealm_dart.so"
echo ""
echo "Next steps:"
echo "1. Build your Flutter app normally"
echo "2. The libraries will be included in the APK/AAB"
echo "3. Test on Android 15+ devices with 16KB pages"
echo ""