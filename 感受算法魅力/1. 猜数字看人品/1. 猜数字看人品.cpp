#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	int n = 1;
	while (n)
	{
		scanf("%d", &n);
		getchar();
		if (!n)
			break;
		int possible[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
		char s[10] = { 0 };
		while (strcmp(s, "right on"))
		{
			scanf("%[^\n]", s);
			if(!strcmp(s, "right on"))
				break;
			else if(!strcmp(s, "too high"))
				for(int i = n; i <= 10; ++i)
					possible[i] = 0;
			else if(!strcmp(s, "too low"))
				for(int i = 1; i <= n; ++i)
					possible[i] = 0;
			scanf("%d", &n);
			getchar();
		}
		//int sum = 0;
		//for(int i = 1; i <= 10; ++i)
		//	sum += possible[i];
		//if(sum)
		//	printf("Tom may be honest\n");
		//else
		//	printf("Tom is dishonest\n");
		if (possible[n])
			printf("Tom may be honest\n");
		else
			printf("Tom is dishonest\n");
	}
	return 0;
}

/*
* ����1����whileѭ���У�n��ֵһ��ȡ���Ҫ�ж��Ƿ�Ϊ0��Ȼ��break��������������в���Ҫ�ĳ��򣻺����ж�right onͬ��
* ����2��ע��scanf�����ո񣡽����������gets������scanf("%[^\n]", s),���߱�ʾ��ȡ�����з�Ϊֹ��
* ����3������scanf("%[^\n]", s)��ʱ��ע��ǰ������뻺�������ܻ��л��з�������Ҫ��getchar()�ѻ��з�������
* ����4��ԭ�ȵķ�������һ��sum��ͳ��possible������1�ĸ�����Ȼ���ж�sum�Ƿ�Ϊ0������������߼��Ͻ���������ģ�����3��ʱ��"too low"������2��ʱ����"right on"����ʱ������ì�ܵģ�����sum����0������Ӧ��ֱ���ж�possible[n]�Ƿ�Ϊ1��
*/