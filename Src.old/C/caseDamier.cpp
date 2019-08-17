// caseDamier.cpp

# include "caseDamier.h"
# include "commonServices.h"

using spc_commonServices::CouleurPion;

namespace spc_caseDamier
{
	CaseDamier::CaseDamier()
		: _apparence(ApparenceCase::normal)
		, _cellule(nullptr)
		, _coordonnees(0, 0)
		, _couleur(CouleurCaseDamier::null)
		, _estLibre(true)
		, _nbDiagonales(0)
		, _notationOfficielle(0)
		, _pion(nullptr)
	{
		for (int ii = 0; ii < NB_DIAGONALES_MAX_PAR_CASE; ++ii)
		{
			_diagonale[ii] = nullptr;
		}
	}

	void spc_plateau::CaseDamier::affiche(void)
	{
		setCellule();
		char tmp[4];
		std::memset(tmp, 0, 4);
		std::memcpy(tmp, _cellule->motif, 3);
		std::cout << tmp;
	}

	int  CaseDamier::countOfGapCells(const CaseDamier& caseDamier) const
	{
		for (unsigned int ii = 0; ii < _nbDiagonales; ++ii)
		{
			if (_diagonale[ii]->estDansLaDiagonale(caseDamier))
			{
				return _diagonale[ii]->countOfGapCells(*this, caseDamier);
			}
		}
		return DUMMY_GAPS;  // the cells aren't on the same diagonal
	}

	void CaseDamier::init(const Coordonnees& coordonnees, int notation, Pion* pion, ApparenceCase apparence, CouleurCaseDamier couleurCase) // , CouleurPion couleurPion)
	{
		_apparence = apparence;
		_estLibre = (pion == nullptr ? true : false);
		_notationOfficielle = notation;
		_pion = pion;
		_coordonnees = coordonnees;
		_couleur = couleurCase;
	}

	bool CaseDamier::isContiguous(const CaseDamier& caseDamier) const
	{
		for (unsigned int ii = 0; ii < _nbDiagonales; ++ii)
		{
			if (_diagonale[ii]->areContiguous(*this, caseDamier))
			{
				return true;
			}
		}

		return false;
	}

	bool CaseDamier::isDiagonally(const CaseDamier& caseDamier) const
	{
		for (unsigned int ii = 0; ii < _nbDiagonales; ++ii)
		{
			if (_diagonale[ii]->estDansLaDiagonale(caseDamier))
			{
				return true;
			}
		}

		return false;
	}

	void CaseDamier::setCellule(void)
	{
		const char Blanc[] = " O ";
		const char blanc[] = " o ";
		const char Noir[] = " X ";
		const char noir[] = " x ";
		const char vide[] = ":::";
		const char bold_Blanc[] = "/O/";
		const char bold_blanc[] = "/o/";
		const char bold_Noir[] = "/X/";
		const char bold_noir[] = "/x/";
		const char bold_vide[] = "///";
		const char* const pMotif
			= (_apparence == ApparenceCase::surbillance
				? (_estLibre
					? bold_vide
					: (_pion->getPromotion()
						? (_pion->getCouleur() == CouleurPion::blanc ? bold_Blanc : bold_Noir)
						: (_pion->getCouleur() == CouleurPion::blanc ? bold_blanc : bold_noir)
						)
					) // fin AppCase::surbillance
				: (_estLibre
					? vide
					: (_pion->getPromotion()
						? (_pion->getCouleur() == CouleurPion::blanc ? Blanc : Noir)
						: (_pion->getCouleur() == CouleurPion::blanc ? blanc : noir)
						)
					) // fin ! AppCase::surbillance
				);
		std::memcpy(_cellule->motif, pMotif, 3);
	}

	void CaseDamier::setDiagonale(const Diagonale* diagonale)
	{
		for (unsigned int ii = _nbDiagonales; ii < NB_DIAGONALES_MAX_PAR_CASE; ++ii)
		{
			if (_diagonale[ii] == nullptr)
			{
				_diagonale[ii] = diagonale;
				++_nbDiagonales;
				break;
			}
		}
	}
}
