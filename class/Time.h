#ifndef TIME_H
#define TIME_H

#include <string>
#include <cstdlib>
#include <iostream>

class Time
{
	private :
		int _h;
		int _min;
		
	public :
		Time();
		Time(const std::string&);

		// Minutes in a day
		static const int ONEDAY = 24 * 60;
	
		int h() const;
		int min() const;
		
		void h(const int);
		void min(const int);
		void set(const std::string);
		
		int duration(Time&);
		
		// Comparator
		bool operator < (const Time&) const;
		// Display
		std::ostream& operator << (std::ostream&) const;
};

#endif
