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
	memset(record, false, sizeof(record)); // �ǵó�ʼ��record����!
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
	memset(record, false, sizeof(record)); // �ǵó�ʼ��record����!
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
* ˼·�����⻹��һ��BFS��Ŀ��������Ҫ���⿼�Ǵ����ŵ�Ӱ�죬��ϸ�����ᷢ����ʵֻҪ���ߵ������ŵ�ʱ�����������ŵ�λ��Ҳ�������ڽӵ�����Ӽ��ɣ�������������ͨ��BFS��һģһ���ġ�
* ��ˣ����ǿ������ȿ���һ���ṹ�����������洢�����ŵ�λ�ã�Ȼ�����ƶ��������ŵ�ʱ�����������ŵ�λ����Ӽ��ɡ�ע�⴫����֮�䴫�Ͳ�����ʱ�䡣
* ��ʵ�����ϸ��һ�»ᷢ�֣�ֻ�о���N����Ĵ����ŲŻᱻ�������룬���������Ŷ���ͨ����������Ŵ��͹�ȥ�ģ�����������������Щ�����ŵ�·������Ϊ���������·����
* ---------------------------------------------------------------------------9��9��---------------------------------------------------------------------------
* ����1��ԭ�ȵ�˼·�ǽ����д�����λ��ʹ������洢�����������ߵ������ŵ�ʱ�����������ŵ�λ����ӣ����ǵ���ͼ�г��ֽ϶ഫ���ŵ�ʱ�򣬻ᵼ�½ϴ�Ŀռ��˷ѣ�������һ����������RE��
* ��ϸ�������⣬������Ȼ�����źܶ࣬��ʵ��������ֻ���������ֱ��Ǿ���N�����C��������������š�����Ҹ�����˼·�����Դ�N��C�������ֱ���������Ĵ����ţ����������������������Ϊ���������ŵľ��룬����N�����������ŵ�C�ľ�����Ƚϣ����ĸ����̡�
* ��Ҫע����ǣ������־����������һ���޽⣬��ֱ��ȡ��һ�ߣ������߾��޽⣬�����Bad Eureka��
*/