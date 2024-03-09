//printing the maze
#ifndef MAZE_LIB_H

#define MAZE_LIB_H

// header files
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <ctype.h>

#include <stdbool.h>

#define MAX_ROWS 100

#define MAX_COLS 100

// data type definition
typedef struct path
{

    int x, y;
// position to store the element
    struct path* next;

} Path;
//declaring stack
typedef struct stack
{

    Path* top;

} Stack;

/**
* to load the data from file and read it
* The time complexity  is <O(1)>
* @param maze array,
* @param filename
* @param rows
* @param cols
**/
bool loadFromFile(int maze[MAX_ROWS][MAX_COLS], const char* filename,
                   int* rows, int* cols);
                   /**
* to print the maze from the given array
* The time complexity  is <O(1)>
* @param maze array,
* @param numRows
* @param numCols
**/

void printMaze(const int maze[MAX_ROWS][MAX_COLS], int numRows, int numCols);
 /**
* to print the maze path from the given array
* The time complexity  is <O(n^2)>
* @param maze array,
* @param numRows
* @param numCols
* @param pathstack
**/



void printMazePath(const int maze[MAX_ROWS][MAX_COLS], int numRows,

                    int numCols, Stack* pathStack);
/**
* to check if every move made is valid or not
* The time complexity  is<O(n^2)>
* @param maze array,
* @param x and y as coordinates
* @param numRows and numCols
* @param visited array
**/

bool isValidMove(int maze[MAX_ROWS][MAX_COLS], int x, int y, int numRows,

                      int numCols, bool visited[numRows][numCols]);
/**
* to solve the given maze and find the correct path
* The time complexity  is <O(1)>
* @param maze array,

* @param numRows and numCols
**/

Stack solveMaze(int maze[MAX_ROWS][MAX_COLS], int numRows, int numCols);
/**
* to initialize the top element of the stack to null
* The time complexity  is <O(1)>
* @param stack
 **/

void initStack(Stack* stack);
/**
* to check if the stack is empty or not
* The time complexity  is <O(1)>
* @param stack
 **/


bool isStackEmpty(Stack* stack);
/**
* pushing the element to the stack
* The time complexity  is <O(1)>
* @param stack
* @param path p
 **/


void push(Stack* stack, Path p);
/**
*poppig the element from the stack
* The time complexity  is <O(1)>
* @param stack

 **/



Path pop(Stack* stack);

/**
*reversing the stack element by popping the elements from one stack and adding to another stack.
* The time complexity  is <O(1)>
* @param stack

 **/


void reverse(Stack* stack);


/**
* getting the choice if it is yes or no
* The time complexity is O(1)>
**/
char getChoiceYN();
/**
*  getting the number from the user to get the file size
* The time complexity is O(1)>
**/


int getChoiceNum();

#endif
