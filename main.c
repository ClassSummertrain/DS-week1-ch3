//表ADT：单链表实现
#include "stdio.h"				
#include "stdlib.h"				//提供malloc()和free()
#include "string.h"				//提供strcpy()等
struct Node
{
	int a;				//数据域
	struct Node* next;	//指针域(指向节点的指针）
};

struct Node* head= NULL;//头指针
struct Node* end = NULL;//尾指针

void AddListTill(int a )//在链表尾添加一个结点
{
		//创建一个节点
		struct Node* temp=(struct Node*)malloc(sizeof(struct Node));		//此处注意强制类型转换

		//节点数据进行赋值
		temp->a=a;
		temp->next=NULL;		
		
		//连接分两种情况1.一个节点都没有2.已经有节点了，添加到尾巴上
		if(NULL==head)
		{	

			head=temp;
		//	end=temp;
		}
		else
		{
		end->next=temp;
	//	end=temp;			//尾结点应该始终指向最后一个
		}
		end=temp;			//尾结点应该始终指向最后一个
}

void ScanList()//遍历表
{
	struct Node *temp =head;		//定义一个临时变量来指向头
	while (temp !=NULL)
	{
		printf("%d\n",temp->a);
		temp = temp->next;		//temp指向下一个的地址 即实现++操作
	}

}

struct Node* FindNode(int a )//查找
{
	struct Node *temp =head;
	while(temp !=NULL)
	{
	if(a == temp->a)
	{
		return temp;
	}
	temp = temp->next;
	}
	//没找到
		return NULL;
} 

void FreeList()//删除
{
	//一个一个NULL
	struct Node *temp =head;		//定义一个临时变量来指向头
	while (temp !=NULL)
	{
	//	printf("%d\n",temp->a);
		struct Node* pt =temp;
		temp = temp->next;		//temp指向下一个的地址 即实现++操作
		free(pt);					//释放当前
	}
	//头尾清空	不然下次的头就接着0x10
	head =NULL;
	end =NULL;
}

void AddListRand(int index,int a)//添加
{	

    if (NULL==head)
	{
		printf("链表没有节点\n");
		return;
	}	
    struct Node* pt =FindNode(index);
	if(NULL==pt)    //没有此节点
	{
		printf("没有指定节点\n");
		return;
	}
    //有此节点
    //创建临时节点，申请内存
	struct Node* temp =(struct Node *)malloc(sizeof(struct Node));
	//节点成员进行赋值
	temp->a=a;
	temp->next=NULL;
	//连接到链表上 1.找到的节点在尾部 2.找到的节点在中间 
	if (pt == end)
	{
	//尾巴的下一个指向新插入的节点
	end->next=temp;
	//新的尾巴
	end=temp;
	}else
	{
	// 先连后面 （先将要插入的节点指针指向原来找到节点的下一个）
	temp->next=pt->next;
	//后连前面
	pt->next=temp;
	}

}

void DeleteListTail()//删除尾
{ 
	if (NULL == end)
	{
		printf("链表为空，无需删除\n");
		return;
	}
	//链表不为空 
	//链表有一个节点
	 if (head==end)
	 {
		 free(head);
		 head=NULL;
		 end=NULL; 
	 }
	 else
	 {
		//找到尾巴前一个节点
		 struct Node* temp =head;
		 while (temp->next!=end)
		 {
			 temp = temp->next;
		 }
		 //找到了，删尾巴
		//释放尾巴
		 free(end);
		 //尾巴迁移
		 end=temp;
		 //尾巴指针为NULL
		 end->next=NULL;
	 }

}

void DeleteListHead()//删除头
{	//记住旧头
	struct Node* temp=head;
	//链表检测 
	if (NULL==head)
	{
			printf("链表为空\n");
			return;
	}

	head=head->next;//头的第二个节点变成新的头
	free(temp);

}

void DeleteListRand(int a)//删除
{

	//链表判断 是不是没有东西
	if(NULL==head)
	{
	printf("链表没东西\n");
	return;
	}
    //链表有东西，找这个节点
	struct Node* temp =FindNode(a);
	if(NULL==temp)
	{
	printf("查无此点\n");
	return;
	}
	//找到了,且只有一个节点
	if(head==end)
	{
	free(head);
	head=NULL;
	end=NULL;
	}
	else if(head->next==end) //有两个节点
	{
	//看是删除头还是删除尾
	if(end==temp)
		{	DeleteListTail(); }
	else if(temp==head)
		{	DeleteListHead(); }	
	}
	else//多个节点
	{
		//看是删除头还是删除尾
		if(end==temp)
			DeleteListTail();
		else if(temp==head)
			DeleteListHead();	
		else	//删除中间某个节点
		{	//找要删除temp前一个，遍历
			struct Node*pt =head;
			while(pt->next!=temp)
			{
			pt=pt->next;
			}
			//找到了
			//让前一个直接连接后一个 跳过指定的即可
			 pt->next=temp->next;
			 free(temp);
		
		}
	}
}

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

//栈ADT数组形式实现
#include <stdio.h>
#define STACKSIZE 100

typedef  int ElemType;

typedef struct {
	ElemType stack[STACKSIZE];
	int top;

}SeqStack;

//初始化栈
void initStack(SeqStack* s) {
	s->top = 0;
}

//判断栈是否为空
int stackEmpty(SeqStack s) {
	if (s.top == 0)
		return 1;
	else
		return 0;
	
}

//取栈顶元素
int getTop(SeqStack s, ElemType* e) {


	if (s.top <= 0) {
		printf("空栈");
		return 0;

	}
	else {
		*e = s.stack[s.top - 1];
		return 1;
	}
}

//进栈

int pushStack(SeqStack* s, ElemType e) {
	if (s->top >= STACKSIZE) {
		printf("栈已满");
		return 0;

	}
	else {
		s->stack[s->top] = e;
		s->top++;
		return 1;
	}
}

//出栈

int popStack(SeqStack* s, ElemType* e) {
	if (s->top = 0) {
		printf("空栈");
		return 0;
	}
	else {
		s->top--;
		*e = s->stack[s->top];
		return 1;
	}
}

//得到栈的长度
int getLength(SeqStack s) {
	return s.top;
}

//清空栈
void clearStack(SeqStack* s) {
	s->top = 0;
}

//栈ADT链表形式实现
#include<stdbool.h>
#include<stdlib.h>
typedef int datatype;
 
//Link Stack 实现顺序栈，使用链表来实现
 
struct stack
{
    datatype data;
    struct stack *next;
};
 
typedef struct stack Stack;
//创建栈
Stack *s;
//初始化栈
void init()
{
    s=NULL;
}
 
//判断栈是否为空
bool Empty()
{
    if(s==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
 
//入栈
void Push(datatype element)
{
    Stack *p = (Stack *)malloc(sizeof(Stack));
    p->data=element;
    p->next=s;
    s=p;             
}
 
//出栈
void Pop()
{
    if(!Empty(s))
    {
        s=s->next;
    }
    else
    {
        printf("栈空\n");
    }
}
 
//取栈顶元素
datatype Top()
{
    if(!Empty(s))
    {
        return s->data;
    }
    else
    {
        printf("栈空\n");
    }
}
 
//销毁栈
void Destroy()
{
    free(s);//因该销毁每一个元素
    s=NULL;
    // free(s.data); //容易导致失败
}

//顺序队列实现
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
 
typedef int QUDataType;
 
typedef struct QueueNode
{
	QUDataType _data;
	struct QueueNode* _next;
}QueueNode;
 
typedef struct Queue
{
	QueueNode* _front;//队头
	QueueNode* _rear;//队尾
}Queue;
 
void QueueInit(Queue* q);
void QueueDestroy(Queue* q);
 
void QueuePush(Queue* q, QUDataType x);//在队头入数据
void QueuePop(Queue* q);//在队头出数据
 
int QueueSize(Queue* q);//数据的个数
int QueueEmpty(Queue* q);//判断是否为NULL
 
QUDataType QueueFront(Queue* q);//取出队头数据
QUDataType QueueBack(Queue* q);//取出队尾数据
void QueueInit(Queue* q)//置空即可
{
	assert(q);
	q->_front = q->_rear = NULL;
}
 
void QueueDestroy(Queue* q)
{
	assert(q);
	QueueNode* cur = q->_front;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;
}
 
QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));//这里注意开辟的是一个结构体，而不是整形
	node->_data = x;
	node->_next = NULL;
 
	return node;
}
 
void QueuePush(Queue* q, QUDataType x)//在队头入数据
{
	assert(q);
	if (q->_front == NULL)
	{
		q->_front = q->_rear = BuyQueueNode(x);
	}
	else
	{
		q->_rear->_next = BuyQueueNode(x);
		q->_rear = q->_rear->_next;
	}
}
 
void QueuePop(Queue* q)//在队头出数据
{
	assert(q);
	if (q->_front)
	{
		QueueNode* next = q->_front->_next;
		free(q->_front);
		q->_front = next;
 
		if (q->_front == NULL)//当front为NULL时，back还未置空，如果队尾不置空，会出现野指针的问题
		{
			q->_rear = NULL;
		}
	}
}
 
int QueueSize(Queue* q)//数据的个数
{
	assert(q);
	int size = 0;
	QueueNode* cur = q->_front;
	while (cur)
	{
		cur = cur->_next;
		size++;
	}
	return size;
}
 
int QueueEmpty(Queue* q)//判断是否为NULL
{
	assert(q);
	if (q->_front == NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
	//return q->_front==NULL ? 0:1;
}
 
QUDataType QueueFront(Queue* q)//取出队头数据
{
	assert(q);
	return q->_front->_data;
}
 
QUDataType QueueBack(Queue* q)//取出队尾数据
{
	assert(q);
	return q->_rear->_data;
}