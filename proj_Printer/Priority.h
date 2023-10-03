#pragma once
#include <iostream>
#include <string>
#include "Statistics.h"
using namespace std;

class QueuePriority
{
private:
	string* Wait;

	int* Pr;
	int maxQueueLen;
	int queueLen;
public:
	QueuePriority(int userLen);
	~QueuePriority();
	void Printer(QueueStatistic& obj);
	void Add(string str, int userPr);

	int GetCount();
	void Print();

	string Extract();
	void Clear();

	bool IsEmpty();
	bool IsFull();
};