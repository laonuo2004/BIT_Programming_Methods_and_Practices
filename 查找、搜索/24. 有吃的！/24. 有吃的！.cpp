#include <iostream>
#include <queue>
#include <cstring>
#include <climits>
#define MAXN 2000
using namespace std;

typedef struct position
{
	int x, y, step;
	//struct position* next;
}node, * pnode;

//pnode loop = NULL;
//
//void insert(int x, int y, int step)
//{
//	pnode temp = new node;
//	temp->x = x;
//	temp->y = y;
//	temp->step = step;
//	temp->next = loop->next;
//	loop->next = temp;
//}

const int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

char map[MAXN + 1][MAXN + 1];
bool record[MAXN + 1][MAXN + 1];

int bfs(int n, int m, int startx, int starty, int endx, int endy)
{
	memset(record, false, sizeof(record)); // 记得初始化record数组!
	queue <node> q;
	node temp, next;
	temp.x = startx; temp.y = starty; temp.step = 0;
	q.push(temp);
	record[startx][starty] = true;
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		if(temp.x == endx && temp.y == endy)
			return temp.step;
		for (int i = 0; i < 4; ++i)
		{
			next.x = temp.x + dir[i][0]; next.y = temp.y + dir[i][1]; next.step = temp.step + 1;
			if (next.x >= 1 && next.x <= n && next.y >= 1 && next.y <= m && map[next.x][next.y] != 'M' && !record[next.x][next.y])
			{
				q.push(next);
				record[next.x][next.y] = true;
			}
		}
	}
	return -1;
}

int bfs_e(int n, int m, int startx, int starty)
{
	memset(record, false, sizeof(record)); // 记得初始化record数组!
	queue <node> q;
	node temp, next;
	temp.x = startx; temp.y = starty; temp.step = 0;
	q.push(temp);
	record[startx][starty] = true;
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		if (map[temp.x][temp.y] == 'E')
			return temp.step;
		for (int i = 0; i < 4; ++i)
		{
			next.x = temp.x + dir[i][0]; next.y = temp.y + dir[i][1]; next.step = temp.step + 1;
			if (next.x >= 1 && next.x <= n && next.y >= 1 && next.y <= m && map[next.x][next.y] != 'M' && !record[next.x][next.y])
			{
				q.push(next);
				record[next.x][next.y] = true;
			}
		}
	}
	return -1;
}

int main()
{
	//loop = new node;
	//loop->next = NULL;
	int n, m, startx, starty, endx, endy;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 'N')
			{
				startx = i;
				starty = j;
			}
			if (map[i][j] == 'C')
			{
				endx = i;
				endy = j;
			}
			//if (map[i][j] == 'E')
			//{
			//	//p->x = i;
			//	//p->y = j;
			//	//p++;
			//	insert(i, j, 0);
			//}
		}
	//if(~bfs(n, m, startx, starty, endx, endy))
	//	cout << bfs(n, m, startx, starty, endx, endy) << endl;
	//else
	//	cout << "Bad Eureka" << endl;
	//delete loop;
	int route_nc = bfs(n, m, startx, starty, endx, endy) == -1 ? INT_MAX : bfs(n, m, startx, starty, endx, endy);
	int route_ne = bfs_e(n, m, startx, starty);
	int route_ec = bfs_e(n, m, endx, endy);
	int route_nec;
	if (route_ne != -1 && route_ec != -1)
		route_nec = route_ne + route_ec;
	else
		route_nec = INT_MAX;
	int route = route_nc < route_nec ? route_nc : route_nec;
	if (route == INT_MAX)
		cout << "Bad Eureka" << endl;
	else
		cout << route << endl;
	return 0;
}

/*
* 思路：本题还是一道BFS题目，但是需要额外考虑传送门的影响，仔细分析会发现其实只要在走到传送门的时候将其他传送门的位置也考虑在邻接点里入队即可，其它操作和普通的BFS是一模一样的。
* 因此，我们可以事先开辟一个结构体数组用来存储传送门的位置，然后在移动到传送门的时候将其他传送门的位置入队即可。注意传送门之间传送不消耗时间。
* 其实如果仔细想一下会发现，只有距离N最近的传送门才会被令狐冲进入，其它传送门都是通过这个传送门传送过去的，不存在其它到达这些传送门的路径，因为均不是最短路径。
* ---------------------------------------------------------------------------9月9日---------------------------------------------------------------------------
* 错误1：原先的思路是将所有传送门位置使用链表存储起来，并在走到传送门的时候将其他传送门的位置入队，但是当地图中出现较多传送门的时候，会导致较大的空间浪费，所以有一个样例总是RE。
* 仔细分析问题，发现虽然传送门很多，但实际上有用只有两个，分别是距离N与距离C最近的两个传送门。因此我更改了思路，可以从N和C出发，分别搜索最近的传送门，并将这两个距离加起来作为借助传送门的距离，并与N不借助传送门到C的距离相比较，看哪个更短。
* 需要注意的是，这两种距离如果其中一者无解，就直接取另一者；若两者均无解，就输出Bad Eureka。
*/