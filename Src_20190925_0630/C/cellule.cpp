// cellule.cpp

# include <iostream>
# include "cellule.h"

namespace spc_dames
{
	void Cellule::setCoordonnees(
		  const unsigned int& y
		, const unsigned int& x
		, const unsigned int& m
		, char* const mtf
		, Pion* pion
	) 
	{ 
		_coordonnees.set(y, x, m, mtf); 
		_motif.set(mtf); 
		_pion = pion;
		//_pion->setMotif();
		std::cout << "[" << m << " ("<<y<<","<< x<<") <"<< pion <</*static_cast<char>(_pion->motif())<<*/"> "  << "" << "] .. ";
	}
}
