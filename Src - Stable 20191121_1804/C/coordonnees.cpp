// coodonnees.cpp

# include <iostream>
# include "coordonnees.h"

namespace spc_dames
{
	void Coordonnees::set(YXM& yxm) 
	{
		_yxmAdress = &yxm;
		//_adresseMotif = adresseMotif; 
	}
}
