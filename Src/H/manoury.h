// manoury.h


# ifndef _MANOURY_H_
# define _MANOURY_H_ (1)

# include <iostream>
# include <vector>

namespace spc_dames
{
	struct YX
	{
		unsigned int y;
		unsigned int x;
	};

	struct YXM
	{
		YX           yx;
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
		void affiche(void) { for (YXM yxm : _yxManoury) { std::cout << "(" << yxm.yx.y << ", " << yxm.yx.x << ", " << yxm.manoury << ") "; } }
		YX getYx(const unsigned int manoury) const { return _yxManoury.at(-1 + manoury).yx; }
		unsigned int getManoury(YX yx) const; 
		unsigned int getManoury(unsigned int y, unsigned int x) const { YX yx = {y, x}; return getManoury(yx); }
	private:
		const std::vector <YXM> _yxManoury = { 
			  {{10, 2}, 1 }, {{10, 4}, 2 }, {{10, 6}, 3 }, {{10, 8}, 4 }, {{10, 10}, 5 }
			, {{9,  1}, 6 }, {{9,  3}, 7 }, {{9,  5}, 8 }, {{9,  7}, 9 }, {{9,  9 }, 10}
			, {{8,  2}, 11}, {{8,  4}, 12}, {{8,  6}, 13}, {{8,  8}, 14}, {{8,  10}, 15}
			, {{7,  1}, 16}, {{7,  3}, 17}, {{7,  5}, 18}, {{7,  7}, 19}, {{7,  9 }, 20}
			, {{6,  2}, 21}, {{6,  4}, 22}, {{6,  6}, 23}, {{6,  8}, 24}, {{6,  10}, 25}
			, {{5,  1}, 26}, {{5,  3}, 27}, {{5,  5}, 28}, {{5,  7}, 29}, {{5,  9 }, 30}
			, {{4,  2}, 31}, {{4,  4}, 32}, {{4,  6}, 33}, {{4,  8}, 34}, {{4,  10}, 35}
			, {{3,  1}, 36}, {{3,  3}, 37}, {{3,  5}, 38}, {{3,  7}, 39}, {{3,  9 }, 40}
			, {{2,  2}, 41}, {{2,  4}, 42}, {{2,  6}, 43}, {{2,  8}, 44}, {{2,  10}, 45}
			, {{1,  1}, 46}, {{1,  3}, 47}, {{1,  5}, 48}, {{1,  7}, 49}, {{1,  9 }, 50}
		};
	};
}

# endif // _MANOURY_H_
