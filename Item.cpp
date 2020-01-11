#include "Item.h"
#include "File.h"
#include "Folder.h"

Item::Item()
{
	n=new char[20];
	for (int i=0; i<20;i++)
		n[i]='\0';
}
void Item::setName(char *a)
{	
	for (int i=0;a[i]!='\0';i++)
		n[i]=a[i];
}
void Item::printName(char *a)
{	
	cout<<a<<endl;
}
char *Item::getName()const
{
	return n;
}