// args.h

# ifndef _ARGS_H_
  # define _ARGS_H_ (1)
  namespace spc_args
  {
    class Args {
    public :
        Args(int argc, char** argv) ;
        ~Args () ;
        Args (const Args& a) ;
        Args& operator = (const Args& a) ;
        //---
        void showArgs(void) ;
    private :
        int _argc = 0 ;
        char** _argv  = nullptr ;
    } ;
  }
# endif // _ARGS_H_
