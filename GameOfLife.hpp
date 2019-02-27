/***************************************************************************************
** Program Filename: GameOfLife.hpp
** Author: Parker Howell
** Date: 1-15-2016
** Description: Based on arguments, will print a selected pattern to the 
**              screen and update/animate it based on the rules of Conway's
**              Game of life. 
** Input: See parameters for GameOfLife Class
** Output: A printed 20x40 array where "." is a dead cell and "o" is a 
**         alive cell. The whole array then animates based on the rules.
***************************************************************************************/

#pragma once

#define ROWS 30       // how many rows tall the array/display board is.

#define COLS 50       // how many columns wide the array/display board is.

#define YOFFSETT 8    // lowers the printed pattern so it's not along the 
                      // top edge. makes it purdy :P



class GameOfLife
{
private:
	int	pattern,       // the pattern selected from main menu.
		offset,        // how far to offset printing of the patten.
		gens;          // how many times to print the pattern - animation frames.

	bool array1 [ROWS][COLS],   // array to be printed, and then coppied to array2.
		array2 [ROWS][COLS];    // array to be evaluated, and used to update array1.


public:

	/***********************************************************************************
	** Function: GameOfLife(int, int, int);
	** Description: GameOfLife constructor. 
	** Parameters: 1st int: int value for pattern selected.
	**             1) Oscillator 2) Glider 3) Glider Gun
	**             2nd int: int value for offset based on pattern and location 
	**                      choice.
	**             3rd int: int value for gens based on pattern choice.
	** Pre-Conditions: Should have values for pattern, offset, and gens.
	** Post-Conditions: Creates a GameOfLife object and then prints/animates
	**                  it based on the pattern selected, the offset, the 
	**                  gens, and the basic rules to Conway's Game of Life.
	** Note: system("CLS") works with win/visual studio. use "clear" for *nix...
	***********************************************************************************/
	GameOfLife(int, int, int);


	// simple getters and setters. 

	// sets pattern to argument value. 
	void setPattern(int);
	
	
	// returns pattern value. 
	int getPattern();
	
	
	// sets offset to argument value. 
	void setOffset(int);
	
	
	// returns offset value. 
	int getOffset();
	
	
	// sets gens to argument value. 
	void setGens(int);
	
	
	// returns gens value. 
	int getGens();

	// end getters and setters. 



	/***********************************************************************************
	** Function:   loadPattern(bool[][COLS])
	** Description: Sets values in an array to "true" in order to
	**              create the pattern for this instance.  
	** Parameters: bool[][COLS]    - select the array you wish to update. 
	** Pre-Conditions: Should already have an array filled with "false" values.
	** Post-Conditions: Changes set cells in the array to "true"  to create 
	**                  the selected pattern.
	***********************************************************************************/
	void loadPattern(bool[][COLS]);




	/***********************************************************************************
	** Function:   void printArray(bool[][COLS])
	** Description: prints an the values of a 2d bool array buy ignoring a 
	**              5 cell border around the whole array. So a 30x50 array 
	**              would only print the center 20x40 cells.
	**              true values print out a "o"
	**              false values print out a "."
	**              Console will be cleared before printing and there will be a 
	**              short system pause after printing to facilitate animation.
	** Parameters: bool[][COLS]    - select the array you wish to print.
	** Pre-Conditions: The array you wish to print should already be populated 
	**                 with true and false values to form the desired pattern.
	** Post-Conditions: Clears the console then prints the pattern to the console.
	**                  Followed by a short system pause. 
	** Note: system("CLS") works with win/visual studio. use "clear" for *nix.
	**       Sleep(150) works with win/visual studio. use usleep(80000) for *nix.
	************************************************************************************/
	void printArray(bool[][COLS]);





	/***********************************************************************************
	** Function:   void copyArray(bool[][COLS], bool[][COLS])
	** Description: Takes the values of one array and copies them to another.
	** Parameters: 1st bool[][COLS]  - array to be copied.
	**             2nd bool[][COLS]  - will be copied here.
	** Pre-Conditions: Both arrays should exist, be populated, and have
	**                 the same size.
	** Post-Conditions: The values of the 1st array are copied to the 2nd.
	***********************************************************************************/
	void copyArray(bool[][COLS], bool[][COLS]);






	/***********************************************************************************
	** Function:   void neighbors(bool[][COLS], bool[][COLS])
	** Description: Goes through a bool array cell by cell, except the outer  
	**              top, bottom, left, and right edges, and counts the amount 
	**              of "true" values in the 8 cells surrounding each cell. 
	**              Then judges based on Conway's Game of Life if each cell 
	**              should live or die. The other array is updated with these
	**              alive or dead values in the form of "true" or "false".
	**              "true" = alive     "false" = dead
	** Parameters: 1st bool[][COLS]  - the array to be updated.
	**             2nd bool[][COLS]  - the array to be evaluated. 
	** Pre-Conditions: Both arrays should exist, be populated, and have
	**                 the same size.
	** Post-Conditions: The first array is updated based on the contents of
	**                  the second array.
	***********************************************************************************/
	void neighbors(bool[][COLS], bool[][COLS]);

};

