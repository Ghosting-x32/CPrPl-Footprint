#include<iostream>
#include"stack.h"
using std::cout;
using std::endl;

Stack::Stack()
{
	top = 0;
}

Stack::~Stack()
{
}

bool Stack::isempty()const
{
	if (top == 0 || top < 0)
		return true;
	else
		return false;
}

bool Stack::isfull()const
{
	if (top < MAX)
		return false;
	else
		return true;
}

bool Stack::push(const Item& item)
{
	if (top < MAX)
	{
		items[top++] = item;
		cout << "��ʣ�� " << MAX - top << " ������ռ䣡" << endl;
		return true;
	}
	else
		return false;
}

bool Stack::pop(Item& item)
{
	if (top > 0)
	{
		item = items[--top];
		cout << "��ʣ�� " << MAX - top << " ������ռ䣡" << endl;
		return true;
	}
	else
		return false;
}