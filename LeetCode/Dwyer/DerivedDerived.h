#pragma once

#include "Derived.h"
using std::cout;
using std::endl;
class DerivedDerived:public Derived
{
public:
	DerivedDerived();
	~DerivedDerived();
	void show() {
		cout << "show ���������" << endl;
	}
};

