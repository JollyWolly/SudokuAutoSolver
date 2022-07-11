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
	sp[x][y].resize(0);
	//sp[x][y][0] = ' ';
}

string Sudoku::toString()
{
	int sqSize = (int)sqrt(size);

	// SET UP FANCY STRING BOX
	string r = "╔";
	string MBX = "╟";
	string MBD = "╠";
	string BOT = "╚";
	for (int i=0; i<size; i++)
	{
		r += "═";
		MBX += "─";
		MBD += "═";
		BOT += "═";
		if ((i+1)%sqSize == 0)
		{
			r += "╦";
			MBX += "╫";
			MBD += "╬";
			BOT += "╩";
		}
		else
		{	
			r += "╤";
			MBX += "┼";
			MBD += "╪";
			BOT += "╧";
		}
	}
	r += "\b╗\r\n";
	MBX += "\b╢\r\n";
	MBD += "\b╣\r\n";
	BOT += "\b╝\r\n";

    for (int i=0; i<size; i++)
    {
	// Draw lines and borders of the box
	// in between numbers
        if (i != 0)
            if (i%sqSize == 0)
                r += MBD;
            else
                r += MBX;
		// end inbetween drawing


		// draw numbers and format them correctly
                r += "║";
                for (int j = 0; j<size; j++)
                {
						r += sdk[i][j];
                        //cout << sdk.at(i).at(j);
                        if ((j + 1) % sqSize == 0)
                                r += "║";
                        else
                                r += "│";
                }
                r += "\r\n";
        }
        r += BOT;
        return r;
}

string Sudoku::printSuperPosition()
{
	int sqSize = (int)sqrt(size);

	// SET UP FANCY STRING BOX
	string thicLine = "";
	string thinLine = "";
	for (int i=0; i<sqSize; i++)
	{
		thicLine += "═";
		thinLine += "─";
	}

	string r = "╔";
	string MBX = "╟";
	string MBD = "╠";
	string BOT = "╚";
	for (int i=0; i<size; i++)
	{
		r += thicLine;
		MBX += thinLine;
		MBD += thicLine;
		BOT += thicLine;
		if ((i+1)%sqSize == 0)
		{
			r += "╦";
			MBX += "╫";
			MBD += "╬";
			BOT += "╩";
		}
		else
		{	
			r += "╤";
			MBX += "┼";
			MBD += "╪";
			BOT += "╧";
		}
	}
	r += "\b╗\r\n";
	MBX += "\b╢\r\n";
	MBD += "\b╣\r\n";
	BOT += "\b╝\r\n";
	// END FANCY STRING BOX SET UP

	for (int i=0; i<size; i++)
	{
		if (i != 0)
		{	
			if ((i)%sqSize == 0)	
				r += MBD;
			else
				r += MBX;
		}

		vector<vector<char>> tmp = sp[i];
		for (int b=0; b<sqSize; b++)
		{
			r += "║";
			for (int j=0; j<size; j++)
			{
				if (tmp[j].size() == 0)
				{
					tmp[j].resize(size, sdk[i][j]);
				}
				tmp[j].resize(size, ' ');
				for (int a=0; a<sqSize; a++)
				{
					r += tmp[j][a+b*sqSize];
				}
				r += "│";
				if ((j+1)%sqSize == 0)
					r += "\b║";
			}
			r += "\r\n";
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
