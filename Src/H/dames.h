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

// ----------------------------------------------------------------------------

# include <iostream>
# include <fstream>

namespace spc_fic
{
	class Fic
	{
	public :
		Fic() : _nomFic("./MyFic.json"), _path("./"), _fic("./Exe/MyFic.json") { if (_fic.is_open()) { std::cout << "Ouvert\n"; } else { std::cout << "Ferm� !\n"; } }
		~Fic() = default ; 
		Fic(const Fic& f) = default;
		Fic& operator = (const Fic& f) = default;
	private :
		std::string   _nomFic;
		std::string   _path;
		std::ifstream _fic; //  ("./MyFic.json", ios::binary);
	};
}

namespace spc_pour_voir
{
# include <iostream>
# include <vector>

# define MOTIF_PLATEAU_DAMIER_X \
            { \
               ' ', ' ', ' ', ' ', ' ', 'a', ' ', ' ', ' ', 'b', ' ', ' ', ' ', 'c', ' ', ' ', ' ', 'd', ' ', ' ', ' ', 'e', ' ', ' ', ' ', 'f', ' ', ' ', ' ', 'g', ' ', ' ', ' ', 'h', ' ', ' ', ' ', 'i', ' ', ' ', ' ', 'j', ' ', ' ', ' ', ' ', ' ', '\n'        \
            ,  ' ', ' ', ' ', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', ' ', ' ', ' ', '\n'  	   \
            ,  '1', '0', ' ', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', '1', '0', '\n'  	   \
            ,  ' ', ' ', ' ', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', ' ', ' ', ' ', '\n'  	   \
            ,  ' ', '9', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', ' ', '9', ' ', '\n'  	   \
            ,  ' ', ' ', ' ', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', ' ', ' ', ' ', '\n'  	   \
            ,  ' ', '8', ' ', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', '8', ' ', '\n'  	   \
            ,  ' ', ' ', ' ', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', ' ', ' ', ' ', '\n'  	   \
            ,  ' ', '7', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', ' ', '7', ' ', '\n'  	   \
            ,  ' ', ' ', ' ', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', ' ', ' ', ' ', '\n'  	   \
            ,  ' ', '6', ' ', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', '6', ' ', '\n'  	   \
            ,  ' ', ' ', ' ', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', ' ', ' ', ' ', '\n'  	   \
            ,  ' ', '5', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', ' ', '5', ' ', '\n'  	   \
            ,  ' ', ' ', ' ', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', ' ', ' ', ' ', '\n'  	   \
            ,  ' ', '4', ' ', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', '4', ' ', '\n'  	   \
            ,  ' ', ' ', ' ', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', ' ', ' ', ' ', '\n'  	   \
            ,  ' ', '3', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', ' ', '3', ' ', '\n'  	   \
            ,  ' ', ' ', ' ', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', ' ', ' ', ' ', '\n'  	   \
            ,  ' ', '2', ' ', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', '2', ' ', '\n'  	   \
            ,  ' ', ' ', ' ', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', ' ', ' ', ' ', '\n'  	   \
            ,  ' ', '1', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', '$', '$', '$', '|', ' ', ' ', ' ', '|', ' ', '1', ' ', '\n'  	   \
            ,  ' ', ' ', ' ', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', ' ', ' ', ' ', '\n'  	   \
            ,  ' ', ' ', ' ', ' ', ' ', 'a', ' ', ' ', ' ', 'b', ' ', ' ', ' ', 'c', ' ', ' ', ' ', 'd', ' ', ' ', ' ', 'e', ' ', ' ', ' ', 'f', ' ', ' ', ' ', 'g', ' ', ' ', ' ', 'h', ' ', ' ', ' ', 'i', ' ', ' ', ' ', 'j', ' ', ' ', ' ', ' ', ' ', '\0'  	   \
            }																																																								   

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
		char _ardoise [NB_X_REF_CELLULES* NB_Y_REF_CELLULES* (TAILLE_CELLULE + TAILLE_SEPARATEUR)] = MOTIF_PLATEAU_DAMIER_X ;
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

namespace spc_essais_vector
{
# define SZ_TRI (3)
# define SZ_SEP_TRI (1)
# define MTF_TRI \
    { \
       '1', '2', '3', ' ', '4', '5', '6', ' ', '7', '8', '9', '\n'        \
     , '4', '5', '6', ' ', '7', '8', '9', ' ', '1', '2', '3', '\n'        \
     , '7', '8', '9', ' ', '1', '2', '3', ' ', '4', '5', '6', '\n'        \
	 , '-', '-', '-', ' ', '-', '-', '-', ' ', '-', '-', '-', '\n'        \
     , '1', '2', '3', ' ', '4', '5', '6', ' ', '7', '8', '9', '\n'        \
     , '4', '5', '6', ' ', '4', '5', '6', ' ', '7', '8', '9', '\n'        \
     , '7', '8', '9', ' ', '4', '5', '6', ' ', '7', '8', '9', '\n'        \
	 , '-', '-', '-', ' ', '-', '-', '-', ' ', '-', '-', '-', '\n'        \
     , '1', '2', '3', ' ', '4', '5', '6', ' ', '7', '8', '9', '\n'        \
     , '4', '5', '6', ' ', '4', '5', '6', ' ', '7', '8', '9', '\n'        \
     , '7', '8', '9', ' ', '4', '5', '6', ' ', '7', '8', '9', '\n'        \
    }
# define MTF_TRI_CARRE \
    { \
       {{{'1', '2', '3'}, {'|'}}, {{'4', '5', '6'}, {'|'}}, {{'7', '8', '9'}, {'\n'}}}        \
     , {{{'4', '5', '6'}, {'|'}}, {{'7', '8', '9'}, {'|'}}, {{'1', '2', '3'}, {'\n'}}}        \
     , {{{'7', '8', '9'}, {'|'}}, {{'1', '2', '3'}, {'|'}}, {{'4', '5', '6'}, {'\n'}}}        \
	 , {{{'-', '-', '-'}, {'+'}}, {{'-', '-', '-'}, {'+'}}, {{'-', '-', '-'}, {'\n'}}}        \
     , {{{'3', '1', '2'}, {'|'}}, {{'4', '5', '6'}, {'|'}}, {{'7', '8', '9'}, {'\n'}}}        \
     , {{{'6', '4', '5'}, {'|'}}, {{'4', '5', '6'}, {'|'}}, {{'7', '8', '9'}, {'\n'}}}        \
     , {{{'9', '7', '8'}, {'|'}}, {{'4', '5', '6'}, {'|'}}, {{'7', '8', '9'}, {'\n'}}}        \
	 , {{{'-', '-', '-'}, {'+'}}, {{'-', '-', '-'}, {'+'}}, {{'-', '-', '-'}, {'\n'}}}        \
     , {{{'2', '3', '1'}, {'|'}}, {{'4', '5', '6'}, {'|'}}, {{'7', '8', '9'}, {'\n'}}}        \
     , {{{'5', '6', '4'}, {'|'}}, {{'4', '5', '6'}, {'|'}}, {{'7', '8', '9'}, {'\n'}}}        \
     , {{{'8', '9', '7'}, {'|'}}, {{'4', '5', '6'}, {'|'}}, {{'7', '8', '9'}, {'\n'}}}        \
    }

	class Trio
	{
	public:
		Trio() : _refTrio(_trioCarre.at(5).at(1).at(0)) {
			//std::cout << "_trio.size()=" << _trio.size() << "\n";
			_trioCarre.at(5).at(1).at(0).at(1) = 'X';
			_refTrio.at(0) = '=';
			_refTrio.at(2) = '#';
			std::cout << "_trioCarre.size()=" << _trioCarre.size() << "\n";
			for (unsigned int ii = 0; ii < _trioCarre.size(); ++ii)
			{
				//std::cout << "_trioCarre.at(" << ii << ").size() = " << _trioCarre.at(ii).size() << "\n";
				for (unsigned kk = 0; kk < _trioCarre.at(ii).size(); ++kk)
				{
					//std::cout << "_trioCarre.at(" << ii << ").at("<<kk<<").size() = " << _trioCarre.at(ii).at(kk).size() << "\n";
					for (unsigned zz = 0; zz < _trioCarre.at(ii).at(kk).size(); ++zz)
					{
						//std::cout << "_trioCarre.at("<<ii<<").at("<<kk<<").size()=" << _trioCarre.at(ii).at(kk).size() << "\n";
						for (char& c : _trioCarre.at(ii).at(kk).at(zz))
						{
							std::cout << c;
						}
					}
				}
				//std::cout << " <= " << _trioCarre.at(ii).size() << " ";
			}
			std::cout << "\n";
		}
		~Trio() = default;
		Trio(const Trio& t) = default;
		Trio& operator = (const Trio& t) = default;
	private:
		std::vector<char> _trio = MTF_TRI;
		std::vector<std::vector <std::vector < std::vector<char> > > > _trioCarre = MTF_TRI_CARRE;
		std::vector<char>& _refTrio;
	};
}

namespace spc_ctor2vars
{
	class MultiVars
	{
	public :
		MultiVars(const int& uno, const int& duo) : _uno(uno), _duo(duo) { std::cout << "Mv("<<_uno<<", "<<_duo<<")"; }
		~MultiVars() = default;
		MultiVars(const MultiVars& m) = default;
		MultiVars& operator = (const MultiVars& m) = default;
	private :
		int _uno;
		int _duo;
	};

	class MultiCall
	{
	public :
		MultiCall() : _un(1), _deux(2), _mv(_un, _deux) {}
		~MultiCall() = default;
		MultiCall(const MultiCall& m) = default;
		MultiCall& operator = (const MultiCall& m) = default;
	private :
		int       _un;
		int       _deux;
		MultiVars _mv;
	};
}


# endif //DAMES_H
