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
* ˼·��ͳ������Եĸ������ɡ������������ð��������ģ��Ļ��ᳬʱ���������ǿ��Բ��ù鲢����ķ�����ÿ�κϲ���ʱ��ͳ������Եĸ������ɡ�
* ע��1���鲢�����ʱ�临�Ӷ�ΪO(nlogn)���������ⷨ��ʱ�临�Ӷ�ΪO(n^2)�����Թ鲢������Է�ֹTLE��
* ע��2������midʱ��Ӧ��ʹ��left + (right - left) / 2��������(left + right) / 2����Ϊ���߿��ܻᵼ�������
*/