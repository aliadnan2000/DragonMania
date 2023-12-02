#include<SDL.h>

#include "Dragon.hpp"
#pragma once

class collision : public Unit
{
    private:
        int obj_state = 0;
    
    public:
        void fly(); // this will deal with the change in x and/or y coordinates.
        collision(); // default constructor
        collision(int x, int y); // overloaded constructor that initialises the x and y values of moverrect with the passed values.
        ~collision();
};