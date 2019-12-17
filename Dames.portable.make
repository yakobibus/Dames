#! /usr/bin/make 

# g++ /cygdrive/c/Users/Jacques/GitHub/Dames/Src/C/dames.cpp  -std=c++17 -o dames.exe

CC = g++

OPTIONS = -std=c++17 -Os -Wall

BASE_DIR=${HOME}/Prog

SRC_DIR = /cygdrive/c/Users/Jacques/GitHub/Dames/Src/C
HDR_DIR = /cygdrive/c/Users/Jacques/GitHub/Dames/Src/H
EXE_DIR = $(BASE_DIR)/Exe
OBJ_DIR = $(BASE_DIR)/Obj

SRC_LIST = $(SRC_DIR)/ardoise.cpp $(SRC_DIR)/args.cpp $(SRC_DIR)/cellule.cpp $(SRC_DIR)/coordonnees.cpp $(SRC_DIR)/coup.cpp $(SRC_DIR)/dames.cpp $(SRC_DIR)/damier.cpp $(SRC_DIR)/input.cpp $(SRC_DIR)/jeux.cpp $(SRC_DIR)/joueur.cpp $(SRC_DIR)/manoury.cpp $(SRC_DIR)/pion.cpp $(SRC_DIR)/regles.cpp

HDR_LIST = $(HDR_DIR)/ardoise.h $(HDR_DIR)/args.h $(HDR_DIR)/cellule.h $(HDR_DIR)/constantes.h $(HDR_DIR)/coordonnees.h $(HDR_DIR)/coup.h $(HDR_DIR)/dames.h $(HDR_DIR)/dames.h $(HDR_DIR)/damier.h $(HDR_DIR)/input.h $(HDR_DIR)/jeux.h $(HDR_DIR)/joueur.h  $(HDR_DIR)/manoury.h  $(HDR_DIR)/pion.h $(HDR_DIR)/regles.h 

OBJ_LIST = $(OBJ_DIR)/ardoise.o $(OBJ_DIR)/args.o $(OBJ_DIR)/cellule.o $(OBJ_DIR)/dames.o $(OBJ_DIR)/coordonnees.o $(OBJ_DIR)/coup.o $(OBJ_DIR)/damier.o $(OBJ_DIR)/input.o $(OBJ_DIR)/jeux.o $(OBJ_DIR)/joueur.o $(OBJ_DIR)/manoury.o $(OBJ_DIR)/pion.o $(OBJ_DIR)/regles.o 



$(EXE_DIR)/dames.exe : $(OBJ_LIST)
	$(CC) -o $(EXE_DIR)/dames.exe $(OBJ_LIST) $(OPTIONS) -I $(HDR_DIR)

$(OBJ_DIR)/ardoise.o : $(SRC_DIR)/ardoise.cpp $(HDR_DIR)/ardoise.h $(HDR_DIR)/constantes.h $(HDR_DIR)/cellule.h $(HDR_DIR)/coup.h $(HDR_DIR)/input.h $(HDR_DIR)/joueur.h $(HDR_DIR)/manoury.h $(HDR_DIR)/pion.h
	$(CC) -c -o $(OBJ_DIR)/ardoise.o $(SRC_DIR)/ardoise.cpp  $(OPTIONS) -I $(HDR_DIR)

$(OBJ_DIR)/args.o : $(SRC_DIR)/args.cpp $(HDR_DIR)/args.h $(HDR_DIR)/constantes.h
	$(CC) -c -o $(OBJ_DIR)/args.o $(SRC_DIR)/args.cpp  $(OPTIONS) -I $(HDR_DIR)

$(OBJ_DIR)/cellule.o : $(SRC_DIR)/cellule.cpp $(HDR_DIR)/cellule.h $(HDR_DIR)/constantes.h $(HDR_DIR)/coordonnees.h $(HDR_DIR)/manoury.h $(HDR_DIR)/pion.h
	$(CC) -c -o $(OBJ_DIR)/cellule.o $(SRC_DIR)/cellule.cpp  $(OPTIONS) -I $(HDR_DIR)

$(OBJ_DIR)/coordonnees.o : $(SRC_DIR)/coordonnees.cpp $(HDR_DIR)/coordonnees.h $(HDR_DIR)/constantes.h $(HDR_DIR)/manoury.h
	$(CC) -c -o $(OBJ_DIR)/coordonnees.o $(SRC_DIR)/coordonnees.cpp  $(OPTIONS) -I $(HDR_DIR)

$(OBJ_DIR)/coup.o : $(SRC_DIR)/coup.cpp $(HDR_DIR)/coup.h $(HDR_DIR)/constantes.h $(HDR_DIR)/cellule.h $(HDR_DIR)/input.h $(HDR_DIR)/joueur.h $(HDR_DIR)/pion.h
	$(CC) -c -o $(OBJ_DIR)/coup.o $(SRC_DIR)/coup.cpp  $(OPTIONS) -I $(HDR_DIR)

$(OBJ_DIR)/dames.o : $(SRC_DIR)/dames.cpp $(HDR_DIR)/dames.h $(HDR_DIR)/constantes.h $(HDR_DIR)/jeux.h
	$(CC) -c -o $(OBJ_DIR)/dames.o $(SRC_DIR)/dames.cpp  $(OPTIONS) -I $(HDR_DIR)

$(OBJ_DIR)/damier.o : $(SRC_DIR)/damier.cpp $(HDR_DIR)/damier.h $(HDR_DIR)/constantes.h $(HDR_DIR)/ardoise.h $(HDR_DIR)/coup.h $(HDR_DIR)/damier.h
	$(CC) -c -o $(OBJ_DIR)/damier.o $(SRC_DIR)/damier.cpp  $(OPTIONS) -I $(HDR_DIR)

$(OBJ_DIR)/input.o : $(SRC_DIR)/input.cpp $(HDR_DIR)/input.h $(HDR_DIR)/constantes.h $(HDR_DIR)/coordonnees.h $(HDR_DIR)/manoury.h
	$(CC) -c -o $(OBJ_DIR)/input.o $(SRC_DIR)/input.cpp  $(OPTIONS) -I $(HDR_DIR)

$(OBJ_DIR)/jeux.o : $(SRC_DIR)/jeux.cpp $(HDR_DIR)/jeux.h $(HDR_DIR)/constantes.h $(HDR_DIR)/coup.h $(HDR_DIR)/damier.h $(HDR_DIR)/joueur.h $(HDR_DIR)/pion.h
	$(CC) -c -o $(OBJ_DIR)/jeux.o $(SRC_DIR)/jeux.cpp  $(OPTIONS) -I $(HDR_DIR)

$(OBJ_DIR)/joueur.o : $(SRC_DIR)/joueur.cpp $(HDR_DIR)/joueur.h $(HDR_DIR)/constantes.h $(HDR_DIR)/pion.h $(HDR_DIR)/coup.h
	$(CC) -c -o $(OBJ_DIR)/joueur.o $(SRC_DIR)/joueur.cpp  $(OPTIONS) -I $(HDR_DIR)

$(OBJ_DIR)/manoury.o : $(SRC_DIR)/manoury.cpp $(HDR_DIR)/manoury.h $(HDR_DIR)/constantes.h
	$(CC) -c -o $(OBJ_DIR)/manoury.o $(SRC_DIR)/manoury.cpp  $(OPTIONS) -I $(HDR_DIR)

$(OBJ_DIR)/pion.o : $(SRC_DIR)/pion.cpp $(HDR_DIR)/pion.h $(HDR_DIR)/constantes.h
	$(CC) -c -o $(OBJ_DIR)/pion.o $(SRC_DIR)/pion.cpp  $(OPTIONS) -I $(HDR_DIR)

$(OBJ_DIR)/regles.o : $(SRC_DIR)/regles.cpp $(HDR_DIR)/regles.h $(HDR_DIR)/constantes.h
	$(CC) -c -o $(OBJ_DIR)/regles.o $(SRC_DIR)/regles.cpp  $(OPTIONS) -I $(HDR_DIR)


lignes :
	$(shell sss=0;for nnn in $(find /cygdrive/c/Users/Jacques/GitHub/Dames/Src/ -type f -exec wc -l {} \; | cut -f1 -d' '); do sss=$(( $nnn + $sss )) ; echo "$sss lignes de code" ; done)

clean :
	rm -f $(EXE_DIR)/dames.exe $(OBJ_LIST)

