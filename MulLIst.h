#ifndef MULLIST_H
#define MULLIST_H

#include <iostream>
#include "Node.h"

using namespace std;

class MulList//多项式链表
{
public:
	MulList();//构造函数
	~MulList();//析构函数
    bool AddNode(int q,int e);//添加节点,q为节点的系数，e为指数
	bool MulReverse(MulList &L);//多项式逆序，用链表获得并存放；
	bool ClearList();//清空链表；
	bool MulEval(int i,int &e);//将i的值带入到多项式中求值,赋值给e;
	void GetHead(Node *&t);//将head的值赋给t指针
private:
	Node *head;//头指针
	Node *current;//当前指针；
	Node *tail;//尾指针；
};
#endif
