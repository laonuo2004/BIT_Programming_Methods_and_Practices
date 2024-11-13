#include <iostream>
#define MAXN 100000
using namespace std;

int a[2 * MAXN + 1];
char temp[MAXN + 1];
char* top = temp;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		char temp[MAXN + 1] = { 0 };
		char* top = temp;
		string s;
		cin >> s;
		int left = 0, right = 0;
		for (int j = 0; j < s.size(); ++j)
		{
			if(top != temp && s[j] == ')' && *(top - 1) == '(')
				--top;
			else
				*top++ = s[j];
			//for(int k = 0; k < top - temp; ++k)
			//	cout << temp[k];
			//cout << endl;
		}
		for (int j = 0; j < top - temp; ++j)
			if (temp[j] == '(')
				++left;
			else
				++right;
		//for(int k = 0; k < top - temp; ++k)
		//	cout << temp[k];
		//cout << endl;
		if (left)
		{
			if (!right)
				++a[MAXN - left];
		}
		else
			++a[MAXN + right];
	}
	int ans = 0;
	for (int i = 0; i < MAXN; ++i)
		ans += min(a[i], a[2 * MAXN - i]);
	ans += a[MAXN] / 2;
	cout << ans << endl;
	return 0;
}

/*
* 思路：针对每个括号序列，按照括号匹配的原则存入栈中，如果存在可以匹配的括号则及时弹出，最后分别统计栈中左括号和右括号的数量。
* 按照左右括号是否为0，可以分为4种情况：1. left != 0, right != 0; 2. left = 0, right != 0; 3. left != 0, right = 0; 4. left = 0, right = 0. 
* 对于第一种情况，直接舍弃；对于后面三种情况，专门开辟一个数组，大小为2 * MAXN + 1。对于left = 0, right != 0的情况，数组的MAXN + right位置++；对于left != 0, right = 0的情况，数组的MAXN - left位置++；对于left = 0, right = 0的情况，数组的MAXN位置++。
* 这个数组相当于数轴，MAXN处为原点，左右范围长度分别MAXN。我们从左到右遍历这个数组，每次取两个对称位置的最小值，累加到结果中，对于MAXN位置的值需要特殊处理，将其除以2后累加到结果中。
*/