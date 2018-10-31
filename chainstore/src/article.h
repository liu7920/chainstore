#ifndef ARTICLE_H_
#define ARTICLE_H_
#include <iostream>
using namespace std;

class article {
	int Quantity;
public:
	article(){
		this->Quantity=0;
	}
	void input(int in){
		this->Quantity+=in;
	}
	int re(){
		return this->Quantity;
	}
	virtual ~article();
};

#endif /* ARTICLE_H_ */
