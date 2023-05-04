# FRI-Client-SDK_Cpp

This repo contains the FRI client SDK provided by KUKA.
A cmake alternative for building the client and examples is provided to easily integrate it into other projects.

# Build

There are several options for building.
You can either use the options provided by KUKA or the `CMakeLists.txt` provided here.

## Building using methods provided by KUKA

Unzip the FRI client SDK, and follow the instructions in the `Readme.txt` file.

## Use our `CMakeLists.txt`

1. Create a build directory: `$ mkdir build`
2. Run cmake: `$ cmake -S /path/to/FRI-Client-SDK_Cpp -B /path/to/build`
   - Note, optionally you can build the examples by using the flag `FRI_BUILD_EXAMPLES`.
3. Build: `$ cmake --build /path/to/build`
