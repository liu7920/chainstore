#ifndef HEADQUARTERS_H_
#define HEADQUARTERS_H_

#include <iostream>
using namespace std;
#include "article.h"

class Headquarters : public article{
public:
	Headquarters();
	int output(){
		return re();
	}
	void input(int in){
		inp(in);
	}
	void ss(int in){
		sub(in);
	}
	virtual ~Headquarters();

};

#endif /* HEADQUARTERS_H_ */
