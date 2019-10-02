// dames.c

# include "dames.h"

using namespace spc_dames ;

int main (int argc, char** argv)
{
    int retCode = 0;

	Dames dames;

	retCode = dames.jouer();

	//std::cout << "...ici...\n";
	//std::cout.flush();

    return retCode ;
}

namespace spc_dames
{
	int Dames::jouer(void)
	{
		_finDePartie = _jeux.jouer();

		//std::cout << "...ici.1..\n";
		//std::cout.flush();


		return 0;
	}
}
