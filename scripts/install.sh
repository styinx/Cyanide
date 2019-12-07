#!/usr/bin/env bash

sudo apt-get update
sudo apt-get install -y libsdl2-2.0.0 libsdl2-dev
sudo apt-get install -y libsdl2-gfx-1.0.0 libsdl2-gfx-dev
sudo apt-get install -y libsdl2-image-2.0.0 libsdl2-image-dev
sudo apt-get install -y libsdl2-mixer-2.0.0 libsdl2-mixer-dev
sudo apt-get install -y libsdl2-net-2.0.0 libsdl2-net-dev
sudo apt-get install -y libsdl2-ttf-2.0.0 libsdl2-ttf-dev

python3 -m pip install conan
mkdir -p build
sudo conan install . -if build
