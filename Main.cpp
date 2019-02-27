/***************************************************************************************
** Program Filename: Main.cpp
** Author: Parker Howell
** Date: 1-15-2016
** Description: Menus to gather basic info needed to call GameOfLife Class.
**              Then creates GameOfLife object. 
** Input: User selected menu choices.
** Output: Creates a GameOfLife object.
***************************************************************************************/

#include "GameOfLife.hpp"
#include "functions.hpp"
#include <iostream>


/***************************************************************************************
** Function: int main()
** Description: Menu system and creates a GOL object.
** Parameters: none.
** Pre-Conditions: none. 
** Post-Conditions: GameOfLife object created. 
***************************************************************************************/
int main(){
	int pattern,          // which pattern to display, or exit program.
		location,         // where to display the pattern, left, center, or right.
		offset,           // where to start drawing the selected pattern.
		generations;      // how many generations to animate the pattern.


	// main menu
	do {
		std::cout << "Welcome to a limited version of Conway's Game of Life." << std::endl;
		std::cout << "Please select a number to see its pattern, or to exit:" << std::endl;
		std::cout << "1. Oscillator." << std::endl;
		std::cout << "2. Glider." << std::endl;
		std::cout << "3. Glider Gun." << std::endl;
		std::cout << "4. to Exit." << std::endl;
		std::cin >> pattern;

		// validate main menu selection
		while ((pattern < 1) || (pattern > 4)){
			std::cout << "Please choose 1-4." << std::endl;
			std::cin >> pattern;
		}

		// sub menu for offset
		if (pattern != 4){
			std::cout << std::endl << "Please select which side the pattern should start at: " << std::endl;
			std::cout << "1. Left Side." << std::endl;
			std::cout << "2. Center." << std::endl;
			std::cout << "3. Right Side" << std::endl;
			std::cin >> location;

			// validate sub menu selection
			while ((location < 1) || (location > 3)){
				std::cout << "Please choose 1-3." << std::endl;
				std::cin >> location;
			}
		}
		
		// if the user didn't exit.
		if (pattern != 4){

			/* get the starting position offset based on the pattern and location selected.
			*  see functions.cpp  */
			offset = getOffset(pattern, location);


			/* retruns how many generations to run based on the pattern chosen.
			*  see functions.cpp  */
			generations = getGens(pattern);


			// create myGOL instance of GOL Class.
			GameOfLife myGOL(pattern, offset, generations);
		}

	// return to main menu if user did not exit
	} while (pattern != 4);

	return 0;
}