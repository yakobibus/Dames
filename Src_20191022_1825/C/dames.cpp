// dames.c

# include "dames.h"

using namespace spc_dames ;

int main (int argc, char** argv)
{
    int retCode = 0;

	//spc_pour_voir::Essayer essai;
	//spc_ctor2vars::MultiCall mc;

	Dames dames;

	retCode = dames.jouer();

    return retCode ;
}

namespace spc_pour_voir
{
	void PourVoir::get(void)
	{
		unsigned short ii = 0;
		for (Voir& v : _voir)
		{
			memcpy(_dummy, v.get(), 3);
			std::cout << ++ii << ".["  << _dummy << "]\n";
		}
	}

	void PourVoir::place(unsigned short& p, const char& c)
	{
		_voir.at(p).place(c);
		//_voir[p].place(c);
	}

	void PourVoir::set(void)
	{
		int manoury = 0;
		int y = 10;
		int x = 99;
		for (Voir& v : _voir)
		{
			++manoury;
			x = y % 2 == 0 ? (x > 8 ? 2 : x + 2) : (x > 7 ? 1 : x + 2);

			v.set(&_ardoise[NB_CHAR_PAR_LIGNE * decalage(y) + (TAILLE_CELLULE + TAILLE_SEPARATEUR) * x]);

			if (manoury % 5 == 0) { --y; std::cout << std::endl; }
		}
	}
}

namespace spc_dames
{
	int Dames::jouer(void)
	{
		_finDePartie = _jeux.jouer();

		return 0;
	}
}
