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
* �������ھ����lattice path����������˼������ɷ��ʵ㣬���⴦��һ�¼��ɡ�
* ����˼·�Ƕ�̬�滮������һ��·����¼����dp[MAXN + 2][MAXN + 2]������MAXN = 20��dp[i][j]��ʾ��(1, 1)��(i, j)��·���������ڵ��ƹ�ϵdp[i][j] = dp[i - 1][j] + dp[i][j - 1]��˫��ѭ���������е�֮�󷵻�dp[endx][endy]��ֵ���ɡ�
* ���ڲ��ɷ��ʵ㣬���⿪��һ��bool����accessible[MAXN + 2][MAXN + 2]����ʼ��Ϊtrue��Ȼ�󽫲��ɷ��ʵ��ֵ��Ϊfalse���������е�ʱ�������ǰ���ǲ��ɷ��ʵ㣬�򲻽��е��ƹ�ϵ�ļ��㡣�ڼ������ڵ��ֵʱ��������Щ���ɷ��ʵ��ʼ��ʼ��dpֵΪ0�����Բ���Խ������Ӱ�졣
* ϸ�ڣ����ڱ߽�����Ĵ�����i = 0 || j = 0ʱ�����ƹ�ϵ�ұ�dp[i - 1][j] + dp[i][j - 1]�����Խ�硣����ڽ������У��ҵĴ���ʽ�Ǹ�dp��accessible����ı߽�࿪��һ��һ�У�dpֵ��ʼ��Ϊ0��֤��Ӱ������ԭ������������+1������(1, 1)��ʼ���������Ա������У�������Ӽ�ࡣ
* ע��1���ʼ����㲻��Ҫ���е���ʽ�ļ��㣬�����ʼ����1���ֱ������ˡ�
* ע��2������long long _ _ _��
*/