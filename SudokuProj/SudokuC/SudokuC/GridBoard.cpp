#include "GridBoard.h"

GridBoard::GridBoard(ifstream& file)
{
	Grid = new int*[9];
	TextToBoard(file);	
}

//Takes the text file and turns the numbers into a Sudoku Board
/*For each line, split line based on the first empty space. convert the individually split strings into ints.
Store the ints in order into Grid*/
void GridBoard::TextToBoard(ifstream& fin)
{
	string delim = " ", tempStr = "";
	size_t pos = 0;
	int num = 0;

	for (int x=0; x<9; x++)
	{
		Grid[x] = new int[9];
	}

	for (int row=0; row<9; row++)
	{
		getline(fin, tempStr);
		for (int col = 0; col<9; col++)
		{
			if (col < 8)
			{
				pos = tempStr.find(delim);
				num = atoi((tempStr.substr(0, pos)).c_str());
				Grid[row][col] = num;
				tempStr.erase(0, pos + delim.length());
			}
			else
			{
				num = atoi(tempStr.c_str());
				Grid[row][col] = num;
			}
		}
		getline(fin, tempStr);
	}
}

//Prints the Grid
void GridBoard::PrintBoard()
{
	for (int row=0; row<9; row++)
	{
		for (int col=0; col<9; col++)
		{
			cout << Grid[row][col] << " ";
		}
		cout << endl;
	}
}

void GridBoard::PlaceNum()
{
}

bool GridBoard::CheckRow()
{
	int numList[9] = { 1,2,3,4,5,6,7,8,9 };
	return false;
}

bool GridBoard::CheckCol()
{
	return false;
}

bool GridBoard::CheckSubGrid()
{
	return false;
}
