// pion.cpp

# include "pion.h"

namespace spc_pion
{
	using spc_caseDamier::CaseDamier;
	// --
	void Pion::init(CaseDamier* const cd, CouleurPion c, bool p)
	{
		_case = cd;
		_couleur = c;
		_promotion = p;
	}
	void Pion::setCase(CaseDamier* c)
	{
		_case = c;
	}
}
