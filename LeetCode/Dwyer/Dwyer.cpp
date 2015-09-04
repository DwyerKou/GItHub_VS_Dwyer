// Dwyer.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "QuickSort.h"
#include "PlateAFactory.h"
#include "PlateBFactory.h"
#include "Derived.h"
#include "DerivedDerived.h"
#include "Context.h"
#include "StrategyA.h"
#include "StrategyB.h"
int main()
{
	/*�麯��
	Base A;
	Base B;
	Derived C;
	Derived D;
	DerivedDerived dd;
	Base &e = C;
	Base *f = &D;
	Derived *g = &dd;
	g->print();
	g->show();
	e.print();
	f->print();*/

	//����ģʽ
	/* 
	Factory* A = new PlateAFactory();
	Plate *p = A->createPlate();
	Gift *pg = A->createGift();
	p->setPrice();
	pg->showGift();

	Factory* B = new PlateBFactory();
	Plate* q = B->createPlate();	
	Gift *qg = B->createGift();
	q->setPrice();
	qg->showGift();
    */

	//����ģʽ
	Context *c = new Context();
	Strategy *s = new StrategyA();
	c->setS(s);
	c->algorithm();
	s = new StrategyB();
	c->setS(s);
	c->algorithm();
	return 0;
}

