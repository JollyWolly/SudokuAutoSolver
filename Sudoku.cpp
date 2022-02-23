#ifndef SUDOKU_IMP
#define SUDOKU_IMP

#include "Sudoku.h"

using namespace std;

Sudoku::Sudoku(char sdk[9][9])
{
	this->sdk = sdk;
}

string Sudoku::toString()
{

	string SUD_TOP = "╔═╤═╤═╦═╤═╤═╦═╤═╤═╗\r\n"
	string SUD_MBX = "╟─┼─┼─╫─┼─┼─╫─┼─┼─╢\r\n"
	string SUD_MBD = "╠═╪═╪═╬═╪═╪═╬═╪═╪═╣\r\n"
	string SUD_BOT = "╚═╧═╧═╩═╧═╧═╩═╧═╧═╝\r\n"

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


#endif
