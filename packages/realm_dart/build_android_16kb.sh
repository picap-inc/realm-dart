#!/bin/bash

# Script para compilar las librerías de Realm para Android con soporte de páginas de 16KB

set -e

# Configuración del NDK
NDK_VERSION="28.0.12674087"
MIN_API_LEVEL=23

# Asegurarnos de que estamos en el directorio correcto
cd "$(dirname "$0")"

# Función para compilar para una arquitectura específica
build_arch() {
    local ARCH=$1
    local ABI=$2

    echo "Building for $ABI..."

    # Crear directorio de build
    BUILD_DIR="build-android-$ABI"
    rm -rf "$BUILD_DIR"
    mkdir -p "$BUILD_DIR"
    cd "$BUILD_DIR"

    # Configurar CMake con las opciones correctas
    cmake .. \
        -DCMAKE_TOOLCHAIN_FILE="$ANDROID_NDK_ROOT/build/cmake/android.toolchain.cmake" \
        -DCMAKE_SYSTEM_NAME=Android \
        -DCMAKE_ANDROID_ARCH_ABI="$ABI" \
        -DCMAKE_ANDROID_NATIVE_API_LEVEL=$MIN_API_LEVEL \
        -DCMAKE_BUILD_TYPE=Release \
        -DANDROID_ABI="$ABI" \
        -DANDROID_PLATFORM=android-$MIN_API_LEVEL \
        -DANDROID_STL=c++_static \
        -DCMAKE_ANDROID_NDK="$ANDROID_NDK_ROOT"

    # Compilar
    cmake --build . --config Release --target realm_dart

    # Strip symbols
    if [ -f "src/librealm_dart.so" ]; then
        echo "Stripping librealm_dart.so for $ABI..."
        $ANDROID_NDK_ROOT/toolchains/llvm/prebuilt/*/bin/llvm-strip src/librealm_dart.so
    fi

    cd ..

    echo "Build complete for $ABI"
}

# Verificar que ANDROID_NDK_ROOT está configurado
if [ -z "$ANDROID_NDK_ROOT" ]; then
    echo "Error: ANDROID_NDK_ROOT environment variable is not set"
    echo "Please set it to your Android NDK installation path"
    exit 1
fi

echo "Using Android NDK at: $ANDROID_NDK_ROOT"

# Compilar para cada arquitectura
build_arch arm64 arm64-v8a
build_arch x86_64 x86_64

echo "All builds complete!"
echo ""
echo "The compiled libraries support Android 15+ 16KB pages."
echo "Libraries are located in:"
echo "  - build-android-arm64-v8a/src/librealm_dart.so"
echo "  - build-android-x86_64/src/librealm_dart.so"