#include<iostream>
#include"yhzh.h"
Yhzh::Yhzh()
{
	name = "no name";
	zaha = "no zaha";
	cuka = 0.0;
}

Yhzh::Yhzh(const std::string& mona, const std::string& mozh, double mock)
{
	name = mona;
	zaha = mozh;
	if (mock < 0 || mock == 0)
	{
		std::cout << "��û���κδ���\a\n";
		cuka = 0.0;
	}
	else
		cuka = mock;
	
}

Yhzh::~Yhzh()
{
}

void Yhzh::show()const
{
	using std::cout;
	using std::endl;
	using std::ios_base;
	ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = cout.precision(3);

	cout << "���������ǣ�" << name << endl;
	cout << "�˺��ǣ�" << zaha << endl;
	cout.precision(2);
	cout << "����ǣ�" << cuka << endl;
	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);
}

void Yhzh::cun(double pr) 
{
	if (pr > 0)
		cuka += pr;
	else
		std::cout << "��û�д����κο����\a\n";
}

void Yhzh::qu(double pr)
{
	using std::cout;
	using std::endl;
	if (pr < 0 || pr == 0)
		cout << "��û��ȡ���κο����\a\n";
	else if (pr > cuka)
		cout << "�㲻��ȡ���������Ŀ����\a" << endl;
	else
		cuka -= pr;
}