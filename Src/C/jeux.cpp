// jeux.cpp

# include "jeux.h"

namespace spc_dames
{
	Jeux::Jeux()
		: _placementDesJoueurs(ePlacementJoueurs::blancs_noirs) // noirs_blancs  //  blancs_noirs
		, _joueurs(NB_JOUEURS)
		, _joueurEnCours(static_cast<eJoueurEnCours>((Couleur::eCouleur::blanc == static_cast <Couleur::eCouleur> (_placementDesJoueurs) ? Couleur::eCouleur::blanc : Couleur::eCouleur::noir)))
		, _pionsBlancs(NB_PIONS_PAR_COULEUR)
		, _pionsNoirs(NB_PIONS_PAR_COULEUR)
		, _damier(_placementDesJoueurs, _joueurEnCours, _joueurs, { (_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? &_pionsBlancs : &_pionsNoirs), (_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? &_pionsNoirs : &_pionsBlancs) })
		, _finDePartie(false)
	{
		_joueurs[0].set((_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? Couleur::eCouleur::blanc : Couleur::eCouleur::noir)
			, (_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? "BLANCS" : "NOIRS")
			, (_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? eSensAvance::positif : eSensAvance::negatif)
			, &_pionsBlancs
		);
		_joueurs[1].set((_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? Couleur::eCouleur::noir : Couleur::eCouleur::blanc)
			, (_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? "NOIRS" : "BLANCS")
			, (_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? eSensAvance::negatif : eSensAvance::positif)
			, &_pionsNoirs
		);
	}
}

namespace spc_dames
{
	bool Jeux::jouer(void)
	{
		do 
		{
			_damier.afficher();
			_coups.push_back(_dummyCoup);

			//Coup dummy;
			//_dummyCoup.push_back(dummy);

			//unsigned int i = 0;
			//dummy.jouer(i, &_joueurs.at(0)); // TODO : débarrasser le Coup du comportement .jouer() ... reporté dans le Damier
			//_finDePartie = false; 
			_finDePartie = _damier.jouer(_dummyCoup, _joueurEnCours); // TODO ... // ... sauf si c'est uniquement coup, puis damier ...  ; 
		} 
		while (_finDePartie);

		return _finDePartie;
	}
}

// 8 827 V8V  -- projet Ikea 
