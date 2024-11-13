#include <iostream>
#define MAXN 300000
#define ll long long
using namespace std;

int brick[MAXN], temp[MAXN];

//int main()
//{
//	int n;
//	cin >> n;
//	for(int i = 0; i < n; ++i)
//		cin >> brick[i];
//	ll ans = 0;
//	for(int i = 0; i < n - 1; ++i)
//		for(int j = i + 1; j < n; ++j)
//			if (brick[i] > brick[j])
//				++ans;
//	cout << ans << endl;
//	return 0;
//}

ll conquer(int left, int right, int mid)
{
	int i = left, j = mid + 1;
	ll ans = 0;
	for (int k = left; k <= right; ++k)
	{
		if (j > right || (i <= mid && brick[i] <= brick[j]))
			temp[k] = brick[i++];
		else
		{
			temp[k] = brick[j++];
			ans += mid - i + 1;
		}
	}
	for(int k = left; k <= right; ++k)
		brick[k] = temp[k];
	return ans;
}

ll devide(int left, int right)
{
	if (left >= right)
		return 0;
	int mid = left + (right - left) / 2;
	ll ans = devide(left, mid) + devide(mid + 1, right) + conquer(left, right, mid);
	return ans;
}

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> brick[i];
	ll ans = devide(0, n - 1);
	cout << ans << endl;
}

/*
* 思路：统计逆序对的个数即可。但是如果采用冒泡排序法来模拟的话会超时。所以我们可以采用归并排序的方法，每次合并的时候统计逆序对的个数即可。
* 注意1：归并排序的时间复杂度为O(nlogn)，而暴力解法的时间复杂度为O(n^2)，所以归并排序可以防止TLE。
* 注意2：计算mid时，应当使用left + (right - left) / 2，而不是(left + right) / 2，因为后者可能会导致溢出。
*/