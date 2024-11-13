#include <iostream>
#define MAXN 1000000
#define MAXPATH 300000
using namespace std;

typedef struct node
{
	int data;
	node* next;
}node, * pnode;

node key[MAXN + 1];
bool record[MAXN + 1];
int queue[MAXPATH + 1];
int head = 0, tail = 0;

void insert(int start, int dest)
{
	pnode p = new node;
	p->data = dest;
	p->next = key[start].next;
	key[start].next = p;
}

void bfs(int start, int dest, int sum)
{
	record[start] = true;
	pnode p = key[start].next;
	while (p != NULL)
	{
		queue[tail++] = p->data;
		record[p->data] = true;
		p = p->next;
	}
	int size = tail - head;
	while (head < tail)
	{
		if(queue[head] == dest)
		{
			cout << sum << endl;
			exit(0);
		}
		pnode q = key[queue[head++]].next;
		while (q != NULL)
		{
			if (!record[q->data])
			{
				record[q->data] = true;
				queue[tail++] = q->data;
			}
			q = q->next;
		}
		size--;
		if (!size)
		{
			size = tail - head;
			sum++;
		}
	}
	cout << -1 << endl;
}

int main()
{
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int start, dest, temp;
		cin >> start >> temp >> temp >> dest;
		insert(start, dest);
	}
	int start_begin, start_end, dest_begin, dest_end, temp;
	cin >> start_begin >> temp >> temp >> start_end >> dest_begin >> temp >> temp >> dest_end;
	if (start_begin == dest_begin && start_end == dest_end)
		cout << "1" << endl;
	else if (start_end == dest_begin)
		cout << "2" << endl;
	else
		bfs(start_end, dest_begin, 3);
	return 0;
}

/*
* 思路：核心思想是广度优先搜索，辅助三个结构：一个散列表用于存储图的边，一个队列用于存储广度优先搜索的路径，一个布尔数组用于标记已经访问过的结点。
* 广度优先搜索的过程：
* 1. 从起点开始，将起点的所有邻接点加入队列，记得标记起点已经访问过。
* 2. 从队首取出结点，判断是否为终点，如果是则输出路径长度，程序结束；否则将该结点的所有邻接点依次加入队列。注意已经访问过的结点不要入队，同时每加入一个结点都要记得标记已经访问过。
* 3. 重复步骤2，直到队列为空。程序可以写作while(head < tail)。
* 4. 如何记录路径长度？记录每一层的结点数size = tail - head，从队首取出一个结点就size--，当size为0时，说明当前层的结点已经全部取出，此时路径长度加1，并更新size = tail - head。
* 注意：对于自己就是结束成语的情况与两个成语顶真的情况要特殊处理。
* 
* 因为乐学一直编译不出来，所以我也不敢说我的代码一定是对的，不过我感觉我的思路应该没有问题。
* 首先需要明确的是，层的划分依据并不是相同开头的成语算一层，而是距离最开始节点距离相同的成语算一层。在测试样例1中，最开始的节点是4。
* 例如可以看一下这张图的例子，如果我们要从1找到8，我们初始化队列并初始化head = 0, tail = 0，路劲长度 = 1。然后我们把第一层的10和4入队，head = 0, tail = 2，两者相减就是第一层的结点数，我们记作size = 2。
* 然后我们依次判断10和4是不是终点：10不是，出队，head++，size--，同时入队邻接点3，tail++；4不是，出队，head++，size--，同时入队邻接点7，9，tail++两次。此时size = 0，说明第一层的结点已经全部出队，路径长度加1，同时更新第二层的节点数量size：size = tail - head = 5 - 2 = 3，恰好就是第二层的结点数。
* 每次我们都让size = 0的时候才让路径长度加1，这样能够保证路径长度是一层层增加的。这样不知道你能不能理解。
*/