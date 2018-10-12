// plateau.c

# include <iostream>
# include "plateau.h"

namespace spc_plateau
{
	void spc_plateau::CaseDamier::affiche(void)
	{
		std::cout << '(' << _y << ',' << _x << ')' << ' ' << (_couleur == CouleurCaseDamier::blanc ? "W" : "B") 
			      << (_estLibre ? "[ ]" 
					  : (_pion->couleur() == CouleurPion::blanc ? "[o]" 
					  : (_pion->couleur() == CouleurPion::noir ? "[x]" 
					  : (_pion->couleur() == CouleurPion::null ? "<z>" : "<?>"))))
			      << std::endl;
	}

	void CaseDamier::init(int x, int y, int notation, Pion * pion, ApparenceCase apparence, CouleurCaseDamier couleurCase, CouleurPion couleurPion)
	{
		_apparence = apparence ;
		_estLibre = (pion == nullptr ? true : false) ;
		_notationOfficielle = notation ;
		_pion = pion ;
		_x = x ;
		_y = y ;
		_couleur = couleurCase ;

		if (pion != nullptr)
		{
			pion->init(x, y, couleurPion, false);
		}
	}
}

namespace spc_plateau
{
	Plateau::Plateau(PositionsCouleursDepart positionsDepart)
	{
		_pionsNord = _pionsBlancs;
		_pionsSud = _pionsNoirs;
		_couleurPionsNord = CouleurPion::blanc;
		_couleurPionsSud = CouleurPion::noir;
		/* 
		Initialisation des casesDamier 
		------------------------------
		- La case 0 est blanche, les 50 suivantes noires ; 
		- Les pions couleur 1/2 dans les cases 1 à 20 et les couleur 2/2 de 31 à 50
		**/
		int iCaseDamier = 0;
		_casesDamier[iCaseDamier].init(0, 0, 0, nullptr, ApparenceCase::normal, CouleurCaseDamier::blanc, CouleurPion::null);

		for (int y = 10; y > 0; --y)       // ligne
		{
			for (int x = 1; x <= 10; ++x)  // colonne
			{
				if (0 == (y % 2))  // lignes paires  => colonnes paires uniquement
				{
					if (0 == (x % 2))
					{
						++iCaseDamier;
						_casesDamier[iCaseDamier].init(
							  x
							, y
							, iCaseDamier
							, (iCaseDamier >= 1 && iCaseDamier <= NB_PIONS_PAR_COULEUR) ? &(_pionsNord[-1 + iCaseDamier])
							: ((iCaseDamier >= 31 && iCaseDamier <= NB_CASES_PLATEAU) ? &(_pionsSud[-1 + iCaseDamier])
								: nullptr)
							, ApparenceCase::normal
							, CouleurCaseDamier::noir
							, (iCaseDamier >= 1 && iCaseDamier <= NB_PIONS_PAR_COULEUR) ? _couleurPionsNord
							: ((iCaseDamier >= 31 && iCaseDamier <= NB_CASES_PLATEAU) ? _couleurPionsSud
								: CouleurPion::null)
						);
					}
				}
				else  // lignes impaires => colonnes impaires
				{
					if (0 != (x % 2))
					{
						++iCaseDamier;
						_casesDamier[iCaseDamier].init(
							  x
							, y
							, iCaseDamier
							, (iCaseDamier >= 1 && iCaseDamier <= NB_PIONS_PAR_COULEUR) ? &(_pionsNord[-1 + iCaseDamier])
							: ((iCaseDamier >= 31 && iCaseDamier <= NB_CASES_PLATEAU) ? &(_pionsSud[-1 + iCaseDamier])
								: nullptr)
							, ApparenceCase::normal
							, CouleurCaseDamier::noir
							, (iCaseDamier >= 1 && iCaseDamier <= NB_PIONS_PAR_COULEUR) ? _couleurPionsNord
							: ((iCaseDamier >= 31 && iCaseDamier <= NB_CASES_PLATEAU) ? _couleurPionsSud
								: CouleurPion::null)
						);
					}
				}
			}
		}

		//initDiagonales();
	}
}

namespace spc_plateau
{
	CouleurPion Pion::couleur(void)
	{
		return _couleur ;
	}

	void Pion::init(int x, int y, CouleurPion c, bool p)
	{
		if (_couleur == CouleurPion::null) {
			_x = x;
			_y = y;
			if (_couleur != CouleurPion::null) { std::cout << "(" << _y << ", " << _x << ") Oooooppppssss !!!!!\n"; }
			_couleur = c;
			_promotion = p;
			std::cout << "Pion.Init("<<_y<<","<<_x<<")\n";
		}
		/*
		std::cout << "InitPion("<< _y <<", " << _x << " : " 
			<< (_couleur == CouleurPion::blanc ? "<o>" 
			: (_couleur == CouleurPion::noir ? "<x>" 
				: "<.>")) << ")" << std::endl;
		*/
	}
}

namespace spc_plateau
{
	void Plateau::affiche(void)
	{
		for (int i = 0; i <= NB_CASES_PLATEAU; ++i)
		{
			std::cout << i << ". ";
			_casesDamier[i].affiche();
		}
	}
}

