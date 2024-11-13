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
* ˼·��������Ҫ�������һ���������ǿ����г��ü��ζ����ӵģ����������������ܻ�����Ϊһ������ֻ���г�һ�����ӣ��㴦������������ˣ����Ǵ�ġ�
* ����˼·�Ƕ��ֲ��ң����ҷ�ΧΪ[1, max(L_i) + 1)��ѡȡ�м�ֵmid = left + (right - left) / 2�������������飬����õ��ܹ��и�������Ӷ��������������ڵ���k����left = mid������right = mid������ж�left�Ƿ��������������������left���������0��
* ���ֲ��ҵ�˼·���ѣ�����ϸ������Ҫע�⣬��������������ƽʱ��д���ֲ���ʱ��Ҫע���ϸ�ڣ�
* 1. mid = left + (right - left) / 2��������mid = (left + right) / 2����Ϊleft + right���ܻ������
* 2. ���ҷ�Χ���������俪�������Ҫ��ǰ���������������һ���ʼ��ʱ��Χ��Ҫ+1��
* 3. ����������Ҫ�������while����left < right����left <= right��Ҫ���á���������while (left + 1 < right)��������while (left < right)����Ϊleft = mid�ᵼ����ѭ����
* 4. �ƶ�left��rightʱ��left = mid����left = mid + 1��right = mid����right = mid - 1��Ҫ���ݾ���������ǡ�
* 5. ���ֲ��ҵķ���ֵ��Ҫ���ݾ���������ǣ��ҵ���return check(left) ? left : 0��ģ�峣����return left��return -1��
* ��ž��뵽��ô�ࡣ
*/