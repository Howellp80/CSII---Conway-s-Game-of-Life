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

#include "GameOfLife.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>


/***************************************************************************************
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
***************************************************************************************/
GameOfLife::GameOfLife(int p, int o, int g)
{
	setPattern(p);
	setOffset(o);
	setGens(g);

	// initialize all cells in array1 as false. 
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			array1[i][j] = false;

	// loads the pattern selected from the main menu. 
	loadPattern(array1);

	/* prints array1, copies it to array2, updates array1 to the next gen,
	** loops through this for as many generations are defined based on the
	** pattern selected.  */
	for (int i = 0; i < gens; i++){
		printArray(array1);
		copyArray(array1, array2);
		neighbors(array1, array2);
	}

	// returns user to main menu after the pattern has animated. 
	std::cout << std::endl << "Press \"enter \\ return\" to return to the main menu.";
	std::cin.ignore();
	std::cin.get();
	system("clear");

}  // end GameOfLife.



// simple getters and setters. 

// sets pattern to argument value. 
void GameOfLife::setPattern(int p)
{
	pattern = p;
}

// returns pattern value. 
int GameOfLife::getPattern()
{
	return pattern;
}

// sets offset to argument value. 
void GameOfLife::setOffset(int o)
{
	offset = o;
}

// returns offset value. 
int GameOfLife::getOffset()
{
	return offset;
}

// sets gens to argument value. 
void GameOfLife::setGens(int g)
{
	gens = g;
}

// returns gens value. 
int GameOfLife::getGens()
{
	return gens;
}  
// end getters and setters. 



/***************************************************************************************
** Function:   loadPattern(bool[][COLS])
** Description: Sets values in an array to "true" in order to
**              create the pattern for this instance.
** Parameters: bool[][COLS]    - select the array you wish to update.
** Pre-Conditions: Should already have an array filled with "false" values.
** Post-Conditions: Changes set cells in the array to "true"  to create
**                  the selected pattern.
***************************************************************************************/
void GameOfLife::loadPattern(bool array[ROWS][COLS])
{
	if (pattern == 1){
		array[2 + YOFFSETT][2 + offset] = true;
		array[2 + YOFFSETT][3 + offset] = true;
		array[2 + YOFFSETT][4 + offset] = true;
		array[3 + YOFFSETT][1 + offset] = true;
		array[3 + YOFFSETT][2 + offset] = true;
		array[3 + YOFFSETT][3 + offset] = true;
	}

	if (pattern == 2){
		array[1 + YOFFSETT][1 + offset] = true;
		array[2 + YOFFSETT][2 + offset] = true;
		array[2 + YOFFSETT][3 + offset] = true;
		array[3 + YOFFSETT][1 + offset] = true;
		array[3 + YOFFSETT][2 + offset] = true;
	}
	
	if (pattern == 3){
		array[1 + YOFFSETT][24 + offset] = true;
		array[2 + YOFFSETT][22 + offset] = true;
		array[2 + YOFFSETT][24 + offset] = true;
		array[3 + YOFFSETT][12 + offset] = true;
		array[3 + YOFFSETT][13 + offset] = true;
		array[3 + YOFFSETT][20 + offset] = true;
		array[3 + YOFFSETT][21 + offset] = true;
		array[3 + YOFFSETT][34 + offset] = true;
		array[3 + YOFFSETT][35 + offset] = true;
		array[4 + YOFFSETT][11 + offset] = true;
		array[4 + YOFFSETT][15 + offset] = true;
		array[4 + YOFFSETT][20 + offset] = true;
		array[4 + YOFFSETT][21 + offset] = true;
		array[4 + YOFFSETT][34 + offset] = true;
		array[4 + YOFFSETT][35 + offset] = true;
		array[5 + YOFFSETT][0 + offset] = true;
		array[5 + YOFFSETT][1 + offset] = true;
		array[5 + YOFFSETT][10 + offset] = true;
		array[5 + YOFFSETT][16 + offset] = true;
		array[5 + YOFFSETT][20 + offset] = true;
		array[5 + YOFFSETT][21 + offset] = true;
		array[6 + YOFFSETT][0 + offset] = true;
		array[6 + YOFFSETT][1 + offset] = true;
		array[6 + YOFFSETT][10 + offset] = true;
		array[6 + YOFFSETT][14 + offset] = true;
		array[6 + YOFFSETT][16 + offset] = true;
		array[6 + YOFFSETT][17 + offset] = true;
		array[6 + YOFFSETT][22 + offset] = true;
		array[6 + YOFFSETT][24 + offset] = true;
		array[7 + YOFFSETT][10 + offset] = true;
		array[7 + YOFFSETT][16 + offset] = true;
		array[7 + YOFFSETT][24 + offset] = true;
		array[8 + YOFFSETT][11 + offset] = true;
		array[8 + YOFFSETT][15 + offset] = true;
		array[9 + YOFFSETT][12 + offset] = true;
		array[9 + YOFFSETT][13 + offset] = true;
	}   
	
}  // end loadPattern.




/***************************************************************************************
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
***************************************************************************************/
void GameOfLife::printArray(bool array[ROWS][COLS])
{
	system("clear");
	for (int i = 5; i < (ROWS - 5); i++){
		for (int j = 5; j < (COLS - 5); j++){
			if (array[i][j] == true)
				std::cout << "o";
			else
				std::cout << ".";
		}
		std::cout << std::endl;
	}

	usleep(80000);

}  // end printArray.




/***************************************************************************************
** Function:   void copyArray(bool[][COLS], bool[][COLS])
** Description: Takes the values of one array and copies them to another.
** Parameters: 1st bool[][COLS]  - array to be copied.
**             2nd bool[][COLS]  - will be copied here.
** Pre-Conditions: Both arrays should exist, be populated, and have
**                 the same size.
** Post-Conditions: The values of the 1st array are copied to the 2nd.
***************************************************************************************/
void GameOfLife::copyArray(bool array[][COLS], bool copy[][COLS])
{
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			copy[i][j] = array[i][j];

}  // end copyArray




/***************************************************************************************
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
***************************************************************************************/
void GameOfLife::neighbors(bool realArray[][COLS], bool copied[][COLS])
{
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++){
			int alive = 0;

			// top left corner
			if (i == 0 && j == 0){
				if (copied[i][j + 1] == 1)
					alive++;
				if (copied[i + 1][j + 1] == 1)
					alive++;
				if (copied[i + 1][j] == 1)
					alive++;
			}

			// top edge
			if (i == 0 && (j != 0 && j != COLS - 1)){
				if (copied[i][j + 1] == 1)
					alive++;
				if (copied[i + 1][j + 1] == 1)
					alive++;
				if (copied[i + 1][j] == 1)
					alive++;
				if (copied[i + 1][j - 1] == 1)
					alive++;
				if (copied[i][j - 1] == 1)
					alive++;
			}

			// top right corner
			if (i == 0 && j == COLS - 1){
				if (copied[i + 1][j] == 1)
					alive++;
				if (copied[i + 1][j - 1] == 1)
					alive++;
				if (copied[i][j - 1] == 1)
					alive++;
			}

			// right edge
			if ((i != 0 && i != ROWS - 1) && (j == COLS - 1)){
				if (copied[i - 1][j - 1] == 1)
					alive++;
				if (copied[i - 1][j] == 1)
					alive++;
				if (copied[i + 1][j] == 1)
					alive++;
				if (copied[i + 1][j - 1] == 1)
					alive++;
				if (copied[i][j - 1] == 1)
					alive++;
			}

			// bottom right corner
			if (i == ROWS - 1 && j == COLS - 1){
				if (copied[i - 1][j - 1] == 1)
					alive++;
				if (copied[i - 1][j] == 1)
					alive++;
				if (copied[i][j - 1] == 1)
					alive++;
			}

			// bottom edge
			if (i == ROWS - 1 && (j != 0 && j != COLS - 1)){
				if (copied[i - 1][j - 1] == 1)
					alive++;
				if (copied[i - 1][j] == 1)
					alive++;
				if (copied[i - 1][j + 1] == 1)
					alive++;
				if (copied[i][j + 1] == 1)
					alive++;
				if (copied[i][j - 1] == 1)
					alive++;
			}

			// bottom left corner
			if (i == ROWS - 1 && j == 0){
				if (copied[i - 1][j] == 1)
					alive++;
				if (copied[i - 1][j + 1] == 1)
					alive++;
				if (copied[i][j + 1] == 1)
					alive++;
			}

			// left edge
			if ((i != 0 && i != ROWS - 1) && j == 0){
				if (copied[i - 1][j] == 1)
					alive++;
				if (copied[i - 1][j + 1] == 1)
					alive++;
				if (copied[i][j + 1] == 1)
					alive++;
				if (copied[i + 1][j + 1] == 1)
					alive++;
				if (copied[i + 1][j] == 1)
					alive++;
			}

			// center of array
			else{
				if (copied[i - 1][j - 1] == 1)
					alive++;
				if (copied[i - 1][j] == 1)
					alive++;
				if (copied[i - 1][j + 1] == 1)
					alive++;
				if (copied[i][j + 1] == 1)
					alive++;
				if (copied[i + 1][j + 1] == 1)
					alive++;
				if (copied[i + 1][j] == 1)
					alive++;
				if (copied[i + 1][j - 1] == 1)
					alive++;
				if (copied[i][j - 1] == 1)
					alive++;
			}


			if (alive < 2)
				realArray[i][j] = false;
			if (alive == 2)
				realArray[i][j] = copied[i][j];
			if (alive == 3)
				realArray[i][j] = true;
			if (alive > 3)
				realArray[i][j] = false;
		}
}  //  end neighbors.


