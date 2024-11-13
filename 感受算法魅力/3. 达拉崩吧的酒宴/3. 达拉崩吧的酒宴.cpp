#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ll long long

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i)
	{
		ll n;
		scanf("%lld", &n);
		if(n == 1)
		{
			printf("0\n");
			continue;
		}
		//n = i;
		ll ans = 1, temp = 2;
		while (n > temp)
		{
			ans++;
			temp = temp << 1;
		}
		//printf("%d桶酒需要%lld只小白鼠\n\n", i, ans);
		printf("%lld\n", ans);
	}
	return 0;
}

/*
* 思路：常规的二进制编码问题。
* 错误1：注意1需要特判！
*/