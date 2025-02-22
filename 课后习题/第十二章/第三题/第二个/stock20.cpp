#include<iostream>
#include<cstring>
#include"stock20.h"

Stock::Stock()
{
	std::cout << "Default constructor called\n";
	company = new char[1];
	company[0] = '0';
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const char* co, long n, double pr)
{
	company = new char[std::strlen(co) + 1];
	strcpy_s(company, std::strlen(co) + 1, co);
	if (n < 0)
	{
		std::cout << "Number of shares can't be negative; "
			<< company << " shares set to 0.\n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}

Stock::Stock(const Stock& de)
{
	company = new char[std::strlen(de.company) + 1];
	strcpy_s(company, std::strlen(de.company) + 1, de.company);
	shares = de.shares;
	share_val = de.share_val;
	total_val = de.total_val;
}

Stock::~Stock()
{
	delete[] company;
}

Stock& Stock::operator=(const Stock& sr)
{
	company = new char[std::strlen(sr.company) + 1];
	strcpy_s(company, std::strlen(sr.company) + 1, sr.company);
	shares = sr.shares;
	share_val = sr.share_val;
	total_val = sr.total_val;
	return *this;
}

void Stock::buy(long num, double price)
{
	if (num < 0)
	{
		std::cout << "Number of shares purchased can't be negative. "
			<< "Transaction is aborted.\n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(long num, double price)
{
	using std::cout;
	if (num < 0)
	{
		cout << "Number of shares purchased can't be negative. "
			<< "Transaction is aborted.\n";
	}
	else if (num > shares)
	{
		cout << "You can't sel more than you have! "
			<< "Transaction is aborted.\n";
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}

const Stock& Stock::topval(const Stock& s)const
{
	if (s.total_val > total_val)
		return s;
	else
		return *this;
}

std::ostream& operator<<(std::ostream& os, const Stock& rs)
{
	using std::ios_base;
	ios_base::fmtflags orig = os.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = os.precision(3);

	os << "Company: " << rs.company
		<< " Shares: " << rs.shares << '\n'
		<< " Share Price: $" << rs.share_val;
	os.precision(2);
	os << " Total Worth: $" << rs.total_val << '\n';
	os.setf(orig, ios_base::floatfield);
	os.precision(prec);
	return os;
}