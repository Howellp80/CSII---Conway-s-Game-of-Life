/*********************************************************************
** Program Filename: functions.hpp
** Author: Parker Howell
** Date: 1-15-2016
** Description: 2 functions to help the main menu determine values that will 
**              be used to create a GameOfLife Object.
** Input: See below for each function.
** Output: See below for each function.
*********************************************************************/



/*********************************************************************
** Function:   int getOffset(int, int)
** Description: Returns an offset based on user selected pattern and starting location
**              so that the pattern doesn't print off screen.
** Parameters: 1st param = the pattern selected. 
**             2nd param = the location selected.
** Pre-Conditions: Should have the pattern and starting location pre selected.
** Post-Conditions: returns an offset value that will shift the printing starting
**                  location over by that many columns.
*********************************************************************/
int getOffset(int, int);



/*********************************************************************
** Function:   int getGens(int)
** Description: Returns the amount of generations a pattern should run for
**              based on the pattern selected. Simple patterns require less 
**              generations to display the animation... 
** Parameters: the int value cooresponding to which pattern will be ran.
** Pre-Conditions: Should have the pattern pre selected.
** Post-Conditions: returns the number of animation cycles to display.
*********************************************************************/
int getGens(int);

