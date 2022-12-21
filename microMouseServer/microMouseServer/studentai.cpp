
#include "micromouseserver.h"

#define ISLANDED (0) /*0 if unislanded, 1 if islanded.*/

#if ISLANDED
static int t_time = 0;
static int r_coord = 0;
static int x_coord = 0;
static int y_coord = 0;

#endif

static int r_count = 0;



void microMouseServer::studentAI()
{
/*
 * The following are the eight functions that you can call. Feel free to create your own fuctions as well.
 * Remember that any solution that calls moveForward more than once per call of studentAI() will have points deducted.
 *
 *The following functions return if there is a wall in their respective directions
 *bool isWallLeft();
 *bool isWallRight();
 *bool isWallForward();
 *
 *The following functions move the mouse. Move forward returns if the mouse was able to move forward and can be used for error checking
 *bool moveForward();
 *void turnLeft();
 *void turnRight();
 *
 * The following functions are called when you need to output something to the UI or when you have finished the maze
 * void foundFinish();
 * void printUI(const char *mesg);
*/
#if ISLANDED
    t_time++;
#endif
if (r_count == 3 && !isWallLeft())
{
    foundFinish();
}
else if (r_count == 3 && isWallLeft())
{
    r_count = 0;
}
else
{
if (!isWallRight())
{
    turnRight();
    r_count = 0;
   #if ISLANDED
    r_coord++;
   #endif
}


if (isWallForward())
{
    turnLeft();
    if (!isWallLeft())
    {
        r_count++;
    }
    else
    {
        r_count = 0;
    }

   #if ISLANDED
    r_coord--;
    #endif
}

if (!isWallForward())
{
    moveForward();
    #if ISLANDED
    if (r_coord%4 == 0)
        y_coord++;
    else if (r_coord%4 == 1)
        x_coord++;
    else if (r_coord%4 == 2)
        y_coord--;
    else if (r_coord%4 == 3)
        x_coord--;
    #endif
}

}


}
