#include <iostream>
#include "Node.h"

using namespace std;

Node::Node()//���캯��
{
	next = NULL;
	quo = 0;
	exp = 0;
}
Node::~Node()//��������
{
	next = NULL;
	quo = 0;
	exp = 0;
}
bool Node::in_quo(int i)//iΪϵ����
{
	quo = i;
	return true;
}
bool Node::in_exp(int i)//iΪָ����
{
	exp = i;
	return true;
}
int Node::get_quo()//����quo;
{
	return quo;
}
int Node::get_exp()//����exp;
{
	return exp;
}
bool NodeNext(Node *&t)//t���Է���˽�г�Աnext;
{
	if(t!=NULL)
	{
		t = t->next;
		return true;
	}
	else
	{
		return false;
	}
}
