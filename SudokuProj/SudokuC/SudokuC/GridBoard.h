#pragma once
#include <iostream>
#include<fstream>
#include<string>

using namespace std;

class GridBoard
{
public:
	GridBoard(ifstream& fin);
	void TextToBoard(ifstream& fin);
	void PrintBoard();
	void PlaceNum();
	bool CheckRow();
	bool CheckCol();
	bool CheckSubGrid();
private:
	int** Grid;
};