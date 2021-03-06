// jeux.cpp

# include "jeux.h"

namespace spc_dames
{
	Jeux::Jeux() 
		: _placementDesJoueurs(ePlacementJoueurs::blancs_noirs)
		, _joueurs(NB_JOUEURS)
		, _damier(_placementDesJoueurs, _joueurs)
		, _pions(NB_JOUEURS)
	{
		_joueurs[0].set((_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? eCouleur::blanc : eCouleur::noir)
			, (_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? "BLANCS" : "NOIRS")
			, _pions.at(0)
		);
		_joueurs[1].set((_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? eCouleur::noir : eCouleur::blanc)
			, (_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? "NOIRS" : "BLANCS")
			, _pions.at(0)
		);
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
