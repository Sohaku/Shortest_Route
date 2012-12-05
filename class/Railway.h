#ifndef RAILWAY_H
#define RAILWAY_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

#include "Time.h"
#include "Station.h"
#include "Vertex.h"
#include "Chemin.h"
// Forward declaration
class Rail;
class Station;
class StationMap;
class Vertex;
class Chemin;

class Railway
{
	private :
		StationMap         _stations;
		std::vector<Rail*> _rails;
		Chemin**		   _chemins;
		
	public :
		Railway(std::ifstream&, std::ifstream&);
		void Pluscourt_cout(Station* depart, Station* arrive, std::set<Rail*> interdit);
		Station* get(const std::string&);
};

#endif
