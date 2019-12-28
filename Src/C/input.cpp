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
		//std::vector<unsigned> zz;
		//for (unsigned ii = 1; ii <= 50; ++ii)
		//{
		//	//_manoury.getNeighbours(zz, ii);
		//	std::cout << "N<"<<ii<<">(";
		//	for (unsigned& v : _manoury.getNeighbours(zz, ii))
		//	{
		//		std::cout << v << " ";
		//	}
		//	std::cout << ")\n";
		//}

		//for (unsigned m1 = 1 ; m1 <= 50 ; ++m1)
		//{
		//	for (unsigned m2 = 1; m2 <= 50; ++m2)
		//	{
		//		if (m1 != m2 && _manoury.areDiagonalized(m1, m2))
		//		{
		//			std::cout << "("<<m1<<", "<<m2<<") ";
		//		}
		//	}
		//	std::cout << "\n";
		//}
		//if (_manoury.areDiagonalized(99, 0)) { std::cout << "1 vrai\n"; } else { std::cout << "1. fx\n"; }
		//for (unsigned int ii = 1; ii <= 50; ++ii) 
		//{ 
		//	const std::vector<unsigned> indicesDiags = _manoury.getDiagonales(ii);
		//	//_manoury.getDiagonales(ii, indicesDiags); 
		//	std::cout << ", {"; 
		//	for (const unsigned& dIndc : indicesDiags)
		//	{
		//		std::cout << dIndc <<", {";
		//		for (const unsigned& m : _manoury.getDiagonale(dIndc))
		//		{
		//			std::cout << m << ", ";
		//		}
		//		std::cout << "} ";
		//	}
		//	std::cout << "} // " << ii << "\n";
		//}
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
		_coordonnees.set(_yxm, &_manoury);
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
