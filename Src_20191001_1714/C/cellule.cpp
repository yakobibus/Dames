// cellule.cpp

# include <iostream>
# include "cellule.h"

namespace spc_dames
{ 
	void Motif::set(char* const motif) 
	{ 
		std::cout << ".";
		_motif = motif;
		memset(_motif, static_cast<char>(eDetailMotif::normal), TAILLE_CELLULE); 
		std::cout.flush();
	}
}

namespace spc_dames
{
	void Cellule::set(
		  const unsigned int& y
		, const unsigned int& x
		, const unsigned int& manoury
		, char* const motif
		, Pion* pion
	) 
	{ 
		std::cout << "m<"<<manoury<<">::("<<y<<", "<<x<<")";
		//_coordonnees.set(y, x, manoury); 
		//_motif.set(motif); 
		//std::cout << "...avant....";
		//_pion = pion;
		//std::cout << "...apres...";
		//////_pion->setMotif(); // ici ouvrir ?
		////std::cout << "[" << manoury << " ("<<y<<","<< x<<") <"<< pion <</*static_cast<char>(_pion->motif())<<*/"> "  << "" << "] .. ";
	}
}
