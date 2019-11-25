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
//		_coordonnees.set(0, 0, 0);
//		std::memset(_buffer, 0, INPUT_BUFFER_MX_SIZE);
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
				_yxm.yx.y = _aToColumn (_buffer[0]);
				_yxm.yx.x = _aToLine (&_buffer[1]);
				_yxm.manoury = _manoury.getManoury(YX(_yxm.yx.y, _yxm.yx.x));
				_isValid = true;
				_inputType = InputType::is_alphaOneDigitTwo;
				//_coordonnees.set(_aToLine(&(_buffer[1])), _aToColumn(_buffer[0]));
			}
			else if (_isDigit(_buffer[0]) && _isAlpha(_buffer[1]) && _buffer[0] != '0')
			{
				_yxm.yx.y = _aToColumn(_buffer[1]);
				_yxm.yx.x = _aToLine(&_buffer[0]);
				_yxm.manoury = _manoury.getManoury(YX(_yxm.yx.y, _yxm.yx.x));
				_isValid = true;
				_inputType = InputType::is_digitOneAlphaTwo;
				//_coordonnees.set(_aToLine(&(_buffer[0]), 1), _aToColumn(_buffer[1]));
			}
		}
		else if (_bufSize == 3)
		{
			if (_isAlpha(_buffer[0]) && _isDigit(_buffer[1]) && _isDigit(_buffer[2]))
			{
				_yxm.yx.y = _aToColumn(_buffer[0]);
				_inputType = InputType::is_alphaOnedigitTwoThree;
				//_coordonnees.set(_aToLine(&(_buffer[1])), _aToColumn(_buffer[0]));
				if (_buffer[1] == '0' && _buffer[2] != '0')
				{
					_yxm.yx.x = _aToLine(&_buffer[2]);
					_yxm.manoury = _manoury.getManoury(YX(_yxm.yx.y, _yxm.yx.x));
					_isValid = true;
				}
				else if (_buffer[1] == '1' && _buffer[2] == '0')
				{
					_yxm.yx.x = 10; //  _aToLine(&_buffer[1]);
					_yxm.manoury = _manoury.getManoury(YX(_yxm.yx.y, _yxm.yx.x));
					_isValid = true;
				}
			}
			else if (_isDigit(_buffer[0]) && _isDigit(_buffer[1]) && _isAlpha(_buffer[2]))
			{
				_yxm.yx.y = _aToColumn(_buffer[2]);
				_inputType = InputType::is_digitOneTwoAlphaThree;
				//_coordonnees.set(_aToLine(&(_buffer[0]), 2), _aToColumn(_buffer[2]));
				if (_buffer[0] == '0' && _buffer[1] != '0')
				{
					_yxm.yx.x = _aToLine(&_buffer[1]);
					_yxm.manoury = _manoury.getManoury(YX(_yxm.yx.y, _yxm.yx.x));
					_isValid = true;
				}
				else if (_buffer[0] == '1' && _buffer[1] == '0')
				{
					_yxm.yx.x = 10; //  _aToLine(&_buffer[1]);
					_yxm.manoury = _manoury.getManoury(YX(_yxm.yx.y, _yxm.yx.x));
					_isValid = true;
				}
			}
		}
		else if (_bufSize > 0 && (_buffer[0] == 'x' || _buffer[0] == 'X' || _buffer[0] == 'q' || _buffer[0] == 'Q'))
		{
			_yxm.yx.y = 0;
			_yxm.yx.x = 0;
			_yxm.manoury = 0;
			_isValid = true;
			_inputType = InputType::is_exiting;
		}
		std::cout << "Analyse en cours lu<" << _buffer << ">::.at(0):" << _buffer[0] << ", [(" << _yxm.yx.y << ", " << _yxm.yx.x << "), " << _yxm.manoury << "] ";
	}

	void Input::saisie(const char* invite)
	{
		_isValid = false;
		std::cout << invite;

		_inputType = InputType::is_undefined;
		// _coordonnees.set(0, 0, 0); ::: TODO : ici
		_bufSize = 0;
		std::memset(_buffer, 0, INPUT_BUFFER_MX_SIZE);
		std::cin.getline(_buffer, static_cast<unsigned int> (-1 + INPUT_BUFFER_MX_SIZE));
		_bufSize = strlen(_buffer);
		//
		_isValidInput();
		std::cout << "ici dans saisie sz["<<_bufSize<<"], buf["<<_buffer<<"]... ";
	}
}

/*
namespace spc_dames
{
	Input::Input()
		: _buffer("")
		, _bufSize(0)
		//, _caseDamier(nullptr)
		, _inputType(InputType::is_undefined)
		, _isValid(false)
	{
		_coordonnees.set(0, 0, 0);
		std::memset(_buffer, 0, INPUT_BUFFER_MX_SIZE);
	}

	void Input::_isValidInput(void)
	{
		_inputType = InputType::is_error;

		if (_bufSize == 2)
		{
			if (_isAlpha(_buffer[0]) && _isDigit(_buffer[1]) && _buffer[1] != '0')
			{
				_isValid = true;
				_inputType = InputType::is_alphaOneDigitTwo;
				_coordonnees.set(_aToLine(&(_buffer[1])), _aToColumn(_buffer[0]));
			}
			else if (_isDigit(_buffer[0]) && _isAlpha(_buffer[1]) && _buffer[0] != '0')
			{
				_isValid = true;
				_inputType = InputType::is_digitOneAlphaTwo;
				_coordonnees.set(_aToLine(&(_buffer[0]), 1), _aToColumn(_buffer[1]));
			}
		}
		else if (_bufSize == 3)
		{
			if (_isAlpha(_buffer[0]) && _isDigit(_buffer[1]) && _isDigit(_buffer[2]))
			{
				_inputType = InputType::is_alphaOnedigitTwoThree;
				_coordonnees.set(_aToLine(&(_buffer[1])), _aToColumn(_buffer[0]));
				if (_buffer[1] == '0' && _buffer[2] != '0')
				{
					_isValid = true;
				}
				else if (_buffer[1] == '1' && _buffer[2] == '0')
				{
					_isValid = true;
				}
			}
			else if (_isDigit(_buffer[0]) && _isDigit(_buffer[1]) && _isAlpha(_buffer[2]))
			{
				_inputType = InputType::is_digitOneTwoAlphaThree;
				_coordonnees.set(_aToLine(&(_buffer[0]), 2), _aToColumn(_buffer[2]));
				if (_buffer[0] == '0' && _buffer[1] != '0')
				{
					_isValid = true;
				}
				else if (_buffer[0] == '1' && _buffer[0] == '0')
				{
					_isValid = true;
				}
			}
		}
		else if (_bufSize > 0 && (_buffer[0] == 'x' || _buffer[0] == 'X' || _buffer[0] == 'q' || _buffer[0] == 'Q'))
		{
			_isValid = true;
			_inputType = InputType::is_exiting;
		}
	}

	void Input::saisie(const char* invite)
	{
		_isValid = false;
		std::cout << invite;

		_inputType = InputType::is_undefined;
		_coordonnees.set(0, 0, 0);
		_bufSize = 0;
		std::memset(_buffer, 0, INPUT_BUFFER_MX_SIZE);
		std::cin.getline(_buffer, -1 + INPUT_BUFFER_MX_SIZE);
		_bufSize = strlen(_buffer);
		//
		_isValidInput();
	}
}
*/