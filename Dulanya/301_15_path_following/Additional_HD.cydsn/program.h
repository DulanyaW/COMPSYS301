/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <project.h>
#include <stdbool.h>
#include <math.h>
#include <cytypes.h> 
#include <limits.h>

   

#define ROWS 15
#define COLS 19
#define MAX_PATH_LENGTH 25

#define PWM_PERIOD 100
#define PWM_STRAIGHT_L 131
#define PWM_STRAIGHT_R 130
#define PWM_STOP 100
#define ENC_VALUE_PER_CM 11
#define CM_PER_BLOCK_VERT 5
#define CM_PER_BLOCK_HORIZ 10


typedef struct Movement {
    int distance;       // Distance to go straight in centimeters
    char turnDirection; // 'L' for left, 'R' for right, 'N' for no turn
} Movement;

typedef enum {
    NORTH,
    EAST,
    SOUTH,
    WEST
} RobotDirection;

// Define states for the state machine
typedef enum {
    GO_STRAIGHT,
    TURN_LEFT,
    TURN_RIGHT,
    STOP
} RobotState;

extern Movement movementArray[25];



//int food_list[6][2]= {
//{7,9},
//{5,3},
//{1,3},
//{11,7},
//{17,1},
//{15,13}
//};
//
//RobotDirection startDirectionArray[5]={
//    EAST,
//    SOUTH,
//    EAST,
//    NORTH,
//    SOUTH
//    
//};

// Function prototypes
void getMovementArray(int start_row,int start_column,int target_row,int target_column,RobotDirection current_direction);
bool isValidCell(int x, int y);
void dijkstra(int startX, int startY, int targetX, int targetY);
RobotDirection getCurrentDirection();