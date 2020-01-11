#include "File.h"

File::File(char *a)
{
	ofstream fout(a);	
	fout.close();
	char *n=new char[30];
	strcpy(n,a);
	this->setName(n);
}
void File::delet()
{
	remove(this->getName());
	/*reference :http://www.cplusplus.com/reference/cstdio/remove/ */
}
void File::w(char *a)
{
	ofstream out(getName(),ios_base::app);
	out<<a;
}
void File::r(char *a)
{
	ifstream fin(getName());
	fin.getline(a,999);
	cout<<getName()<<": ";
	for(int i=0;a[i]!='\0';i++)
		cout<<a[i];
}