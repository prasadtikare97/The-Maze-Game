#include "maze_lib.h"
const char* MAZE_FILES[] = {
    "maze5.csv",
    "maze10.csv",
    "maze20.csv"
};


int main()
{
	const int maze[MAX_ROWS][MAX_COLS];
	int option=	getChoiceNum();
	//int mazeIndex= sizeof(MAZE_FILES) / sizeof(MAZE_FILES[0]);
	//int i;
		if(option==5)
		{
			const char* mazefile = MAZE_FILES[0];
			int rows=5,cols=5;
			loadFromFile(maze,mazefile,&rows,&cols);
			printMaze(maze,rows,cols);
			Stack stack =solveMaze(maze,rows,cols);
			//check if user want to search again
			printf("\nDo you want to see the solution [y|n]? ");
		// Read the choice
		//call get choice function
			char Read_choice = getChoiceYN();
			if(Read_choice=='y')
			{
				printMazePath(maze,rows,cols,&stack);
			}
		}
		else if(option==10)
		{
			const char* mazefile = MAZE_FILES[1];
			int rows=10,cols=10;
				loadFromFile(maze,mazefile,&rows,&cols);
			printMaze(maze,rows,cols);
			Stack stack =solveMaze(maze,rows,cols);
			//check if user want to search again
			printf("\nDo you want to see the solution [y|n]? ");
		// Read the choice
		//call get choice function
			char Read_choice = getChoiceYN();
			if(Read_choice=='y')
			{
				printMazePath(maze,rows,cols,&stack);
			}
		}
		else
		{
			const char* mazefile = MAZE_FILES[2];
			int rows=20,cols=20;
			loadFromFile(maze,mazefile,&rows,&cols);
			printMaze(maze,rows,cols);
			Stack stack =solveMaze(maze,rows,cols);
			//check if user want to search again
			printf("\nDo you want to see the solution [y|n]? ");
		// Read the choice
		//call get choice function
			char Read_choice = getChoiceYN();
			if(Read_choice=='y')
			{
				printMazePath(maze,rows,cols,&stack);
			}
		}

		//end message
		printf("\nCome back another time!");
// end the program
printf("\nProgram ended.\n");
	return 0;
}
