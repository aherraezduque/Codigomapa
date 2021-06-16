#include "Mapa.h"


Mapa::Mapa()
{
	celdas.cargarMatrix(1);									//he puesto el numero 1 porque es el nivel 1 habrá que modificarlo
	//facultad= getTexture("Texturas/facultad.png");
	
}

void Mapa::dibujarMapa()
{
	celdas.cargarMatrix(1);
	celdas.dibuja();									//MatrizTile Dibujar

}

void Mapa::dibujarMapaptr(Mapa* ptr)
{
	(*ptr).dibujarMapa();
}

//Tile* Mapa::getTile(int indice)
//{
//	if (indice < MAX_TILES) {
//		return celdas.getTile(indice);
//	}
//
//}




