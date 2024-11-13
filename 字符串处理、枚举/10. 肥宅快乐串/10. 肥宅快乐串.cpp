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
* 思路：原本的双层循环时间复杂度为O(n^2)，会TLE，因此需要优化。仔细分析题目，发现只有三种情况：1. 直接就能找到"fattyhappy"子串；2. 选定的子串与"fattyhappy"相差一个字符；3. 选定的子串与"fattyhappy"相差两个字符。当选定的子串与"fattyhappy"相差三个及以上字符时，必然无解。因此，只需要分别处理这三种情况即可。
* 对于第一种情况，直接输出即可；对于第二种情况，思路是在整个字符串内、选定的子串之外寻找所选定的子串与"fattyhappy"相差的那个字符，若能找到就输出；对于第三种情况，将选定子串与"fattyhappy"相差的那两个字符交换，如果交换后选定子串可以变成"fattyhappy"，就输出。
* 如此一来，我们只需要从头到尾遍历一次字符串即可，每次截取长度为10的子串，判断相差的字符数，然后分别处理这三种情况。总的时间复杂度为O(n)。
* 收获1：学习到了goto语句的用法，可以用于跳出多层循环，比较方便。
* 收获2：学习到了如何使用自定义函数返回数组，方法是返回指向数组的指针。同时要注意两个细节：1. 主函数接受端不要定义成数组，而应定义成指针，否则会出现奇怪的初始化错误；2. 在自定义函数内部定义的数组在函数结束后会被释放，直接返回指向这个数组的指针是错误的，回来的时候值会变成乱码。解决方法是函数内定义static数组或者函数外定义全局数组，同时记得搭配memset初始化。
* 收获3：学习到了如何使用replace函数替换字符串中的某一段内容。
* 收获4：学习到了Visual Studio的调试技巧，可以添加断点组，这样就不用一个一个点了。
*/