#ifndef STATION_H
#define STATION_H

#include <vector>
#include <string>
#include <map>

#include "Rail.h"

// Forward declarations
class Rail;

class Station
{
	private :
		std::string _name;
		std::map<std::string, Rail*> _out;
	
	public :
		Station(std::string&);
	
		std::string name();
		
		void addOut(std::string, Rail*);
};

class StationMap
{
	private :
		std::map<std::string, Station*> _list;
	
	public :
		unsigned int size();
		std::map<std::string, Station*>::iterator end();
		std::map<std::string, Station*>::iterator begin();
		
		bool contains(std::string);
		
		Station* add(std::string&);
		Station* get(std::string&);
		Station* find(const std::string&);
};

#endif
