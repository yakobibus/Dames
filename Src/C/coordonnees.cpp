// coodonnees.cpp

# include <iostream>
# include "coordonnees.h"

namespace spc_dames
{
	void Coordonnees::set(const YXM& yxm) 
	{
		_yxmAdress = &yxm;
		//_diagonales = _yxmAdress->manoury.
		//Manoury m;
		//m.getNeighbours(_manouryVoisines, _yxmAdress->manoury);
		//_manouryVoisines = _yxmAdress->manoury.getNeighbours(_manouryVoisines, _yxmAdress->manoury);
		//_adresseMotif = adresseMotif; 
	}
}
