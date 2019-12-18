// input.cpp

# include <iostream>
# include <cstring>

# include "input.h"

namespace spc_dames
{
	Input::Input(const Manoury& manoury)
		: _yxm()
		, _buffer("")
		, _bufSize(0)
		, _coordonnees()
		//, _caseDamier(nullptr)
		, _inputType(InputType::is_undefined)
		, _isValid(false)
		, _manoury(manoury)
	{
	}
}

namespace spc_dames
{
	void spc_dames::Input::essai(void) const
	{
		//const Diagonales dd;
		//std::cout << "Ici : " << dd.manouryDiagonales.size() << " diagonales\n";
		//for (unsigned ii=0; ii < dd.manouryDiagonales.size(); ++ii)
		//{ 
		//	std::cout << ".at(" << ii << ").size() = " << dd.manouryDiagonales.at(ii).size() << "\n";
		//	for (unsigned jj = 0; jj < dd.manouryDiagonales.at(ii).size(); ++jj)
		//	{
		//		std::cout << " [" << _manoury.getManoury(dd.manouryDiagonales.at(ii).at(jj)).manoury << " ("<< _manoury.getManoury(dd.manouryDiagonales.at(ii).at(jj)).yx.y <<", "<< _manoury.getManoury(dd.manouryDiagonales.at(ii).at(jj)).yx.x <<")] ";
		//	}
		//	std::cout << std::endl;
		//}
	}
}

namespace spc_dames
{
	void Input::_isValidInput(void)
	{
		_inputType = InputType::is_error;

		if (_bufSize == 2)
		{
			if (_isAlpha(_buffer[0]) && _isDigit(_buffer[1]) && _buffer[1] != '0')
			{
				_yxm.yx.y = _aToLine (&_buffer[1]);
				_yxm.yx.x = _aToColumn(_buffer[0]);
				_yxm.manoury = _manoury.getManoury(YX(_yxm.yx.y, _yxm.yx.x));
				_isValid = (_yxm.manoury > 0 && _yxm.manoury  < 51 ? true : false );
				_inputType = InputType::is_alphaOneDigitTwo;
			}
			else if (_isDigit(_buffer[0]) && _isAlpha(_buffer[1]) && _buffer[0] != '0')
			{
				_yxm.yx.y = _aToLine(&_buffer[0]);
				_yxm.yx.x = _aToColumn(_buffer[1]);
				_yxm.manoury = _manoury.getManoury(YX(_yxm.yx.y, _yxm.yx.x));
				_isValid = (_yxm.manoury > 0 && _yxm.manoury < 51 ? true : false);
				_inputType = InputType::is_digitOneAlphaTwo;
			}
		}
		else if (_bufSize == 3)
		{
			if (_isAlpha(_buffer[0]) && _isDigit(_buffer[1]) && _isDigit(_buffer[2]))
			{
				_yxm.yx.x = _aToColumn(_buffer[0]);
				_inputType = InputType::is_alphaOnedigitTwoThree;

				if (_buffer[1] == '0' && _buffer[2] != '0')
				{
					_yxm.yx.y = _aToLine(&_buffer[2]);
					_yxm.manoury = _manoury.getManoury(YX(_yxm.yx.y, _yxm.yx.x));
					_isValid = (_yxm.manoury > 0 && _yxm.manoury < 51 ? true : false);
				}
				else if (_buffer[1] == '1' && _buffer[2] == '0')
				{
					_yxm.yx.y = 10; //  _aToLine(&_buffer[1]);
					_yxm.manoury = _manoury.getManoury(YX(_yxm.yx.y, _yxm.yx.x));
					_isValid = (_yxm.manoury > 0 && _yxm.manoury < 51 ? true : false);
				}
			}
			else if (_isDigit(_buffer[0]) && _isDigit(_buffer[1]) && _isAlpha(_buffer[2]))
			{
				_yxm.yx.x = _aToColumn(_buffer[2]);
				_inputType = InputType::is_digitOneTwoAlphaThree;

				if (_buffer[0] == '0' && _buffer[1] != '0')
				{
					_yxm.yx.y = _aToLine(&_buffer[1]);
					_yxm.manoury = _manoury.getManoury(YX(_yxm.yx.y, _yxm.yx.x));
					_isValid = (_yxm.manoury > 0 && _yxm.manoury < 51 ? true : false) ;
				}
				else if (_buffer[0] == '1' && _buffer[1] == '0')
				{
					_yxm.yx.y = 10; //  _aToLine(&_buffer[1]);
					_yxm.manoury = _manoury.getManoury(YX(_yxm.yx.y, _yxm.yx.x));
					_isValid = (_yxm.manoury > 0 && _yxm.manoury < 51 ? true : false) ;
				}
			}
		}
		else if (_bufSize > 0 && (_buffer[0] == 'x' || _buffer[0] == 'X' || _buffer[0] == 'q' || _buffer[0] == 'Q'))
		{
			_yxm.yx.y = 0;
			_yxm.yx.x = 0;
			_yxm.manoury = 0;
			_isValid = false;
			_inputType = InputType::is_exiting;
		}
		else
		{
			_yxm.yx.y = 0;
			_yxm.yx.x = 0;
			_yxm.manoury = 0;
			_isValid = false;
			_inputType = InputType::is_error;
		}
		_coordonnees.set(_yxm);
	}

	void Input::saisie(const char* invite)
	{
		_isValid = false;
		std::cout << invite;

		_inputType = InputType::is_undefined;
		_bufSize = 0;
		std::memset(_buffer, 0, INPUT_BUFFER_MX_SIZE);
		std::cin.getline(_buffer, static_cast<unsigned int> (-1 + INPUT_BUFFER_MX_SIZE));
		_bufSize = strlen(_buffer);
		//
		_isValidInput();
		//
		//std::cout << (_isValid  == true ? "True" : "False") << " [("<<_yxm.yx.y<<", "<< _coordonnees.getXalpha() <<"), "<< _yxm.manoury<<"] " << "\n";
	}
}
