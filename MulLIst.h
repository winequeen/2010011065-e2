#ifndef MULLIST_H
#define MULLIST_H

#include <iostream>
#include "Node.h"

using namespace std;

class MulList//����ʽ����
{
public:
	MulList();//���캯��
	~MulList();//��������
    bool AddNode(int q,int e);//��ӽڵ�,qΪ�ڵ��ϵ����eΪָ��
	bool MulReverse(MulList &L);//����ʽ�����������ò���ţ�
	bool ClearList();//�������
	bool MulEval(int i,int &e);//��i��ֵ���뵽����ʽ����ֵ,��ֵ��e;
	void GetHead(Node *&t);//��head��ֵ����tָ��
private:
	Node *head;//ͷָ��
	Node *current;//��ǰָ�룻
	Node *tail;//βָ�룻
};
#endif
