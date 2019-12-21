// manoury.cpp

#include "manoury.h"

namespace spc_dames
{
	bool Manoury::areDiagonalized(const unsigned int& manouryOne, const unsigned int& manouryTwo) const
	{
		//TODO : il faudrait ICI donner l'ecart entre les manoury => plus besoin de fonction areNeighbors
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

	const std::vector<unsigned>& Manoury::getDiagonale(const unsigned& indiceDiag) const
	{
		return _diagonales.manouryDiagonales.at(indiceDiag);
	}

	void Manoury::getDiagonales(const unsigned& manoury, std::vector <unsigned>& refDiagonales) const
	{
		//if (refDiagonales.size() > 0)
		//{
		refDiagonales.clear();
		//}
		switch (manoury)
		{
		case 1:
			refDiagonales.push_back(0);
			refDiagonales.push_back(13);
			break;
		case 2:
			refDiagonales.push_back(1);
			refDiagonales.push_back(12);
			break;
		case 3:
			refDiagonales.push_back(2);
			refDiagonales.push_back(11);
			break;
		case 4:
			refDiagonales.push_back(3);
			refDiagonales.push_back(10);
			break;
		case 5:
			refDiagonales.push_back(4);
			refDiagonales.push_back(9);
			break;
		case 6:
			refDiagonales.push_back(0);
			refDiagonales.push_back(14);
			break;
		case 7:
			refDiagonales.push_back(1);
			refDiagonales.push_back(13);
			break;
		case 8:
			refDiagonales.push_back(2);
			refDiagonales.push_back(13);
			break;
		case 9:
			refDiagonales.push_back(3);
			refDiagonales.push_back(12);
			break;
		case 10:
			refDiagonales.push_back(4);
			refDiagonales.push_back(11);
			break;
		case 11:
			refDiagonales.push_back(1);
			refDiagonales.push_back(14);
			break;
		case 12:
			refDiagonales.push_back(2);
			refDiagonales.push_back(13);
			break;
		case 13:
			refDiagonales.push_back(3);
			refDiagonales.push_back(12);
			break;
		case 14:
			refDiagonales.push_back(4);
			refDiagonales.push_back(11);
			break;
		case 15:
			refDiagonales.push_back(5);
			refDiagonales.push_back(10);
			break;
		case 16:
			refDiagonales.push_back(1);
			refDiagonales.push_back(15);
			break;
		case 17:
			refDiagonales.push_back(2);
			refDiagonales.push_back(14);
			break;
		case 18:
			refDiagonales.push_back(3);
			refDiagonales.push_back(13);
			break;
		case 19:
			refDiagonales.push_back(4);
			refDiagonales.push_back(12);
			break;
		case 20:
			refDiagonales.push_back(5);
			refDiagonales.push_back(11);
			break;
		case 21:
			refDiagonales.push_back(2);
			refDiagonales.push_back(15);
			break;
		case 22:
			refDiagonales.push_back(3);
			refDiagonales.push_back(14);
			break;
		case 23:
			refDiagonales.push_back(4);
			refDiagonales.push_back(13);
			break;
		case 24:
			refDiagonales.push_back(5);
			refDiagonales.push_back(12);
			break;
		case 25:
			refDiagonales.push_back(6);
			refDiagonales.push_back(11);
			break;
		case 26:
			refDiagonales.push_back(2);
			refDiagonales.push_back(16);
			break;
		case 27:
			refDiagonales.push_back(3);
			refDiagonales.push_back(15);
			break;
		case 28:
			refDiagonales.push_back(4);
			refDiagonales.push_back(14);
			break;
		case 29:
			refDiagonales.push_back(5);
			refDiagonales.push_back(13);
			break;
		case 30:
			refDiagonales.push_back(6);
			refDiagonales.push_back(12);
			break;
		case 31:
			refDiagonales.push_back(3);
			refDiagonales.push_back(16);
			break;
		case 32:
			refDiagonales.push_back(4);
			refDiagonales.push_back(15);
			break;
		case 33:
			refDiagonales.push_back(5);
			refDiagonales.push_back(14);
			break;
		case 34:
			refDiagonales.push_back(6);
			refDiagonales.push_back(13);
			break;
		case 35:
			refDiagonales.push_back(7);
			refDiagonales.push_back(12);
			break;
		case 36:
			refDiagonales.push_back(3);
			refDiagonales.push_back(17);
			break;
		case 37:
			refDiagonales.push_back(4);
			refDiagonales.push_back(16);
			break;
		case 38:
			refDiagonales.push_back(5);
			refDiagonales.push_back(15);
			break;
		case 39:
			refDiagonales.push_back(6);
			refDiagonales.push_back(14);
			break;
		case 40:
			refDiagonales.push_back(7);
			refDiagonales.push_back(13);
			break;
		case 41:
			refDiagonales.push_back(4);
			refDiagonales.push_back(17);
			break;
		case 42:
			refDiagonales.push_back(5);
			refDiagonales.push_back(16);
			break;
		case 43:
			refDiagonales.push_back(6);
			refDiagonales.push_back(15);
			break;
		case 44:
			refDiagonales.push_back(7);
			refDiagonales.push_back(14);
			break;
		case 45:
			refDiagonales.push_back(8);
			refDiagonales.push_back(13);
			break;
		case 46:
			refDiagonales.push_back(4);
			refDiagonales.push_back(18);
			break;
		case 47:
			refDiagonales.push_back(5);
			refDiagonales.push_back(17);
			break;
		case 48:
			refDiagonales.push_back(6);
			refDiagonales.push_back(16);
			break;
		case 49:
			refDiagonales.push_back(7);
			refDiagonales.push_back(15);
			break;
		case 50:
			refDiagonales.push_back(8);
			refDiagonales.push_back(14);
			break;
		}
	}

	unsigned int Manoury::getManoury(const YX& yx) const
	{
		unsigned int dizaines = static_cast <int>(5 - (yx.y / 2) - (yx.y % 2 != 0 ? 1 : 0));
		unsigned int unites = static_cast <int>((yx.y % 2 == 0 && yx.x % 2 == 0) || (yx.y % 2 != 0 && yx.x % 2 != 0) ? (yx.x / 2 + (yx.x % 2 != 0 ? 5 : -1)) : 99);
		unsigned int indice = static_cast <unsigned int> (dizaines * 10 + unites) ;
		return (indice <= _yxManoury.size() ? _yxManoury.at(indice).manoury : 0 ) ;
	}
}
