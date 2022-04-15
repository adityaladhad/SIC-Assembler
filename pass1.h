#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<fstream>
#include<sstream>
#ifndef PASS1_H
#define PASS1_H
#include"optab.h"
using namespace std;

class symtab{
	public:
		string addr,size;
		char sym[10];
};
class stmt{
	public:
		int index,bitmask;
		string opcode,loc,operand_address;
		char ref[10],operation[10],operand[10],obj_code[6];
};stmt a[100];
symtab s[100];
int s_top=0;
string locctr;
int i=0,j=0,k=0,l=0;
int x1,z2;
string dectohex(int num)
{
    stringstream stream;
    stream<<hex<<num;
    return stream.str();
}
int hextodec(string str)
{
	int y;
	stringstream stream;
	stream<<str;
	stream>>hex>>y;
	return y;
}
string add(string str, string adder, int flag)
{
	if(flag)
	{
		int num1=hextodec(str);
		int num2=hextodec(adder);
		int sum=num1+num2;
		return dectohex(sum);
	}
	else{
		int num1=hextodec(str);
		int num2=atoi(adder.c_str());
		int sum=num1+num2;
		return dectohex(sum);
	}
}

int convert(long long n) {
    int dec = 0, i = 0, rem;
    while (n != 0) {
        rem = n % 10;
        n /= 10;
        dec += rem * pow(2, i);
        ++i;
    }
    return dec;
}
void pass_one()
{
	string str,c,c1;
ifstream myfile("Input1.txt",ios::in);
while(getline(myfile,str))
{

  c.append(str);
  c.append("\n");
 
}
//cout<<c;


int flg1=0,flg2=0;

while(c[i]!='\0')
{  
	while(c[i]!=' ')
	{
		i++;
	}
	l=0;
	for(j;j<i;j++)
	{
		a[k].ref[l]=c[j];
		l++;
	}a[k].ref[l]='\0';
	i++;
	j=i;
	l=0;
	while(c[i]!=' ')
	{
		i++;
	}
	for(j;j<i;j++)
	{
		a[k].operation[l]=c[j];
		l++;
	}
	a[k].operation[l]='\0';
	if(a[k].operation=="END")
	break;
	
	i++;
	j=i;
	l=0;
		while(c[i]!='\n')
	{
		i++;
	}
	for(j;j<i;j++)
	{
		a[k].operand[l]=c[j];
		l++;
	}a[k].operand[l]='\0';
	if(c[i]=='\0')
	{
		break;
	}
	l=0;
	i++;
	j=i;
	
	if(a[k].ref[0]!='\0')
	{
		flg1=0;
		for(int p=0;p<s_top;p++)
		{
			if(!strcmp(a[k].ref,s[p].sym))
			{
				cout<<"error"<<endl;
				flg1=1;
				exit(0);
			}
		}
		if(flg1==0)
		{
			strcpy(s[s_top].sym,a[k].ref);
			s[s_top].addr=locctr;
			s_top++;
			
		}
	}
	flg2=0;
	if(check_opcode(a[k].operation))
	{
		    a[k].loc=locctr;
			c1=get_opcode(a[k].operation);
			a[k].opcode[0]=c1[0];
			a[k].opcode[1]=c1[1];
			a[k].opcode[2]='\0';
			flg2=1;
			locctr=add(locctr,"3",0);
			
			
	}
	else if(!strcmp(a[k].operation,"START"))
	{
		locctr=a[k].operand;
		flg2=1;
		
		
	}
	else if(!strcmp(a[k].operation,"WORD"))
	{
		a[k].loc=locctr;
		locctr=add(locctr,"3",0);
		flg2=1;
	}
	else if(!strcmp(a[k].operation,"RESW"))
	{
		a[k].loc=locctr;
		int temp=3*atoi(a[k].operand);
		string temp1=dectohex(temp);
		locctr=add(locctr,temp1,0);
		flg2=1;
	}
	else if(!strcmp(a[k].operation,"BYTE"))
	{
		a[k].loc=locctr;
		int temp=strlen(a[k].operand);
		string temp1=dectohex(temp);
		locctr=add(locctr,temp1,0);
		flg2=1;
	}
	else if(!strcmp(a[k].operation,"RESB"))
	{
		a[k].loc=locctr;
		locctr=add(locctr,a[k].operand,0);
		flg2=1;
	}
	else if (flg2=0)
	{
		cout<<"error";
		exit(0);
	}
//	cout<<k<<"\n";
	k++;
}

}
#endif
