// diagonale.h

# ifndef _DIAGONALE_H_
# define _DIAGONALE_H_ (1)

# include "caseDamier.h"

namespace spc_caseDamier
{
	class CaseDamier;
}

namespace spc_diagonale
{
	using spc_caseDamier::CaseDamier;
	// --

	class Diagonale
	{
	public:
		Diagonale() : _casesDamier(nullptr), _numero(0), _taille(0) {}
		~Diagonale();
		Diagonale(const Diagonale& d);
		Diagonale& operator = (const Diagonale& d);
		//
		int addCase(CaseDamier* c);
		bool areContiguous(const CaseDamier& c1, const CaseDamier& c2) const;
		bool estDansLaDiagonale(const CaseDamier& c) const {for (unsigned int ii = 0; ii < _taille; ++ii) {if (*(_casesDamier[ii]) == c) { return true; }} return false; }
		int getNumero(void) const { return _numero; }
		int init(int taille, CaseDamier** c, int numero);
		int countOfGapCells(const CaseDamier& c1, const CaseDamier& c2) const;
	private:
		CaseDamier** _casesDamier;
		unsigned int _numero;
		unsigned int _taille;
	};
}
# endif // _DIAGONALE_H_
