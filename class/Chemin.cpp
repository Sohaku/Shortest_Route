#include "Chemin.h"

double Chemin::cost() const
{
	return _cost;
}

std::vector<Rail*> Chemin::rails() const
{
	return _rails;
}

void Chemin::add(Vertex* node)
{
	_rails.push_back(node->prec());
	_cost += node->cost();
}
