#pragma once
#include <iostream>
#include<fstream>
#include<string>
#include <vector>

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
	bool CheckComplete();
	bool ValidRow(int num, int row);
	bool ValidCol(int num, int col);
	bool ValidSubGrid(int num, int row, int col);
	bool ValidComplete(int num, int row, int col);
private:
	int** Grid;
};