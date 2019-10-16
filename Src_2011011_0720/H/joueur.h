// joueur.h

# ifndef _JOUEUR_H_
# define _JOUEUR_H_ (1)

# include "constantes.h"

namespace spc_dames
{
	class Joueur
	{
	public :
		void set(eCouleur couleur) { _couleur = couleur; }
	private :
		eCouleur _couleur;
	};
}

# endif // _JOUEUR_H_
