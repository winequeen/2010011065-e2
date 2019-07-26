#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <memory.h>
#include "MulList.h"

#define Max_Size 10

using namespace std;

int main(int argc, const char *argv[])
{
	MulList L1,L2;
	if(argc!=3)//���δ���
	{
		cerr<<"wrong input!"<<endl;
		return 0;
	}//���ݲ�������ֱ���˳�
	ifstream infile(argv[1],ios::in);//����Ϊinput.txt���ļ����������ڣ����ش�ʧ�ܵ���Ϣ��ʾ
	if(!infile)
	{
		cerr<<"Failed to open the input.txt!"<<endl;
		return 0;//���ļ�ʧ��
	}
	else
	{
		ofstream outfile(argv[2],ios::trunc);//����Ϊoutput.txt���ļ����������ڣ����ش�ʧ�ܵ���Ϣ��ʾ
		if(!outfile)
		{
			cerr<<"Fail to open the output.txt!"<<endl;
			return 0;//�˳�����
		}
		else
		{
			char a[Max_Size] = "";
			char b[Max_Size] = {0};
			char c[Max_Size] = {0};
			int i = 0;char m = 0,u = 0;//u�����ж��Ƿ�Ϊ��������xһ���
			infile.get(m);
			while(1)//��һ�е�ĩβ
			{   
 				if(m == 'x'){a[i] = '1';i++;infile.get(m);if(m==' '){infile.get(m);}u = 1;}//ϵ��Ϊһ����һλ��x
				else if(m=='-'&&u==0)//��һ���ϵ��Ϊ������
				{
					a[i] = m;
					while(m==' '){infile.get(m);}
					u = 2;
					i++;
					a[i] = m;
				}
				else//ϵ����Ϊһ�� ��һλ��x,��\n;
				{
					a[i] = m;
					i++;
					infile.get(m);if(m==' '){infile.get(m);}
					else{;}
					u = 2;
				}
				int q = atoi(a);//���ַ�����aת��Ϊ�������֣������Ӻż��ţ�
				memset(a,0,Max_Size);
				if(m =='\n')//����ǳ���������һ��
				{
					if(u==2)
					{
						L1.AddNode(q,0);//L1���ӽڵ�
					}
					else
					{
						L1.AddNode(q,1);
					}
					break;
				}
				else if(m=='x')//m==x
				{
					infile.get(m);//mΪ^,+.-
					while(m==' ')
					infile.get(m);
				}
				else{;}
				if(m =='\n')//���з�����ʱx��ָ��Ϊ1��
				{
					L1.AddNode(q,1);
					break;
				}
				else if(m=='^')
				{
					infile.get(m);while(m==' '){infile.get(m);}
					b[0] = m;
					int e = atoi(b);//ָ��ת��
					L1.AddNode(q,e);//��һλ����Ϊ+�����ţ�������\n
					infile.get(m);
					while(m==' '){infile.get(m);}
				}
				else
				{
					L1.AddNode(q,1);//һ��Ϊ-+�ţ�
				}
				if(m=='\n'){break;}
				else
				{
					i = 0;
					a[i] = m;//+.-
					i++;
					infile.get(m);while(m==' '){infile.get(m);}
					
				}
			}
			if(L1.MulReverse(L2)==false)
			{
				outfile<<0<<endl;
			}
			else
			{
			
				Node *t = NULL;
				L2.GetHead(t);
				int number = 0;//��ʾtΪͷָ��
				while(t!=NULL)
				{
					if(number == 0)//ͷָ�룻
					{
						if(t->get_exp()==0)//ָ��Ϊ�㣬����
						{
							outfile<<t->get_quo();
							break;//����ѭ��
						}//����Ϊ���һ���
						else if(t->get_quo()==1)//ϵ��Ϊ1,��ָ����Ϊ0,���ǳ�����
						{
							if(t->get_exp()==1) outfile<<'x';//�Ӻ�ǰ�Ŀ�δ���;ָ��Ϊһ
							else
							{
							outfile<<'x';
							outfile<<' '<<'^'<<' '<<t->get_exp();//���ָ�����Ӻ�ǰ�Ŀ�δ�����
							}
						}
						else if(t->get_quo()==-1)
						{
							if(t->get_exp()==1) outfile<<'-'<<' '<<'x';//�Ӻ�ǰ�Ŀ�δ���;ָ��Ϊһ
							else
							{
							outfile<<'-'<<' '<<'x';
							outfile<<' '<<'^'<<' '<<t->get_exp();//���ָ�����Ӻ�ǰ�Ŀ�δ�����
							}
						}
						else//ϵ����Ϊ1��ָ����Ϊ�� 
						{
							if(t->get_exp()==1) outfile<<t->get_exp()<<' '<<'x';//�Ӻ�ǰ�Ŀ�δ���;ָ��Ϊһ
							else
							{
								outfile<<t->get_quo()<<' '<<'x';
								outfile<<' '<<'^'<<' '<<t->get_exp();//���ָ�����Ӻ�ǰ�Ŀ�δ�����
							}
						}//�����ϣ�
						number++;//����ͷָ��
						NodeNext(t);
					}
					else//��Ϊͷָ�룻
					{
						if(t->get_exp()==0)//ָ��Ϊ�㣬����
						{
							if(t->get_quo()>0)outfile<<' '<<'+';
							outfile<<' '<<t->get_quo();
							break;//����ѭ��
						}//����Ϊ���һ���
						else if(t->get_quo()==1)//ϵ��Ϊ1,��ָ����Ϊ0�����ǳ�����
						{
							if(t->get_exp()==1)//ָ��Ϊ1��
							{
								outfile<<' '<<'+'<<' '<<'x';//�Ӻ�ǰ��δ�����
							}
							else//ָ����Ϊһ
							{
								outfile<<' '<<'+'<<' '<<'x';//�Ӻ�ǰ��δ�����
								outfile<<' '<<'^'<<' '<<t->get_exp();//���ָ�����Ӻ�ǰ�Ŀ�δ�����
							}
						}
						else//ϵ����Ϊ1��ָ����Ϊ�� 
						{
							if(t->get_quo()>0) outfile<<' '<<'+';
							outfile<<' '<<t->get_quo()<<' '<<'x';
							if(t->get_exp()!=1)
							{
								outfile<<' '<<'^'<<' '<<t->get_exp();
							}//���ָ�����Ӻ�ǰ�Ŀ�δ�����
						}//�����ϣ�
						NodeNext(t);
					}
				}
			}
			outfile<<endl;
			int n = 1;
			int conse = 0;//���
			while(n<=4)
			{
				infile.get(m);
				int i =0;
				memset(c,0,Max_Size);
				while(m!='\n')
				{
					c[i] = m;
					i++;
					infile.get(m);
					if(infile.eof()){break;}
				}
				int e = atoi(c);
				cout<<c[0]<<' '<<c[1]<<endl;;
				L1.MulEval(e,conse);//''''''''''''''''
				outfile<<conse<<endl;
				L2.MulEval(e,conse);
				outfile<<conse<<endl;
				cout<<conse<<endl;
				n++;
			}
		infile.close();
		outfile.close();
		return 0;
		}
	}
}
			
			
		


			 




//