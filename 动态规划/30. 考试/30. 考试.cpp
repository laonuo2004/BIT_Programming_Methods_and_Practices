#include <iostream>
#define MAXN 30000
#define MAXM 25
#define ll long long
using namespace std;

ll dp[MAXM + 1][MAXN + 1];
int t[MAXM + 1], v[MAXM + 1];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> t[i] >> v[i];
		v[i] *= t[i];
	}
	for(int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
		{
			if (j >= t[i])
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t[i]] + v[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	cout << dp[m][n] << endl;
	return 0;
}

/*
* 思路：经典01背包问题，dp[i][j]表示前i个物品，背包容量为j时的最大价值，对于(i, j)状态，如果背包放不下，则dp[i][j] = dp[i - 1][j]，否则有转移方程dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t[i]] + v[i])。
* 外循环遍历物品，内循环遍历背包容量，最后输出dp[m][n]即可。
* 在本题中，一道题目就是一个物品，物品的体积为t[i]，价值为v[i] * t[i]，背包容量就是时间n。
*/