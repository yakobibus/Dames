// manoury.cpp

#include "manoury.h"

namespace spc_dames
{
	bool Manoury::isDiagonalized(const unsigned int& manouryOne, const unsigned int& manouryTwo) const
	{
		bool bReturnOne = false ;
		bool bReturnTwo = false;
		for (const std::vector <unsigned int> & d : _diagonales.manouryDiagonales) 
		{
			std::cout << " Diad.sz=["<<d.size()<<"] {";
			for (const unsigned int & m : d) 
			{
				if (m == manouryOne && ! bReturnOne) { bReturnOne = true; }
				if (m == manouryTwo && ! bReturnTwo) { bReturnTwo = true; }
				std::cout << ""<< m <<" ";
			}
			if (bReturnOne && bReturnTwo) { std::cout << " trouvE en d("<<d.size()<<") "; break; }
			else { bReturnOne = false; bReturnTwo = false;  }
			std::cout << "}\n";
		}
		return (bReturnOne && bReturnTwo);
	}

	unsigned int Manoury::getManoury(const YX& yx) const
	{
		unsigned int dizaines = static_cast <int>(5 - (yx.y / 2) - (yx.y % 2 != 0 ? 1 : 0));
		unsigned int unites = static_cast <int>((yx.y % 2 == 0 && yx.x % 2 == 0) || (yx.y % 2 != 0 && yx.x % 2 != 0) ? (yx.x / 2 + (yx.x % 2 != 0 ? 5 : -1)) : 99);
		unsigned int indice = static_cast <unsigned int> (dizaines * 10 + unites) ;
		return (indice <= _yxManoury.size() ? _yxManoury.at(indice).manoury : 0 ) ;
	}
}
