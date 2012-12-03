#ifndef VERTEX_H
#define VERTEX_H

#include <float.h>

#include "Rail.h"

class Rail;

class Vertex
{
	private :
		double _cost;
		Rail* _prec;
	
	public :
		Vertex();
		
		double cost() const;
		Rail*  prec() const;
		
		void set(double, Rail*&);
};

#endif
