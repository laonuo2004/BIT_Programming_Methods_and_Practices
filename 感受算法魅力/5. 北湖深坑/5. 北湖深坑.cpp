//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#define ll long long
//
//typedef struct depth
//{
//	ll position;
//	ll height;
//	struct depth* next;
//}NODE, * PNODE;
//
//PNODE head = NULL;
//
//void push(ll position, ll height)
//{
//	PNODE newdepth = (PNODE)malloc(sizeof(NODE));
//	newdepth->position = position;
//	newdepth->height = height;
//	newdepth->next = head->next;
//	head->next = newdepth;
//	return;
//}
//
//void pop()
//{
//	PNODE temp = head->next;
//	head->next = temp->next;
//	free(temp);
//	return;
//}
//
//ll position()
//{
//	return head->next->position;
//}
//
//ll height()
//{
//	return head->next->height;
//}
//
//bool empty()
//{
//	return head->next == NULL;
//}
//
//ll lake[100001];
////ll diff[100000];
//
//int main()
//{
//	ll t;
//	scanf("%lld", &t);
//	while(t--)
//	{
//		head = (PNODE)malloc(sizeof(NODE));
//		head->next = NULL;
//		head->position = 0;
//		head->height = 0;
//		ll n;
//		scanf("%lld", &n);
//		for(ll i = 1; i <= n; ++i)
//			scanf("%lld", &lake[i]);
//		push(1, lake[1]);
//		//for(ll i = 1; i < n; ++i)
//		//	diff[i] = lake[i + 1] - lake[i];
//		ll sum = 0;
//		for (ll i = 2; i <= n; ++i)
//		{
//			//if(lake[i] == height())
//			//	continue;
//			if(lake[i] > height())
//			{
//				//if(empty())
//				//	continue;
//				//else
//				//{
//				//	ll temp = diff[i];
//				//	while(temp--)
//				//	{
//				//		if(empty())
//				//			break;
//				//		sum += (i - top());
//				//		pop();
//				//	}
//				//}
//				while (!empty() && lake[i] > height())
//				{
//					ll temp_height = height();
//					pop();
//					if (!empty())
//						sum += (i - position() - 1) * ((height() < lake[i] ? height() : lake[i]) - temp_height);
//				}
//				push(i, lake[i]);
//			}
//			else
//			{
//				//ll temp = diff[i];
//				//while(temp++)
//				//	push(i);
//				push(i, lake[i]);
//			}
//		}
//		while(!empty())
//			pop();
//		printf("%lld\n", sum);
//	}
//	return 0;
//}
//
///*
//* ˼·��ʹ�õ�������ջ�洢�߶ȣ�ÿ�������½��ĵط��ͽ�����ջ�����������ĵط��ͽ�ջ�е�Ԫ�س�ջ�����������������͡�
//* ����1��ע������ļ��㣡���ʱҪȡ�������ߵ���Сֵ�������ǳ�ջǰ�ĸ߶ȣ����ʱ�ǳ�ջ���λ�ã������ǳ�ջǰ��λ�ã�����Ҫ�ǵü�һ��
//* ����2���ڳ�ջʱҪ�ж�ջ�Ƿ�Ϊ�գ�
//* ����3��ע������ȵ�ʱ��ѡ��ֱ����ջ���ߵ���ջ��Ԫ�ز��������ԭ����ֱ�����������������ᵼ����������������[3,2,2,1,3]����Ӧ����4����ֱ�������������5��ԭ��������ʱ����˵�����λ�õĿ�ȡ�
//* ��˼1����ʵ����ֱ��������ģ��ջ������д�������㣬�ڴ����Ҳ���㡣
//* ��˼2��C������θ����鶯̬�����С������ʹ��malloc����Ϊ������ʵ����Ҳ��ָ�룩������Ҫע������ת������ָ�룩���ǵ��ͷ��ڴ棬�Լ���ָ��ָ��NULL��
//*/

//������ʹ��˫ָ��ķ�����һ��ָ����ߣ�һ��ָ���ұߣ�ÿ���ƶ��߶Ƚ�С���Ǹ�ָ�롣

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define ll long long

ll *lake, *left, *right, leftmax, rightmax;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		lake = (ll*)malloc(sizeof(ll) * (n + 1));
		for(int i = 1; i <= n; ++i)
			scanf("%lld", &lake[i]);
		ll sum = 0;
		leftmax = lake[1]; rightmax = lake[n];
		left = lake + 1; right = lake + n;
		while (left <= right)
		{
			if (leftmax < rightmax)
			{
				if (*left < leftmax)
					sum += leftmax - *left++;
				else
					//leftmax = *left++;
					*left++;
				if(*left > leftmax)
					leftmax = *left;
			}
			else if (leftmax > rightmax)
			{
				if (*right < rightmax)
					sum += rightmax - *right--;
				else
					//rightmax = *right--;
					*right--;
				if (*right > rightmax)
					rightmax = *right;
			}
			else
			{
				if (*left < leftmax)
					sum += leftmax - *left++;
				else
					//leftmax = *left++;
					*left++;
				if (*left > leftmax)
					leftmax = *left;
				if (*right < rightmax && left <= right)
					sum += rightmax - *right--;
				else
					//rightmax = *right--;
					*right--;
				if (*right > rightmax)
					rightmax = *right;
			}
		}
		//if (left <= right)
			//if (*left < leftmax)
				//sum += leftmax - *left;
		printf("%lld\n", sum);
		free(lake);
		lake = NULL;
	}
	return 0;
}

/*
* ˼·��ʹ��˫ָ�룬һ��ָ����ߣ�һ��ָ���ұߣ�ÿ���ƶ��߶Ƚ�С���Ǹ�ָ�룬��������ͬʱ�ƶ�����ͬʱ����ˮ����ֱ������ָ��������������͡�
*/