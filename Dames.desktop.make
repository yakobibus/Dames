#! /usr/bin/make 

# g++ /cygdrive/c/Users/Jacques/GitHub/Dames/Src/C/dames.cpp  -std=c++17 -o dames.exe

CC = g++

OPTIONS = -std=c++17 

SRC_DIR = /cygdrive/c/Users/Jacques/GitHubRepository/Dames/Src/C
HDR_DIR = /cygdrive/c/Users/Jacques/GitHubRepository/Dames/Src/H
EXE_DIR = ./Exe
OBJ_DIR = ./Obj

SRC_LIST = $(SRC_DIR)/dames.cpp $(SRC_DIR)/args.cpp $(SRC_DIR)/constantes.cpp $(SRC_DIR)/plateau.cpp $(SRC_DIR)/regles.cpp
HDR_LIST = $(HDR_DIR)/dames.h $(HDR_DIR)/args.h $(HDR_DIR)/constantes.h $(HDR_DIR)/plateau.h $(HDR_DIR)/regles.h
OBJ_LIST = $(OBJ_DIR)/dames.o $(OBJ_DIR)/args.o $(OBJ_DIR)/constantes.o $(OBJ_DIR)/plateau.o $(OBJ_DIR)/regles.o

$(EXE_DIR)/dames.exe : $(OBJ_LIST)
	$(CC) -o $(EXE_DIR)/dames.exe $(OBJ_LIST) $(OPTIONS) -I $(HDR_DIR)

$(OBJ_DIR)/args.o : $(SRC_DIR)/args.cpp $(HDR_DIR)/args.h
	$(CC) -c -o $(OBJ_DIR)/args.o $(SRC_DIR)/args.cpp  $(OPTIONS) -I $(HDR_DIR)

$(OBJ_DIR)/constantes.o : $(SRC_DIR)/constantes.cpp $(HDR_DIR)/constantes.h
	$(CC) -c -o $(OBJ_DIR)/constantes.o $(SRC_DIR)/constantes.cpp  $(OPTIONS) -I $(HDR_DIR)

$(OBJ_DIR)/dames.o : $(SRC_DIR)/dames.cpp $(HDR_DIR)/dames.h
	$(CC) -c -o $(OBJ_DIR)/dames.o $(SRC_DIR)/dames.cpp  $(OPTIONS) -I $(HDR_DIR)

$(OBJ_DIR)/plateau.o : $(SRC_DIR)/plateau.cpp $(HDR_DIR)/plateau.h
	$(CC) -c -o $(OBJ_DIR)/plateau.o $(SRC_DIR)/plateau.cpp  $(OPTIONS) -I $(HDR_DIR)

$(OBJ_DIR)/regles.o : $(SRC_DIR)/regles.cpp $(HDR_DIR)/regles.h
	$(CC) -c -o $(OBJ_DIR)/regles.o $(SRC_DIR)/regles.cpp  $(OPTIONS) -I $(HDR_DIR)


lignes :
	$(shell sss=0;for nnn in $(find /cygdrive/c/Users/Jacques/GitHub/Dames/Src/ -type f -exec wc -l {} \; | cut -f1 -d' '); do sss=$(( $nnn + $sss )) ; echo "$sss lignes de code" ; done)

clean :
	rm -f $(EXE_DIR)/dames.exe $(OBJ_LIST)

