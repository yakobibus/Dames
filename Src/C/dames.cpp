// dames.c

# include "dames.h"

using namespace spc_dames ;

int main (int argc, char** argv)
{
    int retCode = 0;

	//spc_pour_voir::Essayer essai;
	//spc_ctor2vars::MultiCall mc;
	//spc_fic::Fic f;
	//spc_pour_voir::PourTiti t;

	Dames dames;

	retCode = dames.jouer();

    return retCode ;
}

namespace spc_dames
{
	int Dames::jouer(void)
	{
		_finDePartie = _jeux.jouer();

		return 0;
	}
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

void spc_manoury::Manou::titi(int y, int x)
{
	//int dizaine = (int)(5 - (y / 2) - (y % 2 != 0 ? 1 : 0));
	//int unite = (int)((y % 2 == 0 && x % 2 == 0) || (y % 2 != 0 && x % 2 != 0) ? (x / 2 + (x % 2 != 0 ? 6 : 0)) : 99);
	//std::cout << "(" << y << ", " << x << ") manoury -> [" << dizaine << " * 10 + " << unite << " : " << (dizaine * 10 + unite) << "]\n";
	unsigned int dizaine = (int)(5 - (y / 2) - (y % 2 != 0 ? 1 : 0));
	unsigned int unite = (int)((y % 2 == 0 && x % 2 == 0) || (y % 2 != 0 && x % 2 != 0) ? (x / 2 + (x % 2 != 0 ? 5 : -1)) : 99);
	std::cout << "(" << y << ", " << x << ") vector.at() -> ["<< dizaine << " * 10 + " << unite << " : " << (dizaine * 10 + unite) << "]\n";
}

