// commonServices.h

# ifndef _COMMON_SERVICES_H_
# define _COMMON_SERVICES_H_ (1)

# include <iostream>

namespace spc_commonServices
{
	enum class ApparenceCase : unsigned int
	{
		null = 0,
		normal = 1,
		surbillance = 2
	};

	enum class CouleurCaseDamier : unsigned int
	{
		null = 0,
		blanc = 1,
		noir = 2
	};

	enum class CouleurPion : unsigned int
	{
		null = 0,
		blanc = 1,
		noir = 2
	};

	enum class InputType
	{
		is_undefined = 0
		, is_digitOne = 1     // a legal digit on _buffer[0]
		, is_digitTwo = 2     // a legal digit on _buffer[1]
		, is_digitOneTwo = 3  // legal digits on _buffer[1 and 2]
		, is_digitThree = 4   // a legal digit on _buffer[2]
		, is_alphaOne = 8     // a legal char on _buffer[0]
		, is_alphaOneDigitTwo = 10
		, is_alphaOnedigitTwoThree = 14
		, is_alphaTwo = 16    // a legal char on _buffer[1]
		, is_digitOneAlphaTwo = 17
		, is_alphaThree = 32  // a legal char on _buffer[2]
		, is_digitOneTwoAlphaThree = 35
		, is_nullTwo = 64     // no char on _buffer[1]
		, is_nullThree = 128  // no char on _buffer[2]
		, is_exiting = 256    // an exit token in the buffer
		, is_error = 512      // No legal char combination in the buffer
	};

	enum class IdJoueur
	{
		undefined = 0
		, premier = 1
		, second = 2
	};

	enum class NatureJoueur
	{
		undefined = 0
		, humain = 1
		, ia = 2
	};

	enum class PositionsCouleursDepart : unsigned int
	{
		blancs_noirs = 0, // les blancs (cases 1 à 20) puis les noirs (cases 31 à 50)
		noirs_blancs = 1  // les noirs (cases 1 à 20) puis les blancs (cases 31 à 50)
	};

	enum class SensDuDeplacement : int
	{
		negatif = -1
		, undefined = 0
		, positif = 1
	};
}

# endif // _COMMON_SERVICES_H_
