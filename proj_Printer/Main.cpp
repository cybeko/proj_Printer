#include "Priority.h"
#include "Statistics.h"

int main()
{
	const int SIZE = 3;
	QueuePriority priority(SIZE);
	QueueStatistic stats(SIZE);

	for (int i = 0; i < SIZE; i++)
	{
		string userName;
		int userPri;

		cout << "Enter name for client #" << i + 1 <<": ";
		cin >> userName;
		cout << "Enter priority for client #" << i + 1 << ": ";
		cin >> userPri;

		priority.Add(userName, userPri);
	}

	for (int i = 0; i < SIZE; i++)
	{
		priority.Printer(stats);
	}

	priority.Print();
	stats.Print();
}