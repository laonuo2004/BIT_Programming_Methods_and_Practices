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
* ˼·������˼���ǹ���������������������ṹ��һ��ɢ�б����ڴ洢ͼ�ıߣ�һ���������ڴ洢�������������·����һ�������������ڱ���Ѿ����ʹ��Ľ�㡣
* ������������Ĺ��̣�
* 1. ����㿪ʼ�������������ڽӵ������У��ǵñ������Ѿ����ʹ���
* 2. �Ӷ���ȡ����㣬�ж��Ƿ�Ϊ�յ㣬����������·�����ȣ�������������򽫸ý��������ڽӵ����μ�����С�ע���Ѿ����ʹ��Ľ�㲻Ҫ��ӣ�ͬʱÿ����һ����㶼Ҫ�ǵñ���Ѿ����ʹ���
* 3. �ظ�����2��ֱ������Ϊ�ա��������д��while(head < tail)��
* 4. ��μ�¼·�����ȣ���¼ÿһ��Ľ����size = tail - head���Ӷ���ȡ��һ������size--����sizeΪ0ʱ��˵����ǰ��Ľ���Ѿ�ȫ��ȡ������ʱ·�����ȼ�1��������size = tail - head��
* ע�⣺�����Լ����ǽ��������������������ﶥ������Ҫ���⴦��
* 
* ��Ϊ��ѧһֱ���벻������������Ҳ����˵�ҵĴ���һ���ǶԵģ������Ҹо��ҵ�˼·Ӧ��û�����⡣
* ������Ҫ��ȷ���ǣ���Ļ������ݲ�������ͬ��ͷ�ĳ�����һ�㣬���Ǿ����ʼ�ڵ������ͬ�ĳ�����һ�㡣�ڲ�������1�У��ʼ�Ľڵ���4��
* ������Կ�һ������ͼ�����ӣ��������Ҫ��1�ҵ�8�����ǳ�ʼ�����в���ʼ��head = 0, tail = 0��·������ = 1��Ȼ�����ǰѵ�һ���10��4��ӣ�head = 0, tail = 2������������ǵ�һ��Ľ���������Ǽ���size = 2��
* Ȼ�����������ж�10��4�ǲ����յ㣺10���ǣ����ӣ�head++��size--��ͬʱ����ڽӵ�3��tail++��4���ǣ����ӣ�head++��size--��ͬʱ����ڽӵ�7��9��tail++���Ρ���ʱsize = 0��˵����һ��Ľ���Ѿ�ȫ�����ӣ�·�����ȼ�1��ͬʱ���µڶ���Ľڵ�����size��size = tail - head = 5 - 2 = 3��ǡ�þ��ǵڶ���Ľ������
* ÿ�����Ƕ���size = 0��ʱ�����·�����ȼ�1�������ܹ���֤·��������һ������ӵġ�������֪�����ܲ�����⡣
*/