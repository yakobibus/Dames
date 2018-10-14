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
			//<<"..."<< (*_pion)      
			<< std::endl;
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
	{
		int iPionsNord = 0; // Ittérateur pour les pions nord
		int iPionsSud = 0;  // Ittérateur pour les pions sud

		/* 
		Initialisation des casesDamier 
		------------------------------
		- La case 0 est blanche, les 50 suivantes noires ; 
		- Les pions couleur 1/2 dans les cases 1 à 20 et les couleur 2/2 de 31 à 50
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
							, (iCaseDamier >= 1 && iCaseDamier <= 20 ? &(_pionsNord [iPionsNord++])
								: (iCaseDamier >= 31 && iCaseDamier <= 50 ? &(_pionsSud [iPionsSud++])
									: nullptr))
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
							, (iCaseDamier >= 1 && iCaseDamier <= 20 ? &(_pionsNord[iPionsNord++])
								: (iCaseDamier >= 31 && iCaseDamier <= 50 ? &(_pionsSud[iPionsSud++])
									: nullptr))
							, ApparenceCase::normal
							, CouleurCaseDamier::noir
						);
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
	CouleurPion Pion::couleur(void)
	{
		//std::cout << "::"<<_y<<","<<_x<<"::\n";
		return _couleur ;
	}

	void Pion::init(int x, int y, CouleurPion c, bool p)
	{
		_x = x;
		_y = y;
		_couleur = c;
		_promotion = p;
		std::cout << "Pion.Init("<<_y<<","<<_x<<")\n";
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

	void Plateau::initPions(Pion* const pions, CaseDamier* const cases, CouleurPion& couleur)
	{
		for (int i = 0; i < NB_PIONS_PAR_COULEUR; ++i)
		{
			//if (cases[i].getPion() != &pions[i]) { std::cout << "Ecart d'adresse en (" << i << ")\n"; }
			//pions[i].init(cases[i].getX(), cases[i].getY(), couleur, false);
			if (cases[i].getPion() == nullptr) { 
				std::cout << "Ce Pion est NULL <"<<i<<">("<< cases[i].getY() <<", "<< cases[i].getX() 
					<<") prec=("<<cases[i-1].getY()<<", "<<cases[i-1].getX()<<")\n"; 
			}else
			cases[i].getPion()->init(cases[i].getX(), cases[i].getY(), couleur, false);
		}
	}
}

