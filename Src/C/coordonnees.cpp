// coodonnees.cpp

# include <iostream>
# include "coordonnees.h"

namespace spc_dames
{
	void Coordonnees::set(const YXM& yxm, Manoury* manouryAddress)
	{
		_yxmAdress = &yxm;
		_manouryAddress = manouryAddress;
		//_diagonales = _yxmAdress->manoury.
		//Manoury m;
		_manouryAddress->getNeighbours(_manouryVoisines, _yxmAdress->manoury);
		//_manouryVoisines = _yxmAdress->manoury.getNeighbours(_manouryVoisines, _yxmAdress->manoury);
		//_adresseMotif = adresseMotif; 
	}
}
