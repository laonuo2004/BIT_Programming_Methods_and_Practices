#include <iostream>
#include <algorithm>
#define MAXN 300000
using namespace std;

typedef struct activity
{
	int s, e;
}DATA, * PDATA;

DATA a[MAXN];

//int cmp(const void* a, const void* b)
//{
//	return ((PDATA)a)->e - ((PDATA)b)->e;
//}

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i].s >> a[i].e;
	//qsort(a, n, sizeof(DATA), cmp);
	sort(a, a + n, [](DATA a, DATA b) { return a.e < b.e; });
	int ans = 1, last = a[0].e;
	for(int i = 1; i < n; ++i)
		if (a[i].s >= last)
		{
			++ans;
			last = a[i].e;
		}
	cout << ans << endl;
	return 0;
}

/*
* ˼·������̰���㷨���⣬���Ȱ��ս���ʱ�����򣬲���ѡ����һ�����Ȼ��ӵڶ������ʼ�������ʼʱ����ڵ�����һ����Ľ���ʱ�䣬��ѡ��û������ѡ��
* ���������֤��̰���㷨���Եõ����Ž⣬֤�����£�
* �������Ž�ΪA��̰���㷨�õ��Ľ�ΪB�����A���л����B�У���ôA�б�Ȼ��һ����Ľ���ʱ����B�е�ĳ����Ŀ�ʼʱ��֮ǰ����ô���ǿ��Խ�A�еĻ�滻ΪB�еĻ�������õ��Ľ���Ȼ�����Ž⣬����B�����Ž⡣
*/