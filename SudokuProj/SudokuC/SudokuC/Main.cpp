#include <iostream>
#include<fstream>
#include<string>
#include "GridBoard.h"

using namespace std;

int main() {

	ifstream file;
	file.open("samplesudoku1.txt");
	GridBoard* Sudoku = new GridBoard(file);
	Sudoku->PrintBoard();

	system("pause");
	return 0;
}