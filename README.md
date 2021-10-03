# week1-ch1-main.c
## 第一周学习记录（9.29-10.3）

### ADT

抽象数据结构类型（Abstract Data Type）是一些操作的集合。例如表，集合，图等以及他们的操作我们都可以看成是ADT。

### 表ADT

1. 表的数组实现（顺序表）
2. 链表
3. 比较：顺序表不能动态增减元素但是查找只需要O（1）的时间，插入，删除需要O（n）时间；链表可以动态增减元素，插入删除仅需要O（1）时间，但是查找需要O（n）时间。两种表各有和适用条件，没有绝对优劣好坏之分。
4. 双链表
5. 循环链表
6. 三个使用链表的例子（了解原理）
   1. 多项式ADT
   2. 基数排序
   3. 多重表
7. 表的游标实现（静态链表）

### 栈ADT

1. 栈：LIFO（后进先出）
2. 栈的链表实现与数组实现
3. 栈的应用（了解原理）
   1. 平衡符号
   2. 后缀表达式
   3. 中缀表达式转换为后缀表达式

### 队列ADT

1. 队列：先进先出
2. 队列的数组实现
3. 队列的应用（例如：排队，植物大战僵尸）

### 学习心得

本周学习了一些基本的数据结构，重点学习了链表的代码实现，掌握链表的实现之后栈和队列相对而言就简单了，可以说就是加上一些限制条件的表。
