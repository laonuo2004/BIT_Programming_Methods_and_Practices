#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m;
int table[102][102];

int if_row(int row, int col)
{
	int flag = 1;
	for(int i = 1; i <= m; ++i)
		if(table[row][i] > table[row][col])
		{
			flag = 0;
			break;
		}
	return flag;
}

int if_col(int row, int col)
{
	int flag = 1;
	for (int i = 1; i <= n; ++i)
		if (table[i][col] > table[row][col])
		{
			flag = 0;
			break;
		}
	return flag;
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%d", &table[i][j]);
	int flag = 1;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			if(!if_row(i, j) && !if_col(i, j))
			{
				flag = 0;
				break;
			}
	if(flag)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}

/*
* 思路：对于每一个元素，判断它所在行与所在列是否存在比它大的元素，这其实不是我们所期望的，因为如果行和列均存在比它大的元素，那么这个元素就没法割出来。这时候跳出来输出NO，否则输出YES。
*/