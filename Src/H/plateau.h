// plateau.h


/* Le plateau de jeu et tout ce qui y touche : damier, pions joueurs ... */

# ifndef _PLATEAU_H_
# define _PLATEAU_H_ (1)

namespace spc_plateau
{
	class Regle
	{
	public:
		Regle() = default;
		~Regle() = default;
		Regle(const Regle& r) = default;
		Regle& operator = (const Regle& r) = default;
	private:
	};

	class Case
	{
	public:
		Case() = default;
		~Case() = default;
		Case(const Case& c) = default;
		Case& operator = (const Case& c) = default;
	private:
	};

	class Pion
	{
	public:
		Pion() = default;
		~Pion() = default;
		Pion(const Pion& p) = default;
		Pion& operator = (const Pion& p) = default;
	private:
	};

	class Plateau
	{
	public :
		Plateau() = default;
		~Plateau() = default;
		Plateau(const Plateau& p) = default;
		Plateau& operator = (const Plateau& p) = default;
		//
		void affiche(void);
	private :
	};
}

# endif // _PLATEAU_H_
