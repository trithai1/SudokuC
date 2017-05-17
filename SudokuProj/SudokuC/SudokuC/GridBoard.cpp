#include "GridBoard.h"
#include <random>
#include <time.h>

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
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			cout << Grid[row][col] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void GridBoard::PlaceNum()
{
	vector<int> numList = { 1,2,3,4,5,6,7,8,9 };
	vector<int>::iterator test = find(numList.begin(), numList.end(), 3);
	int pos = test - numList.begin();
	int row, col;
	//int numList[9] = { 1,2,3,4,5,6,7,8,9 };
	//srand(time(NULL));
	//int randNum = rand() % 9 + 1;
	
	if (CheckComplete())
	{

	}
	else
	{
		bool found = false;
		int r = 0, c = 0;
		while (found == false && r < 9)
		{
			while (found == false && c < 9)
			{
				if (Grid[r][c] != 0)
				{
					row = r;
					col = c;
					found = true;
				}
				c++;
			}
			r++;
		}

		while (!CheckComplete())
		{
			
		}
	}
}

//Checks if all rows don't have repeating numbers
bool GridBoard::CheckRow()
{
	int numList[9] = { 1,2,3,4,5,6,7,8,9 };
	int *test;

	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			test = find(begin(numList), end(numList), Grid[row][col]);
			if (test == end(numList))
			{
				return false;
			}
			else
			{
				*test = -1;
			}
		}

		for (int x = 0; x < 9; x++)
		{
			numList[x] = x+1;
		}
	}
	return true;
}

//Checks if all columns don't have repeating numbers
bool GridBoard::CheckCol()
{
	int numList[9] = { 1,2,3,4,5,6,7,8,9 };
	int *test;

	for (int col = 0; col < 9; col++)
	{
		for (int row = 0; row < 9; row++)
		{
			test = find(begin(numList), end(numList), Grid[row][col]);
			if (test == end(numList))
			{
				return false;
			}
			else
			{
				*test = -1;
			}
		}

		for (int x = 0; x < 9; x++)
		{
			numList[x] = x + 1;
		}
	}
	return true;
}

//Checks if all subgrid don't have repeating numbers
bool GridBoard::CheckSubGrid()
{
	int numList[9] = { 1,2,3,4,5,6,7,8,9 };
	int *test;
	for (int irow = 0; irow < 9; irow += 3)
	{
		for (int icol = 0; icol < 9; icol += 3)
		{
			for (int row = irow; row < irow+3; row++)
			{
				for (int col = icol; col < icol+3; col++)
				{
					test = find(begin(numList), end(numList), Grid[row][col]);
					if (test == end(numList))
					{
						return false;
					}
					else
					{
						*test = -1;
					}
				}
			}

			for (int x = 0; x < 9; x++)
			{
				numList[x] = x + 1;
			}
		}
	}
	return true;
}

//Checks if the sudoku is completed correctly
bool GridBoard::CheckComplete()
{
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			if (Grid[row][col] == 0)
			{
				return false;
			}
		}
	}

	if (!(CheckRow() && CheckCol() && CheckSubGrid()))
	{
		return false;
	}

	return true;
}

//Checks if a given number is valid in a row
bool GridBoard::ValidRow(int num, int row)
{
	int numList[9] = { 1,2,3,4,5,6,7,8,9 };
	int *test = find(begin(numList), end(numList), num);
	*test = -1;

	for (int col = 0; col < 9; col++)
	{
		test = find(begin(numList), end(numList), Grid[row][col]);

		if (test == end(numList) && Grid[row][col] != 0)
		{
			return false;
		}
		else if (Grid[row][col] != 0)
		{
			*test = -1;
		}
	}

	return true;
}

//Checks if a given number is valid in a column
bool GridBoard::ValidCol(int num, int col)
{
	int numList[9] = { 1,2,3,4,5,6,7,8,9 };
	int *test = find(begin(numList), end(numList), num);
	*test = -1;

	for (int row = 0; row < 9; row++)
	{
		test = find(begin(numList), end(numList), Grid[row][col]);

		if (test == end(numList) && Grid[row][col] != 0)
		{
			return false;
		}
		else if(Grid[row][col] != 0)
		{
			*test = -1;
		}
	}

	return true;
}

//Checks if a given number is valid through a subgrid for a location in the grid
bool GridBoard::ValidSubGrid(int num, int row, int col)
{
	int numList[9] = { 1,2,3,4,5,6,7,8,9 };
	int *test = find(begin(numList), end(numList), num);
	*test = -1;
	int irow, icol;

	if (row < 3)
	{
		irow = 0;
	}
	else if (row >= 3 && row < 6)
	{
		irow = 3;
	}
	else if (row >= 6)
	{
		irow = 6;
	}

	if (col < 3)
	{
		icol = 0;
	}
	else if (col >= 3 && col < 6)
	{
		icol = 3;
	}
	else if (col >= 6)
	{
		icol = 6;
	}

	for (int row = irow; row < irow + 3; row++)
	{
		for (int col = icol; col < icol + 3; col++)
		{
			test = find(begin(numList), end(numList), Grid[row][col]);
			if (test == end(numList) && Grid[row][col] != 0)
			{
				return false;
			}
			else if(Grid[row][col] != 0)
			{
				*test = -1;
			}
		}
	}
	return true;
}

//Checks if a given number is valid at a location in the grid
bool GridBoard::ValidComplete(int num, int row, int col)
{
	if (ValidCol(num, col) && ValidRow(num, row) && ValidSubGrid(num, row, col))
	{
		return true;
	}

	return false;
}
