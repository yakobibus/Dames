// jeux.cpp

# include "jeux.h"

namespace spc_dames
{
	Jeux::Jeux() 
		: _placementDesJoueurs(ePlacementJoueurs::blancs_noirs)
		, _joueurs(NB_JOUEURS)
		, _pionsPtrs(NB_JOUEURS)
		, _damier(_placementDesJoueurs, _joueurs, _pionsPtrs)
		//
		, _pionsRefactoring(NB_JOUEURS)
	{
		_pionsPtrs.at(0) = (_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? &_pionsBlancs : &_pionsNoirs);
		_pionsPtrs.at(1) = (_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? &_pionsNoirs : &_pionsBlancs);

		_joueurs[0].set((_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? eCouleur::blanc : eCouleur::noir)
			, (_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? "BLANCS" : "NOIRS")
			, _pionsRefactoring.at(0)
		);
		_joueurs[1].set((_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? eCouleur::noir : eCouleur::blanc)
			, (_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? "NOIRS" : "BLANCS")
			, _pionsRefactoring.at(0)
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
