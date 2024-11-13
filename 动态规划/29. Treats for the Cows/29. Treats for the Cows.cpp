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
* ˼·����̬�滮����dp[MAXN + 1][MAXN + 1]������dp[i][j]��ʾ��n - j + i�췽�����������
* ���ǴӺ���ǰ���������ȳ�ʼ��dp[i][i] = value[i] * n������ȷ�����һ����������������Ȼ����ǰ��������ת�Ʒ��̣�dp[i][j] = max(dp[i][j - 1] + value[j] * (n - j + i), dp[i + 1][j] + value[i] * (n - j + i))��
* ������dp[1][n]���ɡ�
*/