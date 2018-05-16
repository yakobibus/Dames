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
  }
# endif // _CONSTANTES_H_
