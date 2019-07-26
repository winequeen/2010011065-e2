#include <iostream>
#include <fstream>
#include <math.h>
#include "MulList.h"

using namespace std;

MulList::MulList()//构造函数
{
	head = NULL;
	current = NULL;
	tail = NULL;
}
MulList::~MulList()//析构函数
{
	ClearList();
}
	
bool MulList::ClearList()//清空链表
{
	for(current = head;head!=NULL;)
	{
		current = head->next;
		delete head;
		head = current;
	}
	tail = NULL;
	return true;
}
bool MulList::AddNode(int q,int e)//添加节点,q为节点的系数，e为指数；
{
	Node *p = (Node*)new Node[1];
	if(p == NULL)
	{
		cout<<"Failed to allot;"<<endl;
		return false;
	}
	p->exp = e;
	p->quo = q;
	if(head == NULL)//链表为空；
	{
		head = p;
		tail = p;
		current = p;
		return true;
	}
	else if(head->exp<e)//插入到第一个节点；
	{
		p->next = head;
		head = p;
		return true;
	}
	else if(current->exp == e )
	{
		current->quo = current->quo+q;
		return true;
	}
	else if(current->exp>e)
	{
		while(current->next!=NULL&&(current->next->exp)>e)
		{
			current = current->next;
		}
		if(current->next==NULL)//最后一个节点
		{
			tail->next = p;
			tail = p;
		}
		else if(current->next->exp == e)
		{
			current = current->next;
			current->quo = current->quo+q;
		}
		else
		{
			p->next = current->next;
			current->next = p;
		}
		return true;
	}
	else//current->exp<e,从头遍历，但不需改变头指针；
	{
		current = head;
		while(current->exp>e&&(current->next->exp)>e)
		{
			current = current->next;
		}
		p->next = current->next;
		current->next = p;
		return true;
	}
}
bool MulList::MulEval(int i,int &e)//将i的值带入到多项式中求值,返回答案
{
	e = 0;
	for(current = head;current!=NULL;current = current->next)
	{
		e = e+(int)((current->quo)*(pow((double)i,(double)current->exp)));
	}
	return true;
}

bool MulList::MulReverse(MulList &L)//多项式逆序，用链表获得并存放；
{
	if(head == NULL){L.ClearList();return true;}
	L.ClearList();
	Node *p = tail;//定义指向尾节点的指针；
	Node *t = NULL;
	current = head;
	int num = 0;//当num为偶数时，p在t后面，基数时，t在p后面
	if(head->next==NULL)//只有一项；
	{
		int q = head->quo;
		int e = head->exp;
		L.AddNode(q,e);
		return true;
	}
	while(p!=head&&t!=head)
	{
		if(num%2 == 0)//t,p
		{
			for(t = head;t->next!=p;t = t->next){;}
			num++;
			int q = p->quo;
			int e = current->exp;
			L.AddNode(q,e);
			current = current->next;
		}
		else//此时t的指数为所应插入节点的指数
		{
			for(p = head;p->next!=t;p = p->next){;}//p,t
			num++;
			L.AddNode(t->quo,current->exp);
			current = current->next;
		}
	}
	L.AddNode(head->quo,current->exp);
	return true;
}
//bool MulList::OutList(char p[])//将多项式的表示存储到字符数组p中;
//{
//	if(head = NULL)
//	{
//		return false;
//	}
//	int i = 0;
//	current = head;
//	while(current!=NULL)
//	{
//		if(current->quo>1&&current!=head)
//		{
//			p[i] = '+';i++;
///			p[i] = (char)current->quo;i++;
//			p[i] = 'x';i++;
//		}
//		else if(current->quo==1)
//		{
//			p[i]='x';i++;
//			
//		}
//		else
//		{
//			p[i] = (char)current->quo;i++;
//			p[i] = 'x';i++;
//		}
//		if(current->exp==0)
//		{
//			i--;
//			p[i] = '\0';
//		}
//		else 
//		{
//			p[i] = '^';i++;
//			p[i] = (char)current->exp;i++;
//		}
//		current = current->next;
//	}
//	return true;
//}/

void MulList::GetHead(Node *&t)//将head的值赋给t指针
{
	t = this->head;
}



