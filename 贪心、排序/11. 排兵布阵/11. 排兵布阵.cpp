#include <iostream>
#include <algorithm>
#include <cmath>
#include <cfloat>
#include <climits>
#include <vector>
#define MAXN 100000
#define ll long long
using namespace std;

int x[MAXN], y[MAXN];

int cmp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	sort(x, x + n); sort(y, y + n);
	int mid = n / 2;
	ll ans = 0;
	for (int i = 0; i < n; ++i)
		ans += abs(y[i] - y[mid]);
	int minus[MAXN] = { 0 };
	for (int i = 0; i < n; ++i)
		minus[i] = x[i] - i;
	qsort(minus, n, sizeof(int), cmp);
	for(int i = 0; i < n; ++i)
		ans += abs(minus[i] - minus[mid]);
	cout << ans << endl;
	return 0;
}

/*
* 思路：先对x坐标和y坐标分别排序，然后找到中位数，分别计算x坐标和y坐标的移动距离，最后输出总距离。
* 其中对于x而言，由于每个人坐标不能重合，由贪心算法，越靠左的应当排在越靠左的位置，所以对于每个人，我们将其x坐标减去排序后的下标i，这样就相当于手动让他们重合，于是与y同样找中位数即可。
*/