#ifndef SUDOKU_IMP
#define SUDOKU_IMP

#include "Sudoku.h"
#include <math.h>
#include <algorithm>

using namespace std;


Sudoku::Sudoku(char sdk[9][9])
{
	for (int i=0; i<9; i++)
	{
		for (int j=0; j<9; j++)
		{
			this->sdk[i][j] = sdk[i][j];

			// Assign the squares to their proper box
			int boxNum = (int)( floor(j/3) + 3*floor(i/3) );
			// Assign the squares to their proper place in the box
			int boxSqr = (int)( j%3 + 3*(i%3) );
			box[boxNum][boxSqr] = sdk[i][j];
		}
	}
}


string Sudoku::toString()
{
	string SUD_TOP = "╔═╤═╤═╦═╤═╤═╦═╤═╤═╗\r\n";
	string SUD_MBX = "╟─┼─┼─╫─┼─┼─╫─┼─┼─╢\r\n";
	string SUD_MBD = "╠═╪═╪═╬═╪═╪═╬═╪═╪═╣\r\n";
	string SUD_BOT = "╚═╧═╧═╩═╧═╧═╩═╧═╧═╝\r\n";

	string sdkStr = "";
        for (int i=0; i<9; i++)
        {
		// Draw lines and borders of the box
		// in between numbers
                if (i == 0)
                        sdkStr += SUD_TOP;
                else
                        if (i%3 == 0)
                                sdkStr += SUD_MBD;
                        else
                                sdkStr += SUD_MBX;
		// end inbetween drawing


		// draw numbers and format them correctly
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

vector<char> Sudoku::getOpt(int n)
{
	// options: numbers missing from the box
	vector<char> opt = {'1','2','3','4','5','6','7','8','9'};

	// iterates through the box and removes existing numbers
	// from the options vector
	for (int i=0; i<9; i++)
	{
		if (box[n][i] != '-')
		{
			opt.erase(remove(opt.begin(), opt.end(), box[n][i]), opt.end());
		}
	}
	return opt;
}

// currently for testing purposes only
string Sudoku::boxOpt()
{
	string str = "";
	for (int i=0; i<9; i++)
	{
		str += "{";
		vector<char> opt = getOpt(i);
		for (auto j = opt.begin(); j != opt.end(); ++j)
		{
			str += *j;
			str += ",";
		}
		str += '\b';
		str += "} ";
		if (i%3 == 2)
			str += '\n';
	}
	return str;
}

#endif
