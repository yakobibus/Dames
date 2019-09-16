// jeux.h

# ifndef _JEUX_H_
# define _JEUX_H_ (1)

# include "plateau.h"

namespace spc_dames
{
	class Jeux
	{
	public :
		bool jouer(void);
	private :
		Plateau _plateau;
	};
}

# endif  // _JEUX_H_
