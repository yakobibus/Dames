// dames.c

# include <iostream>
# include "dames.h"
# include "plateau.h"

class Essais
{
public :
	Essais() { f(); g(); }
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
			unsigned int fn(const unsigned int& i) const { return i; }
		};

		S st[5] = { {1, "Un solitaire"}, {3, "Trois trios"}, {5, "Cinq quintes"}, {7, "Sept septres"}, {9, "Neuf oeufs"} };
		S* sp = st;

		std::cout << "...[" << sp[sp->fn(2)].id << " + " << sp[2].z << "]..." << std::endl;
	}

	void g(void)
	{
		Coup coup;
		TableDeCoups tCoups;
		coup.set(nullptr, nullptr, nullptr, 0, nullptr, false);
		///coup.aaahhh(22);

		for (short int ii = 0; ii < 15; ++ii)
		{
			unsigned int n = tCoups.ajouterNouveauCoup();
			tCoups.getCoup(-1 + n)->set(nullptr, nullptr, nullptr, 0, nullptr, false);
		}
		
		tCoups.getCoup(2)->set(nullptr, nullptr, nullptr, 0, nullptr, false);
		tCoups.getCoup(-1 + tCoups.getArraySize())->set(nullptr, nullptr, nullptr, 0, nullptr, false);
		std::cout << "ArrSz==["<< tCoups.getArraySize() <<"]\n";
		///tCoups.getCoup(-1 + tCoups.getArraySize())->aaahhh(33);
		///tCoups.getCoup(3)->aaahhh();
		int x = tCoups.ajouterNouveauCoup();
		///tCoups.getCoup(x)->aaahhh(x);
		std::cout << " x = " << x << std::endl;
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

