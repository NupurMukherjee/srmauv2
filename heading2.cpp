#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <math.h>
using namespace std;

#define PI 3.14159265

class HeadingAverager
{
	private:
		int heading[1000];
		int noofheading;

	public :
		void userInput();
		void show();
		void computeAvg();

};


void HeadingAverager::computeAvg()
{
	double sinAngle[1000];
	double cosAngle[1000];
	double sinAngleTotal = 0;
	double cosAngleTotal = 0;
	double sinAngleAvg = 0;
	double cosAngleAvg = 0;
	double avgHeading;

	for (int i=0;i<noofheading;i++)
	{
		sinAngle[i] = sin((double)(PI*heading[i]/180));
		sinAngleTotal = sinAngleTotal + sinAngle[i];
		cosAngle[i] = cos((double)(PI*heading[i]/180));
		cosAngleTotal = cosAngleTotal + cosAngle[i];
		cout << sinAngle[i] << "  " << cosAngle[i] << endl;
	}
	sinAngleAvg = sinAngleTotal/noofheading;
	cosAngleAvg = cosAngleTotal/noofheading;
	avgHeading = 180 * atan(sinAngleAvg/cosAngleAvg)/PI;
	if (cosAngleTotal < 0)
		avgHeading   = avgHeading  + 180;
	if ((cosAngleTotal > 0) && (sinAngleTotal < 0)) 
		avgHeading   = avgHeading  + 360;

	cout << "Avg heading  " << avgHeading  << endl;
}


void HeadingAverager::show()
{
	for (int i=0;i<noofheading;i++)
	{
		cout << (i+1) << ". " << heading[i] << endl;
	}
}

/********
void HeadingAverager::userInput()
{
	noofheading = 0;
	int head = ;
	char inputmore = 'y';

	while (inputmore == 'y')
	{
		cout << "Input Heading (0-360) ";
		cin >> head;
		if ((head>=0) && (head<=360))
		{
			heading[noofheading] = head;
			noofheading = noofheading + 1;
		}
		else
			cout << "Invalid input" << endl;

		cout << "Input more? (y/n)";
		cin >> inputmore;
	}
}
*********/


void HeadingAverager::userInput()
{
	noofheading = 0;
	int head = 0;

	while ((head>=0) && (head<=360))
	{
		cout << "Input Heading (0-360) ";
		cin >> head;
		if ((head>=0) && (head<=360))
		{
			heading[noofheading] = head;
			noofheading = noofheading + 1;
		}
		else
			cout << "Invalid input" << endl;
	}
}





int main()
{
	HeadingAverager	myHeadingAverager;

	myHeadingAverager.userInput();
	myHeadingAverager.show();
	myHeadingAverager.computeAvg();
}


