#ifndef D_H
#define D_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include "Item.h"
#include "File.h"
using namespace std;

class Folder:public Item
{
public:
	Folder(char *);
	void view();
	void makefolder(char *);
	void makefile(char *);
	Folder *makedir(char *);
	void w(char *);
	void r(char *);
	void remComposite(char *);
	Folder *goroot();
	//void save(char *);
	void save(char *);
	void details(char *&,int &)const;
	bool search(char *);
	void delet();
	//~Folder();
private:
	Item **arr;
	Folder *fd;
	int n;
};
#endif