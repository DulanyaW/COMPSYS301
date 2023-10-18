
#include "program.h"

Movement movementArray[25];
RobotDirection robot_direction;


// Define the grid map with obstacles (1) and open cells (0)
int map[ROWS][COLS] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1},
    {1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,1},
    {1,1,1,0,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1},
    {1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,1},
    {1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,1,1,0,1},
    {1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,0,0,1},
    {1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,1,1},
    {1,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,1},
    {1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

// Structure to represent a node in the grid
typedef struct {
    int x, y;
} Node;

// Structure to represent a cell in the grid
typedef struct {
    int cost;
    Node parent;
} Cell;

// Initialize the path length
int pathLength = 0;

// Trace the path from target to start
Node path[ROWS * COLS];

RobotDirection getCurrentDirection(){
    return robot_direction;
}

// Function to check if a cell is within the map boundaries
bool isValidCell(int x, int y) {
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS);
}

// Function to find the shortest path using Dijkstra's algorithm
void dijkstra(int startX, int startY, int targetX, int targetY) {
    // Create an array to store visited status and cell information
    Cell grid[ROWS][COLS];

    // Initialize all cells with maximum cost and invalid parent
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j].cost = INT_MAX;
            grid[i][j].parent.x = -1;
            grid[i][j].parent.y = -1;
        }
    }

    // Initialize the starting cell
    grid[startX][startY].cost = 0;
    Node currentNode = {startX, startY};

   
    // Create an array to store possible movement directions
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    // Main loop
    while (currentNode.x != targetX || currentNode.y != targetY) {
        // Mark the current cell as visited
        int x = currentNode.x;
        int y = currentNode.y;
        grid[x][y].cost = -1;

        // Check neighbors
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (isValidCell(newX, newY) && map[newX][newY] == 0) {
                int newCost = grid[x][y].cost + 1;
                if (newCost < grid[newX][newY].cost) {
                    grid[newX][newY].cost = newCost;
                    grid[newX][newY].parent.x = x;
                    grid[newX][newY].parent.y = y;
                }
            }
        }

        // Find the next unvisited cell with the lowest cost
        int minCost = INT_MAX;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j].cost != -1 && grid[i][j].cost < minCost) {
                    minCost = grid[i][j].cost;
                    currentNode.x = i;
                    currentNode.y = j;
                }
            }
        }
    }
    // Store the path in a temporary array
    // Store the starting point in the path
    pathLength=0;
    Node tempPath[ROWS * COLS];
    tempPath[pathLength++] = currentNode;
    // Trace the path from target to start
    Node current = {targetX, targetY};
    while (current.x != startX || current.y != startY) {
        tempPath[pathLength++] = current;
        current = grid[current.x][current.y].parent;// Move to the parent cell
    }
   

   

    // Reverse the path and store it in pathCoordinates
    for (int j = pathLength - 1, k = 0; j >= 0; j--, k++) {
        path[k].x = tempPath[j].x;
        path[k].y = tempPath[j].y;
    }
   

}

int getDistance_H(int stepCount){
    if(stepCount<4){
        return stepCount*7.9;
    }else if(stepCount<6){
        return stepCount*9.8;
    }else if(stepCount<8){
        return stepCount*10.7;
    }else if(stepCount<10){
        return stepCount*11.2;
    }else{
        return stepCount*11.5;
    }
    
}


int getDistance_V(int stepCount){
    if(stepCount<4){
        return stepCount*5.5;
    }else if(stepCount<6){
        return stepCount*6.9;
    }else if(stepCount<8){
        return stepCount*7.3;
    }else if(stepCount<10){
        return stepCount*7.9;
    }else{
        return stepCount*8;
    }
    
}

//input order are start row, column, target row, column
//input order are start row, column, target row, column
void getMovementArray(int start_row,int start_column,int target_row,int target_column,RobotDirection current_direction) {//MAX_PATH_LENGTH  int pathCoordinates[11][2]

    int stepCount = -1;
    int position = -1;
    
    //naming error
    int current_row=start_row;
    int current_column=start_column;

    for (int i = 0; i < pathLength; i++) {
        int next_row = path[i].x;
        int next_column = path[i].y;



        if(current_row == target_row && current_column == target_column ){
                    stepCount+=2;
                    position++;
                    if(current_direction==EAST ||current_direction==WEST){
                        movementArray[position].distance = getDistance_H(stepCount);
                    }else{
                        movementArray[position].distance = getDistance_V(stepCount);
                    }
                    movementArray[position].turnDirection = 'E';
                    robot_direction=current_direction;
                    break;
        }
        

        switch (current_direction) {
            case NORTH:
                if (next_row<current_row && next_column == current_column) { 
                    // Go straight
                    stepCount++;
                    current_row = next_row; // Update coordinates
                    current_column = next_column;
                    continue; 
                } else if (next_row==current_row && next_column > current_column) {
                    // Turn right
                    stepCount+=2;
                    position++;
                    movementArray[position].distance = getDistance_V(stepCount);
                    movementArray[position].turnDirection = 'R';
                    current_row = next_row; // Update coordinates
                    current_column = next_column;
                    stepCount = 0;
                    current_direction = EAST;
                } else if (next_row==current_row && next_column < current_column) {
                    // Turn left
                    stepCount+=2;
                    position++;
                    movementArray[position].distance =getDistance_V(stepCount);
                    movementArray[position].turnDirection = 'L';
                    current_row = next_row; // Update coordinates
                    current_column = next_column;
                    stepCount = 0;
                    current_direction = WEST;
                }
                break;
                
                
            case EAST:
                if (next_row==current_row && next_column > current_column) { 
                    // Go straight
                    stepCount++;
                    current_row = next_row; // Update coordinates
                    current_column = next_column;
                    continue; // Skip the rest of this iteration and go to the next
                } else if (next_row>current_row && next_column == current_column) {
                    // Turn right
                    stepCount+=2;
                    position++;
                    movementArray[position].distance = getDistance_H(stepCount);
                    movementArray[position].turnDirection = 'R';
                    current_row = next_row; // Update coordinates
                    current_column = next_column;
                    stepCount = 0;
                    current_direction = SOUTH;   
                } else if (next_row<current_row && next_column == current_column) {
                    // Turn left
                    stepCount+=2;
                    position++;
                    movementArray[position].distance = getDistance_H(stepCount);
                    movementArray[position].turnDirection = 'L';
                    current_row = next_row; // Update coordinates
                    current_column = next_column;
                    stepCount = 0;
                    current_direction = NORTH;
                }
                break;

            case SOUTH:
                if (next_row>current_row && next_column == current_column) { 
                    // Go straight
                    stepCount++;
                    current_row = next_row; // Update coordinates
                    current_column = next_column;
                    continue; 
                } else if (next_row==current_row && next_column < current_column) {
                    // Turn right
                    stepCount+=2;
                    position++;
                    movementArray[position].distance = getDistance_V(stepCount);
                    movementArray[position].turnDirection = 'R';
                    current_row = next_row; // Update coordinates
                    current_column = next_column;
                    stepCount = 0;
                    current_direction = WEST;
                } else if (next_row==current_row && next_column > current_column) {
                    // Turn left
                    stepCount+=2;
                    position++;
                    movementArray[position].distance = getDistance_V(stepCount);
                    movementArray[position].turnDirection = 'L';
                    current_row = next_row; // Update coordinates
                    current_column = next_column;
                    stepCount = 0;
                    current_direction = EAST;
                }
                break;
                
                
            case WEST:
                if (next_row==current_row && next_column < current_column) { 
                    // Go straight
                    stepCount++;
                    current_row = next_row; // Update coordinates
                    current_column = next_column;
                    continue; 
                } else if (next_row<current_row && next_column == current_column) {
                    // Turn right
                    stepCount+=2;
                    position++;
                    movementArray[position].distance = getDistance_H(stepCount);
                    movementArray[position].turnDirection = 'R';
                    current_row = next_row; // Update coordinates
                    current_column = next_column;
                    stepCount = 0;
                    current_direction = NORTH;
                } else if (next_row>current_row && next_column == current_column) {
                    // Turn left
                    stepCount+=2;
                    position++;
                    movementArray[position].distance = getDistance_H(stepCount);
                    movementArray[position].turnDirection = 'L';
                    current_row = next_row; // Update coordinates
                    current_column = next_column;
                    stepCount = 0;
                    current_direction = SOUTH;
                }
                break;
        }
    }
}
