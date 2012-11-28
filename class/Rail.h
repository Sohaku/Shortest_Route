#ifndef RAIL_H
#define RAIL_H

#include <vector>

#include "Station.h"
#include "Time.h"

// Forward declaration
class Station;
class Time;

class Rail
{
	private :
		Station *_depart, *_arrival;
		
		Time _start;
		
		int   _duration;
		float _price;
		
	public :
		Rail(Station*, Station*, int);
		Rail(Time, Time&);
		// Rail(const Rail&);
		
		// Getters
		int      duration() const;
		float    price()    const;
		Station* depart()   const;
		Station* arrival()  const;
		Time     time()     const;
		
		// Pointer getter
		const Time* start() const;
		
		// Setters
		void setPrice(int);
		void setDepart(Station*);
		void setArrival(Station*);
		void setTrip(Station*, Station*);
		void setTime(Time);
};

#endif
