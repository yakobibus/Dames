// ardoise.cpp

# include "ardoise.h"
# include "constantes.h"
# include "pion.h"


namespace spc_dames
{
	Ardoise::Ardoise(ePlacementJoueurs placementDesJoueurs)
		: _cellule(NB_CASES_PLATEAU)
		, _pionsBlancs(NB_PIONS_PAR_COULEUR)
		, _pionsNoirs(NB_PIONS_PAR_COULEUR)
		, _placementDesJoueurs(placementDesJoueurs)
	{
		for (Pion& pionB : _pionsBlancs)
		{
			pionB.setMotif(eMotifDuPion::normalBlanc);
			//std::cout << ":::" << static_cast<char>(pionB.motif()) << "::: ";
		}

		for (Pion& pionN : _pionsNoirs)
		{
			pionN.setMotif(eMotifDuPion::normalNoir);
			std::cout << ":::ici" << static_cast<char>(pionN.motif()) << "ici::: ";
		}
		//
		unsigned int ii_blanc = 0;
		unsigned int ii_noir = 0;
		unsigned int manoury = 0;
		for (unsigned int y = TAILLE_COTE_ARDOISE; y > 0; --y)
		{
			for (unsigned int x = 1; x <= TAILLE_COTE_ARDOISE; ++x)
			{
				if ((((y % 2) == 0) && ((x % 2) == 0)) || (((y % 2) != 0) && ((x % 2) != 0)))
				{
					_cellule[manoury].setCoordonnees(
						  y
						, x
						, 1 + manoury
						, &_ardoise[NB_CHAR_PAR_LIGNE * decalage(y) + (TAILLE_CELLULE + TAILLE_SEPARATEUR) * x]
						, y <= 4 || y >= 7 ? (_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? &_pionsBlancs[ii_blanc++]  : &_pionsNoirs[ii_noir++]) : nullptr
					);
					++manoury;
					if (y <= 4 || y >= 7) {
						std::cout << ":(" << static_cast<char>(_placementDesJoueurs == ePlacementJoueurs::blancs_noirs 
							? _pionsBlancs[(ii_blanc > 0 ? -1 : 0) + ii_blanc].motif() 
							:  _pionsNoirs[(ii_noir > 0 ? -1 : 0) + ii_noir].motif() ) << "): ";
					}
				}
			}
		}
	}
}

/*
namespace spc_dames
{
	void Ardoise::f(void)
	{
		unsigned int ii_blanc = 0;
		unsigned int ii_noir = 0;
		int y = 0;
		int x = 0;
		Pion& p = (y <= 4 || y >= 7 
			? (_placementDesJoueurs == ePlacementJoueurs::blancs_noirs 
				? &_pionsBlancs[ii_blanc++] 
				: &_pionsNoirs[ii_noir++]) 
			: nullptr
			);
	}
}
*/
//namespace spc_dames
//{

		// setMotif(21, 'x');

		/*
		unsigned int manoury = 0;
		for (unsigned int y = TAILLE_COTE_ARDOISE ; y > 0 ; --y)
		{
			for (unsigned int x = 1; x <= TAILLE_COTE_ARDOISE; ++x)
			{
				if ((((y % 2) == 0) && ((x % 2) == 0)) || (((y % 2) != 0) && ((x % 2) != 0)))
				{
					_cellule[manoury].setCoordonnees(y, x, 1 + manoury, &_ardoise[NB_CHAR_PAR_LIGNE * (12 - y) + (y%2 == 0 ? 8 : 4)]);
					char Motif[4] = {0, 0, 0, 0};
					memcpy(Motif, _cellule[manoury].getMotif(), 3);
					std::cout << "(" << 1 + manoury << ":" << y << "," << x << ") [" << Motif << "] (" << 12-y << ")";
					++manoury;
				}
			}
			std::cout << std::endl;
			char zzz[4];
			memset(zzz, 0, 4);
			memcpy(zzz, &_ardoise[104], 3); // 48 + 48 + 9 -1 = manoury 1, manoury 2 en + 8
			std::cout << "(" << zzz << ")" << std::endl; // en +5 (au lieu de +9 sur les lignes paires)sur lignes impaires ()
			memcpy(zzz, &_ardoise[112], 3); // manoury 2 en manoury 1 + 8
			std::cout << "(" << zzz << ")" << std::endl;
		}
		*/


		//for (Cellule& cellule : _cellule)
		//for (std::vector< Cellule >::iterator ii = _cellule.begin() ; ii != _cellule.end() ; ++ii)
		//for (unsigned int ii = 0 ; ii < NB_CASES_PLATEAU ; ++ii)
		//{
			//_cellule[ii] ;
			//std::cout << '.';
		//}
	//}
//}
