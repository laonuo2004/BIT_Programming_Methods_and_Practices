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
* 错误1：在while循环中，n的值一读取完就要判断是否为0，然后break，否则后面会多运行不必要的程序；后面判断right on同理。
* 错误2：注意scanf不读空格！解决方法：用gets或者用scanf("%[^\n]", s),后者表示读取到换行符为止。
* 错误3：在用scanf("%[^\n]", s)的时候，注意前面的输入缓冲区可能还有换行符，所以要用getchar()把换行符读掉。
* 错误4：原先的方法是用一个sum来统计possible数组中1的个数，然后判断sum是否为0，但是这个从逻辑上讲是有问题的，例如3的时候"too low"，但是2的时候又"right on"，这时是自相矛盾的，但是sum不是0。所以应该直接判断possible[n]是否为1。
*/