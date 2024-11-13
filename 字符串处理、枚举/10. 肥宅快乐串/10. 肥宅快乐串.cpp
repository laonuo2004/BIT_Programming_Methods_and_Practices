#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

//int main()
//{
//	int t;
//	cin >> t;
//	const string str = "fattyhappy";
//	while (t--)
//	{
//		bool flag = false;
//		string s;
//		cin >> s;
//		if (s.find(str) != string::npos)
//		{
//			cout << s.find(str) + 3 << ' ' << s.find(str) + 4 << endl;
//			continue;
//		}
//		for(int i = s.size() - 1; i >= 0; --i)
//			for (int j = 0; j + i < s.size(); ++j)
//			{
//				string temp = s;
//				swap(temp[j], temp[j + i]);
//				if (temp.find(str) != string::npos)
//				{
//					cout << j + 1 << ' ' << j + i + 1 << endl;
//					flag = true;
//					goto end;
//				}
//			}
//	end:
//		if (!flag)
//			cout << -1 << endl;
//	}
//	return 0;
//}

const string str = "fattyhappy";
string s, temp;
int incorrespondence[10] = { 0 };

int* correspond(int i)
{
	memset(incorrespondence, 0, sizeof(incorrespondence));
	for (int j = 0; j < 10; ++j)
		if (temp[i + j] != str[j])
			incorrespondence[j] = 1;
	return incorrespondence;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		bool flag = false;
		cin >> s;
		for (int i = 0; i < s.size() - 9; ++i)
		{
			temp = s;
			int* incorrespondence = correspond(i);
			int sum = 0, position_1 = -1, position_2 = -1;
			for(int j = 0; j < 10; ++j)
				if (incorrespondence[j])
				{
					++sum;
					if (position_1 == -1)
						position_1 = j;
					else
						position_2 = j;
				}
			switch (sum)
			{
				case 0:
					cout << i + 3 << ' ' << i + 4 << endl;
					flag = true;
					goto end;
				case 1:
					temp.replace(i, 10, "          ");
					if (temp.find(str[position_1]) != string::npos)
					{
						cout << i + position_1 + 1 << ' ' << temp.find(str[position_1]) + 1 << endl;
						flag = true;
						goto end;
					}
					break;
				case 2:
					swap(temp[i + position_1], temp[i + position_2]);
					int* incorrespondence = correspond(i);
					bool flag_2 = true;
					for(int j = 0; j < 10; ++j)
						if(incorrespondence[j])
						{
							flag_2 = false;
							break;
						}
					if (flag_2)
					{
						cout << i + position_1 + 1 << ' ' << i + position_2 + 1 << endl;
						flag = true;
						goto end;
					}
					break;
			}
		}
	end:
		if (!flag)
			cout << -1 << endl;
	}
	return 0;
}

/*
* ˼·��ԭ����˫��ѭ��ʱ�临�Ӷ�ΪO(n^2)����TLE�������Ҫ�Ż�����ϸ������Ŀ������ֻ�����������1. ֱ�Ӿ����ҵ�"fattyhappy"�Ӵ���2. ѡ�����Ӵ���"fattyhappy"���һ���ַ���3. ѡ�����Ӵ���"fattyhappy"��������ַ�����ѡ�����Ӵ���"fattyhappy"��������������ַ�ʱ����Ȼ�޽⡣��ˣ�ֻ��Ҫ�ֱ���������������ɡ�
* ���ڵ�һ�������ֱ��������ɣ����ڵڶ��������˼·���������ַ����ڡ�ѡ�����Ӵ�֮��Ѱ����ѡ�����Ӵ���"fattyhappy"�����Ǹ��ַ��������ҵ�����������ڵ������������ѡ���Ӵ���"fattyhappy"�����������ַ����������������ѡ���Ӵ����Ա��"fattyhappy"���������
* ���һ��������ֻ��Ҫ��ͷ��β����һ���ַ������ɣ�ÿ�ν�ȡ����Ϊ10���Ӵ����ж������ַ�����Ȼ��ֱ���������������ܵ�ʱ�临�Ӷ�ΪO(n)��
* �ջ�1��ѧϰ����goto�����÷������������������ѭ�����ȽϷ��㡣
* �ջ�2��ѧϰ�������ʹ���Զ��庯���������飬�����Ƿ���ָ�������ָ�롣ͬʱҪע������ϸ�ڣ�1. ���������ܶ˲�Ҫ��������飬��Ӧ�����ָ�룬����������ֵĳ�ʼ������2. ���Զ��庯���ڲ�����������ں���������ᱻ�ͷţ�ֱ�ӷ���ָ����������ָ���Ǵ���ģ�������ʱ��ֵ�������롣��������Ǻ����ڶ���static������ߺ����ⶨ��ȫ�����飬ͬʱ�ǵô���memset��ʼ����
* �ջ�3��ѧϰ�������ʹ��replace�����滻�ַ����е�ĳһ�����ݡ�
* �ջ�4��ѧϰ����Visual Studio�ĵ��Լ��ɣ�������Ӷϵ��飬�����Ͳ���һ��һ�����ˡ�
*/