#ifndef FRANCHISEE_H_
#define FRANCHISEE_H_

#include <iostream>
using namespace std;
#include "Headquarters.h"

class franchisee : public Headquarters{
public:
	franchisee();
	virtual ~franchisee();
};

#endif /* FRANCHISEE_H_ */
