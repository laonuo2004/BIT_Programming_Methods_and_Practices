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
* ˼·������01�������⣬dp[i][j]��ʾǰi����Ʒ����������Ϊjʱ������ֵ������(i, j)״̬����������Ų��£���dp[i][j] = dp[i - 1][j]��������ת�Ʒ���dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t[i]] + v[i])��
* ��ѭ��������Ʒ����ѭ����������������������dp[m][n]���ɡ�
* �ڱ����У�һ����Ŀ����һ����Ʒ����Ʒ�����Ϊt[i]����ֵΪv[i] * t[i]��������������ʱ��n��
*/