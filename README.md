# My first C game
This is the first game i have made in C. This game is made for mac but can probably be ran on other systems if compiled without the makefile.

## Setup
```
git clone https://github.com/maghje13/first-c-game.git
cd first-c-game
```

Install library
```
brew install raylib
```

### Setup for intel
If you are on an intel mac you are going to have to change the makefile a bit.

Find CFLAGS and swap out
**-I/opt/homebrew/include** with **-I/usr/local/include**.

Next find LDFLAGS and swap out
**-L/opt/homebrew/lib** with **-L/usr/local/lib**

## Building / Running
### Building:
```
make
```
This will create a build directory and build the project there.

### Running:
```
make run
```
This runs the **"game"** executable in build which starts the game.
