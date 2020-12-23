#pragma once
#include"global.h"
class jiaocheng
{
public:
	jiaocheng(HANDLE);
	void readNext(int,int);
	void Print();
	void animeFordown(int);
	void animeForRight(int);
	void nmd(int);
private:
	HANDLE hOut;
};

