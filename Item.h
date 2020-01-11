#ifndef I_H
#define I_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

class File;

class Item
{
public:
	Item();
	char *getName()const;
	void setName(char *);
	//virtual void details(char *)=0;
	void printName(char *);
	virtual void w(char *)=0;
	virtual void r(char *)=0;
	virtual void delet()=0;
	//~Item();
private:
	char *n;
};
#endif