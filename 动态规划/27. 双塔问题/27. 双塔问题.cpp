#include <iostream>
#include <algorithm>
#define MAXN 100
using namespace std;

int main()
{
	int n1, n2, t = 0;
	while (cin >> n1 >> n2, ++t, n1 || n2)
	{
		int a[MAXN + 1] = { 0 }, b[MAXN + 1] = { 0 }, dp[MAXN + 1][MAXN + 1] = { 0 };
		for (int i = 1; i <= n1; ++i)
			cin >> a[i];
		for (int i = 1; i <= n2; ++i)
			cin >> b[i];
		for (int i = 1; i <= n1; ++i)
			for (int j = 1; j <= n2; ++j)
				if (a[i] == b[j])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		cout << "Twin Towers #" << t << endl;
		cout << "Number of Tiles : " << dp[n1][n2] << endl;
	}
	return 0;
}

/*
* ˼·���������������������⣬��̬�滮���������һ��dp����dp[MAXN + 1][MAXN + 1]��dp[i][j]��ʾa[1...i]��b[1...j]������������г��ȡ����ƹ�ϵ�����a[i] == b[j]����dp[i][j] = dp[i - 1][j - 1] + 1������dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])��
* ϸ�ڣ����ڱ߽�����Ĵ�����i = 0 || j = 0ʱ�����ƹ�ϵ�ұ�i-1��j-1�����Խ�硣����ڽ������У��ҵĴ���ʽ�Ǹ�dp����ı߽�࿪��һ��һ�У�dpֵ��ʼ��Ϊ0��֤��Ӱ������ԭ������������+1������(1, 1)��ʼ���������Ա������У�������Ӽ�ࡣ
*/