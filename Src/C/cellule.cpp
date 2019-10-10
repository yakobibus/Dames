// cellule.cpp

# include <iostream>
# include "cellule.h"

namespace spc_dames
{ 
	void Motif::set(char* const adresseMotif, const char& bordMotif, const char& centreMotif)
	{ 
		_adresseMotif = adresseMotif;
		memset(_adresseMotif, bordMotif, TAILLE_CELLULE); 
		*(_adresseMotif + 1) = centreMotif;
	}
}

namespace spc_dames
{
	void Cellule::initCell(const unsigned int& y, const unsigned int& x, const unsigned int& manoury, std::vector<char>* cellMotifPtr, Pion* pionPtr)
	{
		setCoordonnees(y, x, manoury, pionPtr);
		_adressePion = pionPtr;
		_adresseMotif = cellMotifPtr;

		setMotif();
	}

	void Cellule::setCoordonnees(
		  const unsigned int& y
		, const unsigned int& x
		, const unsigned int& manoury
		, Pion* adressePion
	) 
	{ 
		_coordonnees.set(y, x, manoury); 
		_adressePion = adressePion;
	}

	void Cellule::setMotif(void)
	{
		_adresseMotif->at(0) = (_aspect == eAspectCellule::normal ? DETAIL_MOTIF_NORMAL : DETAIL_MOTIF_BOLD);
		_adresseMotif->at(2) = (_aspect == eAspectCellule::normal ? DETAIL_MOTIF_NORMAL : DETAIL_MOTIF_BOLD);
		_adresseMotif->at(1) = (_adressePion == nullptr ? DETAIL_MOTIF_NORMAL : static_cast<char> (_adressePion->motif()));
	}
}
