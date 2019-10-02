// coodonnees.cpp

# include <iostream>
# include "coordonnees.h"

namespace spc_dames
{
	void Coordonnees::set(const unsigned int& y, const unsigned int& x, const unsigned int& manoury, char* const adresseMotif) 
	{
		_y = y; 
		_x = x; 
		_manoury = manoury; 
		_adresseMotif = adresseMotif; 
	}
}
