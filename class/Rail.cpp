#include "Rail.h"

/**
 *	Construct from two times, price will be set afterwards. Used when creating
 *	rails between stations.
 *
 *	@param Time
 *	@param Time
 *	@param int  number of the train
 */
Rail::Rail(Time depart, Time &arrival)
{
	_train    = 0;
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
	_train    = 0;
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

int Rail::train() const
{
	return _train;
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

void Rail::setTrain(int train)
{
	_train = train;
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

/**
 *	A rail is a "trip", i.e. links two Stations, if it has a train number.
 *
 *	@return bool
 */
bool Rail::isTrip()
{
	return _train == 0;
}
