#pragma once
#include "Tile.h"
#define MAX_TILES 250				//10*largo del maga
class MatrizTile
{

private:

	//Tile (*mimatriz)[25];		//10 "filas" de vectores
	Tile*mimatriz[MAX_TILES];			//vector de 10 "filas"
public:
	//void cargarMatrix(int nivel);		//cargar en matriz los tipos de los tiles del fichero nivel
	void cargarMatrix(int nivel);		//funcion pensada para abarcar todos los tipo de tiles
	void dibuja();
	Tile* operator [](int i);
};


