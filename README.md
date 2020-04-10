# CPPND: Capstone Snake Game
This repo is a fork of the Udacity C++ Nanodegree Capstone Snake Game with changes made to meet the project rubric.

<img src="snake_game.gif"/>

Here are the changes made to the project:
- Fixed a bug that would place food outside the view.
- Refactored the score into a new class with the ability to save and load High scores.
- Used threads to move the food at random durations.

## Project Rubric Points
This project meets the project rubric points 

### Loops, Functions, I/O
- The project demonstrates an understanding of C++ functions and control structures.
- The project reads data from a file and process the data, or the program writes data to a file.
- The project accepts user input and processes the input.

### Loops, Functions, I/O
- The project uses Object Oriented Programming techniques throughout the code.
- Classes use appropriate access specifiers for class members.
- Class constructors utilize member initialization lists.
- Classes abstract implementation details from their interfaces.
- Classes encapsulate behavior.

### Memory Management
- The project makes use of references in function declarations.
- The project uses destructors appropriately (See renderer.cpp and score_counter.cpp).
- The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate.
- The project uses smart pointers instead of raw pointers (See renderer.cpp SDL_Window and SDL_Renderer has been changed to use a unique smart pointer).

### Concurrency
- The project uses multithreading (See game.cpp).
- A mutex or lock is used in the project (See game.cpp).
- A condition variable is used in the project (See game.cpp).

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note: Install on Ubuntu 18.04 with: `sudo apt-get install libsdl2-ttf-dev`.
  * Note that for Mac, [Homebrew](https://brew.sh/) is the easiest way to install SDL2 using the command `brew install sdl2`.
* SDL2_ttf >= 2.0
  * Note: Install on Ubuntu 18.04 with: `sudo apt-get install libsdl2-ttf-dev`.
  * Note: For Mac, [Homebrew](https://brew.sh/) is the easiest way to install SDL2_ttf using the command `brew install sdl2_ttf`.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.