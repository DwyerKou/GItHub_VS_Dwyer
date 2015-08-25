// Dwyer.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "QuickSort.h"
#include "PlateAFactory.h"
#include "PlateBFactory.h"
int main()
{
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
    return 0;
}

