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
* 思路：该题与上一题的区别在于，我们不需要将高度转换为0-1串，并将栈的规则进行一些修改，变为类似于单调递减栈的栈：如果栈为空或者栈顶元素大于当前元素，那么我们就将当前元素压入栈中；如果栈顶元素等于当前元素，那么我们就将栈顶元素弹出；如果栈顶元素小于当前元素，那么我们就输出NO，并continue，考察下一组样例；最后判断能否填平的条件是栈中元素个数是否为0或1，如果是，那么就可以填平，否则就不能。
* 注意1：如果是向我一样边输入边判断是否出入栈的，栈顶元素小于当前元素时输出结果后，要记得把剩下的输入读完，否则会影响下一次输入。
* 注意2：cin >> temp, ++i;注意使用的是逗号表达式，算是一条语句，while循环中两条都会执行。
* 注意3：栈中剩余元素为1时，不一定可以填平，例如2 2 2 2 1, 因此需要判断最后栈顶元素是否为最大值。
*/