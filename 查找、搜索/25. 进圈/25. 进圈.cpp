#include <iostream>
#include <queue>
#include <cstring>
#define MAXN 1000
using namespace std;

typedef struct position
{
	int x, y, step;
}node, * pnode;

const int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

char map[MAXN + 1][MAXN + 1];
bool record[MAXN + 1][MAXN + 1];

int bfs(int n, int m, int k, int startx, int starty, int endx, int endy)
{
	memset(record, false, sizeof(record));
	queue <node> q;
	node temp, next;
	temp.x = startx; temp.y = starty; temp.step = 0;
	q.push(temp);
	record[startx][starty] = true;
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		if (temp.x == endx && temp.y == endy)
			return temp.step;
		for (int i = 0; i < 4; ++i)
		{
			next.step = temp.step + 1;
			for (int j = 1; j <= k; ++j)
			{
				next.x = temp.x + dir[i][0] * j; next.y = temp.y + dir[i][1] * j;
				if (next.x >= 1 && next.x <= n && next.y >= 1 && next.y <= m && map[next.x][next.y] != '#' && !record[next.x][next.y])
				{
					q.push(next);
					record[next.x][next.y] = true;
				}
				else if (next.x < 1 || next.x > n || next.y < 1 || next.y > m || map[next.x][next.y] == '#') // 小细节
					break;
			}
		}
	}
	return -1;
}

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> map[i][j];
	int startx, starty, endx, endy;
	cin >> startx >> starty >> endx >> endy;
	cout << bfs(n, m, k, startx, starty, endx, endy) << endl;
	return 0;
}

/*
* 思路：同样是BFS问题，不过我们可以一次朝一个方向走k步，所以我们在BFS内部多加一个循环，在一步之内将一个方向的多个邻接点入队。代码实现大致这样即可：
* next.step = temp.step + 1;
* for (int j = 1; j <= k; ++j)
*	next.x = temp.x + dir[i][0] * j; next.y = temp.y + dir[i][1] * j;
* 
* 本题一个最坑的地方在于“跨越”：
* 首先，我们在走1到k步的时候，如果中途遇到了障碍物或者边界，就要及时break，否则不合题意。
* 但是如果你的代码写成这样：
* if (next.x >= 1 && next.x <= n && next.y >= 1 && next.y <= m && map[next.x][next.y] != '#' && !record[next.x][next.y])
* {
* 	  入队操作;
* }
* else
*	  break;
* 那就忽略了跨越的情况。某些情况下，虽然record[next.x][next.y]为true，但是我们仍然要继续走下去，因为我们可以跨越这个点。而在这里，break语句会让程序提前结束。因此可以这样写：
* else if (next.x < 1 || next.x > n || next.y < 1 || next.y > m || map[next.x][next.y] == '#')
*     break;
* 可以测试一下这两个样例：

* 样例一：
5 7 5
....###
.##.###
.......
###.##.
###....
1 1 5 7

* 样例二：
7 5 5
...##
.#.##
.#.##
.....
##.#.
##.#.
##...
1 1 7 5

* 看看输出是否都是3，如果存在4那就是忽略了“跨越”的情况。
*/