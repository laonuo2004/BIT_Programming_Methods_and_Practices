#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#define MAXN 1000000
using namespace std;

typedef struct building
{
	int color;
	int height;
}NODE, * PNODE;

NODE building[MAXN + 1] = { 0 };
PNODE top = NULL;

void push(PNODE top, int color, int height)
{
	top->color = color; top->height = height;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int turn;
	cin >> turn;
	for (int t = 0; t < turn; ++t)
	{
		memset(building, 0, sizeof(building));
		PNODE top = building;
		int color_temp[MAXN] = { 0 };
		int color_sum = 0;
		int color_record[MAXN + 1] = { 0 };
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
			//cin >> color_temp[i];
			scanf("%d", &color_temp[i]);
		for (int i = 0; i < n; ++i)
		{
			int color = color_temp[i];
			int height;
			cin >> height;
			while (top != building && (top - 1)->height <= height)
			{
				--top;
				--color_record[(top)->color];
				if (!color_record[(top)->color])
					--color_sum;
			}
			push(top, color, height);
			++top;
			if (!color_record[color])
				++color_sum;
			++color_record[color];
			cout << color_sum << (i == n - 1 ? '\n' : ' ');
		}
	}
	return 0;
}

/*
* 思路：使用单调栈来模拟楼房的遮挡情况，保证栈的高度依次递减即可。
* 由于每多考虑一栋楼的时候就要输出一次颜色数量，因此维护一个颜色数量的变量color_sum，以及一个颜色记录数组color_record，以记录总的颜色数与每种颜色的数量。每次入栈时，将color_record颜色对应索引的值+1，出栈则-1。color_sum则根据变化前后0的情况来及时更新。
* 错误1：注意在进行出栈操作时，需要判断栈是否为空！
* 错误2：C++的cin和cout会超时，即便关闭了同步也是，因此直接改写C语言，使用scanf和printf就能过了。
*/