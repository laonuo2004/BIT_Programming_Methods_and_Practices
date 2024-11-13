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
//* 思路：使用单调链表栈存储高度，每次遇到下降的地方就将其入栈，遇到上升的地方就将栈中的元素出栈并计算面积。按行求和。
//* 错误1：注意面积的计算！算高时要取左右两边的最小值，减数是出栈前的高度；算宽时是出栈后的位置，而不是出栈前的位置！此外要记得减一。
//* 错误2：在出栈时要判断栈是否为空！
//* 错误3：注意在相等的时候选择直接入栈或者弹出栈顶元素并算面积。原先是直接跳过，但是这样会导致面积计算错误，例如[3,2,2,1,3]，本应该是4，但直接跳过算出来是5，原因是算宽的时候多了第三个位置的宽度。
//* 反思1：其实可以直接用数组模拟栈，这样写起来方便，内存管理也方便。
//* 反思2：C语言如何给数组动态分配大小？可以使用malloc（因为数组名实质上也是指针），不过要注意类型转换（成指针），记得释放内存，以及让指针指向NULL。
//*/

//还可以使用双指针的方法，一个指向左边，一个指向右边，每次移动高度较小的那个指针。

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
* 思路：使用双指针，一个指向左边，一个指向右边，每次移动高度较小的那个指针，如果相等则同时移动，并同时结算水量，直到两个指针相遇。按列求和。
*/