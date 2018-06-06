// args.c

# include <iostream>
# include <cstring>
# include "args.h"

namespace spc_args
{
	Args::Args(int argc, char** argv) : _argc(argc)
	{
		if(_argc > 0)
		{
			_argv = new char*[_argc] ;
			for(int ii = 0 ; ii < _argc ; ++ii)
			{
				int sz = 1 + std::strlen(argv [ii]) ;
				_argv[ii] = new char[sz] ;
				std::memset(_argv[ii], 0, sz) ;
				std::memcpy(_argv[ii], argv[ii], sz) ;
			}
		}
	}
	// ---
	Args::~Args ()
	{
		if(_argc > 0)
		{
			for(int ii = -1 +_argc ; ii >= 0 ; --ii)
			{
				std::cout << "~" << _argv[ii] << std::endl ;
				delete[] _argv[ii] ;
				_argv[ii] = nullptr;
			}
			delete[] _argv ;
			_argv = nullptr;
			_argc = 0 ;
			std::cout << "~x" << std::endl ;
		}
	}
	// ---
	Args::Args (const Args& a)
	{
		if(this != &a)
		{
				if (_argc > 0)
				{
					for (int i = 0; i < _argc; ++i)
					{
						delete[] _argv[i];
						_argv[i] = nullptr;
					}
					delete[] _argv;
					_argv = nullptr;
				}

				_argc = a._argc;
				if (_argc > 0)
				{
					_argv = new char*[_argc];

					for (int i = 0; i < _argc; ++i)
					{
						int sz = 1 + std::strlen(a._argv[i]);
						_argv[i] = new char[sz];
						std::memset(_argv[i], 0, sz);
						std::memcpy(_argv[i], a._argv[i], -1 + sz);
					}
				}
		}
	}
	// ---
	Args& Args::operator = (const Args& a)
	{
			if (this != &a)
			{
				if (_argc > 0)
				{
					for (int i = 0; i < _argc; ++i)
					{
						delete[] _argv[i];
						_argv[i] = nullptr;
					}
					delete[] _argv;
					_argv = nullptr;
				}

				_argc = a._argc;
				if (_argc > 0)
				{
					_argv = new char*[_argc];

					for (int i = 0; i < _argc; ++i)
					{
						int sz = 1 + std::strlen(a._argv[i]);
						_argv[i] = new char[sz];
						std::memset(_argv[i], 0, sz);
						std::memcpy(_argv[i], a._argv[i], -1 + sz);
					}
				}
			}
			return *this;
	}
	
	void Args::showArgs(void)
	{
		for(int ii = 0 ; ii < _argc ; ++ii)
		{
			std::cout << "(" << ii << ") [" << _argv[ii] << "]" << std::endl ;
		}
	}
}
