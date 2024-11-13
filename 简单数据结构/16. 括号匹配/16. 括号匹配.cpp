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
* ˼·�����ÿ���������У���������ƥ���ԭ�����ջ�У�������ڿ���ƥ���������ʱ���������ֱ�ͳ��ջ�������ź������ŵ�������
* �������������Ƿ�Ϊ0�����Է�Ϊ4�������1. left != 0, right != 0; 2. left = 0, right != 0; 3. left != 0, right = 0; 4. left = 0, right = 0. 
* ���ڵ�һ�������ֱ�����������ں������������ר�ſ���һ�����飬��СΪ2 * MAXN + 1������left = 0, right != 0������������MAXN + rightλ��++������left != 0, right = 0������������MAXN - leftλ��++������left = 0, right = 0������������MAXNλ��++��
* ��������൱�����ᣬMAXN��Ϊԭ�㣬���ҷ�Χ���ȷֱ�MAXN�����Ǵ����ұ���������飬ÿ��ȡ�����Գ�λ�õ���Сֵ���ۼӵ�����У�����MAXNλ�õ�ֵ��Ҫ���⴦���������2���ۼӵ�����С�
*/