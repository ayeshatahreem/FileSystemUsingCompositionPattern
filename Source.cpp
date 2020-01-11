#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include "Item.h"
#include "File.h"
#include "Folder.h"
using namespace std;

int foo(char [],char []);
char a[100],b[100],c[20],d[100][100]={0},e[100]={0};
bool ok=false,stats=true;
int l=0,m=0,x;

void main()
{
	Folder f("Root Directory");
	Folder *p=&f;
	ofstream myfout("record.txt", ios_base::app);
	ifstream myfin("record.txt");
	system("Color 8F");
	for(;!myfin.eof();m++) 
		myfin.getline(d[m],100);
	myfin.close();
	d[m][0]='\0';
	cout<<" *** File System Implementation *** "<<endl;
	if(m!=0)
		ok=true;
	cout<<" --- Commands are goroot,makefile,makefolder,makedirectory,readfile,writefile,view,remove --- "<<endl;
	p->view();
	while(stats)
	{
		if (ok==true&&l<m)
		{
			strcpy(a,d[l++]);
			if (l==m)
				ok=false;
		}
		else
		{
			cout<<p->getName()<<": ";
			cin.getline(a,99,'\n');
			f.save(a);
		}
		if (foo(a,b)==0)
			p=p->goroot();
		else if (foo(a,b)==1)
			p->makefile(b);
		else if (foo(a,b)==2)
			p->makefolder(b);
		else if (foo(a,b)==3)
			p=p->makedir(b);
		else if (foo(a,b)==4)
			p->r(b);
		else if (foo(a,b)==5)
		{
			if (ok==true)
			{
				strcpy(e,d[l++]);
				if (l==m) ok=false;
				strcat(b,"~");
				strcat(b,e);
			}
			p->w(b);
		}
		else if (foo(a,b)==6)
			p->view();
		else if (foo(a,b)==7)
			p->remComposite(b);
		else if (foo(a,b)==-1)
			cout<<"Invalid command"<<endl;
	}
}
int foo(char a[],char b[])
{
	if(strlen(a)==0)
		return -1; 
	for (int i=0;a[i]!=' '&&a[i]!='\0';i++)
	{	
		x=i;
		c[i]=a[i];
	}
	x++;
	c[x]='\0';
	for (int i=x,j=0;a[i]!='\0';i++,j++)
	{	
		b[j]=a[i];
		x=j;
	}
	x++;
	b[x]='\0';
	if (strcmp(c,"goroot")==0)
		return 0;
	else if (strcmp(c,"makefile")==0)
		return 1;
	else if (strcmp(c,"makefolder")==0)
		return 2;
	else if (strcmp(c,"makedirectory")==0)
		return 3;
	else if (strcmp(c,"readfile")==0)
		return 4;
	else if (strcmp(c,"writefile")==0)
		return 5;
	else if (strcmp(c,"view")==0)
		return 6;
	else if (strcmp(c,"remove")==0)
		return 7;
	else
		return -1;
}