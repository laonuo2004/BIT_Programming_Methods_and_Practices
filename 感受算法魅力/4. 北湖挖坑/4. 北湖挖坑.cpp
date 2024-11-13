#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100002

int lake[MAX];

int main()
{
	int n, h;
	scanf("%d %d", &n, &h);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &lake[i]);
		lake[i] = h - lake[i];
	}
	//lake[n] = lake[n - 1];
	//int day = 0, flag = 1;
	//while (flag)
	//{
	//	flag = 0;
	//	for (int i = 0; i < n; ++i)
	//	{
	//		if (lake[i])
	//		{
	//			flag = 1;
	//			++day;
	//			while (lake[i])
	//				--lake[i++];
	//		}
	//	}
	//}
	long long day = lake[0];
	for (int i = 0; i < n - 1; ++i)
	{
		//while (lake[i] >= lake[i + 1])
		//	if(i < n - 1)
		//		++i;
		//	else
		//		goto p;
		if (lake[i] < lake[i + 1])
			day += lake[i + 1] - lake[i];
	}
	printf("%lld\n", day);
	return 0;
}

/*
* 思路：首先将湖每个位置的高度转化为需要挖掉的高度，然后从左到右遍历湖，如果当前位置需要挖的土的高度小于下一个位置需要挖的土的高度，则需要多花两者差值的天数来挖下一个位置的土。
* 错误1：注意天数要开long long！有可能溢出。
*/