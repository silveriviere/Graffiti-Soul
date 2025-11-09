#!/bin/bash

# Project: Graffiti Soul
# Quick build script for JSRF decompilation

set -e

# Create build directory if it doesn't exist
if [ ! -d "build" ]; then
    mkdir build
fi

cd build

# Configure and build
cmake ..
make -j$(nproc)

echo ""
echo "Build complete! Binary at: build/bin/graffiti-soul"
