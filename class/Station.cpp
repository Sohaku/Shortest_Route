#include "Station.h"

/****************************************
*************** Station *****************
****************************************/

Station::Station(std::string &name)
{
	_name = name;
}

std::string Station::name() const
{
	return _name;
}

std::map<std::string, Rail*> Station::rails() const
{
	return _out;
}

void Station::addOut(std::string name, Rail *r)
{
	_out.insert(std::pair<std::string, Rail*> (name, r));
}

/****************************************
************** StationMap **************
****************************************/

Station* StationMap::add(std::string &name)
{
	Station *res = NULL;
	std::map<std::string, Station*>::iterator find = _list.find(name);
	
	if (find == _list.end()) {
		res = new Station(name);
		
		_list.insert(std::pair<std::string, Station*> (name, res));
	} else {
		res = find->second;
	}
	
	return res;
}

std::map<std::string, Station*> StationMap::list() const
{
	return _list;
}

Station* StationMap::get(std::string &name)
{
	return _list.find(name)->second;
}

unsigned int StationMap::size()
{
	return _list.size();
}

std::map<std::string, Station*>::iterator StationMap::end()
{
	return _list.end();
}

std::map<std::string, Station*>::iterator StationMap::begin()
{
	return _list.begin();
}

Station* StationMap::find(const std::string &name)
{
	std::map<std::string, Station*>::iterator found = _list.find(name);
	Station* station = NULL;
	
	if (found != _list.end()) {
		station = found->second;
	}
	
	return station;
}
