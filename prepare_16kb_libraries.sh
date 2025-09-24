#!/bin/bash

# Script simplificado para preparar las librerías con soporte de 16KB
# Este script debe ejecutarse después de compilar las librerías con build_android_16kb_libraries.sh

set -e

echo "==========================================="
echo "Preparing 16KB-aligned libraries for Realm"
echo "==========================================="

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
REALM_ANDROID_DIR="$SCRIPT_DIR/packages/realm/android"
TARGET_DIR="$REALM_ANDROID_DIR/src/main/jniLibs-16kb"

# Crear directorio destino
mkdir -p "$TARGET_DIR/arm64-v8a"
mkdir -p "$TARGET_DIR/x86_64"

echo ""
echo "This script will prepare the 16KB-aligned libraries."
echo "Make sure you have already run build_android_16kb_libraries.sh"
echo ""

# Buscar las librerías compiladas
REALM_DART_DIR="$SCRIPT_DIR/packages/realm_dart"

for ABI in "arm64-v8a" "x86_64"; do
    BUILD_DIR="$REALM_DART_DIR/build-android-$ABI"

    if [ -d "$BUILD_DIR" ]; then
        # Buscar librealm_dart.so
        LIBRARY=$(find "$BUILD_DIR" -name "librealm_dart.so" -type f 2>/dev/null | head -1)

        if [ -n "$LIBRARY" ] && [ -f "$LIBRARY" ]; then
            echo "Found library for $ABI: $LIBRARY"
            cp "$LIBRARY" "$TARGET_DIR/$ABI/librealm_dart.so"
            echo "Copied to $TARGET_DIR/$ABI/librealm_dart.so"
        else
            echo "Warning: librealm_dart.so not found for $ABI"
        fi
    else
        echo "Warning: Build directory not found for $ABI"
    fi
done

echo ""
echo "==========================================="
echo "16KB libraries prepared successfully!"
echo "==========================================="
echo ""
echo "The libraries are now in:"
echo "  $TARGET_DIR"
echo ""
echo "When you build your Flutter app, these libraries will be used"
echo "automatically for arm64-v8a and x86_64 architectures."
echo ""
echo "To build your app:"
echo "  flutter build apk --release"
echo "  or"
echo "  flutter build appbundle --release"
echo ""