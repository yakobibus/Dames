// coodonnees.cpp

# include <iostream>
# include "coordonnees.h"

namespace spc_dames
{
	void Coordonnees::set(const YXM& yxm, const Manoury* manouryAddress)
	{
		_yxmAddress = &yxm;
		_manouryAddress = manouryAddress;
		_boardDiagonalsIndices = _manouryAddress->getAcrossDiagonals(_yxmAddress->manoury) ;
		_manouryAddress->getNeighbours(_manouryVoisines, _yxmAddress->manoury);
		//_adresseMotif = adresseMotif; 
	}
}
