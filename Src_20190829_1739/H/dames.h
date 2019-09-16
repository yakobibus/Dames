// dames.h

# ifndef DAMES_H
# define DAMES_H  (1)

# include "joueurs.h"
# include "plateau.h"

namespace spc_dames
{
	class Dames
	{
	public:
		Dames() = default;
		~Dames() = default;
		Dames(const Dames& d) = default;
		Dames& operator = (const Dames& d) = default;
		//
		int jouer(void) { return 0;}
	private:
		bool _finDePartie = false;
		Plateau _plateau ;
		Joueur _joueurBlanc ;
		Joueur _joueurNoir ;
	};
}

# endif //DAMES_H

/*
# include "plateau.h"

using namespace spc_dames ;

*/
