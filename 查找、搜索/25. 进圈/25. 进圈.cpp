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
				else if (next.x < 1 || next.x > n || next.y < 1 || next.y > m || map[next.x][next.y] == '#') // Сϸ��
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
* ˼·��ͬ����BFS���⣬�������ǿ���һ�γ�һ��������k��������������BFS�ڲ����һ��ѭ������һ��֮�ڽ�һ������Ķ���ڽӵ���ӡ�����ʵ�ִ����������ɣ�
* next.step = temp.step + 1;
* for (int j = 1; j <= k; ++j)
*	next.x = temp.x + dir[i][0] * j; next.y = temp.y + dir[i][1] * j;
* 
* ����һ����ӵĵط����ڡ���Խ����
* ���ȣ���������1��k����ʱ�������;�������ϰ�����߽߱磬��Ҫ��ʱbreak�����򲻺����⡣
* ���������Ĵ���д��������
* if (next.x >= 1 && next.x <= n && next.y >= 1 && next.y <= m && map[next.x][next.y] != '#' && !record[next.x][next.y])
* {
* 	  ��Ӳ���;
* }
* else
*	  break;
* �Ǿͺ����˿�Խ�������ĳЩ����£���Ȼrecord[next.x][next.y]Ϊtrue������������ȻҪ��������ȥ����Ϊ���ǿ��Կ�Խ����㡣�������break�����ó�����ǰ��������˿�������д��
* else if (next.x < 1 || next.x > n || next.y < 1 || next.y > m || map[next.x][next.y] == '#')
*     break;
* ���Բ���һ��������������

* ����һ��
5 7 5
....###
.##.###
.......
###.##.
###....
1 1 5 7

* ��������
7 5 5
...##
.#.##
.#.##
.....
##.#.
##.#.
##...
1 1 7 5

* ��������Ƿ���3���������4�Ǿ��Ǻ����ˡ���Խ���������
*/