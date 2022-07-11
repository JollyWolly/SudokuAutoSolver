/**
 * Noah Harbor
 * Sudoku Auto Solve
 */

#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <memory>       // smart pointers
#include <algorithm>    // builtin iterator functions for_each

#include "Sudoku.h"

using namespace std;


int main()
{
	const int sz = 4;
	Sudoku sPtr = Sudoku(4);

	for (int i=0; i<sz; i++)
	{
		for (int j = 0; j<sz; j++)
		{
			char c;
			cin >> c;
			sPtr.insert(i, j, c);
			cout << sPtr.printSuperPosition();
		}
	}
	//vector<vector<char>> asdf(9, vector<char>(9, 'A'));
	//cout << asdf[0][2];

	cout << sPtr.toString();
	cout << sPtr.printSuperPosition();

}
