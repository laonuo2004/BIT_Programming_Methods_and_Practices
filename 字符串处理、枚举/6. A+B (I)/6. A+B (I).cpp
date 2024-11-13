#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string binary_add(string a, string b)
{
	string result = "";
	int carry = 0;
	for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; --i, --j)
	{
		int sum = carry;
		if (i >= 0)
			sum += a[i] - '0';
		if(j >= 0)
			sum += b[j] - '0';
		result.push_back(sum % 2 + '0');
		carry = sum / 2;
	}
	if (carry)
		result.push_back('1');
	reverse(result.begin(), result.end());
	return result;
}

int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		string a, b;
		cin >> a >> b;
		string result = binary_add(a, b);
		result.insert(result.begin(), ' '); result.insert(result.begin(), ' ');
		string divider(result.size(), '-');
		string a_blank(result.size() - a.size(), ' ');
		string b_blank(result.size() - b.size() - 1, ' ');
		a = a_blank + a; b = b_blank + b;
		//while(a.size() < result.size())
		//	a.insert(a.begin(), ' ');
		//while(b.size() < result.size() - 1)
		//	b.insert(b.begin(), ' ');
		cout << a << endl << '+' << b << endl << divider << endl << result << endl;
	}
	return 0;
}

/*
* ˼·������carry�������ӵ�λ��ʼ��λ��ӣ�ע���λ��
* ������ʹ��C++��string�࣬�����ַ�������ʮ�ַ��㡣
* ����1��reverse������������algorithmͷ�ļ������±������
*/