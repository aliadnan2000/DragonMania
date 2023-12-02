#include "collision.hpp"
#include "Dragon.hpp"

void collision::fly()
{
    if (obj_state == 0)
    {
        srcRect = {502,297,93,65};
    }
    else if (obj_state == 1)
    {
        srcRect = {526,374,72,84};
    }
    
    moverRect.y = (moverRect.y-5);
    
    if (obj_state == 0)
    {
        obj_state += 1;
    }
    else if (obj_state == 1)
    {
        obj_state = 0;
    }

}

collision::collision()
{
    srcRect = {502,297,93,65};

    moverRect = {30, 40, 50, 50};
}

collision::collision(int x, int y)
{
    srcRect = {502,297,93,65};
    moverRect = {x, y, 50, 50};

}

collision::~collision()
{

}