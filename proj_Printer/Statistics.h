#pragma once
#include <iostream>
#include <string>
using namespace std;

class QueueStatistic
{
private:
	string* Name;
	int* Pr;
	string* Time;

	int maxQueueLen;
	int queueLen;
public:
	QueueStatistic(int userLen);
	~QueueStatistic();

	bool IsFull();
	void Add(string userStr, int userPr);
	void Print();
};