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


string outSdk(char sdk[9][9])
{
	string sdkStr = "";
	for (int i=0; i<9; i++)
	{
		if (i == 0)
			sdkStr += SUD_TOP;
		else
			if (i%3 == 0)
				sdkStr += SUD_MBD;
			else
				sdkStr += SUD_MBX;

		sdkStr += "║";
		for (int j = 0; j < 9; j++)
		{
			sdkStr += sdk[i][j];
			if ((j + 1) % 3 == 0)
				sdkStr += "║";
			else
				sdkStr += "│";
		}
		sdkStr += "\r\n";
	}
	sdkStr += SUD_BOT;
	return sdkStr;
}


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
}
