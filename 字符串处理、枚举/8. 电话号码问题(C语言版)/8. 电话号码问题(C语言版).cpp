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
* ˼·��������淶����Ȼ���ж��Ƿ��д������д��������������룬���޴������ж��Ƿ����ظ����룬�����ظ�������������������ظ����뼰�������
* ˼·���䣺������λͼ����������淶�����ǰ׺Ϊ3�ĺ����ǰ׺Ϊ6�ĺ���ֱ�洢������λͼ�У��������Ѵ�������������򽫺������λͼ��
* ˼·���䣺�����ظ��ĺ��룬ʹ�ýṹ��洢���������Ѵ����������һ�����򽫺������ṹ�塣
* �ջ�1��λͼ�����Լ����ڴ��ʹ�ã��Լ��ٵĿռ�洢�������ݡ�������ֻ�ܱ�ʾ״̬�����ܱ�ʾ������
* �ջ�2��ѧϰ����C++��new��delete���÷���
* �ջ�3��ѧϰ����C++��һЩ������ʹ�÷���������string.c_str()��string.find()��string.push_back()��string.insert()��string.size()��to_string()��stoi()��sort()������stoi()���������Խ��ַ���ת��Ϊ��������to_string()�������Խ�����ת��Ϊ�ַ��������⣬ע��sort()��qsort()������ǰ�߷���ֵΪTrue��ʱ�򲻽���������ֵΪFalse��ʱ�򽻻��������߷���ֵΪ����ʱ�򽻻�������ֵΪ����0��ʱ�򲻽���������sort()�����е�lambda���ʽҪ��������
* �ջ�4��ѧϰ����C++�е�lambda���ʽ��ʹ�÷������ֳ�����������������sort()�������Զ���������򣬲��õ�������cmp������
* �ջ�5������C++��string�����ֱ���ж���ȣ�����Ҫʹ��strcmp������
* �ջ�6����ο���mod2^i? x % 2^i = x - (x / 2^i) * 2^i = x - (x >> i) << i = x & (2^i - 1),Ч������ߡ�
* �ջ�7������λͼ�������ֻ������������ԡ����á���������ԣ�bitmap[i >> shift] & (1 << (i & mask));���ã�bitmap[i >> shift] |= 1 << (i & mask);�����bitmap[i >> shift] &= ~(1 << (i & mask));����shift = log2(bits_per_XXX)��mask = bits_per_XXX - 1��ע��bitmap��i >> shift��ʾ�������еĵڼ���Ԫ�أ�1 << (i & mask)��ʾ�ڸ�Ԫ���еĵڼ�λ��
* �ջ�8������stoi()����������ַ������з������ַ������ȡ���������ַ���ֹͣ������ǰ������ֲ��֣�����ַ�����һ���ַ����Ƿ������ַ������׳�std::invalid_argument�쳣��
* ����1��������C++д��ʱ���ڴ�ᳬ�ޣ����˼�ʮKB����֪����Ϊʲô������C����д֮���ڴ��ֻ��300��KB�ˡ�
*/