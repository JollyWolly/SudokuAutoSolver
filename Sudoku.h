#ifndef SUDOKU_H
#define SUDOKU_H

#include <string>
#include <vector>

// remove when done testing
#include <iostream>

#define DEFAULT_OPT_LIST {'1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G'}
#define DEFAULT_SIZE 9

using namespace std;

class Sudoku
{
private:
	int size;
	vector<char> options;

	vector<vector<char> > sdk;
	vector<vector<char> > box;
	vector<vector<vector<char>> > sp; // super posistion

	void updateSuperPosition(int x, int y, char c);

public:
	Sudoku() : Sudoku(9, DEFAULT_OPT_LIST) {};
	Sudoku(int size) : Sudoku(size, DEFAULT_OPT_LIST) {};
	Sudoku(int size, vector<char> options);
	//Sudoku(int size, vector<char> opt, vector<vector<char>> sdk);
	void insert(int x, int y, char c);
	
	//vector<char> getOpt(int n);
	//char[9] getCol(int index);
	//char[3][3] getBox(int x, int y);

	vector<char> getMissingBox(int n);
	vector<char> getMissingRow(int n);
	vector<char> getMissingCol(int n);


	string toString();
	string printSuperPosition();
	string boxOpt();
};

#endif
