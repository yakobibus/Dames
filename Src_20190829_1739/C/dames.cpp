// dames.c

# include <iostream>
# include "dames.h"

using namespace spc_dames ;

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
}

/*
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
*/
