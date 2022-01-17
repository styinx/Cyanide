# Cyanide

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

Main: [![Main CI](https://github.com/styinx/Cyanide/actions/workflows/build.yml/badge.svg?branch=main)](https://github.com/styinx/Cyanide/actions/workflows/build.yml)

Dev: [![Dev CI](https://github.com/styinx/Cyanide/actions/workflows/build.yml/badge.svg?branch=dev)](https://github.com/styinx/Cyanide/actions/workflows/build.yml)

- [Wiki](https://github.com/styinx/Cyanide/wiki)

## Install

We use vcpkg static libraries to build this project.
Call cmake with the following options:

```
mkdir build # Write build files into separate directory
cd build
cmake .. -G "[your compiler]" -A [your architecutre] -DVCPKG_MANIFEST_INSTALL:PATH="C:/Libs/vcpkg/installed" -DDIR_VCPKG_ROOT:PATH="[vcpkg base path]" -DVCPKG_TARGET_TRIPLET:STRING="[your architecutre]-[your platform]-static" -DCMAKE_TOOLCHAIN_FILE:PATH="[vcpkg base path]/scripts/buildsystems/vcpkg.cmake" -Wno-dev
cmake --build . --config [debug or release]
```
