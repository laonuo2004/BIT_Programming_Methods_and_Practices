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
* 思路：经典的最长公共子序列问题，动态规划解决。开辟一个dp数组dp[MAXN + 1][MAXN + 1]，dp[i][j]表示a[1...i]与b[1...j]的最长公共子序列长度。递推关系是如果a[i] == b[j]，则dp[i][j] = dp[i - 1][j - 1] + 1，否则dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])。
* 细节：关于边界问题的处理，当i = 0 || j = 0时，递推关系右边i-1、j-1数组会越界。相比于进行特判，我的处理方式是给dp数组的边界多开辟一行一列，dp值初始化为0保证不影响结果，原来的所有坐标+1，起点从(1, 1)开始。这样可以避免特判，代码更加简洁。
*/