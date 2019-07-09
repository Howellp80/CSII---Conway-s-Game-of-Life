Conway’s Game of Life is a standard example of a cellular automaton. Given an array or matrix of cells, each 
turn or generation the value of each cell may change based upon its neighbors state. For more background: 
http://en.wikipedia.org/wiki/Conway's_Game_of_Life.

Usage:
> make all
> gol

The rules are: Each cell has eight neighbor cells. The neighbors are the cells directly above, below, to the
right, to the left, diagonally above to the right and left, and diagonally below to the right and left.
1. If an occupied cell has zero or one neighbor, it dies of loneliness.
2. If an occupied cell has more than three neighbors, it dies of overcrowding.
3. If an empty cell has exactly three occupied neighbor cells, there is a birth of a new cell
to replace the empty cell.
4. Births and deaths are instantaneous and occur at the changes of generation.
