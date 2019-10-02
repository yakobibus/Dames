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
	void Cellule::setCoordonnees(
		  const unsigned int& y
		, const unsigned int& x
		, const unsigned int& manoury
		, char* const adresseMotif
		, Pion* adressePion
	) 
	{ 
		_coordonnees.set(y, x, manoury, adresseMotif);
		_motif.set(adresseMotif, (_aspect == eAspectCellule::normal ? DETAIL_MOTIF_NORMAL : DETAIL_MOTIF_BOLD), (_adressePion != nullptr ? static_cast<char>(_adressePion->motif()) : (_aspect == eAspectCellule::normal ? DETAIL_MOTIF_NORMAL : DETAIL_MOTIF_BOLD)));
		_adressePion = adressePion;
		setMotif();
	}
	void Cellule::setMotif(void)
	{
		_motif.set(_motif.adresseMotif(), (_aspect == eAspectCellule::normal ? DETAIL_MOTIF_NORMAL : DETAIL_MOTIF_BOLD), (_adressePion == nullptr ? (_aspect == eAspectCellule::normal ? DETAIL_MOTIF_NORMAL : DETAIL_MOTIF_BOLD) : static_cast<char>(_adressePion->motif())));
	}
}
