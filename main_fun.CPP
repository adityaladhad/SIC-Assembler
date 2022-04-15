#include<iostream>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include"pass1.h"
using namespace std;
int x=0;
class text_record
{
	public:
	int d[30],max,temp[100],flg[100],i1;
    string bitmask;
	string start_address,size;
	text_record()
	{  
	for(int i=0;i<10;i++)
	temp[i]=0;
	    i1=0;
		bitmask="000";
		max=0;
	}
};
text_record te[10];
long long cnvrt(int a[])
{
	long long x,a1,y=0,z=1000000000;
	for(int i=0;i<10;i++)
	{
		x=a[i]*z;
		y+=x;
		z/=10;
	}
	a1=y*100;
	return a1;
}
void pass_two()
{
	
	int i=0,flag1=0,flag2=0,t,y=0,u=0,g=0;
	string b,r;
	for(i=0;i<k;i++)
	{
		
		a[i].index=i;
		flag1=0;
		flag2=0;
		if(check_opcode(a[i].operation))
		{
			if(a[i].operand[0]!='\0')
			{   
				for(int j=0;j<s_top;j++)
				{
					if(!strcmp(s[j].sym,a[i].operand))
					{
						a[i].operand_address=s[j].addr;
						flag1=1;
						break;
					}
				}
				if(flag1==0)
				{
					cout<<"symbol not defined";
					exit(0);
				}
				if(a[i].operand_address[1]=='\0')
					strcpy(a[i].obj_code,(get_opcode(a[i].operation)+"000"+a[i].operand_address).c_str());
				else if(a[i].operand_address[2]=='\0')
					strcpy(a[i].obj_code,(get_opcode(a[i].operation)+"00"+a[i].operand_address).c_str());
				else if(a[i].operand_address[3]=='\0')
					strcpy(a[i].obj_code,(get_opcode(a[i].operation)+"0"+a[i].operand_address).c_str());
				else if(a[i].operand_address[4]=='\0')
					strcpy(a[i].obj_code,(get_opcode(a[i].operation)+a[i].operand_address).c_str());
			}
			else
			{
				a[i].operand_address="0000";
				strcpy(a[i].obj_code,(a[i].opcode+a[i].operand_address).c_str());
				
			}
			
		
		}
		else if(!strcmp(a[i].operation,"WORD"))
		{   
			t=atoi(a[i].operand);
		//	cout<<t;
			if(t/10==0)
			{
				//cout<<"hi"<<"\n";
				b="00000";
				b=b.append(a[i].operand);
				strcpy(a[i].obj_code,b.c_str());
				
			}
			else if(t/100==0)
			{
				b="0000";
				b=b.append(a[i].operand);
				strcpy(a[i].obj_code,b.c_str());
			}
			else if(t/1000==0)
			{
				b="000";
				b=b.append(a[i].operand);
				strcpy(a[i].obj_code,b.c_str());
			}
			else if(t/10000==0)
			{
				b="00";
				b=b.append(a[i].operand);
				strcpy(a[i].obj_code,b.c_str());
			}
			else if(t/100000==0)
			{
				b="0";
				b=b.append(a[i].operand);
				strcpy(a[i].obj_code,b.c_str());
			}
			else
			{
				strcpy(a[i].obj_code,a[i].operation);
			}
		}
		else if(!strcmp(a[i].operation,"BYTE"))
		{   
			b="";r="";y=0;
			while(a[i].operand[y]!=0)
			{
				r=dectohex(int(a[i].operand[y]));
				b.append(r);
				y++;
			}
			strcpy(a[i].obj_code,b.c_str());
		    
		}
		else if(!strcmp(a[i].operation,"RESW"))
		{
			a[i].obj_code[0]='\0';
			a[i].index=-1;
		}
		else if(!strcmp(a[i].operation,"RESB"))
		{
			a[i].obj_code[0]='\0';
			a[i].index=-1;
		}
		if(a[i].index!=-1 && (u+strlen(a[i].obj_code)/2)<=30)
		{   
		    te[x].d[te[x].max]=a[i].index;
			u=u+strlen(a[i].obj_code)/2;
			te[x].max++;
			 if(!strcmp(a[i].operation,"BYTE"))
			{
				te[x].temp[te[x].i1]=0;
		    	te[x].i1++;
			}
		    else if(!strcmp(a[i].operation,"WORD"))
			{
				te[x].temp[te[x].i1]=0;
		    	te[x].i1++;
			}
			else if(!strcmp(a[i].operation,"RSUB"))
			{
				te[x].temp[te[x].i1]=0;
		    	te[x].i1++;
			}
		   else	if(check_opcode(a[i].operation))
		    {   
		    	te[x].temp[te[x].i1]=1;
		    	te[x].i1++;
			}
			
			
		}
		else
		{   
			te[x].start_address=a[te[x].d[0]].loc;
			te[x].size=dectohex(u);
			te[x].temp[te[x].i1]=0;
			u=0;
			
		    te[x].temp[te[x].i1]=0; 
		    te[x].i1--;
		   	x++;
			if(a[i].index!=-1)
			{
			te[x].d[te[x].max]=a[i].index;
			u=u+strlen(a[i].obj_code)/2;
			te[x].max++;
			}
		}
	}
	te[x].start_address=a[te[x].d[0]].loc;
	te[x].size=dectohex(u);
	for(int i=0;i<=x;i++)
	{
		if(te[i].start_address[0]=='\0')
	    { b="000000";
	      te[i].start_address=b;
		}
	else if(te[i].start_address[1]=='\0')
	{
		b="00000";
		b.append(te[i].start_address);
		te[i].start_address=b;
	}
	else if(te[i].start_address[2]=='\0')
	{
		b="0000";
		b.append(te[i].start_address);
		te[i].start_address=b;
	}
	else if(te[i].start_address[3]=='\0')
	{
		b="000";
		b.append(te[i].start_address);
		te[i].start_address=b;
	}
    else if(te[i].start_address[3]=='\0')
	{
		b="0";
		b.append(te[i].start_address);
		te[i].start_address=b;
	}
	else if(te[i].start_address[3]=='\0')
	{
		b="0";
		b.append(te[i].start_address);
		te[i].start_address=b;
	}
	}
	for(int i=0;i<=x;i++)
	{
		if(te[i].size[0]=='\0')
		{
			b="00";
		    b.append(te[i].size);
		    te[i].size=b;
		}
		if(te[i].size[1]=='\0')
		{
			b="0";
		    b.append(te[i].size);
		    te[i].size=b;
		}
	}
	

}
string get_bitmask(int a)
{   long long con1=0;
    long long con;
    string hex1;
	con=cnvrt(te[a].temp);
	con1=convert(con);
	hex1=dectohex(con1);
if(hex1[0]=='\0')
{
  	string b="000";
		b.append(hex1);
		hex1=b;	
}
if(hex1[1]=='\0')
{
  	string b="00";
		b.append(hex1);
		hex1=b;	
}
	return hex1;
	
}
void printt()
{
	for(int i=0;i<=x;i++)
	{  
	   
	   if(te[i].max!=0){
	    if(i==0)
     	{
    	    cout<<"H^"<<a[i].ref<<"^"<<te[i].start_address<<"^0000"<<a[k-1].loc<<endl;	
     	}
		cout<<"T^"<<te[i].start_address<<"^"<<te[i].size<<"^"<<get_bitmask(i)<<"^";
		for(int j=0;j<te[i].max;j++)
		{
			cout<<a[te[i].d[j]].obj_code<<"^";
		}
		cout<<"\n";
	}
}
	cout<<"E^"<<te[0].start_address<<endl;
}
int main(){
pass_one();
pass_two();
printt();
return 0;

}

