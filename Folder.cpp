#include "Folder.h"

Folder::Folder(char *a)
{
	arr=new Item*[50];
	fd=nullptr;
	n=0;
	this->setName(a);
}
Folder *Folder::goroot()
{
	cout<<"changing.."
	if (fd!=nullptr)	return fd;
	else cout<<"In root folder"<<endl;
	return this;
}
void Folder::makefolder(char *a)
{
	if (search(a)==true) 
	{
		Folder *b=new Folder(a);
		b->fd=this;
		arr[n]=b;
	     cout<<"changing.."
		n++;
		b=nullptr;
	}
	else
		cout<<"Already present"<<endl;
}
void Folder::makefile(char *a)
{
	char *b=new char[50];
	int q=0;
	for(int i=0;i<50;i++)
		b[i]='\0';
	this->details(b,q);
	strcat(b,a);
	cout<<"changing.."
	if (search(b)==true)
	{
		File *f=new File(b);
		arr[n]=f;
		n++;
		f=nullptr;
	}
	else
		cout<<"Already present"<<endl;
}
void Folder::w(char *a)
{
	char *c=new char[50],*g=new char[1000],f[100];
	char *v=nullptr;
	v=strstr(a,"~");
	int j,k=0,x,m;
	cout<<"changing.."
	if (v!=nullptr)
	{
		for (int i=0;a[i]!='~';i++)
			j=i;
		j++;
		k++;
		strcpy(f,v);
		a[j]='\0';
	}
	cout<<"changing.."
	for(int i=0;i<50;i++)
		c[i]='\0';
	this->details(c,m);
	strcat(c,a);
	if (search(c)==false)
	{
		cout<<"changing.."
		for (int i=0;i<n;i++)
		{
			if (strcmp(c,arr[i]->getName())==0)
				x=i;
		}
		if (k==0)
		{
			cout<<getName()<<":  ";
			cin.getline(g,999);
			save(g);
			arr[x]->w(g);
		}
		else
			arr[x]->w(f);
	}
	else
		cout<<"Not present"<<endl;
}
void Folder::r(char *a)
{
	char *b=new char[50];
	char c[1000];
	int x=0,y;
	cout<<"changing.."
	for(int i=0;i<50;i++)
		b[i]='\0';
	this->details(b,x);
	strcat(b,a);
	if (search(b)==true)
	{
		for (int i=0;i<n;i++)
		{
			if (strcmp(b,arr[i]->getName())==0)
				y=i;
		}
		arr[y]->r(c);
	cout<<"changing.."
	}
	else cout<<"Not present"<<endl;
}
Folder *Folder::makedir(char *a)
{
	int y;
	if (search(a)==false)
	{
		for (int i=0;i<n;i++)
		{
			if (strcmp(a,arr[i]->getName())==0)
				y=i;
		}
		//cout<<"changing.."
		Folder *f= (Folder*)arr[y];
		//cout<<"changing.."
		return f;
	}
	else
	{
	cout<<"changing.."
		cout<<"Not present"<<endl;
		return this;
	}
}
void Folder::view()
{
	int u=0;
	cout<<getName()<<": ";
	for(int i=0;i<n;i++)
	{
		u++;
		cout<<arr[i]->getName()<<" ";
	}
	cout<<endl;
	cout<<"changing.."
	if (u==0)
		cout<<"Empty folder"<<endl;
}
void Folder::save(char *a)
{
	ofstream myout("record.txt",ios_base::app);
	myout<<a<<endl;
	cout<<"changing.."
}
bool Folder::search(char *a)
{
	bool s=true;
	for (int i=0;i<n;i++)
	{
	cout<<"changing.."
		if (strcmp(a,arr[i]->getName())==0)
			s=false;
	}
	return s;
}
void Folder::details(char* &a,int &x)const
{
	char *b=new char[30];
	b=this->getName();
	if (fd!=nullptr)
	{
		for (int i=0;b[i]!='\0';i++)
		{
			a[x]=b[i];
			x++;
		}
		a[x]='#';
		x++;
		this->fd->details(a,x);
	}
	//else
}
void Folder::delet()
{
	for (int i=0;i<n;i++) arr[i]->delet();
}
void Folder::remComposite(char *a)
{
	char *b=nullptr,*c=new char[50];
	int d=0,x;
	b=strstr(a,".file");
	if (b!=nullptr)
	{
		for(int i=0;i<50;i++)
			c[i]='\0';
		//this->details(c,d);
		this->details(c,d);
		strcat(c,a);
		//strcpy(c,a);
		//strcat(a,c);
		strcpy(a,c);
	}
	if (search(a)==false)
	{
		for (int i=0;i<n;i++)
		{
			if (strcmp(a,arr[i]->getName())==0)
				x=i;
		}
		for (int i=x,j=x+1;j<n;)
		{
			swap(arr[i],arr[j]);
			i++;
			j++;
		}
		n--;
		arr[n]->delet();
		arr[n]=nullptr;
	}
	else
		cout<<"Not present"<<endl;
}