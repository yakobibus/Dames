// plateau.c

# include <iostream>
# include "plateau.h"

namespace spc_plateau
{
	void CaseDamier::init(int x, int y, int notation, Pion * pion, ApparenceCase apparence, CouleurCaseDamier couleur)
	{
		_apparence = apparence ;
		_estLibre = (pion == nullptr ? true : false) ;
		_notationOfficielle = notation ;
		_pion = pion ;
		_x = x ;
		_y = y ;
		_couleur = couleur ;
	}
}

namespace spc_plateau
{
	Plateau::Plateau(PositionsCouleursDepart positionsDepart)
	{
		_pionsNord = _pionsBlancs;
		_pionsSud = _pionsNoirs;
		/* 
		Initialisation des casesDamier 
		------------------------------
		- La case 0 est blanche, les 50 suivantes noires ; 
		- Les pions couleur 1/2 dans les cases 1 à 20 et les couleur 2/2 de 31 à 50
		**/
		int iCaseDamier = 0;
		_casesDamier[iCaseDamier].init(0, 0, 0, nullptr, ApparenceCase::normal, CouleurCaseDamier::blanc);

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
							: ((iCaseDamier >= 31 && iCaseDamier < NB_CASES_PLATEAU) ? &(_pionsSud[-1 + iCaseDamier])
								: nullptr)
							, ApparenceCase::normal
							, CouleurCaseDamier::noir
						);
				/*
				*/
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
							: ((iCaseDamier >= 31 && iCaseDamier < NB_CASES_PLATEAU) ? &(_pionsSud[-1 + iCaseDamier])
								: nullptr)
							, ApparenceCase::normal
							, CouleurCaseDamier::noir
						);
					}
				/*
				*/
				}

				if ((0 == (y % 2) && 0 == (x % 2)) || (0 != (y % 2) && 0 != (x % 2)))
				{
					if (iCaseDamier >= 1 && iCaseDamier <= NB_PIONS_PAR_COULEUR)
					{
						/*
						_pionsBlancs[-1 + iCaseDamier].setCouleur(couleur_pion::blanc);
						_pionsBlancs[-1 + iCaseDamier].setApparence(apparence_pion::normal);
						_cases[iCaseDamier].setPion(&(_pionsBlancs[-1 + iCaseDamier]));
						_pionsBlancs[-1 + iCaseDamier].setSensAttaque(sens_attaque_pion::descendant);
						*/
					}
					else
					{
						if (iCaseDamier >= 31 && iCaseDamier < NB_CASES_PLATEAU)
						{
							/*
							_pionsNoirs[-1 + iCaseDamier].setCouleur(couleur_pion::noir);
							_pionsNoirs[-1 + iCaseDamier].setApparence(apparence_pion::normal);
							_cases[iCaseDamier].setPion(&(_pionsNoirs[-1 + iCaseDamier]));
							_pionsNoirs[-1 + iCaseDamier].setSensAttaque(sens_attaque_pion::ascendant);
							*/
						}
					}
				}
			}
		}

		//initDiagonales();
	}
}

namespace spc_plateau
{
	void Plateau::affiche(void)
	{
	}
}

