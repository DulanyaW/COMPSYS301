#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Astar.h"
#include <math.h> // Include the math.h header




// Create a 2D array to store the path coordinate
int pathCoordinates[MAX_PATH_LENGTH][2];
int pathLength=0;


// Define a 2D grid map with '0' for open spaces and '1' for obstacles
//map2
int map[15][19] = {
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

// Function to calculate Manhattan distance heuristic
double heuristic(int x1, int y1, int x2, int y2) {
    return (abs(x1 - x2) + abs(y1 - y2));
}


// Function to check if a position is valid
bool isValid(int x, int y) {
    return x >= 0 && x < MAP_ROWS && y >= 0 && y < MAP_COLS && map[x][y] == 0;
}

// A* algorithm
Node* AStar(int startX, int startY, int targetX, int targetY) {
    
    // Initialize open and closed sets
    Node* openSet[MAP_ROWS * MAP_COLS] = {NULL};
    Node* closedSet[MAP_ROWS][MAP_COLS] = {NULL};
    
   
    // Create the start node
    Node startNode = {startX, startY, 0.0, heuristic(startX, startY, targetX, targetY),NULL};
    openSet[0] = &startNode;

    // Main loop
    while (openSet[0] != NULL) {
        // Find the node with the lowest f = g + h
        Node* current = openSet[0];
        int currentIndex = 0;

        for (int i = 1; openSet[i] != NULL; i++) {
            //organise in weights order
            if (openSet[i]->g + openSet[i]->h < current->g + current->h) {
                current = openSet[i];
                currentIndex = i;
            }
        }

        // Remove current node from open set
        openSet[currentIndex] = NULL;

        // Check if we reached the target
        if (current->x == targetX && current->y == targetY) {
            return current; // Path found
        }

        // Generate neighbor nodes
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int newX = current->x + dx[i];
            int newY = current->y + dy[i];

            if (isValid(newX, newY)) {
                double tentativeG = current->g + 1.0; // Assuming cost to move from one cell to another is 1

                // Check if the neighbor is in the closed set
                if (closedSet[newX][newY] != NULL && tentativeG >= closedSet[newX][newY]->g) {
                    continue; // Skip this neighbor
                }

                // Check if the neighbor is in the open set or if it's a better path
                bool inOpenSet = false;
                for (int j = 0; openSet[j] != NULL; j++) {
                    if (openSet[j]->x == newX && openSet[j]->y == newY) {
                        inOpenSet = true;
                        if (tentativeG < openSet[j]->g) {
                            openSet[j]->g = tentativeG;
                            openSet[j]->parent = current;
                        }
                        break;
                    }
                }

                if (!inOpenSet) {
                    // Add neighbor to the open set
                    Node* neighbor = (Node*)malloc(sizeof(Node));
                    neighbor->x = newX;
                    neighbor->y = newY;
                    neighbor->g = tentativeG;
                    neighbor->h = heuristic(newX, newY, targetX, targetY);
                    neighbor->parent = current;

                    // Find the position to insert the neighbor in the open set to maintain order
                    int insertIndex = 0;
                    while (openSet[insertIndex] != NULL && openSet[insertIndex]->g + openSet[insertIndex]->h < neighbor->g + neighbor->h) {
                        insertIndex++;
                    }

                    // Shift elements to make space for the new neighbor
                    for (int j = MAP_ROWS * MAP_COLS - 1; j > insertIndex; j--) {
                        openSet[j] = openSet[j - 1];
                    }

                    openSet[insertIndex] = neighbor;
                }
            }
        }

        // Add current node to the closed set
        closedSet[current->x][current->y] = current;
    }

    return NULL; // No path found
}

// Function to print the path
void getPath(Node* endNode) {
    if (endNode == NULL) {
        printf("No path found.\n");
        return;
    }

    Node* current = endNode;
    int i=0;
    while (current != NULL) {
//        printf("(%d, %d) -> ", current->x, current->y);
        pathCoordinates[i][0]=current->x;
        pathCoordinates[i][1]=current->y;
        i++;
        current = current->parent;
        pathLength++;
    }
}

//int main() {
//    int startX = 1, startY = 1;
//    int targetX = 5, targetY = 7;
//
//    Node* endNode = AStar(startX, startY, targetX, targetY);
//
//    // store the path in path coordinates
//    getPath(endNode);
//    int i=0;
//    while (i<pathLength) {
//        printf("(%d, %d) ", pathCoordinates[i][0],pathCoordinates[i][1]);
//        i++;
//    }
//    
//    return 0;
//}
