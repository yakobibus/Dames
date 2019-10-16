// ardoise.cpp

# include "ardoise.h"
# include "constantes.h"
# include "pion.h"


namespace spc_dames
{
	void Ardoise::afficher(void) 
	{ 
		std::cout << std::endl;
		for (unsigned int ii = 0; ii < _ardoise.size(); ++ii)
		{
			for (unsigned int jj = 0; jj < _ardoise.at(ii).size(); ++jj)
			{
				for (char& c : _ardoise.at(ii).at(jj))
				{
					std::cout << c;
				}
			}
		}
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
		int manoury = 0;
		int y = 10;
		int x = 99;

		unsigned int iiNord = 0;
		unsigned iiSud = 0;

		Pion* pionPtr = nullptr ;

		for (Cellule& currentCell : _cellules)
		{
			++manoury;
			x = y % 2 == 0 ? (x > 8 ? 2 : x + 2) : (x > 7 ? 1 : x + 2);

			if (y <= 10 && y >= 7)
			{
				pionPtr = (_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? &_pionsBlancs.at(iiNord++) : &_pionsNoirs.at(iiNord++));
				pionPtr->init(
					  (_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? eMotifDuPion::normalBlanc : eMotifDuPion::normalNoir)
					, manoury
					, eAspectDuPion::normal
					, eStatutDuPion::libre
				);
			}
			else
			{
				if (y <= 4 && y >= 1)
				{ 
					pionPtr = (_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? &_pionsNoirs.at(iiSud++) : &_pionsBlancs.at(iiSud++));
					pionPtr->init(
						  (_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? eMotifDuPion::normalNoir : eMotifDuPion::normalBlanc)
						, manoury
						, eAspectDuPion::normal
						, eStatutDuPion::libre
					);
				}
				else
				{
					pionPtr = nullptr ;
				}
			}

			currentCell.initCell(y, x, manoury, _cellMotifPtrs.at(-1 + manoury), pionPtr);
			if (manoury % 5 == 0) { --y; }
		}
	}
}
