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
	if(argc!=3)//传参错误
	{
		cerr<<"wrong input!"<<endl;
		return 0;
	}//传递参数错误，直接退出
	ifstream infile(argv[1],ios::in);//打开名为input.txt的文件，若不存在，返回打开失败的信息提示
	if(!infile)
	{
		cerr<<"Failed to open the input.txt!"<<endl;
		return 0;//打开文件失败
	}
	else
	{
		ofstream outfile(argv[2],ios::trunc);//打开名为output.txt的文件，若不存在，返回打开失败的信息提示
		if(!outfile)
		{
			cerr<<"Fail to open the output.txt!"<<endl;
			return 0;//退出程序；
		}
		else
		{
			char a[Max_Size] = "";
			char b[Max_Size] = {0};
			char c[Max_Size] = {0};
			int i = 0;char m = 0,u = 0;//u用来判断是否为常数还是x一次项；
			infile.get(m);
			while(1)//第一行的末尾
			{   
 				if(m == 'x'){a[i] = '1';i++;infile.get(m);if(m==' '){infile.get(m);}u = 1;}//系数为一，下一位是x
				else if(m=='-'&&u==0)//第一项的系数为负数；
				{
					a[i] = m;
					while(m==' '){infile.get(m);}
					u = 2;
					i++;
					a[i] = m;
				}
				else//系数不为一； 下一位是x,、\n;
				{
					a[i] = m;
					i++;
					infile.get(m);if(m==' '){infile.get(m);}
					else{;}
					u = 2;
				}
				int q = atoi(a);//将字符数组a转换为整形数字（包括加号减号）
				memset(a,0,Max_Size);
				if(m =='\n')//如果是常数项或最后一项
				{
					if(u==2)
					{
						L1.AddNode(q,0);//L1增加节点
					}
					else
					{
						L1.AddNode(q,1);
					}
					break;
				}
				else if(m=='x')//m==x
				{
					infile.get(m);//m为^,+.-
					while(m==' ')
					infile.get(m);
				}
				else{;}
				if(m =='\n')//换行符，此时x的指数为1；
				{
					L1.AddNode(q,1);
					break;
				}
				else if(m=='^')
				{
					infile.get(m);while(m==' '){infile.get(m);}
					b[0] = m;
					int e = atoi(b);//指数转化
					L1.AddNode(q,e);//后一位可能为+，—号，可能是\n
					infile.get(m);
					while(m==' '){infile.get(m);}
				}
				else
				{
					L1.AddNode(q,1);//一定为-+号；
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
				int number = 0;//表示t为头指针
				while(t!=NULL)
				{
					if(number == 0)//头指针；
					{
						if(t->get_exp()==0)//指数为零，常数
						{
							outfile<<t->get_quo();
							break;//跳出循环
						}//常数为最后一个项；
						else if(t->get_quo()==1)//系数为1,且指数不为0,即非常数项
						{
							if(t->get_exp()==1) outfile<<'x';//加号前的空未输出;指数为一
							else
							{
							outfile<<'x';
							outfile<<' '<<'^'<<' '<<t->get_exp();//输出指数，加号前的空未输出；
							}
						}
						else if(t->get_quo()==-1)
						{
							if(t->get_exp()==1) outfile<<'-'<<' '<<'x';//加号前的空未输出;指数为一
							else
							{
							outfile<<'-'<<' '<<'x';
							outfile<<' '<<'^'<<' '<<t->get_exp();//输出指数，加号前的空未输出；
							}
						}
						else//系数不为1；指数不为零 
						{
							if(t->get_exp()==1) outfile<<t->get_exp()<<' '<<'x';//加号前的空未输出;指数为一
							else
							{
								outfile<<t->get_quo()<<' '<<'x';
								outfile<<' '<<'^'<<' '<<t->get_exp();//输出指数，加号前的空未输出；
							}
						}//输出完毕；
						number++;//不是头指针
						NodeNext(t);
					}
					else//不为头指针；
					{
						if(t->get_exp()==0)//指数为零，常数
						{
							if(t->get_quo()>0)outfile<<' '<<'+';
							outfile<<' '<<t->get_quo();
							break;//跳出循环
						}//常数为最后一个项；
						else if(t->get_quo()==1)//系数为1,且指数不为0，即非常数项
						{
							if(t->get_exp()==1)//指数为1；
							{
								outfile<<' '<<'+'<<' '<<'x';//加号前空未输出；
							}
							else//指数不为一
							{
								outfile<<' '<<'+'<<' '<<'x';//加号前空未输出；
								outfile<<' '<<'^'<<' '<<t->get_exp();//输出指数，加号前的空未输出；
							}
						}
						else//系数不为1；指数不为零 
						{
							if(t->get_quo()>0) outfile<<' '<<'+';
							outfile<<' '<<t->get_quo()<<' '<<'x';
							if(t->get_exp()!=1)
							{
								outfile<<' '<<'^'<<' '<<t->get_exp();
							}//输出指数，加号前的空未输出；
						}//输出完毕；
						NodeNext(t);
					}
				}
			}
			outfile<<endl;
			int n = 1;
			int conse = 0;//结果
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