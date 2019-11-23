// coup.h

# ifndef _COUP_H_
# define _COUP_H_ (1)

# include "cellule.h"
# include "joueur.h"
# include "pion.h"

namespace spc_dames
{
	class Coup
	{
	public :
		Coup() : _id(0), _joueur(nullptr), _pion(nullptr), _celluleDepart(nullptr), _celluleArrivee(nullptr) {}
		~Coup() = default;
		Coup(const Coup& c) = default;
		Coup& operator = (const Coup& c) = default;
		//
		void jouer(unsigned& id, Joueur* joueur);
	private :
		unsigned  _id;
		Joueur*   _joueur ;
		Pion*     _pion ;
		Cellule*  _celluleDepart ;
		Cellule*  _celluleArrivee ;
	};
}

# endif // _COUP_H_
