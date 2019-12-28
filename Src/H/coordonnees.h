// coordonnees.h

# ifndef _COORDONNEES_H_
# define _COORDONNEES_H_ (1)

# include "constantes.h"
# include "manoury.h"

namespace spc_dames
{
	class Coordonnees
	{
	public:
		Coordonnees() : _yxmAdress(nullptr), _manouryAddress(nullptr) {}
		Coordonnees(YXM* yxm, Manoury* manouryAddress, char* motif) : _yxmAdress(yxm), _manouryAddress(manouryAddress) {}
		~Coordonnees() = default;
		Coordonnees(const Coordonnees& c) = default;
		Coordonnees& operator = (const Coordonnees& c) = default;
		// ---
		void set(const YXM& yxm, const Manoury* manouryAddress);
		Coordonnees& get(void) { return *this; }
		unsigned int getX(void) const { return _yxmAdress->yx.x; }
		unsigned int getY(void) const { return _yxmAdress->yx.y; }
		const YXM*         getXMaddress(void) const { return _yxmAdress; }
		unsigned int getManoury(void) const { return _yxmAdress->manoury; } 
		char         getXalpha(void) const { return 'a' + _yxmAdress->yx.x - 1; }
	private:
		const YXM*                         _yxmAdress ;
		const Manoury*                     _manouryAddress;
		std::vector<std::vector<unsigned>> _diagonales ;
		std::vector<unsigned>              _manouryVoisines ;

		// ici peut-être ptrMotif : _adresseMotif ?
	};
}

# endif // _COORDONNEES_H_
