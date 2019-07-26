#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

class Node
{
	friend class MulList;
	friend bool NodeNext(Node *&t);//t���Է���˽�г�Աnext;
public:
	Node();
	~Node();
	bool in_quo(int i);//iΪϵ����
	bool in_exp(int i);//iΪָ����
	
	int get_quo();//����quo;
	int get_exp();//����exp;
private:
	Node *next;
	int quo;//ϵ��
	int exp;//ָ��
};
#endif