// manoury.cpp

#include "manoury.h"

namespace spc_dames
{
	bool Manoury::areDiagonalized(const unsigned int& manouryOne, const unsigned int& manouryTwo) const
	{
		//TODO : il faudrait ICI donner l'ecart entre les manoury => plus besoin de fonction areNeighbors

		bool bReturn = false ;

		if (manouryOne >= 1 && manouryOne <= 50 && manouryTwo >= 1 && manouryTwo <= 50)
		{
			const std::vector<unsigned>& manouryOneFirstDiag = _diagonales.boardsDiagonalsList.at(_diagonales.diagonalsAcrossAcell.at(manouryOne).at(0));
			const std::vector<unsigned>& manouryOneLastDiag = _diagonales.boardsDiagonalsList.at(_diagonales.diagonalsAcrossAcell.at(manouryOne).at(1));
			const std::vector<unsigned>& manouryTwoFirstDiag = _diagonales.boardsDiagonalsList.at(_diagonales.diagonalsAcrossAcell.at(manouryTwo).at(0));
			const std::vector<unsigned>& manouryTwoLastDiag = _diagonales.boardsDiagonalsList.at(_diagonales.diagonalsAcrossAcell.at(manouryTwo).at(1));

			if ((manouryOneFirstDiag.size() + manouryOneLastDiag.size()) < (manouryTwoFirstDiag.size() + manouryTwoLastDiag.size()))
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
		}

		return bReturn;
	}

	unsigned int Manoury::getManoury(const YX& yx) const
	{
		unsigned int dizaines = static_cast <int>(5 - (yx.y / 2) - (yx.y % 2 != 0 ? 1 : 0));
		unsigned int unites = static_cast <int>((yx.y % 2 == 0 && yx.x % 2 == 0) || (yx.y % 2 != 0 && yx.x % 2 != 0) ? (yx.x / 2 + (yx.x % 2 != 0 ? 5 : -1)) : 99);
		unsigned int indice = static_cast <unsigned int> (dizaines * 10 + unites) ;
		return (indice <= _yxManoury.size() ? _yxManoury.at(indice).manoury : 0 ) ;
	}

	std::vector<unsigned>& Manoury::getNeighbours(std::vector<unsigned>& neighboursRef, const unsigned& manouryRef) const
	{
		neighboursRef.clear();
		if (manouryRef >= 1 && manouryRef <= 50)
		{
			for (const unsigned& indice : _diagonales.diagonalsAcrossAcell.at(manouryRef))
			{
				for (unsigned ii = 0; ii < _diagonales.boardsDiagonalsList.at(indice).size(); ++ii)
				{
					if (manouryRef == _diagonales.boardsDiagonalsList.at(indice).at(ii))
					{
						if (ii > 0)
						{
							neighboursRef.push_back(_diagonales.boardsDiagonalsList.at(indice).at(-1 + ii));
						}

						if(ii + 1 < _diagonales.boardsDiagonalsList.at(indice).size())
						{
							neighboursRef.push_back(_diagonales.boardsDiagonalsList.at(indice).at(+1 + ii));
						}
					}
				}
			}
		}

		return neighboursRef;
	}


	//bool Manoury::hasAfreeNeighbour(const unsigned& manouryRef) const
	//{
	//	bool bReturn = false;
	//	if (manouryRef >= 1 && manouryRef <= 50)
	//	{
	//		const std::vector<unsigned>& manouryFirstDiag = _diagonales.manouryDiagonales.at(_diagonales.diagonalesCellules.at(manouryRef).at(0));

	//		const std::vector<unsigned>& manouryLastDiag = _diagonales.manouryDiagonales.at(_diagonales.diagonalesCellules.at(manouryRef).at(1));
	//	}
	//	
	//	return bReturn;
	//}
}
