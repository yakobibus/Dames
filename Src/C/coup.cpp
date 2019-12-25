// coup.cpp

# include "coup.h"

namespace spc_dames
{
	bool Coup::isValidDepart(void)
		/*  * : et, + : ou ; (ok)
		(*) La cellule départ est occupée (ok)
		(*) occupée par un pion de la couleur du joueur (ok)
		* Le pion est mobile : la case voisine en diagonale vers l'avant est libre ou le pion peut sauter
		  + la case voisine en diagonale vers l'avant est libre
		  + la voisine vers l'avant est occupée par un pion adverse et la case suivante dans la diagonale est libre
		  + le pion pointé est promu et les cases voisines successives dans la diagonale vers l'avant sont libres et la case suivante est occupée par un pion adverse suivi d'une case libre
		*/
	{
		if (_celluleDepart->getPionAddress() == nullptr) // Cellule départ occupée ?
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

		if (true) // Le pion est mobile (Cellule voisine libre vers l'avant) ou peut sauter (Voisine adverse suivie d'un vide ou promu et saut distant possible)
		{
		}
		std::cout << "_eMoveErrors = " << (int) _eMoveErrors << "\n";
		_isValidDepart = (
			_eMoveErrors == eMoveErrors::noErrors
			&& true  // Le joueur avance un pion de sa couleur : implique 
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
