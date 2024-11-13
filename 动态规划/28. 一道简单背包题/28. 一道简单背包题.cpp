#include <iostream>
#define MAX 2000
#define MAXS 10000000
using namespace std;

int volume[MAX + 1], dp[2 * MAX + 1];

int main()
{
	int n, v;
	cin >> n >> v;
	for (int i = 1; i <= n; ++i)
	{
		cin >> volume[i];
		volume[i] %= v;
		if(!volume[i])
			volume[i] = v;
	}
	dp[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		for(int j = 2 * v; j >= volume[i]; --j)
			dp[j] += dp[j - volume[i]];
		for (int j = v + 1; j <= 2 * v; ++j)
		{
			dp[j - v]  = (dp[j - v] + dp[j]) % MAXS;
			dp[j] = 0;
		}
	}
	cout << dp[v] << endl;
	return 0;
}

/*
* 思路：动态规划，dp[i][j]表示前i个物品中选出一些物品，使得体积和为j的方案数，由于第i+1行的数据只与第i行的数据有关，所以可以用滚动数组优化空间，即只设dp[j]，外部嵌套循环i遍历所有物品，每次循环更新数组即可，可以优化空间复杂度；
* 仔细分析会发现，每种物品的等效体积为volume[i] % v，即每种物品的体积除以v的余数，如果等效体积为0，则特殊修改为v，我们对所有物体的体积进行等效化处理，可以进一步简化dp数组，即只用设dp[2 * MAXV + 1]，其中MAXV为v的最大值，本题为2000，这样可以优化空间复杂度；
* 开始遍历前，我们先初始化dp[0] = 1，至于原因我也说不清楚，但是在纸上演算了一遍，发现这样初始化是对的，所以就这样了；
* 于是，我们遍历所有物品，对于每一种物品，存在两种情况，一种是不选这种物品，另一种是选这种物品，不选这种物品时，dp[j]不变，选这种物品时，dp[j] += dp[j - volume[i]]，由于本题不涉及到价值，所以理论上能装就装，于是我们从dp数组的末尾dp[2 * v]开始遍历，遍历到dp[volume[i]]结束，每一次均更新数组：dp[j] += dp[j - volume[i]];
* 由于我们只需要保留等效体积v以内的数据，所以每次遍历完一种物品后，我们需要将v以后的数据合并至v前面，然后置零，即for (int j = v + 1; j <= 2 * v; ++j) { dp[j - v] += dp[j]; dp[j] = 0； }
* 最后输出dp[v]即可；
* 注意：需要从数组末尾向前遍历！如果从前向后遍历，会使用到更新之后的dp[j - volume[i]]值，而这是错的。
*/