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
		//std::cout << " ...<"<<_adressePion<<">... ";
		_adresseMotif = cellMotifPtr;
		//std::cout << " ..(" << manoury << ":" << (_adressePion == nullptr ? '~' : (char)_adressePion->motif()) << ").. ";

		_adresseMotif->at(0) = DETAIL_MOTIF_NORMAL;
		_adresseMotif->at(2) = DETAIL_MOTIF_NORMAL;
		_adresseMotif->at(1) = (_adressePion == nullptr ? DETAIL_MOTIF_NORMAL : static_cast<char> (_adressePion->motif()));

		std::cout << " " << y << " " << x << " " << manoury << " " << cellMotifPtr->at(0) << cellMotifPtr->at(1) << cellMotifPtr->at(2) << " " << (pionPtr == nullptr ? "inoccupée" : (pionPtr->estLibre() == true ? "libre" : "occupe")) << " " ;
	}

	void Cellule::setCoordonnees(
		  const unsigned int& y
		, const unsigned int& x
		, const unsigned int& manoury
		//, char* const adresseMotif
		, Pion* adressePion
	) 
	{ 
		_coordonnees.set(y, x, manoury); // , adresseMotif);
		//_motif.set(adresseMotif, (_aspect == eAspectCellule::normal ? DETAIL_MOTIF_NORMAL : DETAIL_MOTIF_BOLD), (_adressePion != nullptr ? static_cast<char>(_adressePion->motif()) : (_aspect == eAspectCellule::normal ? DETAIL_MOTIF_NORMAL : DETAIL_MOTIF_BOLD)));
		_adressePion = adressePion;
		setMotif();
	}

	void Cellule::setMotif(int i)
	{
		_adresseMotif->at(0) = (_aspect == eAspectCellule::normal ? DETAIL_MOTIF_NORMAL : DETAIL_MOTIF_BOLD);
		_adresseMotif->at(2) = (_aspect == eAspectCellule::normal ? DETAIL_MOTIF_NORMAL : DETAIL_MOTIF_BOLD);
		_adresseMotif->at(1) = (_adressePion == nullptr ? (_aspect == eAspectCellule::normal ? DETAIL_MOTIF_NORMAL : DETAIL_MOTIF_BOLD) : static_cast<char>(_adressePion->motif()));

		//_motif.set(_motif.adresseMotif()
		//	, (_aspect == eAspectCellule::normal ? DETAIL_MOTIF_NORMAL : DETAIL_MOTIF_BOLD)
		//	, (_adressePion == nullptr ? (_aspect == eAspectCellule::normal ? DETAIL_MOTIF_NORMAL : DETAIL_MOTIF_BOLD) : static_cast<char>(_adressePion->motif())));
	}

	void Cellule::setMotif(void)
	{
		//_motif.set(_motif.adresseMotif(), (_aspect == eAspectCellule::normal ? DETAIL_MOTIF_NORMAL : DETAIL_MOTIF_BOLD), (_adressePion == nullptr ? (_aspect == eAspectCellule::normal ? DETAIL_MOTIF_NORMAL : DETAIL_MOTIF_BOLD) : static_cast<char>(_adressePion->motif())));
	}
}
