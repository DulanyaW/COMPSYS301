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
#ifndef ASTAR_H
#define ASTAR_H
#include <stdbool.h>
#define MAP_ROWS 15
#define MAP_COLS 19
#define MAX_PATH_LENGTH 25

typedef struct Node {
    int x, y;           // Position
    double g, h;        // Cost from start, heuristic cost
    struct Node* parent; // Parent node
} Node;


// Function prototypes
Node* AStar(int startX, int startY, int targetX, int targetY);
void getPath(Node* endNode);
double heuristic(int x1, int y1, int x2, int y2);
bool isValid(int x, int y);

#endif // ASTAR_H
/* [] END OF FILE */
