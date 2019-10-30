// jeux.cpp

# include "jeux.h"

namespace spc_dames
{
	Jeux::Jeux() 
		: _placementDesJoueurs(ePlacementJoueurs::blancs_noirs) // noirs_blancs  //  blancs_noirs
		, _joueurs(NB_JOUEURS)
		, _joueurEnCours( static_cast<eJoueurEnCours>((Couleur::eCouleur::blanc == static_cast <Couleur::eCouleur> (_placementDesJoueurs) ? Couleur::eCouleur::blanc : Couleur::eCouleur::noir)) )
		, _damier(_placementDesJoueurs, _joueurEnCours, _joueurs)
	{
		_joueurs[0].set((_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? Couleur::eCouleur::blanc : Couleur::eCouleur::noir)
			, (_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? "BLANCS" : "NOIRS")
			, &_pionsBlancs
		);
		_joueurs[1].set((_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? Couleur::eCouleur::noir : Couleur::eCouleur::blanc)
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

// 8 827 V8V  -- projet Ikea 
