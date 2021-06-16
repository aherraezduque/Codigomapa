#include "Tile.h"
#include "freeglut.h"
#include <iostream>
using namespace ETSIDI;
Tile::Tile()
{
	tipo = 0;
	columna = 0;
	fila = 0;
	lado = 4.0f;
	alto = 4.0f;
	ancho = 4.0f;
												//defino la posicion mediante los índices columna y fila que hace las veces de la coordenada superior izquierda del cuadrado
												//la posicion será la suma de la mitad del lado a la coumna por el valor establecido para el lado
	posicion.x = (double)lado* ((double)columna+ 0.5f);
	posicion.y = (double)lado *((double)-fila - 0.5f);

	//textura=getTexture("Texturas/textura1.png");//defecto ladrillo
	//facultad = getTexture("Texturas/facultad.png");
}

void Tile::setTipo(int _tipo)
{
	tipo = _tipo;
}

void Tile::setColumna_Fila(int _fila, int _columna)
{
	fila = _fila;
	columna = _columna;
	setPosicion();					//al modificar los indices en la matriz se modifica la posicion del tile
}

void Tile::setPosicion()
{
	//defino la posicion mediante los índices columna y fila que hace las veces de la coordenada superior izquierda del cuadrado
	//la posicion será la suma de la mitad del lado a la coumna por el valor establecido para el lado
	posicion.x = (double)lado * ((double)columna + 0.5f);
	posicion.y = (double)lado * ((double)-fila - 0.5f);
}

void Tile::dibuja()
{
	switch (tipo)
	{
	case 0:
		//en el caso de a textura no se pinta nada //la textura es vacia para mostrar el fondo, la imagen de la facultad
		cout << "DIbujo 0 aire" <<endl;
		break;

	case 1:
	{//ladrillo
		this->ladrillo.setPos(posicion.x, posicion.y);
		this->ladrillo.setSize(4, 4);
		this->ladrillo.draw();
		cout << "DIbujo 1 ladrillo" << endl;
		break;
	}
	case 2://agua			
		this->agua.setPos(posicion.x, posicion.y);															//los case para las otras clases solo son necesarios en la funcion cargar
		this->agua.setSize(4, 4);
		this->agua.draw();																		//mediante polimorfismo, al invocar el dibuja de cada tile , dependiendo de la clase hará la llamada a la suya
		cout << "DIbujo 0 agua" << endl;
		break;																					//tan solo los tiles aire-vacio, ladrillo y agua requieren de case.
	//case 3://bonus																			
	//	this->dibuja();			//de hacerse bien deberia llamar al dibuja de la clase bonus
	//	break;
	//case 4://obtaculo fijo-llama

	//	break;
	//case 5://obstaculo movil -alpaca

	//	break;
	default:
		break;

	}
}

int Tile::getTipo()
{
	return tipo;
}
