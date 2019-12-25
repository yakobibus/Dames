// manoury.cpp

#include "manoury.h"

namespace spc_dames
{
	bool Manoury::areDiagonalized(const unsigned int& manouryOne, const unsigned int& manouryTwo) const
	{
		//TODO : il faudrait ICI donner l'ecart entre les manoury => plus besoin de fonction areNeighbors

		const std::vector<unsigned>& manouryOneFirstDiag = _diagonales.manouryDiagonales.at(_diagonales.diagonalesCellules.at(manouryOne).at(0));
		const std::vector<unsigned>& manouryOneLastDiag  = _diagonales.manouryDiagonales.at(_diagonales.diagonalesCellules.at(manouryOne).at(1));
		const std::vector<unsigned>& manouryTwoFirstDiag = _diagonales.manouryDiagonales.at(_diagonales.diagonalesCellules.at(manouryTwo).at(0));
		const std::vector<unsigned>& manouryTwoLastDiag  = _diagonales.manouryDiagonales.at(_diagonales.diagonalesCellules.at(manouryTwo).at(1));

		bool bReturn = false ;
		if((manouryOneFirstDiag.size() + manouryOneLastDiag.size()) < (manouryTwoFirstDiag.size() + manouryTwoLastDiag.size()) )
		{ // Parcours de manouryOne -- le plus court
			for (const unsigned& m : manouryOneFirstDiag)
			{
				if (m == manouryTwo)
				{
					bReturn = true;
					break;
				}
			}
			if (bReturn == false)
			{
				for (const unsigned& m : manouryOneLastDiag)
				{
					if (m == manouryTwo)
					{
						bReturn = true;
						break;
					}
				}
			}
		}
		else
		{ // Parcours de manouryTwo : le plus court
			for (const unsigned& m : manouryTwoFirstDiag)
			{
				if (m == manouryOne)
				{
					bReturn = true;
					break;
				}
			}
			if (bReturn == false)
			{
				for (const unsigned& m : manouryTwoLastDiag)
				{
					if (m == manouryOne)
					{
						bReturn = true;
						break;
					}
				}
			}
		}

		return bReturn;
	}

	bool Manoury::areNeighbors(const unsigned int& manouryOne, const unsigned int& manouryTwo, unsigned int& ecart)
		/*
		Les deux manoury sont voisines sur la diagonales, 
		en sortie ecart indique le nombre de cases qui separent les deux manoury
		code retour : true si les manoury sont voisines false sinon
		*/
	{
		if(areDiagonalized(manouryOne, manouryTwo))
		{
			;
		}
		else
		{
			;
		}

		return false;
	}

	unsigned int Manoury::getManoury(const YX& yx) const
	{
		unsigned int dizaines = static_cast <int>(5 - (yx.y / 2) - (yx.y % 2 != 0 ? 1 : 0));
		unsigned int unites = static_cast <int>((yx.y % 2 == 0 && yx.x % 2 == 0) || (yx.y % 2 != 0 && yx.x % 2 != 0) ? (yx.x / 2 + (yx.x % 2 != 0 ? 5 : -1)) : 99);
		unsigned int indice = static_cast <unsigned int> (dizaines * 10 + unites) ;
		return (indice <= _yxManoury.size() ? _yxManoury.at(indice).manoury : 0 ) ;
	}
}
