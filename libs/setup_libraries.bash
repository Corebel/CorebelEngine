#!/bin/bash

# Ensure script is run from CorebelEngine root directory
if [ ! -d "libs" ]; then
  mkdir -p libs
fi

# Define library sources
declare -A libraries=(
  ["bgfx"]="https://github.com/bkaradzic/bgfx.git"
  ["bullet"]="https://github.com/bulletphysics/bullet3.git"
  ["assimp"]="https://github.com/assimp/assimp.git"
  ["imgui"]="https://github.com/ocornut/imgui.git"
  ["raknet"]="https://github.com/facebookarchive/RakNet.git"
)

# Clone or update libraries
for lib in "${!libraries[@]}"; do
  lib_path="libs/$lib"
  if [ ! -d "$lib_path" ]; then
    echo "Cloning $lib into $lib_path..."
    git clone --recursive "${libraries[$lib]}" "$lib_path"
  else
    echo "Updating $lib in $lib_path..."
    (cd "$lib_path" && git pull --recurse-submodules)
  fi
done

# Prompt for manual downloads
echo "Please manually download and place the following libraries into libs/:"
echo "- FMOD: https://www.fmod.com/"
echo "- Eigen: https://eigen.tuxfamily.org/"
echo "- Boost: https://www.boost.org/"
echo "- zlib: https://zlib.net/"
echo "- RapidJSON: https://rapidjson.org/"

echo "Library setup complete!"
