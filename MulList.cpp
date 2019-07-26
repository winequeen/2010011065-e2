#include <iostream>
#include <fstream>
#include <math.h>
#include "MulList.h"

using namespace std;

MulList::MulList()//���캯��
{
	head = NULL;
	current = NULL;
	tail = NULL;
}
MulList::~MulList()//��������
{
	ClearList();
}
	
bool MulList::ClearList()//�������
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
bool MulList::AddNode(int q,int e)//��ӽڵ�,qΪ�ڵ��ϵ����eΪָ����
{
	Node *p = (Node*)new Node[1];
	if(p == NULL)
	{
		cout<<"Failed to allot;"<<endl;
		return false;
	}
	p->exp = e;
	p->quo = q;
	if(head == NULL)//����Ϊ�գ�
	{
		head = p;
		tail = p;
		current = p;
		return true;
	}
	else if(head->exp<e)//���뵽��һ���ڵ㣻
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
		if(current->next==NULL)//���һ���ڵ�
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
	else//current->exp<e,��ͷ������������ı�ͷָ�룻
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
bool MulList::MulEval(int i,int &e)//��i��ֵ���뵽����ʽ����ֵ,���ش�
{
	e = 0;
	for(current = head;current!=NULL;current = current->next)
	{
		e = e+(int)((current->quo)*(pow((double)i,(double)current->exp)));
	}
	return true;
}

bool MulList::MulReverse(MulList &L)//����ʽ�����������ò���ţ�
{
	if(head == NULL){L.ClearList();return true;}
	L.ClearList();
	Node *p = tail;//����ָ��β�ڵ��ָ�룻
	Node *t = NULL;
	current = head;
	int num = 0;//��numΪż��ʱ��p��t���棬����ʱ��t��p����
	if(head->next==NULL)//ֻ��һ�
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
		else//��ʱt��ָ��Ϊ��Ӧ����ڵ��ָ��
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
//bool MulList::OutList(char p[])//������ʽ�ı�ʾ�洢���ַ�����p��;
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

void MulList::GetHead(Node *&t)//��head��ֵ����tָ��
{
	t = this->head;
}



