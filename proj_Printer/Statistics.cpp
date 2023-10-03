#include "Statistics.h"
#include <iostream>
#include <string>
#include "windows.h"
using namespace std;

QueueStatistic::QueueStatistic(int userLen)
{
	maxQueueLen = userLen;
	Name = new string[maxQueueLen];

	Pr = new int[maxQueueLen];
	Time = new string[maxQueueLen];

	queueLen = 0;
}
QueueStatistic::~QueueStatistic()
{
	delete[] Name;
	delete[] Pr;
	delete[] Time;
}

void QueueStatistic::Add(string userStr, int userPri)
{
	if (!IsFull())
	{
		struct tm newtime;
		time_t now = time(0);
		localtime_s(&newtime, &now);

		char buff[9];
		strftime(buff, 9, "%H:%M:%S", &newtime);
		Time[queueLen] = buff;

		Name[queueLen] = userStr;
		Pr[queueLen] = userPri;
		queueLen++;

		Sleep(1000);
	}
}
void QueueStatistic::Print()
{
	cout << "\tStatistics:" << endl;
	for (int i = 0; i < queueLen; i++)
	{
		cout << "Client: " << Name[i] << "\tPriority: " << Pr[i] << " - " << Time[i] << endl;
	}
}

bool QueueStatistic::IsFull()
{
	return queueLen == maxQueueLen;
}