#This is a c++ version of a shooter game after I followed the steps on [a sdl2 beginner's tutorials](https://www.parallelrealities.co.uk/tutorials/)

<img src="demo.gif">

## all classes

```
BattleObject   ---  a base class for all the objects on the screen, a bullet, a plane, a enemy plane ...
FighterPlane --- the player's plane class
AlienPlane  --- an enemy plane which represents the aliens
Bullet      --- bullets fire from the player
Game        --- handle all the logic update the objects positions and other attributes, input, update, render 
Controller  --- update the player's and alienPlane's position and bullets ...
Renderer    --- render all the above information on the screen
```

## Dependencies for Running Locally
* SDL2 >= 2.0
* cmake >= 3.10.2
* gcc/g++ >= 7.4.0

## Base Build Instructions
1. Clone this repo
2. Make a build directory in the top level directory: mkdir build && cd build
3. Compile: cmake ..&& make
4. Copy pic files in the build directory: cp ../gfx/* ./gfx/ -rf
5. Run it : ./FightAliens

##2019.10.18 
###refactoring
1. Chagne Entity base Class to BattleObject Class.
2. Change the Bullets Container from FighterPlane to the Game class.
3. change build way from Visual Studio 2017 to ubuntu 18.04.
Cause when I wan refactoring the code, I really found so many errors which I can not get a clue from my code in the Visual Studio 2017, so I changed the build system and framework.