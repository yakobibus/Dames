// ardoise.cpp

# include "ardoise.h"
# include "constantes.h"
# include "pion.h"


namespace spc_dames
{
	void Ardoise::afficher(void) 
	{ 
		std::cout << std::endl;
		std::cout << _ardoise; 
		std::cout << std::endl;
		std::cout.flush();
	}
}

namespace spc_dames
{
	Ardoise::Ardoise(ePlacementJoueurs placementDesJoueurs)
		: _cellules(NB_CASES_PLATEAU)
		, _pionsBlancs(NB_PIONS_PAR_COULEUR)
		, _pionsNoirs(NB_PIONS_PAR_COULEUR)
		, _placementDesJoueurs(placementDesJoueurs)
	{
		for (Pion& pionB : _pionsBlancs)
		{
			pionB.setMotif(eMotifDuPion::normalBlanc);
		}

		for (Pion& pionN : _pionsNoirs)
		{
			pionN.setMotif(eMotifDuPion::normalNoir);
		}
		int manoury = 0;
		int y = 10;
		int x = 99;

		unsigned int iiBlancs = 0;
		unsigned iiNoirs = 0;

		for (Cellule& currentCell : _cellules)
		{
			++manoury;
			x = y % 2 == 0 ? (x > 8 ? 2 : x + 2) : (x > 7 ? 1 : x + 2);
			currentCell.setCoordonnees(
				y
				, x
				, manoury
				, &_ardoise[NB_CHAR_PAR_LIGNE * decalage(y) + (TAILLE_CELLULE + TAILLE_SEPARATEUR) * x]
				, (y <= 10 && y >= 7 ? &_pionsBlancs[iiBlancs++] : (y <= 4 && y >= 1 ? &_pionsNoirs[iiNoirs++] : nullptr))
			);
			if (manoury % 5 == 0) { --y; std::cout << std::endl; }
		}
	}
}
