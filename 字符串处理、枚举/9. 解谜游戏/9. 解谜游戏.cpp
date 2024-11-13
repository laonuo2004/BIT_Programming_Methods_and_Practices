#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <climits>
#include <algorithm>
#define MAXN 18
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int state[MAXN][MAXN] = { 0 };
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			scanf("%1d", &state[i][j]);
	int ans = INT_MAX;
	for (int i = 1; i <= (1 << m); ++i)
	{
		int press[MAXN][MAXN] = { 0 };
		for (int j = 1; j <= m; ++j)
			press[1][j] = (i >> (j - 1)) & 1;
		for (int j = 1; j <= n - 1; ++j)
			for (int k = 1; k <= m; ++k)
				press[j + 1][k] = (state[j][k] + press[j][k] + press[j][k - 1] + press[j][k + 1] + press[j - 1][k]) % 2;
		bool flag = true;
		for(int j = 1; j <= m; ++j)
			if(state[n][j] ^ (press[n][j] + press[n][j - 1] + press[n][j + 1] + press[n - 1][j]) % 2)
			{
				flag = false;
				break;
			}
		if (flag)
		{
			for(int i = 1; i <= n; ++i)
			{
				for(int j = 1; j <= m; ++j)
					cout << press[i][j] << ' ';
				cout << endl;
			}
			cout << endl;
			int sum = 0;
			for (int j = 1; j <= n; ++j)
				for (int k = 1; k <= m; ++k)
					sum += press[j][k];
			ans = min(ans, sum);
		}
	}
	cout << ans << endl;
	return 0;
}

/*
* 思路：每一行的按键情况只与上一行的按键情况有关，因此可以枚举第一行的按键情况，然后根据第一行的按键情况推出后面的按键情况，最后判断最后一行的按键情况是否符合要求。
* 收获1：学习到了两个宏：INT_MAX和INT_MIN，分别表示int类型的最大值和最小值。
* 收获2：学习到了使用位运算的一些技巧：例如表示2的n次方的数可以使用1 << n，表示取出第n位的数可以使用i >> n & 1。后者搭配前者以及++i可以模拟二进制，遍历所有情况。
* 错误1：某些样例存在多解性，因此在找到一个解时不能直接break，而应该继续寻找更优解。（最开始就是因为这个导致样例12WA）
*/