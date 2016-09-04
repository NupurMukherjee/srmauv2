#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <math.h>
using namespace std;

class SudokuGame
{
	private:
		int sudoku[9][9];
		int tester[9];

	public :
		int horizontalLinesAreValid();
		int verticalLinesAreValid();
		int squaresAreValid();
		int smallsquaresAreValid(int, int);
		void initTester();
		void randomInitialize();
		void show();
		void squareinit();
		void smallsquaresinit(int, int);
};




void SudokuGame::randomInitialize()
{
	squareinit();

	for (int row=0;row<9;row++)
		for (int col=0;col<9;col++);
			//sudoku[row][col] = floor(1 + rand() % 9);
			//sudoku[row][col] = col+1;
			//sudoku[row][col] = row+1;

}


void SudokuGame::squareinit()
{
	for (int startrow=0;startrow<9;startrow = startrow+3)	
		for (int startcol=0;startcol<9;startcol = startcol+3)	
			smallsquaresinit(startrow, startcol);
}

void  SudokuGame::smallsquaresinit(int startrow, int startcol)
{
	int digit = 1;
	for (int row=startrow;row<(startrow+3);row++)	
		for (int col=startcol;col<(startcol+3);col++)
		{
			sudoku[row][col] = digit;
			digit++;
		}

}

void SudokuGame::show()
{
	for (int row=0;row<9;row++)
	{
		for (int col=0;col<9;col++)
			cout << sudoku[row][col] << "  ";

		cout << endl;
	}		
}


void SudokuGame::initTester()
{
	for (int i=0;i<9;i++)
	{
		tester[i] = 0;
	}
}


int SudokuGame::horizontalLinesAreValid()
{
	int flag = 1;
	int digit;

	for (int row=0;row<9;row++)
	{
		initTester();
		for (int col=0;col<9;col++)
		{
			digit = sudoku[row][col];
			if (tester[digit-1] == 0)
				tester[digit-1] = 1;
			else
			{
				flag = 0;
				break;
			}
		}
		if (flag == 0)
			break;
	}
	return flag;
}

int SudokuGame::verticalLinesAreValid()
{
	int flag = 1;
	int digit;

	for (int col=0;col<9;col++)
	{
		initTester();
		for (int row=0;row<9;row++)
		{
			digit = sudoku[row][col];
			if (tester[digit-1] == 0)
				tester[digit-1] = 1;
			else
			{
				//printf("%d %d %d\n",col,row,digit);
				flag = 0;
				break;
			}
		}
		if (flag == 0)
			break;
	}
	return flag;
}


int SudokuGame::squaresAreValid()
{
	int flag = 1;

	for (int startrow=0;startrow<9;startrow = startrow+3)	
	{
		for (int startcol=0;startcol<9;startcol = startcol+3)	
		{
			flag = smallsquaresAreValid(startrow, startcol);
			if (flag == 0)
				break;
		}
		if (flag == 0)
			break;
	}
	return flag;
}

int SudokuGame::smallsquaresAreValid(int startrow, int startcol)
{

	int flag = 1;
	int digit;

	initTester();
	for (int row=startrow;row<(startrow+3);row++)	
	{
		for (int col=startcol;col<(startcol+3);col++)
		{
			digit = sudoku[row][col];
			if (tester[digit-1] == 0)
				tester[digit-1] = 1;
			else
			{
				flag = 0;
				break;
			}
		}
		if (flag == 0)
			break;
	}
	return flag;
}

int main()
{
	SudokuGame mySudoku;
	mySudoku.randomInitialize();
	mySudoku.show();
	int Horizontalline = mySudoku.horizontalLinesAreValid();
	int Verticalline = mySudoku.verticalLinesAreValid();
	int ThreeSquares = mySudoku.squaresAreValid();
	cout << "Horizontal line : " << Horizontalline<<endl;
	cout << "Vertcal line : " << Verticalline << endl;
	cout << "3 squares : " << ThreeSquares << endl;
	if ((Horizontalline == 1) && (Verticalline == 1) && (ThreeSquares == 1))
		cout << "Solution is correct" << endl;
	else
		cout << "Solution is not correct" << endl;
}


