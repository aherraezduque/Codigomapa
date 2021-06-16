#include "MatrizTile.h"
#include <iostream>
#include <fstream>
#include "Bonus.h"
#include "ListaBonus.h"
#include "ObstaculoFijo.h"	
#include "ListaObstaculoFijo.h"
#include "ObstaculoMovil.h"
#include "ListaObstaculoMovil.h"
using namespace std;
		
//void MatrizTile::cargarMatrix(int nivel)
//{
//	//mimatriz = new Tile[10][25];
//	//for (int i = 0; i < 10; i++) { mimatriz[i] = new Tile[25]; };		//reserva espacio para la memoria 10 filas 25 columnas
//	//for (auto& p:mimatriz) p= new Tile[10];		//reserva espacio para la memoria 10 filas 25 columnas
//	//to do dependiendo del nivel introducido leerá un fichero u otro
//	ifstream fichero("Texturas/Nivel_1.txt");
//	if (!fichero)return;
//	while (fichero.good()) {	//=!fichero.eof()
//		int num; 
//		//fichero >> num;
//		
//		for (int i1 = 0; i1 < 10; i1++) {
//			for (int j = 0; j < 25; j++) {
//				fichero >> num;
//				
//				(&mimatriz[i1][j])->setTipo(num);					//carga el tipo en cada tile de la matriz en base a lo que hay en el fichero
//				//(mimatriz +(i1*25)+ j)->
//				(&mimatriz[i1][j])->setColumna_Fila(i1, j);			//inicializo los valores de los indices en cada tile
//																	//setColumna_Fila llama a setPosicion() que actualiza la posicion del tile.
//			}
//		}
//	}
//}

void MatrizTile::cargarMatrix(int nivel)
{
	//dependiendo del nivel introducido abrirá un txt u otro, switch case TO-DO
	
	ifstream fichero("Texturas/Nivel_1.txt");					//abro el fichero correspondiente
	while (fichero.good()) {	//=!fichero.eof()
		int num;
		//fichero >> num;

		for (int k = 0; k < MAX_TILES; (k + 0)) {
			for (int i1 = 0; i1 < 10; i1++) {
				for (int j = 0; j < 25; j++) {
					fichero >> num;										//coge el tipo que sea

					//switch-case en funcion del tipo realizará un new distinto.
					switch (num)
					{
					case 0: //aire-vacio
					{
						(mimatriz[k]) = new Tile;
						break;
					}
					case 1: //ladrillo
					{
						
						(mimatriz[k]) = new Tile;
						break;
					}
					case 2:	//agua
					{
						(mimatriz[k]) = new Tile;
						break;
					}
					case 3:// bonus
					{
						mimatriz[k] = new Bonus;
						
						break;
					}
					case 4://obstaculo fijo- llama
					{
						mimatriz[k] = new ObstaculoFijo;
						break;
					}
					case 5://obstaculo movil- alpaca
					{
						mimatriz[k] = new ObstaculoMovil;
						break;
					}
					default:
						break;

					}
																		//por ultimo ejecuta las funciones que caracterizan las propiedades del tile.

					//(&mimatriz[i1][j])->setTipo(num);					//carga el tipo en cada tile de la matriz en base a lo que hay en el fichero
					mimatriz[k]->setTipo(num);
					//(&mimatriz[i1][j])->setColumna_Fila(i1, j);			//inicializo los valores de los indices en cada tile
					mimatriz[k]->setColumna_Fila(i1, j);													//setColumna_Fila llama a setPosicion() que actualiza la posicion del tile.
					k++;												//aumento el índice
				}
			}
		}
		
	}
}

void MatrizTile::dibuja()
{
	for (int i = 0; i < MAX_TILES; i++) {
		mimatriz[i]->dibuja();
	}
	//ANTIGUO
	//for (int i1 = 0; i1 < 10; i1++) {
	//	for (int j = 0; j < 25; j++) {
	//		//(&mimatriz[i1][j])->dibuja();							//llama a la funcion dibuja de la clase Tile para cada tile de la matriz
	//		mimatriz[i1][j].dibuja();								//mediante polimorfismo llama a la funcion dibuja que corresponda seguna la clase
	//																//todos los punteros son a la clase base Tile
	//	}
	//}
}

Tile* MatrizTile::operator[](int i)
{
	return mimatriz[i];
}


