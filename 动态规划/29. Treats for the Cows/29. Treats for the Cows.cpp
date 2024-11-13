#include <iostream>
#include <algorithm>
#define MAXN 2000
#define ll long long
using namespace std;

ll dp[MAXN + 1][MAXN + 1];

int main()
{
	int value[MAXN + 1], n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> value[i];
		dp[i][i] = value[i] * n;
	}
	for (int day = n - 1; day >= 1; --day)
		for (int i = 1; i <= day; ++i)
			dp[i][n - day + i] = max(dp[i][n - day + i - 1] + value[n - day + i] * day, dp[i + 1][n - day + i] + value[i] * day);
	cout << dp[1][n] << endl;
	return 0;
}

/*
* 思路：动态规划，设dp[MAXN + 1][MAXN + 1]，其中dp[i][j]表示第n - j + i天方案的最大利润。
* 我们从后往前遍历，首先初始化dp[i][i] = value[i] * n，即先确定最后一天各方案的最大利润，然后向前遍历，有转移方程：dp[i][j] = max(dp[i][j - 1] + value[j] * (n - j + i), dp[i + 1][j] + value[i] * (n - j + i))。
* 最后输出dp[1][n]即可。
*/