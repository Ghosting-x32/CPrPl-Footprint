#ifndef MYTIME1_H_
#define MYTIME1_H_




class Time
{
private:
	int hours;
	int minutes;

public:
	Time();
	Time(int h, int m = 0);
	~Time();
	void addMin(int m);
	void addHr(int h);
	void Reset(int h = 0, int m = 0);
	Time operator+(const Time& t)const;
	void Show()const;
};




#endif