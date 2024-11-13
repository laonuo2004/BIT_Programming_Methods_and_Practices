#include <iostream>
#include <algorithm>
#define MAXN 10000
#define ll long long
using namespace std;

int fruit[MAXN];

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> fruit[i];
	sort(fruit, fruit + n);
	ll ans = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		fruit[i + 1] += fruit[i];
		ans += fruit[i + 1];
		for(int j = i + 1; j < n - 1; ++j)
			if(fruit[j + 1] < fruit[j])
				swap(fruit[j + 1], fruit[j]);
			else
				break;
	}
	cout << ans << endl;
	return 0;
}

/*
* 思路：经典贪心算法问题，首先将所有果子按照数量排序，然后每次取最小的两堆果子合并，然后将合并后的果子重新插入到原来的位置，进行排序。如此循环，直到只剩下一堆果子。
*/