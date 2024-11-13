#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAXN 1000000

typedef struct building {
    int color;
    int height;
} NODE;

NODE building[MAXN + 1];
NODE* top = NULL;

void push(NODE* top, int color, int height)
{
    top->color = color;
    top->height = height;
}

int main()
{
    int turn;
    scanf("%d", &turn);
    for (int t = 0; t < turn; ++t)
    {
        memset(building, 0, sizeof(building));
        top = building;
        int color_temp[MAXN] = { 0 };
        int color_sum = 0;
        int color_record[MAXN + 1] = { 0 };
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &color_temp[i]);
        for (int i = 0; i < n; ++i)
        {
            int color = color_temp[i];
            int height;
            scanf("%d", &height);
            while (top != building && (top - 1)->height <= height)
            {
                --top;
                --color_record[top->color];
                if (!color_record[top->color])
                    --color_sum;
            }
            push(top, color, height);
            ++top;
            if (!color_record[color])
                ++color_sum;
            ++color_record[color];
            printf("%d%c", color_sum, (i == n - 1) ? '\n' : ' ');
        }
    }
    return 0;
}

/*
* ˼·��ʹ�õ���ջ��ģ��¥�����ڵ��������֤ջ�ĸ߶����εݼ����ɡ�
* ����ÿ�࿼��һ��¥��ʱ���Ҫ���һ����ɫ���������ά��һ����ɫ�����ı���color_sum���Լ�һ����ɫ��¼����color_record���Լ�¼�ܵ���ɫ����ÿ����ɫ��������ÿ����ջʱ����color_record��ɫ��Ӧ������ֵ+1����ջ��-1��color_sum����ݱ仯ǰ��0���������ʱ���¡�
* ����1��ע���ڽ��г�ջ����ʱ����Ҫ�ж�ջ�Ƿ�Ϊ�գ�
* ����2��C++��cin��cout�ᳬʱ������ر���ͬ��Ҳ�ǣ����ֱ�Ӹ�дC���ԣ�ʹ��scanf��printf���ܹ��ˡ�
*/