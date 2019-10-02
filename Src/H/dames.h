// dames.h

# ifndef DAMES_H
# define DAMES_H  (1)

# include "jeux.h"

namespace spc_pour_voir
{
# include <iostream>
# include <vector>
	class Voir
	{
	public :
		void set(char* z) { _z = z; }
		char* get(void) { return _z; }
		void place(const char& c) { _z[1] = c; }
	private :
		char* _z;
	};

	class PourVoir
	{
	public :
		PourVoir() : _voir(50) { memset(_dummy, 0, 4); }
		~PourVoir() = default;
		PourVoir(const PourVoir& p) = default;
		PourVoir& operator = (const PourVoir& p) = default;
		void affiche(void) { std::cout << _ardoise; std::cout.flush(); }
		void get(void);
		void set(void);
		void place(unsigned short& p, const char& c);
	private :
		char _ardoise [NB_X_REF_CELLULES* NB_Y_REF_CELLULES* (TAILLE_CELLULE + TAILLE_SEPARATEUR)] = MOTIF_PLATEAU_DAMIER;
		std::vector<Voir> _voir;
		char _dummy[4];
		//
		const unsigned int decalage(const unsigned int& y) const { return (y == 10 ? 2 : y == 9 ? 4 : y == 8 ? 6 : y == 7 ? 8 : y == 6 ? 10 : y == 5 ? 12 : y == 4 ? 14 : y == 3 ? 16 : y == 2 ? 18 : y == 1 ? 20 : 0); }
	};

	class Essayer
	{
	public :
		Essayer() { essai(); }
		~Essayer() = default;
		Essayer(const Essayer& e) = default;
		Essayer& operator = (const Essayer& e) = default;

		void essai(void)
		{
			_pourvoir.set();
			std::cout << std::endl;
			_pourvoir.affiche();
			std::cout << std::endl;
			_pourvoir.get();
			for (unsigned short ii = 0; ii < 20; ++ii)
			{
				_pourvoir.place(ii, 'x');
			}
			for (unsigned short ii = 29; ii < 50; ++ii)
			{
				_pourvoir.place(ii, 'o');
			}
			std::cout << std::endl;
			_pourvoir.get();
			std::cout << std::endl;
			_pourvoir.affiche();
		}
	private :
		PourVoir _pourvoir;
	};
}

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
