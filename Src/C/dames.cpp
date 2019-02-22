// dames.c

# include <iostream>
# include "dames.h"
# include "plateau.h"

//using namespace spc_plateau ;
using namespace spc_dames  ;


class Essais
{
public :
	Essais() { f(); }
	~Essais() = default;
	Essais(const Essais& e) = default;
	Essais& operator = (const Essais& e) = default;
private :
	void f(void)
	{
		int t[4] = { 6, 4, 2, 0 };
		int* p = t;
		std::cout << "...[" << p[1] << "]..." << std::endl;

		struct S {
			int id;
			char z[55];
		};

		S st[5] = { {1, "Un solitaire"}, {3, "Trois trios"}, {5, "Cinq quintes"}, {7, "Sept septres"}, {9, "Neuf oeufs"} };
		S* sp = st;

		std::cout << "...[" << sp[2].id << " + " << sp[2].z << "]..." << std::endl;
	}
};


int main (int argc, char** argv)
{
	//Essais e;
	//return 0;
	//
    int retCode = 0;
	Dames dames;

	retCode = dames.jouer();

    return retCode ;
}

namespace spc_dames
{
	int Dames::jouer(void)
	{
		int retCode = 0;

		while (!_finDePartie)
		{
			_plateau.affiche();
			_finDePartie = ! (_plateau.coupSuivant());
			if (_plateau.getAbandon())
			{
				std::cout << "ABANDON" << std::endl;
				break;
			}
		}

		return retCode ;
	}
}

