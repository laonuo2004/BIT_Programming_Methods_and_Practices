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
* ˼·�����Ƚ���ÿ��λ�õĸ߶�ת��Ϊ��Ҫ�ڵ��ĸ߶ȣ�Ȼ������ұ������������ǰλ����Ҫ�ڵ����ĸ߶�С����һ��λ����Ҫ�ڵ����ĸ߶ȣ�����Ҫ�໨���߲�ֵ������������һ��λ�õ�����
* ����1��ע������Ҫ��long long���п��������
*/