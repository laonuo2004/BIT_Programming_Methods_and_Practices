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
* 思路：本题如果除去怪物的影响因素，那便是一道经典的BFS题目。然而本题的难点在于如何处理怪物的影响因素。
* 怪物可以理解为具有二象性的路径，即在k的倍数时刻是可以通行的路，其余时刻是不可以通行的墙。如果再进一步分析，会发现怪物使整张地图具有周期性，周期为k，我们可以通过将时间对k取模的值来反映当前处于一个周期当中的哪个阶段。易知当k = 1时，整张地图只有一种状态，即怪物的影响因素消失，问题退化为一道普通的BFS题目。
* 基于此，我们只需要在原先的BFS算法中添加一个维度，用于反映一个周期当中的各个阶段即可。具体来说，有三个地方需要修改：
* 1. 用于记录是否访问过的数组record需要增加一个维度变为三维数组，即record[MAX + 1][MAX + 1][MAXK]，用于记录当前位置在一个周期中的哪个阶段是否访问过。
* 2. 在判断下一个位置是否可以访问时，需要判断该位置在一个周期中的对应阶段是否访问过，即if (!record[next.x][next.y][next.time % k])。
* 3. 对于怪物所在位置，判断访问该位置时时间是否为k的倍数，如果不是则continue，即if (map[next.x][next.y] == '*' && next.time % k != 0) continue;。
* 核心在于对第二点的理解：相比于普通的BFS题目，本题中，一个周期内不同阶段到达同一位置的含义是不同的，而不同时间但是在一个周期内的同一阶段到达同一位置的含义是相同的。因此我们需要对每个位置在一个周期内的不同阶段是否访问过分别进行记录。
*/