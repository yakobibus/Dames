// coodonnees.cpp

# include "coordonnees.h"

namespace spc_dames
{
	void Coordonnees::set(const unsigned int& y, const unsigned int& x, const unsigned int& m, char* const mtf) 
	{
		_y = y; 
		_x = x; 
		_manoury = m; 
		_motif = mtf; 
	}
}
