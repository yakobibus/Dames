// plateau.c

# include <iostream>
# include "plateau.h"

namespace spc_plateau
{
	void spc_plateau::CaseDamier::affiche(void)
	{
		setCellule();
		char tmp[4];
		std::memset(tmp, 0, 4);
		std::memcpy(tmp, _cellule->motif, 3);
		std::cout << tmp ;
	}

	void CaseDamier::init(int x, int y, int notation, Pion * pion, ApparenceCase apparence, CouleurCaseDamier couleurCase) // , CouleurPion couleurPion)
	{
		_apparence = apparence ;
		_estLibre = (pion == nullptr ? true : false) ;
		_notationOfficielle = notation ;
		_pion = pion ;
		_x = x ;
		_y = y ;
		_couleur = couleurCase ;
	}
	void CaseDamier::setCellule(void)
	{
		const char Blanc[] = " O ";
		const char blanc[] = " o ";
		const char Noir[] = " X ";
		const char noir[] = " x ";
		const char vide[] = ":::";
		const char bold_Blanc[] = "/O/";
		const char bold_blanc[] = "/o/";
		const char bold_Noir[] = "/X/";
		const char bold_noir[] = "/x/";
		const char bold_vide[] = "///";
		const char * const pMotif 
			= ( _apparence == ApparenceCase::surbillance 
				? (_estLibre 
					? bold_vide 
					: (_pion->getPromotion() 
						? (_pion->getCouleur() == CouleurPion::blanc ? bold_Blanc : bold_Noir)
						: (_pion->getCouleur() == CouleurPion::blanc ? bold_blanc : bold_noir)
						) 
					) // fin AppCase::surbillance
				: (_estLibre
					? vide
					: (_pion->getPromotion()
						? (_pion->getCouleur() == CouleurPion::blanc ? Blanc : Noir)
						: (_pion->getCouleur() == CouleurPion::blanc ? blanc : noir)
						)
					) // fin ! AppCase::surbillance
			);
		std::memcpy(_cellule->motif, pMotif, 3);
	}
}

namespace spc_plateau
{
	Plateau::Plateau(PositionsCouleursDepart positionsDepart)
		: _pionsNord(positionsDepart == PositionsCouleursDepart::blancs_noirs ? _pionsBlancs 
			: (positionsDepart == PositionsCouleursDepart::noirs_blancs ? _pionsNoirs 
				: nullptr ))
		, _pionsSud(positionsDepart == PositionsCouleursDepart::blancs_noirs ? _pionsNoirs
			: (positionsDepart == PositionsCouleursDepart::noirs_blancs ? _pionsBlancs
				: nullptr))
		, _couleurPionsNord(positionsDepart == PositionsCouleursDepart::blancs_noirs ? CouleurPion::blanc
			: (positionsDepart == PositionsCouleursDepart::noirs_blancs ? CouleurPion::noir
				: CouleurPion::null))
		, _couleurPionsSud(positionsDepart == PositionsCouleursDepart::blancs_noirs ? CouleurPion::noir
			: (positionsDepart == PositionsCouleursDepart::noirs_blancs ? CouleurPion::blanc
				: CouleurPion::null))
	{
		/* 
		Initialisation des casesDamier :
		------------------------------
		- La case 0 est blanche, les 50 suivantes noires ; 
		- Les pions couleur 1/2 dans les cases 1 à 20 et les couleur 2/2 de 31 à 50
		NB : le pointeur sur le pion reste null dans un premier temps
		**/

		int iCaseDamier = 0;
		_casesDamier[iCaseDamier].init(0, 0, 0, nullptr, ApparenceCase::normal, CouleurCaseDamier::blanc); //  , CouleurPion::null);

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
							, nullptr
							, ApparenceCase::normal
							, CouleurCaseDamier::noir
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
							, nullptr
							, ApparenceCase::normal
							, CouleurCaseDamier::noir
						);
					}
				}
			}
		}

		{
			// Initialisation des pointeurs de cellules dans les caseDamiers
			// y paire de [2 à 20] et x de [2 à 10 si y%4!=0, de 1 à 9 si y%4==0] => cellule
			for (int y = 2, iCase = 1 ; y <= 20; y += 2)
			{
				for (int x = 1; x <= 10; ++x)
				{
					if ((x % 2 == 0 && y % 4 != 0) || (x % 2 != 0 && y % 4 == 0))
					{
						_casesDamier[iCase].setCellule(&_cellules[y][x]);
						++iCase;
					}
				}
			}
		}

		initPions(_pionsNord, &_casesDamier[1], _couleurPionsNord);
		initPions(_pionsSud, &_casesDamier[31], _couleurPionsSud);

		//initDiagonales();
	}
}

namespace spc_plateau
{
	void Pion::init(CaseDamier* const cd, CouleurPion c, bool p)
	{
		_case = cd;
		_couleur = c;
		_promotion = p;
	}
	void Pion::setCase(CaseDamier* c)
	{
		_case = c;
	}
}

namespace spc_plateau
{
	void Plateau::affiche(void)
	{
		for (int iCase = 1; iCase < NB_CASES_PLATEAU; ++iCase)
		{
			_casesDamier[iCase].setCellule();
		}
		std::cout << _cellules[0][0].motif << std::endl;
	}

	void Plateau::initPions(Pion* const pions, CaseDamier* const cases, CouleurPion& couleur)
	{
		for (int i = 0; i < NB_PIONS_PAR_COULEUR; ++i)
		{
			pions[i].init(&cases[i], couleur, false);
			cases[i].setPion(&pions[i]);
		}
	}
}

