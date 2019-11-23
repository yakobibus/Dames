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
	void spc_dames::Cellule::initCell(YXM& yxm, std::vector<char>* cellMotifPtr, Pion* pionPtr)
	{
		_adressePion = pionPtr;
		_adresseMotif = cellMotifPtr;
		_coordonnees.set(yxm);

		setMotif();
	}

	void Cellule::setMotif(void)
	{
		_adresseMotif->at(0) = (_aspect == eAspectCellule::normal ? DETAIL_MOTIF_NORMAL : DETAIL_MOTIF_BOLD);
		_adresseMotif->at(2) = (_aspect == eAspectCellule::normal ? DETAIL_MOTIF_NORMAL : DETAIL_MOTIF_BOLD);
		_adresseMotif->at(1) = (_adressePion == nullptr ? DETAIL_MOTIF_NORMAL : static_cast<char> (_adressePion->motif()));
	}
}
