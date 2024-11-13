#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, sum = 0;
	cin >> n;
	string database[1000], * top = database;
	while (n--)
	{
		string comment;
		cin >> comment;
		if (comment.size() > 10)
		{
			string* current = database;
			int flag = 1;
			while (current != top)
			{
				if (*current == comment)
				{
					flag = 0;
					break;
				}
				++current;
			}
			if (flag)
			{
				*top++ = comment;
				++sum;
			}
		}
	}
	cout << sum << endl;
	return 0;
}