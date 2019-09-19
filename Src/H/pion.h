// pion.h

# ifndef _PION_H_
# define _PION_H_ (1) 

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
	};

	enum class eStatutDuPion
	{
		  libre
		, pris
	};

	class Pion
	{
	public :
		Pion() : _aspect(eAspectDuPion::normal), _statut(eStatutDuPion::libre) {}
		~Pion() = default;
		Pion(const Pion& p) = default;
		Pion& operator = (const Pion& p) = default;
		//
		bool estLibre(void) const { return _statut == eStatutDuPion::libre ? true : false ; }
	private :
		eAspectDuPion  _aspect;
		eStatutDuPion  _statut;
	};

}
# endif  // _PION_H_ 
