// dames.h

# ifndef DAMES_H
# define DAMES_H  (1)

# include "plateau.h"

using namespace spc_plateau ;

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
		int jouer(void);
	private:
		bool _finDePartie = false;
		TblPlateau _plateau ;
	};
}

# endif //DAMES_H
