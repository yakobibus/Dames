// coup.cpp

# include "coup.h"

namespace spc_dames
{
	bool Coup::isValidDepart(void)
	{
		std::cout << "1 | 2 = " << (1 | 2) << "\n";
		if (_celluleDepart->getPionAddress() == nullptr) // Cellule d�part occup�e ?
		{ 
			_eMoveErrors = eMoveErrors::emptyStartingCell; 
		} 
		else
		{
			_eMoveErrors = (true == _celluleDepart->getPionAddress()->estLibre() ? _eMoveErrors : static_cast<eMoveErrors> (static_cast<unsigned> (_eMoveErrors) | static_cast<unsigned> (eMoveErrors::pawnIsCaptured)));

			if (_joueur->eCouleur() != _celluleDepart->getPionAddress()->eCouleur()) // Le joueur joue sa couleur
			{
				_eMoveErrors = static_cast<eMoveErrors> (static_cast<unsigned int> (_eMoveErrors) | static_cast<unsigned int> (eMoveErrors::colorsMismatch));
			}
		}

		if (true) // Le pion est active (Cellule voisine libre vers l'avant) ou peut sauter (Voisine adverse suivie d'un vide)
		{
		}
		std::cout << "_eMoveErrors = " << (int) _eMoveErrors << "\n";
		_isValidDepart = (
			_eMoveErrors == eMoveErrors::noErrors
			&& true  // Le joueur avance un pion de sa couleur : implique 
			&& true // Le pion d�part est libre (ou peut sauter) 
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
