#include <iostream>
#include <cstring>
#define MAXN 20
#define ll long long
using namespace std;

bool accessible[MAXN + 2][MAXN + 2];
ll dp[MAXN + 2][MAXN + 2];

const int defender[9][2] = 
{
	{0, 0},
	{1, 2},
	{1, -2},
	{-1, 2},
	{-1, -2},
	{2, 1},
	{2, -1},
	{-2, 1},
	{-2, -1}
};

ll lattice_path(int endx, int endy)
{
	dp[1][1] = 1;
	for (int i = 1; i <= endx; ++i)
		for (int j = 1; j <= endy; ++j)
			if (accessible[i][j] && i * j != 1)
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
	return dp[endx][endy];
}

int main()
{
	memset(accessible, 1, sizeof(accessible));
	int endx, endy, defenderx, defendery;
	cin >> endx >> endy >> defenderx >> defendery;
	endx++, endy++, defenderx++, defendery++;
	for (int i = 0; i < 9; ++i)
	{
		int x = defenderx + defender[i][0], y = defendery + defender[i][1];
		if(x >= 0 && x <= endx && y >= 0 && y <= endy)
			accessible[x][y] = false;
	}
	cout << lattice_path(endx, endy) << endl;
	return 0;
}

/*
* 概括：在经典的lattice path问题上添加了几个不可访问点，特殊处理一下即可。
* 总体思路是动态规划，开辟一个路径记录数组dp[MAXN + 2][MAXN + 2]，其中MAXN = 20，dp[i][j]表示从(1, 1)到(i, j)的路径数，存在递推关系dp[i][j] = dp[i - 1][j] + dp[i][j - 1]。双层循环遍历所有点之后返回dp[endx][endy]的值即可。
* 关于不可访问点，另外开辟一个bool数组accessible[MAXN + 2][MAXN + 2]，初始化为true，然后将不可访问点的值设为false。遍历所有点时，如果当前点是不可访问点，则不进行递推关系的计算。在计算相邻点的值时，由于这些不可访问点最开始初始化dp值为0，所以不会对结果产生影响。
* 细节：关于边界问题的处理，当i = 0 || j = 0时，递推关系右边dp[i - 1][j] + dp[i][j - 1]数组会越界。相比于进行特判，我的处理方式是给dp与accessible数组的边界多开辟一行一列，dp值初始化为0保证不影响结果，原来的所有坐标+1，起点从(1, 1)开始。这样可以避免特判，代码更加简洁。
* 注意1：最开始的起点不需要进行递推式的计算，否则最开始赋的1就又被覆盖了。
* 注意2：不开long long _ _ _。
*/