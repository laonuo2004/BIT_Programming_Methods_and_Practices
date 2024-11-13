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
* 思路：经典贪心算法问题，首先按照结束时间排序，并先选定第一个活动，然后从第二个活动开始，如果开始时间大于等于上一个活动的结束时间，则选择该活动，否则不选择。
* 该问题可以证明贪心算法可以得到最优解，证明如下：
* 假设最优解为A，贪心算法得到的解为B，如果A中有活动不在B中，那么A中必然有一个活动的结束时间在B中的某个活动的开始时间之前，那么我们可以将A中的活动替换为B中的活动，这样得到的解仍然是最优解，所以B是最优解。
*/