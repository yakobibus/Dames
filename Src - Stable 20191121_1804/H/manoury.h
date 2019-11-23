// manoury.h


# ifndef _MANOURY_H_
# define _MANOURY_H_ (1)

# include <iostream>
# include <vector>
# include "constantes.h"

namespace spc_dames
{
	struct YX
	{
		unsigned int y ;
		unsigned int x ;
	};

	struct YXM
	{
		YX           yx ;
		unsigned int manoury;
	};

	class Manoury
	{
	public:
		Manoury() = default;
		~Manoury() = default;
		Manoury(const Manoury& m) = default;
		Manoury& operator = (const Manoury& m) = default;
		//
		std::vector< YXM>& getYxManouryReference(void) { return _yxManoury; }
	private:
		std::vector <YXM> _yxManoury = MOTIF_MANOURY;
	};
}

# endif // _MANOURY_H_
