// cellule.cpp

# include <iostream>
# include "cellule.h"

namespace spc_dames
{ 
	void Motif::set(char* const mtf) 
	{ 
		_motif = mtf;
		memset(_motif, static_cast<char>(eDetailMotif::normal), TAILLE_CELLULE); 
	}
}

namespace spc_dames
{
	void Cellule::setCoordonnees(
		  const unsigned int& y
		, const unsigned int& x
		, const unsigned int& manoury
		, char* const motif
		, Pion* pion
	) 
	{ 
		_coordonnees.set(y, x, manoury, motif); 
		_motif.set(motif); 
		std::cout << "...avant....";
		_pion = pion;
		std::cout << "...apres...";
		////_pion->setMotif(); // ici ouvrir ?
		//std::cout << "[" << manoury << " ("<<y<<","<< x<<") <"<< pion <</*static_cast<char>(_pion->motif())<<*/"> "  << "" << "] .. ";
	}
}
