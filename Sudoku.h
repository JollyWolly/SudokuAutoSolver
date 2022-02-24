#ifndef SUDOKU_H
#define SUDOKU_H

#include <string>
#include <vector>

using namespace std;

class Sudoku
{
private:
	char sdk[9][9];
	char box[9][9];

public:
	Sudoku(char sdk[9][9]);
	void insert(int x, int y);
	

	vector<char> getOpt(int n);
	//char[9] getCol(int index);
	//char[3][3] getBox(int x, int y);

	string toString();
	string boxOpt();
};

#endif
