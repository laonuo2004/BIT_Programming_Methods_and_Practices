#include <iostream>
#define MAXN 1000000
using namespace std;

string queue[MAXN + 1];
int head = 0, tail = 0;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string operation;
		cin >> operation;
		if (operation == "Leave")
		{
			if (head != tail)
				head++;
		}
		else if (operation == "QueueHead")
		{
			if(head == tail)
				cout << "Empty queue" << endl;
			else
				cout << queue[head] << endl;
		}
		else if (operation == "QueueTail")
		{
			if(head == tail)
				cout << "Empty queue" << endl;
			else
				cout << queue[tail - 1] << endl;
		}
		else
		{
			string name;
			cin >> name;
			queue[tail++] = name;
		}
	}
	return 0;
}

/*
* 思路：使用一个数组模拟队列，head指向队头，tail指向队尾的下一个位置。入队时将元素存入tail位置，tail++；出队时将head++。对于查询队头和队尾的操作，先判断head和tail是否相等，如果相等则输出Empty queue，否则输出对应位置的元素。
*/