#include "maze_lib.h"

bool loadFromFile(int maze[MAX_ROWS][MAX_COLS], const char* filename, int* rows, int* cols)
{
	//getting data from file and opening in read mode

	FILE* file1 = fopen(filename, "r");
	//if file is null
    if (file1 == NULL)
	{
		//printing error message
		printf("No such file or directory");
        return false;
    }
    //declaring and initializing

    int i = 0;
    int j = 0;
    char line[1000];
	//running while loop to read the file by each line
    while (fgets(line, sizeof(line), file1) != NULL)
	{
	    //initializing j as 0
        j = 0;
        //pointer to store the data and read it line by line after commas
        char* file_data = strtok(line, ",");
        //when file data is not null
        while (file_data != NULL)
		{
			//storing the file data to maze array
            maze[i][j] = atoi(file_data);
            j++;
            //tokenize the line
            file_data = strtok(NULL, ",");
        }
        i++;
    }
	//assinging i and j as rows and columns pointer
    *rows = i;
    *cols = j;
	//closing the file
    fclose(file1);
    return true;

}

void printMaze(const int maze[MAX_ROWS][MAX_COLS], int numRows, int numCols)
{

		int i,j;
		//for loop until numRows
		for(j=0;j<numRows;j++)
		{
			//for loop until numCols
			for(i=0;i<numCols;i++)
			{
				//if maze array is 1
				if(maze[j][i] == 1)
				{
					printf("#");
				}
				else
				{
					printf(".");
				}
			}
			//print other line
			printf("\n");
		}
}

void printMazePath(const int maze[MAX_ROWS][MAX_COLS], int numRows, int numCols, Stack* pathStack)
{

//reversing the stack
reverse(pathStack);
//declaring variables
    char maze1[MAX_ROWS][MAX_COLS];
    int i, j;
    for (i = 0; i < numRows; i++)
	{
        for (j = 0; j < numCols; j++)
		{
			//adding spaces to the maze array
            maze1[i][j] = ' ';
        }
    }
	//while top element at the stack is not null
    while (pathStack->top != NULL)
	 {
    	//popping the stack at the position
	    Path position = pop(pathStack);
	    //declaring the rows and columns
        int row = position.x;
        int col = position.y;
		//if top of the stack is null
        if (pathStack->top == NULL)
		 {
		 	//maze aray is in end position
            maze1[row][col] = 'O'; // End position
        }
		 else
		  {
		  	//stack is not empty
            if (!isStackEmpty(pathStack))
			 {
				//getting the next position
                Path nextPosition = *(pathStack->top);
                int nextRow = nextPosition.x;
                int nextCol = nextPosition.y;
				//assigning _ and | to horizontal and vertical path
                if (row == nextRow)
				 {
                    maze1[row][col] = '_'; // Horizontal path
                }
				else if (col == nextCol)
				 {
                    maze1[row][col] = '|'; // Vertical path
                }
            }
        }
    }
	//for loop until numRows
    for (i = 0; i < numRows; i++)
	{
			//for loop until numcolumns
        for (j = 0; j < numCols; j++)
		 {
            if (maze[i][j] == 1)
			{
                maze1[i][j] = '#'; // Wall
            }
        }
    }
	//for loop to print the character
    for (i = 0; i < numRows; i++)
	{
        for (j = 0; j < numCols; j++)
		{
            printf("%c ", maze1[i][j]);
        }
        printf("\n");
    }

}

void initStack(Stack* stack)
{
	//top element at stack is null
	stack->top = NULL;
}


//
bool isStackEmpty(Stack* stack)
{
	//checking if the stack is null
	if(stack->top==NULL)
    {
        return true;
    }

	else
    {
        return false;
    }
}

void push(Stack* stack, Path p)
{
	//getting the new node
  Path* newNode = (Path*)malloc(sizeof(Path));
  //checking if it is null
    if (newNode == NULL)
    {
        printf("Error: Memory allocation failed\n");
    }
	//pushing the coordinates to stack
    newNode->x = p.x;
    newNode->y = p.y;
    newNode->next = stack->top;
    stack->top = newNode; //changing to of stack
}

Path pop(Stack* stack)
{
	//checking the stack is empty
   if (isStackEmpty(stack))
    {
        printf("Error: Stack underflow\n");
        Path invalid = {-1, -1, NULL};
        return invalid;
    }
	//pop the coordinates to stack
    Path result = *(stack->top);
    Path* temp = stack->top;
    stack->top = stack->top->next;
    //freeing the memory
    free(temp);

    return result;
}

void reverse(Stack* stack)
{
	//declaring stack
	Stack auxiliary_stack;

	auxiliary_stack.top=NULL;
	//while top element in the stack is not null then reversing it
	while(stack->top != NULL)
	{
		Path* current= stack->top;
		stack->top = current->next;

		current->next = auxiliary_stack.top;
		auxiliary_stack.top=current;
	}
	//assigning top element in the stack as auxillary stop
	stack->top = auxiliary_stack.top;
}

bool isValidMove(int maze[MAX_ROWS][MAX_COLS], int x, int y, int numRows, int numCols, bool visited[MAX_ROWS][MAX_COLS])
 {
    // Check if the coordinates are within the bounds of the maze
    if (x >= 0 && x < numRows && y >= 0 && y < numCols)
        {
        // Check if the position is not a wall and has not been visited
        return (maze[x][y] == 0 && !visited[x][y]);
        }
	else
	 {
        // Coordinates are out of bounds, so the move is not valid
        return false;
    }
}
Stack solveMaze(int maze[MAX_ROWS][MAX_COLS], int numRows, int numCols)
{
	//declaring variable and stack as a boolean datatype
	bool new_matrix[MAX_ROWS][MAX_COLS]={false};
	    Stack s1,s2;
	    //checking if the stack is null or not
    initStack(&s1);
    initStack(&s2);
    //declaring the cooedinat to path
	Path start = {0, 0};
	//pushig the stack
    push(&s1, start);
    //while stackisnotempty

    while (!isStackEmpty(&s1))
	{
		//popping the stack on position
      Path currentPosition = pop(&s1);
       int x = currentPosition.x;
        int y = currentPosition.y;
        new_matrix[x][y] = true;
        push(&s2, currentPosition);
	//checking if the maze is solved
        if (x == numRows - 1 && y == numRows - 1)
            {
            printf("Maze solved!\n");
            return s2;
            }
		//check the positions and push into the stack
        if (isValidMove(maze, x - 1, y, numRows, numRows, new_matrix))
         {
            Path next = {x - 1, y, NULL};
            push(&s1, next);
        }
        if (isValidMove(maze, x + 1, y, numRows, numRows, new_matrix))
         {
           Path next = {x + 1, y, NULL};
            push(&s1, next);
         }
        if (isValidMove(maze, x, y - 1, numRows, numRows, new_matrix))
         {

		    Path next = {x, y - 1, NULL};
            push(&s1, next);
        }
        if (isValidMove(maze, x, y + 1, numRows, numRows,new_matrix))
            {
            Path next = {x, y + 1, NULL};
            push(&s1, next);
            }

	//if stack is not empty then pop
        if (isStackEmpty(&s1))
            {
            while (!isStackEmpty(&s2))
            {
                Path currentPos = pop(&s2);
				//push the element to current position
                if (currentPos.x == x || currentPos.y == y)
                {
                    push(&s1, currentPos);
                    break;
                }
            }
        }
    }

    printf("Maze not solvable.\n");

    while (!isStackEmpty(&s2))
        {
        pop(&s2);
        }

    return s2;
}

char getChoiceYN()
{
	//declaring a variable
	char option;
    char lowerChoice;
    while (1)
	{
    	//initializing the choice
        scanf(" %c", &option);
        //making it lower case
        lowerChoice = tolower(option);
	//checking if it has yes or no
        if (lowerChoice == 'y' || lowerChoice == 'n')
            {
                return lowerChoice;
            }
        else
            {
            printf("Invalid option. Please type 'y' to repeat or 'n' to exit:\n");
            }
    }
}

int getChoiceNum()
{
	int option;
    char lowerChoice;
    while (1)
	{
    	//initializing the dimesions by users input
    	printf("What dimension of maze you want to try?\n");
    	printf("[5 | 10 | 20]: ");
        scanf("%d", &option);
	//checking if it has correct input
        if (option == 5 || option == 10 || option == 20 )
		 {
            return option;
        }
		else
		 {
            printf("Invalid option. Please choose one of the valid options (i.e., 5, 10, 20):\n");
        }
    }
}

