// manoury.cpp

#include "manoury.h"

namespace spc_dames
{
	bool Manoury::areDiagonalized(const unsigned int& manouryOne, const unsigned int& manouryTwo) const
	{
		//TODO : il faudrait ICI donner l'ecart entre les manoury => plus besoin de fonction areNeighbors
		bool bReturn = false ;
		for (const unsigned& i : getDiagonales(manouryOne))
		{
			for (const unsigned& m : getDiagonale(i))
			{
				if (m == manouryTwo)
				{
					bReturn = true;
					break;
				}
			}
		}
		if (!bReturn)
		{
			for (const unsigned& i : getDiagonales(manouryTwo))
			{
				for (const unsigned& m : getDiagonale(i))
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
		/*
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
		return (bReturnOne && bReturnTwo);
		}
		*/
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
