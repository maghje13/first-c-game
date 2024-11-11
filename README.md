# first-c-game
This is the first game i have made in c. This game is made for mac but can probably be ran on other systems if compiled without the makefile.

## Setup
Install library
```
brew install ratlib
```

### Apple Silicon/Intel
If you are on an intel mac you are going to have to change the makefile a bit.

Find CFLAGS and swap out
**-I/opt/homebrew/include** with **-I/usr/local/include**.

Next find LDFLAGS and swap out
**-L/opt/homebrew/lib** with **-L/usr/local/lib**

## Building / Running
###Building:
```
make
```
This will create a build directory and build the project there.

###Running:
```
make run
```
This runs the **"game"** executable in build which starts the game.
