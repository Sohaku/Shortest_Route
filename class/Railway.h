#ifndef RAILWAY_H
#define RAILWAY_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Time.h"
#include "Station.h"

// Forward declaration
class Rail;
class Station;
class StationMap;

class Railway
{
	private :
		StationMap         _stations;
		std::vector<Rail*> _rails;
		
	public :
		Railway(std::ifstream&, std::ifstream&);
		
		Station* get(const std::string&);
};

#endif
