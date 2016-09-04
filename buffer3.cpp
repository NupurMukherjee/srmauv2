#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <math.h>
using namespace std;


#define MAX 64


class CircularBuffer
{
    private:
	double BufferArr[MAX];

    public:
	int front;
	int rear;
	void add(double);
	double read();
	void show();
};



void CircularBuffer::add(double data)
{
	if (front == -1) 			// first data
	{
		front = 0;
		rear = 0;
	}
	else 					// move rear
	{
		if (rear == MAX-1)
			rear = 0;
		else
			rear = rear + 1;

		if (rear == front) 		// Buffer full...keep latest data...overwrite oldest data
			front = front + 1;
	}
	BufferArr[rear] = data;
	cout << "Add to buffer : "<<data<<endl;
}



double CircularBuffer::read()
{
	double data;
	if (front == -1)
	{
		cout<<"No Data in Buffer\n";
		return -1;
	}
	data = BufferArr[front];
	if (front == MAX-1)
		front = 0;
	else
	if (front == rear)
	{		
		front = -1;
		rear = -1;
	}
	else
		front = front + 1;

	cout << "Read from buffer : "<<data<<endl;
	return data;
}



void CircularBuffer::show()
{
	int frontPos = front, rearPos = rear;
	cout<<"front : "<<front<<"    Rear : "<<rear<<endl;
	if (front == -1)
	{
		cout<<"Buffer is empty\n";
		return;
	}
	cout<<"Buffer State :\n";
	if (frontPos <= rearPos)
	{
		while (frontPos <= rearPos)
		{
			cout<<frontPos<<"("<<BufferArr[frontPos]<<")  ";
			frontPos++;
		}
	}
	else
	{
		while (frontPos <= MAX - 1)
		{
		    cout<<frontPos<<"("<<BufferArr[frontPos]<<")  ";
		    frontPos++;
		}
		frontPos = 0;
		while (frontPos <= rearPos)
		{
		    cout<<frontPos<<"("<<BufferArr[frontPos]<<")  ";
		    frontPos++;
		}
	}
	cout<<endl;
}


int main()
{
    int simtime = 1000;
    double readprobthresh = (double)0.5;
    double readprob;
    int t = 1;
    double item;
    CircularBuffer cq;
    cq.front = -1;
    cq.rear = -1;
    
    while (t<simtime)
    {
	item = (double)rand()/(double)RAND_MAX;
	cq.add(item);
	readprob = (double)rand()/(double)RAND_MAX;
	if (readprob<readprobthresh)
		cq.read();
	else
		cout<<"No Read"<<endl;
	cq.show();
	cout << "---------------   Time : "<<t<<endl;
	t++;
    }
    return 0;
}

