#!/bin/bash

BUILD_TYPE="Ninja"
BUILD_SUFFIX="ninja"

BUILD_FOLDER="build_$BUILD_SUFFIX"
SOURCE_FOLDER="projects"

if [ ! -d "$BUILD_FOLDER" ]; then
    mkdir -p "$BUILD_FOLDER"
fi

cd "$BUILD_FOLDER" || { echo "Error: Failed to enter $BUILD_FOLDER"; exit 1; }

cmake -G "$BUILD_TYPE" "../$SOURCE_FOLDER" && cmake --build .

cd ..