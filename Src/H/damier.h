// damier.h

# ifndef _DAMIER_H_
# define _DAMIER_H_ (1)

# include <vector>
//# include "caseDamier.h"
# include "ardoise.h"

namespace spc_dames
{
	class Damier
	{
	public:
		Damier() = default; // : _casesDamier(5) { for (unsigned ii = 0; ii < _casesDamier.size(); ++ii) { if (ii % 2 == 0) { _casesDamier[ii].setOccupe(); } else { _casesDamier[ii].setLibre(); } } }
		~Damier() = default;
		Damier(const Damier& d) = default;
		Damier& operator = (const Damier& d) = default;
		void afficher(void);
		//
		//void effaceMoi(void);
	private:
		//std::vector<CaseDamier>  _casesDamier; 
		Ardoise _ardoise;
	};
}

# endif  // _DAMIER_H_
