// coup.cpp

# include "coup.h"

namespace spc_dames
{
	void Coup::jouer(unsigned& id, Joueur* joueur) 
	{
		_id = id;
		_joueur = joueur;
		std::cout << std::endl;
	}
}
