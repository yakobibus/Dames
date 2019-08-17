// diagonale.cpp

# include "diagonale.h"

namespace spc_diagonale
{
	Diagonale::~Diagonale()
	{
		if (_taille == 0)
		{
			delete _casesDamier;
			_taille = 0;
			_numero = 0;
			_casesDamier = nullptr;
		}
	}

	Diagonale::Diagonale(const Diagonale& d)
	{
		if (this != &d)
		{
			if (_taille > 0)
			{
				delete _casesDamier;
				_taille = 0;
				_numero = 0;
				_casesDamier = nullptr;
			}

			if (d._taille > 0)
			{
				_taille = d._taille;
				_numero = d._numero;
				_casesDamier = new CaseDamier * [_taille];
				for (unsigned int i = 0; i < _taille; ++i)
				{
					_casesDamier[i] = d._casesDamier[i];
				}
			}
		}
	}

	Diagonale& Diagonale::operator = (const Diagonale& d)
	{
		if (this != &d)
		{
			if (_taille > 0)
			{
				delete _casesDamier;
				_taille = 0;
				_numero = 0;
				_casesDamier = nullptr;
			}

			if (d._taille > 0)
			{
				_taille = d._taille;
				_numero = d._numero;
				_casesDamier = new CaseDamier * [_taille];
				for (unsigned int i = 0; i < _taille; ++i)
				{
					_casesDamier[i] = d._casesDamier[i];
				}
			}
		}
		return *this;
	}

	int Diagonale::addCase(CaseDamier* c)
	{
		Diagonale oldDiagonale = *this;

		if (_taille > 0)
		{
			delete _casesDamier;
			_taille = 0;
			_numero = 0;
			_casesDamier = nullptr;
		}

		_taille = 1 + oldDiagonale._taille;
		_numero = oldDiagonale._numero;
		_casesDamier = new CaseDamier * [_taille];
		for (unsigned int i = 0; i < oldDiagonale._taille; ++i)
		{
			_casesDamier[i] = oldDiagonale._casesDamier[i];
		}
		_casesDamier[-1 + _taille] = c;

		return _taille;
	}

	bool Diagonale::areContiguous(const CaseDamier& c1, const CaseDamier& c2) const
	{
		for (unsigned int ii = 0; ii < _taille; ++ii)
		{
			if (c1 == *(_casesDamier[ii]))
			{
				for (unsigned int jj = (ii == 0 ? 0 : -1 + ii); jj < ((1 + ii) < _taille ? 2 + ii : ii); ++jj)
				{
					if ((ii != jj) && (c2 == *(_casesDamier[jj])))
					{
						return true;
					}
				}
				break;
			}
		}

		return false;
	}

	//# include <cstdlib>  // for std::abs

	int Diagonale::countOfGapCells(const CaseDamier& c1, const CaseDamier& c2) const
		/*
		  Returning values :
		  - (DUMMY_GAPS) : the 2 cells aren't on the same diagonal
		  - (0)  : the 2 cells are the same
		  - (!=0) : the number of gap cells (1 : adjacent cells, 2 : one cell between them, n : -1+n cells between)
		**/
	{
		for (unsigned int ii = 0; ii < _taille; ++ii)
		{
			if (c1 == *(_casesDamier[ii]))
			{
				for (unsigned int jj = 0; jj < _taille; ++jj)
				{
					if (c2 == *(_casesDamier[jj]))
					{
						return ((c2.getY() - c1.getY()) < 0 ? -1 : 1) * std::abs(static_cast <long long> (ii - jj)); //  (static_cast<int>(ii - jj));
					}
				}
				break;
			}
		}

		return DUMMY_GAPS; // The 2 cells aren't on the same diagonal
	}

	int Diagonale::init(int taille, CaseDamier** c, int numero)
	{
		if (_taille > 0)
		{
			delete _casesDamier;
			_taille = 0;
			_numero = 0;
			_casesDamier = nullptr;
		}

		_taille = taille;
		_numero = numero;
		_casesDamier = new CaseDamier * [_taille];
		for (unsigned int i = 0; i < _taille; ++i)
		{
			_casesDamier[i] = c[i];
			_casesDamier[i]->setDiagonale(this);
		}

		return _taille;
	}
}
