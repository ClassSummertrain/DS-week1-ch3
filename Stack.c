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
