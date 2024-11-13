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
* ˼·��ʹ��һ������ģ����У�headָ���ͷ��tailָ���β����һ��λ�á����ʱ��Ԫ�ش���tailλ�ã�tail++������ʱ��head++�����ڲ�ѯ��ͷ�Ͷ�β�Ĳ��������ж�head��tail�Ƿ���ȣ������������Empty queue�����������Ӧλ�õ�Ԫ�ء�
*/