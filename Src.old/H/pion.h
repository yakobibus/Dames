// pion.h

# ifndef _PION_H_
# define _PION_H_ (1)


# include "caseDamier.h"
# include "constantes.h"
# include "commonServices.h"

using spc_commonServices::CouleurPion;

namespace spc_caseDamier
{
	class CaseDamier;
}

namespace spc_pion
{
	using spc_caseDamier::CaseDamier;

	/* Un pion est déterminé par sa couleur et sa promotion */
	class Pion
	{
	public:
		Pion() : _case(nullptr), _couleur(CouleurPion::null), _promotion(false) {}
		~Pion() = default;
		Pion(const Pion& p) = default;
		Pion& operator = (const Pion& p) = default;
		//
		CouleurPion getCouleur(void) { return _couleur; }
		const bool& getPromotion(void) const { return _promotion; }
		void init(CaseDamier* const cd, CouleurPion c, bool p = false);
		const bool& isAqueen(void) const { return _promotion; }
		void setCase(CaseDamier* c);
	private:
		CaseDamier* _case;
		CouleurPion _couleur;
		bool _promotion;
	};
}


# endif   // _PION_H_
