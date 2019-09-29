// dames.h

# ifndef DAMES_H
# define DAMES_H  (1)

# include "jeux.h"

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
		Jeux _jeux;
		bool _finDePartie = false;
	};
}

# endif //DAMES_H
