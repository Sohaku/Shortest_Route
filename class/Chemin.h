#ifndef CHEMIN_H
#define CHEMIN_H

#include "Rail.h"
#include "Vertex.h"

class Vertex;
class Rail;

class Chemin
{
	private :
		std::vector<Rail*> _rails;
		double             _cost;
		
	public :
		std::vector<Rail*> rails() const;
		double             cost()  const;
		
		void add(Vertex*);
};

#endif
