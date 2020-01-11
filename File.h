#ifndef L_H
#define L_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include "Item.h"
using namespace std;

class File:public Item
{
public:
	File(char *);
	void w(char *);
	void r(char *);
	void delet();
	//~File();
};
#endif