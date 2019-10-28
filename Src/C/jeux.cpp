// jeux.cpp

# include "jeux.h"

namespace spc_dames
{
	Jeux::Jeux() 
		: _placementDesJoueurs(ePlacementJoueurs::blancs_noirs) // noirs_blancs  //  blancs_noirs
		, _joueurs(NB_JOUEURS)
		, _joueurEnCours( static_cast<eJoueurEnCours>((eCouleur::blanc == static_cast <eCouleur> (_placementDesJoueurs) ? eCouleur::blanc : eCouleur::noir)) )
		, _damier(_placementDesJoueurs, _joueurEnCours, _joueurs)
	{
		_joueurs[0].set((_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? eCouleur::blanc : eCouleur::noir)
			, (_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? "BLANCS" : "NOIRS")
			, &_pionsBlancs
		);
		_joueurs[1].set((_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? eCouleur::noir : eCouleur::blanc)
			, (_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? "NOIRS" : "BLANCS")
			, &_pionsNoirs
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
