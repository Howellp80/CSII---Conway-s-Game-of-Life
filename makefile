all:
	g++ Main.cpp GameOfLife.cpp functions.cpp -o gol

clean:
	rm gol
