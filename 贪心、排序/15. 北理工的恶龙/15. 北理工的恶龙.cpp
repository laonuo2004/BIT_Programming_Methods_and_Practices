#include <iostream>
#include <algorithm>
#define MAXN 200000
#define ll long long
using namespace std;

typedef struct dragon
{
	int x, y;
}DATA, * PDATA;

DATA positive[MAXN], negative[MAXN];
PDATA top_p = positive, top_n = negative;

int main()
{
	int n;
	cin >> n;
	int x, y;
	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y;
		if(y < 0)
		{
			top_n->x = x;
			top_n->y = y;
			++top_n;
		}
		else
		{
			top_p->x = x;
			top_p->y = y;
			++top_p;
		}
	}
	sort(positive, top_p, [](DATA a, DATA b) { return a.x < b.x; });
	sort(negative, top_n, [](DATA a, DATA b) { return a.x + a.y > b.x + b.y; });
	ll attack = 0, money = 0;
	for (PDATA i = positive; i < top_p; ++i)
	{
		if(attack < i->x)
		{
			money += i->x - attack;
			attack = i->x;
		}
		attack += i->y;
	}
	for (PDATA i = negative; i < top_n; ++i)
	{
		if(attack < i->x)
		{
			money += i->x - attack;
			attack = i->x;
		}
		attack += i->y;
	}
	cout << money << endl;
	return 0;
}

/*
* 思路：首先将恶龙依据经验值分为正负两类，对于正类恶龙，我们按照难度从小到大排序，对于负类恶龙，我们按照难度与经验值之和从大到小排序。接着我们从正类恶龙开始打，然后再依次打负类恶龙即可。
*/