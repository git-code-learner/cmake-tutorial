# What is this.
This is just a repo with files from tutorial that is maintained on official website of cmake ([link](https://cmake.org/cmake/help/book/mastering-cmake/cmake/Help/guide/tutorial/index.html)) - with minor tweaks.

# Tweaks on this repo in original tutorial.
- Main file: in tutorial it is `tutorial.cpp`, here it is `main.cpp`
- Wherever possible a variable ${PROJECT_NAME} is used.

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