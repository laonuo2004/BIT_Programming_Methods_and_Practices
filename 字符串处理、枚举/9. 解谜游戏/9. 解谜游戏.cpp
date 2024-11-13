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
* ˼·��ÿһ�еİ������ֻ����һ�еİ�������йأ���˿���ö�ٵ�һ�еİ��������Ȼ����ݵ�һ�еİ�������Ƴ�����İ������������ж����һ�еİ�������Ƿ����Ҫ��
* �ջ�1��ѧϰ���������꣺INT_MAX��INT_MIN���ֱ��ʾint���͵����ֵ����Сֵ��
* �ջ�2��ѧϰ����ʹ��λ�����һЩ���ɣ������ʾ2��n�η���������ʹ��1 << n����ʾȡ����nλ��������ʹ��i >> n & 1�����ߴ���ǰ���Լ�++i����ģ������ƣ��������������
* ����1��ĳЩ�������ڶ���ԣ�������ҵ�һ����ʱ����ֱ��break����Ӧ�ü���Ѱ�Ҹ��Ž⡣���ʼ������Ϊ�����������12WA��
*/