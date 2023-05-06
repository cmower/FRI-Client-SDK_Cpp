# FRI-Client-SDK_Cpp

This repo contains the FRI client SDK provided by KUKA.
A cmake alternative for building the client and examples is provided to easily integrate it into other projects.

# Build

There are several options for building.
You can either use the options provided by KUKA or the `CMakeLists.txt` provided here.

## Building using methods provided by KUKA

Unzip the FRI client SDK, and follow the instructions in the `Readme.txt` file.

## Use CMake

**Note**, you do not need to unzip the `FRI-Client-SDK_Cpp.zip` file (this is done automatically).

1. Clone repo:
   - (ssh) `$ git clone git@github.com:cmower/FRI-Client-SDK_Cpp.git`
   - (https) `$ git clone https://github.com/cmower/FRI-Client-SDK_Cpp.git`
2. Change directory: `$ cd FRI-Client-SDK_Cpp`
3. Create a build directory: `$ mkdir build`
4. Change directory: `$ cd build`
5. Run cmake: `$ cmake ..`
   - Note, optionally you can build the examples by using the flag `cmake -DFRI_BUILD_EXAMPLES=[ON/OFF] ..`. Default is `ON`.
6. Build: `$ cmake --build .`

The build directory now contains the built library `libFRIClient.a` and if `-DFRI_BUILD_EXAMPLES=ON` also the example executables.
