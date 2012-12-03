#include "Vertex.h"

Vertex::Vertex()
{
	_cost = DBL_MAX;
	_prec = NULL;
}

double Vertex::cost() const
{
	return _cost;
}

Rail* Vertex::prec() const
{
	return _prec;
}

void Vertex::set(double cost, Rail *&rail)
{
	_cost = cost;
	_prec = rail;
}
