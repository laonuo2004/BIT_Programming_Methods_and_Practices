#include <iostream>
#define MAXN 200000
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int temp;
		int max = 0;
		int stack[MAXN] = { 0 };
		int top = 0;
		bool flag = true;
		for (int i = 0; i < n; ++i)
		{
			cin >> temp;
			max = max > temp ? max : temp;
			if (!top || stack[top - 1] > temp)
				stack[top++] = temp;
			else if (stack[top - 1] == temp)
				--top;
			else
			{
				cout << "NO" << endl;
				flag = false;
				while (++i < n)
					cin >> temp;
			}
		}
		if (flag)
			if(top > 1)
				cout << "NO" << endl;
			else if(top == 0)
				cout << "YES" << endl;
			else if(stack[0] == max)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
	}
	return 0;
}

/*
* ˼·����������һ����������ڣ����ǲ���Ҫ���߶�ת��Ϊ0-1��������ջ�Ĺ������һЩ�޸ģ���Ϊ�����ڵ����ݼ�ջ��ջ�����ջΪ�ջ���ջ��Ԫ�ش��ڵ�ǰԪ�أ���ô���Ǿͽ���ǰԪ��ѹ��ջ�У����ջ��Ԫ�ص��ڵ�ǰԪ�أ���ô���Ǿͽ�ջ��Ԫ�ص��������ջ��Ԫ��С�ڵ�ǰԪ�أ���ô���Ǿ����NO����continue��������һ������������ж��ܷ���ƽ��������ջ��Ԫ�ظ����Ƿ�Ϊ0��1������ǣ���ô�Ϳ�����ƽ������Ͳ��ܡ�
* ע��1�����������һ����������ж��Ƿ����ջ�ģ�ջ��Ԫ��С�ڵ�ǰԪ��ʱ��������Ҫ�ǵð�ʣ�µ�������꣬�����Ӱ����һ�����롣
* ע��2��cin >> temp, ++i;ע��ʹ�õ��Ƕ��ű��ʽ������һ����䣬whileѭ������������ִ�С�
* ע��3��ջ��ʣ��Ԫ��Ϊ1ʱ����һ��������ƽ������2 2 2 2 1, �����Ҫ�ж����ջ��Ԫ���Ƿ�Ϊ���ֵ��
*/