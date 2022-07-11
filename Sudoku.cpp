#ifndef SUDOKU_IMP
#define SUDOKU_IMP

#include "Sudoku.h"
#include <math.h>
#include <algorithm>

using namespace std;


Sudoku::Sudoku(int size, vector<char> options)
{
	this->size = size;
	this->options = options;

	this->options.resize(size);
	//cout << options.size();

	cout << endl;
	sdk.resize(size, vector<char>(size, '-'));
	box.resize(size, vector<char>(size, '-'));
	sp.resize(size, vector<vector<char>>(size, this->options));

	cout << "Success\n";
	cout << printSuperPosition();
}

void Sudoku::insert(int x, int y, char c)
{
	sdk[x][y] = c;
	updateSuperPosition(x, y, c);


	int t = (int)sqrt(size);

	// Assign the squares to their proper box
	int boxNum = (int)( floor(x/t) + t*floor(y/t) );
	// Assign the squares to their proper place in the box
	int boxSqr = (int)( x%t + t*(y%t) );   

	box[boxNum][boxSqr] = sdk[x][y];
}

void Sudoku::updateSuperPosition(int x, int y, char c)
{
	if (c == '-')
		return;
	
	int sqSize = (int)sqrt(size);
	int x_low  = floor(x/sqSize)*sqSize;
	int x_hi   = x_low + sqSize;
	int y_low  = floor(y/sqSize)*sqSize;
	int y_hi   = y_low + sqSize;
	
	for (int i=0; i<size; i++)
	{
		// rows
		sp[i][y].erase(remove(sp[i][y].begin(), sp[i][y].end(), c), sp[i][y].end());
		// cols
		sp[x][i].erase(remove(sp[x][i].begin(), sp[x][i].end(), c), sp[x][i].end());

		// box
		int xB = x_low + i%sqSize;
		int yB = y_low + floor(i/sqSize);
		sp[xB][yB].erase(remove(sp[xB][yB].begin(), sp[xB][yB].end(), c), sp[xB][yB].end());
	}
	sp[x][y].resize(1);
	sp[x][y][0] = c;
}

string Sudoku::toString()
{
	string SUD_TOP = "╔═╤═╤═╦═╤═╤═╦═╤═╤═╗\r\n";
	string SUD_MBX = "╟─┼─┼─╫─┼─┼─╫─┼─┼─╢\r\n";
	string SUD_MBD = "╠═╪═╪═╬═╪═╪═╬═╪═╪═╣\r\n";
	string SUD_BOT = "╚═╧═╧═╩═╧═╧═╩═╧═╧═╝\r\n";

	string sdkStr = "";
        for (int i=0; i<size; i++)
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
                for (int j = 0; j<size; j++)
                {
						sdkStr += sdk[i][j];
                        //cout << sdk.at(i).at(j);
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

string Sudoku::printSuperPosition()
{
	string TOP = "╔═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗\r\n";
	string MBX = "╟───┼───┼───╫───┼───┼───╫───┼───┼───╢\r\n";
	string MBD = "╠═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\r\n";
	string BOT = "╚═══╧═══╧═══╩═══╧═══╧═══╩═══╧═══╧═══╝\r\n";

	string r = TOP;
	int sqSize = (int)sqrt(size);
	for (int i=0; i<size; i++)
	{
		if (i != 0)
			r += MBX;

		vector<vector<char>> tmp = sp[i];
		for (int b=0; b<sqSize; b++)
		{
			r += "║";
			for (int j=0; j<size; j++)
			{
				if (tmp[j].size() == 1)
				{
					tmp[j].resize(size, '#');
				}
				tmp[j].resize(size, ' ');
				for (int a=0; a<sqSize; a++)
				{
					r += tmp[j][a+b*sqSize];
				}
				r += "│";
			}
			r += "\b║\r\n";
		}
		
	}

	r += BOT;
	return r;
}

// int n : box number
vector<char> Sudoku::getMissingBox(int n)
{
	// options: numbers missing from the box
	vector<char> tmp(options);
	// iterates through the box and removes existing numbers
	// from the options vector
	for (int i=0; i<size; i++)
	{
		if (box[n][i] != '-')
		{
			tmp.erase(remove(tmp.begin(), tmp.end(), box[n][i]), tmp.end());
		}
	}
	return tmp;
}

// currently for testing purposes only
string Sudoku::boxOpt()
{
	string str = "";
	for (int i=0; i<size; i++)
	{
		str += "{";
		vector<char> opt = getMissingBox(i);
		for (auto j = opt.begin(); j != opt.end(); ++j)
		{
			str += *j;
			str += ",";
		}
		str += '\b';
		str += "} ";
		if (i%(int)sqrt(size) == (int)sqrt(size)-1)
			str += '\n';
	}
	return str;
}

#endif
