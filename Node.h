#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

class Node
{
	friend class MulList;
	friend bool NodeNext(Node *&t);//t可以访问私有成员next;
public:
	Node();
	~Node();
	bool in_quo(int i);//i为系数；
	bool in_exp(int i);//i为指数；
	
	int get_quo();//返回quo;
	int get_exp();//返回exp;
private:
	Node *next;
	int quo;//系数
	int exp;//指数
};
#endif