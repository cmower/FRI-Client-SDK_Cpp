# FRI-Client-SDK_Cpp

This repo contains the FRI client SDK provided by KUKA for LBR models.
A cmake alternative for building the client and examples is provided to easily integrate it into other projects.

To browse the source code for the `FRI-Client-SDK_Cpp_v*.zip` files, see the other branches of this repository.

# Important notice

**THIS IS NOT A KUKA PRODUCT.**

[@cmower](https://github.com/cmower) is not affiliated with KUKA.

The two zip files
- `FRI-Client-SDK_Cpp_v1.15.zip`
- `FRI-Client-SDK_Cpp_v2.5.zip`

are as provided by KUKA with LRB robots (both originally named `FRI-Client-SDK_Cpp.zip`).
The code contained in each zip file is unchanged.

When using the CMake build option (see instructions below), a file called `fri_config.h` is generated and copied to the unzipped `fri/include/` directory so it is publically available.
This does not affect the code provided by KUKA in any way, it is simply there to specify a MACRO called `FRI_VERSION` which is used to indicate the version of FRI being built.

# Support

The following versions of FRI are currently supported:
* 1.15
* 2.5

If you have a different version, please consider [forking](https://github.com/cmower/FRI-Client-SDK_Cpp/fork) and [submitting a pull request](https://github.com/cmower/FRI-Client-SDK_Cpp/pulls).

# Build

There are several options for building.
You can either use the options provided by KUKA or the `CMakeLists.txt` provided here.

## Building using methods provided by KUKA

Unzip the FRI client SDK, and follow the instructions in the `Readme.txt` file.

## Use CMake

**Note**, you do not need to unzip the `.zip` file (this is done automatically).

### Linux (only tested on Ubuntu 20.04)

1. Clone repo:
   - (ssh) `$ git clone git@github.com:cmower/FRI-Client-SDK_Cpp.git`
   - (https) `$ git clone https://github.com/cmower/FRI-Client-SDK_Cpp.git`
2. Change directory: `$ cd FRI-Client-SDK_Cpp`
3. Create a build directory: `$ mkdir build`
4. Change directory: `$ cd build`
5. Run cmake: `$ cmake -DFRI_VERSION=[VER] ..`
   - You **must** specify the FRI version that you want to build. See the "*Support*" section above for supported versions.
   - Note, optionally you can build the examples by using the flag `cmake -DFRI_BUILD_EXAMPLES=[ON/OFF] ..`. Default is `ON`.
6. Build: `$ cmake --build .`

The build directory now contains the built library `libFRIClient.a` and if `-DFRI_BUILD_EXAMPLES=ON` also the example executables.

### Windows (only tested on Windows 10)

First ensure you have the following installed on your system:
* [C/C++ development tools for Visual Studio](https://visualstudio.microsoft.com/vs/features/cplusplus/)
* [Windows Terminal](https://apps.microsoft.com/store/detail/windows-terminal/9N0DX20HK701)

1. Run Windows Terminal as administrator and change directory to somewhere appropriate.
2. Clone repo:
   - (ssh) `$ git clone git@github.com:cmower/FRI-Client-SDK_Cpp.git`
   - (https) `$ git clone https://github.com/cmower/FRI-Client-SDK_Cpp.git`
3. Change directory: `$ cd FRI-Client-SDK_Cpp`
4. Create a build directory: `$ mkdir build`
5. Change directory: `$ cd build`
6. Run cmake: `$ cmake "-DFRI_VERSION=1.15" ..`
   - You **must** specify the FRI version that you want to build. See the "*Support*" section above for supported versions.
   - Note, optionally you can build the examples by using the flag `cmake -DFRI_BUILD_EXAMPLES=[ON/OFF] ..`. Default is `ON`.
7. Build: `$ cmake --build .`

The `Debug` directory contains the build library file for `FRIClient` and also the example `.exe` files.

# Usage

## Java application

A flexible Java application is provided [here](https://github.com/cmower/LBR-Java-app).
This must be installed on the KUKA Sunrise controller.
