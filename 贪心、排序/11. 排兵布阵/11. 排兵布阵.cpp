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
* ˼·���ȶ�x�����y����ֱ�����Ȼ���ҵ���λ�����ֱ����x�����y������ƶ����룬�������ܾ��롣
* ���ж���x���ԣ�����ÿ�������겻���غϣ���̰���㷨��Խ�����Ӧ������Խ�����λ�ã����Զ���ÿ���ˣ����ǽ���x�����ȥ�������±�i���������൱���ֶ��������غϣ�������yͬ������λ�����ɡ�
*/