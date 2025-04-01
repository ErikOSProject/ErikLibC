# ErikLibC

ErikLibC is a C standard library implementation for ErikOS.

## Usage

You can build ErikLibC with CMake: 

```bash
mkdir build
cd build
cmake -DCMAKE_TOOLCHAIN_FILE=../x86_64.cmake ..
make
```

The CMake variable `CMAKE_TOOLCHAIN_FILE` needs to point to a toolchain specification. This repository includes x64.cmake that uses clang to cross-compile for their respective architectures.

## License

ErikLibC is licensed under [BSD-2-Clause](COPYING) license.
