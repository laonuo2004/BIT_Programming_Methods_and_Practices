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
* ˼·������ÿһ��Ԫ�أ��ж������������������Ƿ���ڱ������Ԫ�أ�����ʵ���������������ģ���Ϊ����к��о����ڱ������Ԫ�أ���ô���Ԫ�ؾ�û�����������ʱ�����������NO���������YES��
*/