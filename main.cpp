/**
 * Noah Harbor
 * Sudoku Auto Solve
 */

#include <iostream>
#include <sstream>
#include <stdlib.h>
#include "Sudoku.h"

using namespace std;

#define SUD_TOP "╔═╤═╤═╦═╤═╤═╦═╤═╤═╗\r\n"
#define SUD_MBX "╟─┼─┼─╫─┼─┼─╫─┼─┼─╢\r\n"
#define SUD_MBD "╠═╪═╪═╬═╪═╪═╬═╪═╪═╣\r\n"
#define SUD_BOT "╚═╧═╧═╩═╧═╧═╩═╧═╧═╝\r\n"


int main()
{
	char sdk[9][9];

	for (int i=0; i<9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> sdk[i][j];
		}
	}

	Sudoku s = Sudoku(sdk);

	cout << s.toString();
	cout << s.boxOpt();
}
