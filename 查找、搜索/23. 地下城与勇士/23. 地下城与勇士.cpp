#include <iostream>
#include <queue>
#include <cstring>
#define MAX 100
#define MAXK 50
using namespace std;

typedef struct state
{
	int x, y, time;
}node, * pnode;

const int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
char map[MAX + 1][MAX + 1];
bool record[MAX + 1][MAX + 1][MAXK];

int bfs(int n, int m, int k, int startx, int starty, int endx, int endy)
{
	memset(record, false, sizeof(record));
	queue <node> q;
	node temp, next;
	temp.x = startx; temp.y = starty; temp.time = 0;
	q.push(temp);
	record[startx][starty][0] = true;
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		if (temp.x == endx && temp.y == endy)
			return temp.time;
		for (int i = 0; i < 4; ++i)
		{
			next.x = temp.x + dir[i][0]; next.y = temp.y + dir[i][1]; next.time = temp.time + 1;
			if (next.x >= 1 && next.x <= n && next.y >= 1 && next.y <= m && map[next.x][next.y] != '#' && !record[next.x][next.y][next.time % k])
			{
				if(map[next.x][next.y] == '*' && next.time % k != 0)
					continue;
				q.push(next);
				record[next.x][next.y][next.time % k] = true;
			}
		}
	}
	return -1;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, m, k, startx, starty, endx, endy;
		cin >> n >> m >> k;
		for(int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
			{
				cin >> map[i][j];
				if (map[i][j] == 'S')
				{
					startx = i;
					starty = j;
				}
				if (map[i][j] == 'E')
				{
					endx = i;
					endy = j;
				}
			}
		cout << bfs(n, m, k, startx, starty, endx, endy) << endl;
	}
	return 0;
}

/*
* ˼·�����������ȥ�����Ӱ�����أ��Ǳ���һ�������BFS��Ŀ��Ȼ��������ѵ�������δ�������Ӱ�����ء�
* ����������Ϊ���ж����Ե�·��������k�ı���ʱ���ǿ���ͨ�е�·������ʱ���ǲ�����ͨ�е�ǽ������ٽ�һ���������ᷢ�ֹ���ʹ���ŵ�ͼ���������ԣ�����Ϊk�����ǿ���ͨ����ʱ���kȡģ��ֵ����ӳ��ǰ����һ�����ڵ��е��ĸ��׶Ρ���֪��k = 1ʱ�����ŵ�ͼֻ��һ��״̬���������Ӱ��������ʧ�������˻�Ϊһ����ͨ��BFS��Ŀ��
* ���ڴˣ�����ֻ��Ҫ��ԭ�ȵ�BFS�㷨�����һ��ά�ȣ����ڷ�ӳһ�����ڵ��еĸ����׶μ��ɡ�������˵���������ط���Ҫ�޸ģ�
* 1. ���ڼ�¼�Ƿ���ʹ�������record��Ҫ����һ��ά�ȱ�Ϊ��ά���飬��record[MAX + 1][MAX + 1][MAXK]�����ڼ�¼��ǰλ����һ�������е��ĸ��׶��Ƿ���ʹ���
* 2. ���ж���һ��λ���Ƿ���Է���ʱ����Ҫ�жϸ�λ����һ�������еĶ�Ӧ�׶��Ƿ���ʹ�����if (!record[next.x][next.y][next.time % k])��
* 3. ���ڹ�������λ�ã��жϷ��ʸ�λ��ʱʱ���Ƿ�Ϊk�ı��������������continue����if (map[next.x][next.y] == '*' && next.time % k != 0) continue;��
* �������ڶԵڶ������⣺�������ͨ��BFS��Ŀ�������У�һ�������ڲ�ͬ�׶ε���ͬһλ�õĺ����ǲ�ͬ�ģ�����ͬʱ�䵫����һ�������ڵ�ͬһ�׶ε���ͬһλ�õĺ�������ͬ�ġ����������Ҫ��ÿ��λ����һ�������ڵĲ�ͬ�׶��Ƿ���ʹ��ֱ���м�¼��
*/