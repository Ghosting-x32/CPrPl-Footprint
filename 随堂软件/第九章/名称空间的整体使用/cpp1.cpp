﻿#include<iostream>
#include"biaotou.h"
void other(void);
void another(void);
int main(void)
{
	using debts::Debt;
	using debts::showDebt;
	Debt golf = { {"Benny", "Goatsniff"}, 120.0 };
	showDebt(golf);
	other();
	another();

	system("pause");
	return 0;
}

void other(void)
{
	using std::cout;
	using std::endl;
	using namespace debts;
	Person dg = { "Doodles", "Glister" };
	showPerson(dg);
	cout << endl;
	Debt zippy[3];
	int i;
	for (i = 0; i < 3; i++)
		getDebt(zippy[i]);
	for (i = 0; i < 3; i++)
		showDebt(zippy[i]);
	cout << "Total debt: $" << sumDebt(zippy, 3) << endl;
	return;
}

void another(void)
{
	using pers::Person;
	Person collector = { "Milo", "Rightshift" };
	pers::showPerson(collector);
	std::cout << std::endl;
}