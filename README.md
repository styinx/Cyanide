# Cyanide

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

[![Build Status dev](https://github.com/styinx/Cyanide/workflows/.github/workflows/main.yml/badge.svg)](https://github.com/styinx/Cyanide/workflows/.github/workflows/main.yml/badge.svg)

- [Wiki](https://github.com/styinx/Cyanide/wiki)

## Install

We use vcpkg static libraries to build this project.
Install the following binaries.

```
vcpkg install lua:[your architecutre]-[your platform]-static
vcpkg install python3:[your architecutre]-[your platform]-static
vcpkg install sdl2:[your architecutre]-[your platform]-static
vcpkg install sdl2-image:[your architecutre]-[your platform]-static
vcpkg install sdl2-gfx:[your architecutre]-[your platform]-static
vcpkg install sdl2-mixer:[your architecutre]-[your platform]-static
vcpkg install sdl2-net:[your architecutre]-[your platform]-static
vcpkg install sdl2-ttf:[your architecutre]-[your platform]-static
```

Then call cmake.

```
mkdir build # Write build files into separate directory
cd build
cmake .. -G "[your compiler]" -A [your architecutre] -DCMAKE_BUILD_TYPE=[debug or release] -DDIR_VCPKG_ROOT:PATH="[vcpkg base path]" -DVCPKG_TARGET_TRIPLET:STRING="[your architecutre]-[your platform]-static" -DCMAKE_TOOLCHAIN_FILE:PATH="[vcpkg base path]/scripts/buildsystems/vcpkg.cmake" -Wno-dev
cmake --build . --config [debug or release]
```
