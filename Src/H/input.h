// input.h

# ifndef _INPUT_H_
# define _INPUT_H_ (1)

# include "constantes.h"
# include "coordonnees.h"
# include "manoury.h"

namespace spc_dames
{

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

	class Input
	{
	public:
		Input();
		~Input() = default;
		Input(const Input& i) = default;
		Input& operator = (const Input& i) = default;
		//
		const Coordonnees& getCoordonnees(void) const { return _coordonnees; }
		InputType    getInputType(void) const { return _inputType; }
		unsigned int getX(void) const { return _coordonnees.getX(); }
		unsigned int getY(void) const { return _coordonnees.getY(); }
		bool isValid(void) const { return _isValid; }
		void saisie(const char* invite);
	private:
		YXM                _yxm;
		char               _buffer[INPUT_BUFFER_MX_SIZE];
		unsigned int       _bufSize;
		Coordonnees        _coordonnees;
		InputType          _inputType;
		bool               _isValid;
		//
		void               _isValidInput(void);
		//
		inline unsigned int _aToColumn(const char& colonne) const {
			return (
				colonne == 'a' || colonne == 'A' ? 1
				: colonne == 'b' || colonne == 'B' ? 2
				: colonne == 'c' || colonne == 'C' ? 3
				: colonne == 'd' || colonne == 'D' ? 4
				: colonne == 'e' || colonne == 'E' ? 5
				: colonne == 'f' || colonne == 'F' ? 6
				: colonne == 'g' || colonne == 'G' ? 7
				: colonne == 'h' || colonne == 'H' ? 8
				: colonne == 'i' || colonne == 'I' ? 9
				: colonne == 'j' || colonne == 'J' ? 10
				: 0
				);
		}
		inline unsigned int _aToLine(const char* s, std::size_t offset = 0) const { return std::stoi(s, &offset); }
		inline bool _isAlpha(const char& c) const { return IS_ALPHA_DAMIER(c); }
		inline bool _isDigit(const char& c) const { return IS_DIGIT_DAMIER(c); }
	};
}

# endif // _INPUT_H_ 
