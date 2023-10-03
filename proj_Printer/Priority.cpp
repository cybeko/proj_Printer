#include "Priority.h"
#include "Statistics.h"
#include <iostream>
#include <string>
using namespace std;

QueuePriority::QueuePriority(int userLen)
{
	maxQueueLen = userLen;
	Wait = new string[maxQueueLen];
	Pr = new int[maxQueueLen];
	queueLen = 0;
}
QueuePriority::~QueuePriority()
{
	delete[] Wait;
	delete[] Pr;
}

void QueuePriority::Add(string userStr, int userPr)
{
	if (!IsFull())
	{
		Wait[queueLen] = userStr;
		Pr[queueLen] = userPr;
		queueLen++;
	}
}
void QueuePriority::Print()
{
	for (int i = 0; i < queueLen; i++)
	{
		cout << Wait[i] << " - " << Pr[i] << endl;
	}
}
void QueuePriority::Printer(QueueStatistic& obj)
{
	if (!IsEmpty())
	{
		int max_pri = Pr[0];
		int pos_max_pri = 0;

		for (int i = 1; i < queueLen; i++)
		{
			if (max_pri < Pr[i])
			{
				max_pri = Pr[i];
				pos_max_pri = i;
			}
		}

		obj.Add(Wait[pos_max_pri], Pr[pos_max_pri]);

		string temp1 = Wait[pos_max_pri];
		int temp2 = Pr[pos_max_pri];

		for (int i = pos_max_pri; i < queueLen - 1; i++)
		{
			Wait[i] = Wait[i + 1];
			Pr[i] = Pr[i + 1];
		}
		queueLen--;
	}
}

string QueuePriority::Extract()
{
	int max_pri = Pr[0];
	int pos_max_pri = 0;

	for (int i = 1; i < queueLen; i++)
	{
		if (max_pri < Pr[i])
		{
			max_pri = Pr[i];
			pos_max_pri = i;
		}
	}

	string temp1 = Wait[pos_max_pri];
	int temp2 = Pr[pos_max_pri];

	for (int i = pos_max_pri; i < queueLen - 1; i++)
	{
		Wait[i] = Wait[i + 1];
		Pr[i] = Pr[i + 1];
	}

	queueLen--;
	return temp1;
}
void QueuePriority::Clear()
{
	queueLen = 0;
}

bool QueuePriority::IsEmpty()
{
	return queueLen == 0;
}
bool QueuePriority::IsFull()
{
	return queueLen == maxQueueLen;
}

int QueuePriority::GetCount()
{
	return queueLen;
}