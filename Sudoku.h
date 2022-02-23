#ifndef SUDOKU_H
#define SUDOKU_H

#include <string>
using std::string;

class Sudoku
{
private:
	char sdk[9][9];
	bool isRowValid(int row);
	bool isColValid(int col);
	bool isBoxValid(int box);

public:
	Sudoku(char sdk[9][9]);
	void insert(int x, int y);
	//char[9] getRow(int index);
	//char[9] getCol(int index);
	//char[3][3] getBox(int x, int y);

	string toString();
};

#endif
