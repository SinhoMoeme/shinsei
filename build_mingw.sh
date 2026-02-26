#!/bin/bash
set -e

PROJECT_ROOT="$(cd "$(dirname "$0")" && pwd)"
SRC_DIR="$PROJECT_ROOT/src"
BUILD_DIR="$PROJECT_ROOT/build"
OUTPUT_DIR="$PROJECT_ROOT/release/bin"

export PATH=/ucrt64/bin:/usr/bin:$PATH

mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

cmake "$SRC_DIR" \
    -G "MinGW Makefiles" \
	-DCMAKE_BUILD_TYPE=Release \
	-DCMAKE_RUNTIME_OUTPUT_DIRECTORY="$OUTPUT_DIR" \
	-DCMAKE_C_STANDARD=23 \
	-DCMAKE_CXX_STANDARD=26 \
	-DBUILD_SHARED_LIBS=OFF \
	-DCMAKE_CXX_FLAGS_RELEASE="-O3 -flto -march=x86-64 -static-libgcc -static-libstdc++ -static" \
	-DCMAKE_C_FLAGS_RELEASE="-O3 -flto -march=x86-64 -static-libgcc -static-libstdc++ -static"

mingw32-make -j$(nproc)

cp /ucrt64/bin/libgcc_s_seh-1.dll "$OUTPUT_DIR/"
