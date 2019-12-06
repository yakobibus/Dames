// coup.cpp

# include "coup.h"

namespace spc_dames
{
	bool Coup::isValidDepart(void)
	{
		if (_celluleDepart->getPionAddress() == nullptr) { _eMoveErrors = eMoveErrors::emptyStartingCell; } // Cellule départ occupée ?
		if (_joueur->eCouleur() == _celluleDepart->getPionAddress()->eCouleur()) { _eMoveErrors |= eMoveErrors::colorsMismatch; }
		_isValidDepart = (
			_eMoveErrors == eMoveErrors::noErrors
			&&   // Le joueur avance un pion de sa couleur : implique 
			&& true // Le pion départ est libre (ou peut sauter) 
			);
		
		return _isValidDepart;
	}

	void Coup::jouer(unsigned& id, Joueur* joueur)
	{
		_id = id;
		_joueur = joueur;
		std::cout << std::endl;
	}
}
