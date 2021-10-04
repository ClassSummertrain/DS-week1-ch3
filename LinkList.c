//表ADT：单链表实现
#include "stdio.h"				
#include "stdlib.h"				//提供malloc()和free()
#include "string.h"				
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
		}
		else
		{
		end->next=temp;
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

void FreeList()//删除所有结点
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
	//头尾清空
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