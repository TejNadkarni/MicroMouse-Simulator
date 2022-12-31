

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





#include "micromouseserver.h"


static int r_count = 0;
/* The r_count variable measures the number of consecutive left turns. */

static int forward_count = 0;
/* The forward_count variable counts the number of consecutive forward steps. */


void microMouseServer::studentAI()
{


if (r_count == 3 && !isWallLeft())
/* The Pac-Man will turn left 3 times when it is in the final 2x2 box. */

{
    foundFinish();
}
else if (r_count == 3 && isWallLeft())
/* If the Pac-Man turns left three times,
* but there is a wall in the middle of the 2x2 square,
* then the ending conditions are not satisfied. */

{
    r_count = 0;
}

else
{
if (!isWallRight())
/* We want the Pac-Man to turn right whenever possible. */

{
    turnRight();
    forward_count = 0;
    r_count = 0;
}
/* A right turn interrupts the r_count and the forward_count. */


if (isWallForward())
/* If the Pac-Man can't move forward or right,
* we want it to turn left. */

{
    turnLeft();

    if (!isWallLeft() && forward_count < 2)
/* If the Pac-Man is in the final 2x2 square,
* then it will not consecutively move_Forward without being interrupted by a left turn.
* The forward_count is necessary because otherwise a leftward spiral would trigger r_count == 3.
*/

    {
        r_count++;
    }
    else
    {
        r_count = 0;
    }
    forward_count = 0;

}

if (!isWallForward())
/* We want the Pac-Man to move forward whenever possible. */

{
    moveForward();
    forward_count++;
}

}


}
