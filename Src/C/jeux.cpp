// jeux.cpp

# include "jeux.h"

namespace spc_dames
{
	Jeux::Jeux() 
		: _damier(_placementJoueurs)
		, _joueurs(NB_JOUEURS)
		, _placementJoueurs(ePlacementJoueurs::blancs_noirs)
	{
		_joueurs[0].set(eCouleur::blanc); 
		_joueurs[0].set(eCouleur::noir); 
	}
}

namespace spc_dames
{
	bool Jeux::jouer(void)
	{
		_damier.afficher();
		return false;
	}
}
