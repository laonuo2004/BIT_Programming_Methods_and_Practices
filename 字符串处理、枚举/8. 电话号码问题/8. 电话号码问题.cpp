#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
//#include <unordered_map>
//#include <vector>
//#include <map>
using namespace std;

#define MAX 1000000
#define bits_per_int 32
#define shift 5
#define mask 0x1F

int begin_with_3[MAX / bits_per_int + 1];
int begin_with_6[MAX / bits_per_int + 1];

//unordered_map<string, int> phone_map;

//map<string, int> phone_map;

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

//typedef struct duplication
//{
//	char number[9];
//	short count;
//	struct duplication* next;
//}NODE, * PNODE;
//
//PNODE head = new NODE;
//
//void insert(PNODE head, string number)
//{
//	PNODE current = head;
//	while(current->next != NULL && strcmp(current->next->number, number.c_str()) < 0)
//		current = current->next;
//	if (current->next != NULL && strcmp(current->next->number, number.c_str()) == 0)
//	{
//		++current->next->count;
//		return;
//	}
//	else
//	{
//		PNODE temp = new NODE;
//		for(int i = 0; i < number.size(); ++i)
//			temp->number[i] = number[i];
//		temp->number[number.size()] = '\0';
//		temp->count = 2;
//		temp->next = current->next;
//		current->next = temp;
//		return;
//	}
//}

int charToDigit(char c)
{
	//if (c == 'A' || c == 'B' || c == 'C')
	//	return 2;
	//else if (c == 'D' || c == 'E' || c == 'F')
	//	return 3;
	//else if (c == 'G' || c == 'H' || c == 'I')
	//	return 4;
	//else if (c == 'J' || c == 'K' || c == 'L')
	//	return 5;
	//else if (c == 'M' || c == 'N' || c == 'O')
	//	return 6;
	//else if (c == 'P' || c == 'R' || c == 'S')
	//	return 7;
	//else if (c == 'T' || c == 'U' || c == 'V')
	//	return 8;
	//else if (c == 'W' || c == 'X' || c == 'Y')
	//	return 9;
	if(c >= 'A' && c <= 'P')
		return (c - 'A') / 3 + 2;
	else if (c >= 'R' && c <= 'Y')
		return (c - 'A' - 1) / 3 + 2;
	else
		return -1;
}

int normalize(string number)
{
	//string normalized;
	//for (int i = 0; i < number.size(); ++i)
	//{
	//	if (number[i] >= '0' && number[i] <= '9')
	//		normalized.push_back(number[i]);
	//	else if (number[i] >= 'A' && number[i] <= 'Z')
	//	{
	//		if (number[i] == 'A' || number[i] == 'B' || number[i] == 'C')
	//			normalized.push_back('2');
	//		else if (number[i] == 'D' || number[i] == 'E' || number[i] == 'F')
	//			normalized.push_back('3');
	//		else if (number[i] == 'G' || number[i] == 'H' || number[i] == 'I')
	//			normalized.push_back('4');
	//		else if (number[i] == 'J' || number[i] == 'K' || number[i] == 'L')
	//			normalized.push_back('5');
	//		else if (number[i] == 'M' || number[i] == 'N' || number[i] == 'O')
	//			normalized.push_back('6');
	//		else if (number[i] == 'P' || number[i] == 'R' || number[i] == 'S')
	//			normalized.push_back('7');
	//		else if (number[i] == 'T' || number[i] == 'U' || number[i] == 'V')
	//			normalized.push_back('8');
	//		else if (number[i] == 'W' || number[i] == 'X' || number[i] == 'Y')
	//			normalized.push_back('9');
	//	}
	//}
	//return normalized;
	int num = 0, digits = 0;
	for (int i = 0; i < number.size(); ++i)
	{
		//if(!i && !(number[i] == '3' || number[i] == '6'))
		//	return -1;
		if (isdigit(number[i]))
		{
			num = num * 10 + (number[i] - '0');
			digits++;
		}
		else if (isalpha(number[i]))
		{
			int digit = charToDigit(number[i]);
			if (digit == -1) continue;
			num = num * 10 + digit;
			digits++;
		}
		if(!i && !(num == 3 || num == 6))
			return -1;
	}
	return digits == 7 ? num : -1;
}

int test(int* bitmap, int i)
{
	return bitmap[i >> shift] & (1 << (i & mask));
}

void set(int* bitmap, int i)
{
	if (test(bitmap, i - (i / 1000000) * 1000000))
		insert(i);
		//phone_map[to_string(i).insert(3, "-")]++;
		//insert(to_string(i).insert(3, "-"));
		//insert(head, to_string(i).insert(3, "-"));
	else
		bitmap[i - (i / 1000000) * 1000000 >> shift] |= 1 << (i - (i / 1000000) * 1000000 & mask);
}

int main()
{
	cout << "Error:" << endl;
	//head->next = NULL;
	string number;
	int error_flag = 0;
	while (cin >> number)
	{
		//string normalized = normalize(number);
		//if (!(normalized[0] == '3' || normalized[0] == '6') || normalized.find('Q') != string::npos || normalized.find('Z') != string::npos)
		//{
		//	error_flag = 1;
		//	cout << number << endl;
		//	continue;
		//}
		//if (normalized[0] == '3')
		//	set(begin_with_3, stoi(normalized));
		//else if (normalized[0] == '6')
		//	set(begin_with_6, stoi(normalized));
		int normalized = normalize(number);
		if (normalized == -1)
		{
			error_flag = 1;
			cout << number << endl;
			continue;
		}
		if (normalized / 1000000 == 3)
			set(begin_with_3, normalized);
		else if (normalized / 1000000 == 6)
			set(begin_with_6, normalized);
	}
	if (!error_flag)
		cout << "Not found." << endl;
	cout << endl << "Duplication:" << endl;
	int duplicate_flag = 0;
	sort(database, top, [](const NODE& a, const NODE& b) {return a.number < b.number; });
	for (int i = 0; i < top - database; ++i)
	{
		cout << to_string(database[i].number).insert(3, "-") << " " << database[i].count << endl;
		//cout << database[i].number << " " << database[i].count << endl;
		duplicate_flag = 1;
	}
	//vector<pair<string, int>> sorted_phone_map(phone_map.begin(), phone_map.end());
	//sort(sorted_phone_map.begin(), sorted_phone_map.end(), [](const pair<string, int>& a, const pair<string, int>& b) {return a.first < b.first; });
	//for (auto it = sorted_phone_map.begin(); it != sorted_phone_map.end(); ++it)
	//{
	//	cout << it->first << " " << it->second + 1 << endl;
	//	duplicate_flag = 1;
	//}
	//PNODE current = head->next;
	//while (current != NULL)
	//{
	//	cout << current->number << " " << current->count << endl;
	//	duplicate_flag = 1;
	//	current = current->next;
	//}
	if (!duplicate_flag)
		cout << "Not found." << endl;
	//delete head;
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
*/