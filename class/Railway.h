#ifndef RAILWAY_H
#define RAILWAY_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

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
		void Pluscourt_cout(Station* depart, Station* arrive, std::set<Rail*> interdit);
		Station* get(const std::string&);
};

#endif
