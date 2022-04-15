
#ifndef OPTAB_H
#define OPTAB_H
#include <iostream>
#include"defoptab.h"
using namespace std;

bool check_opcode(char a[])
{
    opcd();

	int flag=0;
	for(int i=0;i<42;i++)
	{
		if(a==opobject[i].operation)
		flag=1;	
	}
	if(flag==1)
	return true;
	else
	return false;
}
string get_opcode(char a[])
{
    opcd();
	int i=0;
	for(i=0;i<42;i++)
	{
		int flag;
		if(a==opobject[i].operation)
		{
			flag=i;
			break;
		}
	}
	return(opobject[i].opcode);
}
#endif
