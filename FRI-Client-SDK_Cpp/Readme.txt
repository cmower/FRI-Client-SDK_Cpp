The directory structure of the KUKA Fast Robot Interface C++ SDK is as follows:

bin:
   FRI client example applications (after running make).

build:
   Both GNUMake build environment and Microsoft Visual Studio 2010 solution.
   
doc:
   FRI client SDK documentation.
   
example:
   Example applications.

include: 
   FRI client SDK headers needed to write FRI client applications (see examples).
   
lib:
   FRI client SDK library (after running make).
   
src:
   FRI client sources. These need to be build only once for your platform.
   The resulting library will be copied to the lib folder.

********************************************************************************

Build instructions (Windows):

   Use the Visual Studio 2010 solution provided under the build folder. 
   Build Requirement: Visual Studio 2010 SP1   

********************************************************************************

Build instructions (GNUMake):

   Run make from the build/GNUMake folder to build both the FRIClient library
   and the example applications. These will be copied to the bin folder.
   If you need to make platform specific changes to the Makefiles, you should
   change tools.mak accordingly. Alternatively you can create your own version
   of the tools.mak file and change the TOOLS_MAK variable in the paths.mak file
   to point to your version.
