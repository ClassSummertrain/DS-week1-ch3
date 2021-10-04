//表ADT：数组形式实现
#include "stdio.h"
#include "windows.h"
#include "stdlib.h"

#define MAXSIZE 20//顺序表最大长度

/*定义顺序表*/
typedef struct {
	int data[MAXSIZE];
	int length;
}SeqList;

/*初始化顺序表*/
void InitList(SeqList *l)
{
	l->length = 0;
}

/*建立顺序表*/
int CreatList(SeqList *l, int a[], int n) {
	if (n > MAXSIZE)
	{
		printf("空间不够，无法建立顺序表。\n");
		return 0;
	}
	for (int k = 0; k < n; k++)
	{
		l->data[k] = a[k];
	}
	l->length = n;
	return 1;
}

/*判空操作*/
int Empty(SeqList *l)
{
	if (l->length == 0)
		return 1;
	else
		return 0;
}

/*求顺序表长度*/
int Length(SeqList *l)
{
	return l->length;
}

/*遍历操作*/
void PrintList(SeqList *l)
{
	for (int i = 0; i < l->length; i++)
		printf("%d ", (l->data[i]));
}

/*按值查找*/
int Locate(SeqList *l,int x)
{
	for (int i = 0; i < l->length; i++)
	{
		if (l->data[i] == x)
		{
			return i + 1;
		}
		return 0;

	}
	return 1;
}

/*按位查找*/
int Get(SeqList *l, int x,int *ptr)
{//若查找成功，则通过指针参数ptr返回值
	if ( x <1 || x>l->length){
		printf("查找位置非法，查找错误\n");
		return 0;
	}
	else
	{
		*ptr = l->data[x];
		return 1;
	}
}

/*插入操作*/
int Insert(SeqList *l, int i, int x)
{
	if (l->length > MAXSIZE)
	{
		printf("上溢错误！");
		return 0;
	}
	if (i<1 || i>l->length)
	{
		printf("插入位置错误！");
		return 0;
	}
	for (int k = l->length; k > i; k--)
	{
		l->data[k] = l->data[k - 1];
	}
	l->data[i] = x;
	l->length++;
	return 1;
}

/*删除操作*/
int Delete(SeqList *l, int i, int *ptr)
{
	if (l->length == 0)
	{
		printf("发生下溢错误，即将要访问顺序表之前的地址.\n");
		return 0;
	}
	if (i > l->length || i < 1)
	{
		printf("删除位置错误！\n");
		return 0;
	}
	*ptr = l->data[i - 1];//把要删除的数据返回
	for (int j = i; j < l->length; j++)
	{
		l->data[j - 1] = l->data[j];
	}
	l->length--;
	return 1;
}

/*修改操作*/
int Modify(SeqList *l, int i, int x)
{
	if (i > l->length || i < 1)
	{
		printf("位置错误！\n");
		return 0;
	}
	l->data[i] = x;
	return 1;
}