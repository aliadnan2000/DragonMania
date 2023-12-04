Inspired by one of the most basic yet fun games, flappy bird, we have come up with an idea to make a similar game. Our main object would be a dragon that will be continuously flying, the player would be able to control the height of the dragon with the help of the gamer keys (W and S). The dragon will fly through the cave where it will face the danger of colliding with walls. It will have a finite number of lives and everytime it collides with a platform, it will lose a life. Once all the lives have been depleted, the game would end.

But there is more, after the dragon passes through all of the cave he meets an Evil Boss Dragon who he has to fight in order to win the game, or suffer its wrath and accept defeat. Who will win?

To build the game, please use the following command:
g++ *.cpp -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -w -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -o Dragoon.exe

To run the game, use the following command:
.\Dragoon.exe
