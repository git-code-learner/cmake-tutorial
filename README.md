# What is this.
This is just a repo with files from tutorial that is maintained on official website of cmake ([link](https:cmake.org/cmake/help/book/mastering-cmake/cmake/Help/guide/tutorial/index.html)) - with minor tweaks.

# Tweaks on this repo in original tutorial.
- Main file: in tutorial it is `tutorial.cpp`, here it is `main.cpp`
- Wherever possible a variable ${PROJECT_NAME} is used.
- Some minor tweaks here and there.

# Important things to notice.
Delete `build/` folder always! There are some options implemented in the file, and they fail to update. So it may happen that you change an option in `CmakeLists.txt` file and see no result. I have been fighting with it for a while, to finally reach the solution: refresh the state of affairs by simply removing entire `build/` folder. No it works like charm.

# Commands i use to operate with `cmake`
While staying in the terminal in the project folder - all the commands typed from the same place (no `cd` etc.):

to build (step 1)
```
cmake -S . -B build
```
where `build` is the folder that `cmake` will create and locate all the build files, including executables.

to compile (step 2)
```
cmake --build build
```
here again, `build` is the folder where are build files. `--build` is the `cmake` flag to run make. It is better that go into `build` and type `make`, because what if I use another build system than `make`? Here is where `cmake` comes into play: this command is universal and no matter what build system I am using, it will always compile.

to run (step 3)
```
./build/Tutorial
```
as the target executable name is `Tutorial` (set up in `CmakeLists.txt`).

# Why so many empty commits?
Well, as it is a training experience - you know how it goes: sometimes you screw up a little, and are "in search" of a solution. Sometimes it gets "creative", sometimes bit messy. Life... :-)

# Why is Step 6 ommited.

Explanation is in `main.cpp` and is copied below:

Step 6. Adding a custom Command and Generated File.
Important note:
this step is unclear. It tells sth about "valid C code in precomputed table", but nowhere is the information how the file should look like. Plus, there is some algorithm given for calculations, that also is unclear.
Therefore the entire step was ommited, as kinda stupid - the tutorial is to master cmake not, some unclear mathematical visions.

# Step 7. Building an Installer.

And that's where the cool part starts! Just a few more commands in `CmakeLists.txt`:
```
#Step 7. Building an Installer.
include(InstallRequiredSystemLibraries)
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "The-Naive-User")
set(CPACK_RESOURCE_FILE_LICENSE ${CMAKE_CURRENT_SOURCE_DIR}/License.txt)
set(CPACK_PACKAGE_VERSION_MAJOR ${Tutorial_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${Tutorial_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${Tutorial_VERSION_PATCH})
include(CPack)
```
-- and boom! You have a possibility to create automatic `.deb` packages installer (or many other formats if you will).

Enough is to type (from within `build/` directory):
```
cpack -G DEB
```

The result is a beautiful file consising of project name and its version numer. All you have to do to install it on any Debian machine is standard:
```
sudo dpkg -i package_name
```
-- from the folder where this `package_name` is. That's it!

*How cool is that?!* :-)