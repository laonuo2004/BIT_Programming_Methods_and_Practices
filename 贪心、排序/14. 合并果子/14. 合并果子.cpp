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
* ˼·������̰���㷨���⣬���Ƚ����й��Ӱ�����������Ȼ��ÿ��ȡ��С�����ѹ��Ӻϲ���Ȼ�󽫺ϲ���Ĺ������²��뵽ԭ����λ�ã������������ѭ����ֱ��ֻʣ��һ�ѹ��ӡ�
*/