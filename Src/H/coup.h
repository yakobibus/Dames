// coup.h

# ifndef _COUP_H_
# define _COUP_H_ (1)

# include "cellule.h"
# include "input.h"
# include "joueur.h"
# include "pion.h"

namespace spc_dames
{
	class Coup
	{
	public :
		Coup() : _id(0), _joueur(nullptr), _pion(nullptr), _celluleDepart(nullptr), _celluleArrivee(nullptr) {}
		Coup(const unsigned& id, Joueur* joueurAddress, Pion* pionAddress, Cellule* scramblingCellAddress, Cellule* fallingCellAddress) 
			: _id(id), _joueur(joueurAddress), _pion(pionAddress), _celluleDepart(scramblingCellAddress), _celluleArrivee(fallingCellAddress) {}
		~Coup() = default;
		Coup(const Coup& c) = default;
		Coup& operator = (const Coup& c) = default;
		//
		bool isValidDepart(void) { std::cout << "Joueur " <<_joueur->couleurTexte()<<", pion "<<_celluleDepart->getMotifPion()<<"). \n"; return false; }
		void jouer(unsigned& id, Joueur* joueur);
	private :
		//Input     _input; /// TODO : ici
		unsigned  _id;
		Joueur*   _joueur ;
		Pion*     _pion ;
		Cellule*  _celluleDepart ;
		Cellule*  _celluleArrivee ;
	};
}

# endif // _COUP_H_
