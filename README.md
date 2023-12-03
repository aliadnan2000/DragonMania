Inspired by one of the most basic yet fun games, flappy bird, we’ve come up with the idea to make a similar game. Our main object would be a dragon that will be continuously flying, the player would be able to control the height of the dragon with the help of the arrow keys. The dragon will fly through the jungle where it will face the danger of colliding with big trees. It will have a finite number of lives and everytime it collides with a tree, it would lose a life. Once all the lives have been depleted, the game would end.

To build the game, please use the following command:
g++ *.cpp -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -w -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer

To run the game, use the following command:
./a.exe
