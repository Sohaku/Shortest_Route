#include "Time.h"

Time::Time()
{
	_h   = 0;
	_min = 0;
}

/**
 *	Construct a Time from a formatted string : hh:mm.
 */
Time::Time(const std::string &time)
{
	_h   = atoi(time.substr(0, 2).c_str());
	_min = atoi(time.substr(3, 2).c_str());
}

/**
 *	Getters.
 */
int Time::h() const
{
	return _h;
}

int Time::min() const
{
	return _min;
}

/**
 *	Setters.
 */
void Time::h(const int h)
{
	_h = h;
}

void Time::min(const int min)
{
	_min = min;
}

void Time::set(const std::string data)
{
	
	_h   = atoi(data.substr(0, 2).c_str());
	_min = atoi(data.substr(3, 2).c_str());
}

/**
 *	Time is earlier when its hour is lower, or its hour is the same and
 *	minutes are lower.
 *
 *	@param Time
 *
 *	@return bool
 */
bool Time::operator < (const Time& t) const
{
	return _h  < t.h()
		|| (_h == t.h() && _min < t.min());
}

std::ostream& Time::operator << (std::ostream &os) const
{
	std::string h = "", min = "";
	
	if (_min < 10) {
		min  = '0';
		min += _min;
	}
	
	if (_h < 10) {
		h  = '0';
		h += _h;
	}
	
	return os << h << ':' << min;
}

/**
 *	Duration between now (this) and then (end). If end's parameters are in any
 *	way lower than this', it means it is anterior and we thus need to move 
 *	forward one day.
 *
 *	@param Time end date
 *
 *	@return int duration, in minute, between this and end
 */
int Time::duration(Time &end)
{
	int duration = 0;
	
	if (_h >= end.h() && _min > end.min()) {
		duration += Time::ONEDAY;
	}
	
	return duration + (end.h() - _h) * 60 + end.min() - _min;
}
