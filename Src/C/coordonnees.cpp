// coodonnees.cpp

# include <iostream>
# include "coordonnees.h"

namespace spc_dames
{
	void Coordonnees::set(const YXM& yxm, const Manoury* manouryAddress)
	{
		_yxmAddress = &yxm;
		_manouryAddress = manouryAddress;
		_diagonales = _manouryAddress->getDiagonales(_yxmAddress->manoury); TODO: ajouter une fonction qui retourne un vector des Diagonales de la Manoury reçue
		_manouryAddress->getNeighbours(_manouryVoisines, _yxmAddress->manoury);
		//_adresseMotif = adresseMotif; 
	}
}
