#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1000000
#define bits_per_int 32
#define shift 5
#define mask 0x1F

int begin_with_3[MAX / bits_per_int + 1];
int begin_with_6[MAX / bits_per_int + 1];

typedef struct duplication
{
	int number;
	short count;
}NODE, * PNODE;

NODE database[1500];
PNODE top = database;

void insert(int number)
{
	for (int i = 0; i < top - database; ++i)
	{
		if (database[i].number == number)
		{
			++database[i].count;
			return;
		}
	}
	database[top - database].number = number;
	database[top - database].count = 2;
	++top;
}

int test(int* bitmap, int i)
{
	return bitmap[i >> shift] & (1 << (i & mask));
}

void set(int* bitmap, int i)
{
	if (test(bitmap, i - (i / 1000000) * 1000000))
		insert(i);
	else
		bitmap[i - (i / 1000000) * 1000000 >> shift] |= 1 << (i - (i / 1000000) * 1000000 & mask);
}

int normalize(char number[21])
{
	int i = 0, normalized_number = 0;
	while (number[i] != '\0')
	{
		if(number[i] >= '0' && number[i] <= '9')
			normalized_number = normalized_number * 10 + number[i] - '0';
		else if(number[i] >= 'A' && number[i] <= 'P')
			normalized_number = normalized_number * 10 + (number[i] - 'A') / 3 + 2;
		else if(number[i] >= 'R' && number[i] <= 'Y')
			normalized_number = normalized_number * 10 + (number[i] - 'A' - 1) / 3 + 2;
		++i;
	}
	return normalized_number;
}

int cmp(const void* a, const void* b)
{
	return (*(PNODE)a).number - (*(PNODE)b).number;
}

int main()
{
	printf("Error:\n");
	char number[21];
	bool error_flag = false;
	while (scanf("%s", number) != EOF)
	{
		int normalized_number = normalize(number);
		if (normalized_number >= 3000000 && normalized_number <= 3999999)
			set(begin_with_3, normalized_number);
		else if(normalized_number >= 6000000 && normalized_number <= 6999999)
			set(begin_with_6, normalized_number);
		else
		{
			printf("%s\n", number);
			error_flag = true;
		}
	}
	if (!error_flag)
		printf("Not found.\n");
	printf("\nDuplication:\n");
	bool duplicate_flag = false;
	qsort(database, top - database, sizeof(NODE), cmp);
	for (PNODE p = database; p < top; ++p)
	{
		printf("%d-%04d %d\n", p->number / 10000, p->number % 10000, p->count);
		duplicate_flag = true;
	}
	if (!duplicate_flag)
		printf("Not found.\n");
	return 0;
}

/*
* 思路：将号码规范化，然后判断是否有错误，若有错误则输出错误号码，若无错误则判断是否有重复号码，若有重复号码则计数，最后输出重复号码及其计数。
* 思路补充：采用了位图法，将号码规范化后的前缀为3的号码和前缀为6的号码分别存储在两个位图中，若号码已存在则计数，否则将号码存入位图。
* 思路补充：对于重复的号码，使用结构体存储，若号码已存在则计数加一，否则将号码存入结构体。
* 收获1：位图法可以减少内存的使用，以极少的空间存储大量数据。（不过只能表示状态，不能表示次数）
* 收获2：学习到了C++中new和delete的用法。
* 收获3：学习到了C++中一些函数的使用方法，例如string.c_str()、string.find()、string.push_back()、string.insert()、string.size()、to_string()、stoi()、sort()。对于stoi()函数，可以将字符串转换为整数，而to_string()函数可以将整数转换为字符串。此外，注意sort()与qsort()的区别：前者返回值为True的时候不交换，返回值为False的时候交换，而后者返回值为正的时候交换，返回值为负或0的时候不交换，所以sort()函数中的lambda表达式要反过来。
* 收获4：学习到了C++中的lambda表达式的使用方法，又称匿名函数，可以在sort()函数中自定义排序规则，不用单独定义cmp函数。
* 收获5：发现C++中string类可以直接判断相等，不需要使用strcmp函数。
* 收获6：如何快速mod2^i? x % 2^i = x - (x / 2^i) * 2^i = x - (x >> i) << i = x & (2^i - 1),效率逐渐提高。
* 收获7：对于位图法，三种基本操作：测试、设置、清除。测试：bitmap[i >> shift] & (1 << (i & mask));设置：bitmap[i >> shift] |= 1 << (i & mask);清除：bitmap[i >> shift] &= ~(1 << (i & mask));其中shift = log2(bits_per_XXX)，mask = bits_per_XXX - 1。注意bitmap中i >> shift表示在数组中的第几个元素，1 << (i & mask)表示在该元素中的第几位。
* 收获8：对于stoi()函数，如果字符串中有非数字字符，则读取到非数字字符就停止，返回前面的数字部分，如果字符串第一个字符就是非数字字符，则抛出std::invalid_argument异常。
* 错误1：发现用C++写的时候内存会超限，超了几十KB，不知道是为什么。改用C语言写之后内存就只有300多KB了。
*/