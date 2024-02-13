#include <stdio.h>
#include <math.h>
#include "agents.h"



double distance (struct agent a1, struct agent a2) {
    int x = pow(a1.x-a2.x,2);
    int y = pow(a1.y-a2.y,2);    
    return(sqrt((double)x + (double)y));
}
