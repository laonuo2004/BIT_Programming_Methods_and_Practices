#include <iostream>
#include <climits>
#define MAXN 100000
using namespace std;

int rope[MAXN], n, k;

int check(int length)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		count += rope[i] / length;
	}
	return count >= k ? 1 : 0;
}

int binary_search(int left, int right)
{
	int mid;
	while (left + 1 < right)
	{
		mid = left + (right - left) / 2;
		if (check(mid))
			left = mid;
		else
			right = mid;
	}
	return check(left) ? left : 0;
}

int main()
{
	int max = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> rope[i];
		if (rope[i] > max)
			max = rope[i];
	}
	cin >> k;
	cout << binary_search(1, max + 1) << endl;
	return 0;
}

/*
* 思路：首先需要留意的是一条长绳子是可以切出好几段短绳子的，单看测试样例可能会误以为一条绳子只能切出一段绳子，便处理成排序问题了，这是错的。
* 核心思路是二分查找，查找范围为[1, max(L_i) + 1)，选取中间值mid = left + (right - left) / 2，遍历绳子数组，计算得到能够切割出的绳子段数，若段数大于等于k，则left = mid，否则right = mid，最后判断left是否满足条件，满足则输出left，否则输出0。
* 二分查找的思路不难，但是细节上需要注意，否则会出错。以下是平时编写二分查找时需要注意的细节：
* 1. mid = left + (right - left) / 2，而不是mid = (left + right) / 2，因为left + right可能会溢出。
* 2. 查找范围的左右区间开闭情况需要提前考虑清楚，开区间一侧初始化时范围需要+1。
* 3. 结束条件需要想清楚，while中是left < right还是left <= right需要斟酌。本题中是while (left + 1 < right)，而不是while (left < right)，因为left = mid会导致死循环。
* 4. 移动left和right时，left = mid还是left = mid + 1，right = mid还是right = mid - 1需要根据具体情况考虑。
* 5. 二分查找的返回值需要根据具体情况考虑，我的是return check(left) ? left : 0。模板常常是return left与return -1。
* 大概就想到这么多。
*/