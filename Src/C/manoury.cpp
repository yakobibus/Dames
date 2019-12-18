// manoury.cpp

#include "manoury.h"

namespace spc_dames
{
	bool Manoury::isDiagonalized(const unsigned int& manouryOne, const unsigned int& manouryTwo) const
	{
		bool bReturn = false;
		//for (const std::vector<std::vector<unsigned int>>& manoury : _diagonales.manouryDiagonales)
		return bReturn;
	}

	unsigned int Manoury::getManoury(YX yx) const
	{
		unsigned int dizaines = static_cast <int>(5 - (yx.y / 2) - (yx.y % 2 != 0 ? 1 : 0));
		unsigned int unites = static_cast <int>((yx.y % 2 == 0 && yx.x % 2 == 0) || (yx.y % 2 != 0 && yx.x % 2 != 0) ? (yx.x / 2 + (yx.x % 2 != 0 ? 5 : -1)) : 99);
		unsigned int indice = static_cast <unsigned int> (dizaines * 10 + unites) ;
		return (indice <= _yxManoury.size() ? _yxManoury.at(indice).manoury : 0 ) ;
	}
}
