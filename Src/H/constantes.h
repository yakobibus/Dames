// constantes.h

# ifndef _CONSTANTES_H_
  # define _CONSTANTES_H_ (1)
  namespace spc_constantes
  {
     # define NB_MX_COUPS_PAR_PRISE (static_cast<int>(20))
     # define NB_MX_COUPS_PAR_RAFLE (static_cast<int>(20))
     # define NB_PIONS_PAR_COULEUR  (static_cast<int>(20))
     # define NB_DIAGONALES_PLATEAU (static_cast<int>(19))  // de une à 10 cases de suite par diagonale
     # define NB_MX_COUPS_HISTORIQUE (static_cast<int>(500))
     # define NB_CASES_PLATEAU      (static_cast<int>(51))  // 50 cases noires numérotées de 01 à 50 ; la case 00 est blanche ; le numéro de la case correspond à son indice
     # define BUFFER_MX_SIZE        (static_cast<int>(500))
     # define INPUT_TYPE_ARRAY_SIZE (static_cast<int>(3))
     # define MOTIF_SIZE            (static_cast<int>(4))

     # define IS_DIGIT_ONE (static_cast<int>(input_type::is_digitOne)) 
     # define IS_DIGIT_TWO (static_cast<int>(input_type::is_digitTwo))
     # define IS_DIGIT_THREE (static_cast<int>(input_type::is_digitThree))
     # define IS_ALPHA_ONE (static_cast<int>(input_type::is_alphaOne)) 
     # define IS_ALPHA_TWO (static_cast<int>(input_type::is_alphaTwo))
     # define IS_ALPHA_THREE (static_cast<int>(input_type::is_alphaThree))

     # define IS_ALPHA_DAMIER(c) ((c >= 'a' && c <= 'j') || (c >= 'A' && c <= 'J'))
     # define IS_DIGIT_DAMIER(c) (c >= '0' && c <= '9')
  }
# endif // _CONSTANTES_H_
