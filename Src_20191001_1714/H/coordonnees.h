// coordonnees.h

# ifndef _COORDONNEES_H_
# define _COORDONNEES_H_ (1)

# include "constantes.h"

namespace spc_dames
{
	class Coordonnees
	{
	public:
		Coordonnees() : _x(0), _y(0), _manoury(0) {}
		Coordonnees(unsigned int y, unsigned x, unsigned manoury, char* motif) : _x(x), _y(y), _manoury(manoury) {}
		~Coordonnees() = default;
		Coordonnees(const Coordonnees& c) = default;
		Coordonnees& operator = (const Coordonnees& c) = default;
		// ---
		void set(const unsigned int& y, const unsigned int& x, const unsigned int& manoury);
		Coordonnees& get(void) { return *this; }
		unsigned int getX(void) const { return _x; }
		unsigned int getY(void) const { return _y; }
		unsigned int getManoury(void) const { return _manoury; }
		char         getXalpha(void) const { return 'a' + _x - 1; }
	private:
		unsigned _x;
		unsigned _y;
		unsigned _manoury;
	};
}

# endif // _COORDONNEES_H_
