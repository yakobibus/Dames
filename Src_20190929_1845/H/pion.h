// pion.h

# ifndef _PION_H_
# define _PION_H_ (1) 

# include <iostream>
# include "constantes.h"

namespace spc_dames
{
	enum class eAspectDuPion
	{
		  normal
		, promu
	};

	enum class eMotifDuPion
	{
		  normalBlanc = MOTIF_NORMAL_PION_BLANC
		, promuBlanc  = MOTIF_PROMU_PION_BLANC
		, normalNoir  = MOTIF_NORMAL_PION_NOIR
		, promuNoir   = MOTIF_PROMU_PION_NOIR
		, nonDefini   = ' '
	};

	enum class eStatutDuPion
	{
		  libre
		, pris
	};

	class Pion
	{
	public :
		Pion() : _aspect(eAspectDuPion::normal), _statut(eStatutDuPion::libre), _motif(eMotifDuPion::nonDefini) {}
		~Pion() = default;
		Pion(const Pion& p) = default;
		Pion& operator = (const Pion& p) = default;
		//
		eMotifDuPion motif(void) { std::cout << " THE_MOTIF(" << (char)(_motif) << ") "; return _motif; }
		bool estLibre(void) const { return _statut == eStatutDuPion::libre ? true : false ; }
		void setMotif(eMotifDuPion motif); // { _motif = motif; }
	private :
		eAspectDuPion  _aspect;
		eStatutDuPion  _statut;
		eMotifDuPion   _motif ;
	};

}
# endif  // _PION_H_ 
