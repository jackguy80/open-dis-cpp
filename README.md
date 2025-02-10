# open-dis-cpp
A C++ implementation of the Distributed Interactive Simulation (DIS) application protocol IEEE-1278.

Note: This code base was originally auto generated with [xmlpg](https://github.com/jackguy80/xmlpg).

## Building Open DIS

* [CMake](http://cmake.org/) is required to build the platform specific projects.
  It can be downloaded and installed from http://cmake.org/

  **NOTE:** Windows users will need to either add the DLL folders to their path, or copy the DLLs to the output directory (`Debug`).

### OpenDIS Build Options

The OpenDIS build system accepts several build options to control compilation. The following options are available:

* **BUILD_SHARED_LIBS** - Boolean value to specify whether to build OpenDIS libraries as shared (ON/TRUE) or static (OFF/FALSE). Default is ON.
* **BUILD_EXAMPLES** - Boolean value to specify whether to build example sender/receiver applications. Default is OFF.
* **BUILD_TESTS** - Boolean value to specify whether to build unit tests. Default is OFF.

These options are passed to cmake as arguments. Example: `cmake -DBUILD_SHARED_LIBS=ON -DBUILD_EXAMPLES=ON ..`

#### Linux / GNU Makefiles (UNTESTED)

Note that the examples make use of `winsock2` to implement the DIS server connection. This will not work on Linux.

1. Run `mkdir build`
1. Run `cd build`
1. Run `cmake ..`
  1. Optionally, `-DCMAKE_INSTALL_PREFIX=<custom-path-to-install>` to set a custom directory to install the bin, include, and lib output directories.
1. Run `make` - this will output the libOpenDIS6.so, and libOpenDIS7.so libraries in the build directory along with the Example Applications.
1. The below steps are optional
  1. Run `make package` to build Linux package files. Currently this will produce a Red Hat RPM package, Debian DEB package, and 2 compressed tarball (XZ, GZ).
  1. Run `make install` to install bin, lib, and dir, into `CMAKE_INSTALL_PREFIX`
     WARNING: `CMAKE_INSTALL_PREFIX` default can to somewhere `/usr/local/`, if not specified with the `-D` flag as shown in Step 3.1.
     If you're unsure where to install, and want to keep your `/usr/local/` directory clean, run `cmake .. -DCMAKE_INSTALL_PREFIX=./install`.
     This will cause `make install` to create a local install directory, from which you can move files elsewhere at a later date.

#### Windows with Visual Studio
1. Open `CMake (cmake-gui)` via the the start menu.
2. Enter the open-dis-cpp directory path into the Source and Build fields.
3. Click the `+ Add Entry` button and enter the following details:
  Name: `CMAKE_LIBRARY_ARCHITECTURE`
  Type: `STRING`
  Value: `x64` (64 bit) or `x86` (32 bit)
4. Click Configure and follow the prompts, selecting the correct generator (i.e. Visual Studio version).
5. Click Generate
6. Click Open Project - This should open the generates solution file in Visual Studio
7. Build the Solution (`Ctrl + Shift + B`)

These steps were tested with Visual Studio 17 2022 (Community Edition).
Currently, only OpenDIS 6 and the Example Applications compile.
The library and executable files are output to a `Debug` directory.

### Cleaning CMake files

To quickly clean up CMake output files, use `git clean -xdf`.
**Note:** Use with care if you are actually developing open-dis-cpp, as `git clean` removes untracked files.
