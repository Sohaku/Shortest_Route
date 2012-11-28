#include "Rail.h"

/**
 *	Construct from two times, price will be set afterwards. Used when creating
 *	rails between stations.
 *
 *	@param Time
 *	@param Time
 */
Rail::Rail(Time depart, Time &arrival)
{
	_start    = depart;
	_duration = depart.duration(arrival);
	_price    = 0.0;
	_depart   = NULL;
	_arrival  = NULL;
}

/**
 *	Construct from two stations, with a duration. Price will be set to 0 as it
 *	a travel between two stations in a same city.
 *
 *	@param Station*
 *	@param Station*
 *	@param int
 */
Rail::Rail(Station *depart, Station *arrival, int duration)
{
	_start    = Time();
	_duration = duration;
	_price    = 0.0;
	_depart   = depart;
	_arrival  = arrival;
}

/**
 *	Clone constructor.
 *
 *	@param Rail
 *
Rail::Rail(const Rail &r)
{
	_start    = r.time();
	_duration = r.duration();
	_price    = r.price();
	_depart   = r.depart();
	_arrival  = r.arrival();
}
*/

// - Getters

Station* Rail::depart() const
{
	return _depart;
}

Station* Rail::arrival() const
{
	return _arrival;
}

int Rail::duration() const
{
	return _duration;
}

float Rail::price() const
{
	return _price;
}

const Time* Rail::start() const
{
	return &_start;
}

Time Rail::time() const
{
	return _start;
}

// - Setters

void Rail::setPrice(int price)
{
	// Price per minute	
	_price = price * _duration / 60;
}

void Rail::setDepart(Station *s)
{
	_depart = s;
}

void Rail::setArrival(Station *s)
{
	_arrival = s;
}

void Rail::setTrip(Station *d, Station *a)
{
	_depart  = d;
	_arrival = a;
}
