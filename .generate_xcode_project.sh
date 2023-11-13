#!/bin/bash

# Spécifiez le chemin du projet CMake
CMAKE_PROJECT_DIR="/Users/flagada/Desktop/test2"

# Spécifiez le chemin du répertoire de génération Xcode
XCODE_BUILD_DIR="/Users/flagada/Desktop/test2/XcodeProjet"

# Vérifiez si le projet Xcode existe déjà
if [ ! -d "${XCODE_BUILD_DIR}" ]; then
    echo "Generating Xcode project..."
    cmake -G Xcode -H. -B_Xcode
else
    echo "Xcode project already exists. Skipping generation."
fi