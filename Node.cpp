#include <iostream>
#include "Node.h"

using namespace std;

Node::Node()//构造函数
{
	next = NULL;
	quo = 0;
	exp = 0;
}
Node::~Node()//析构函数
{
	next = NULL;
	quo = 0;
	exp = 0;
}
bool Node::in_quo(int i)//i为系数；
{
	quo = i;
	return true;
}
bool Node::in_exp(int i)//i为指数；
{
	exp = i;
	return true;
}
int Node::get_quo()//返回quo;
{
	return quo;
}
int Node::get_exp()//返回exp;
{
	return exp;
}
bool NodeNext(Node *&t)//t可以访问私有成员next;
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
