#pragma once

#define MAX_ObstaculoMovil 100
#include "ObstaculoMovil.h"
#include "Interaccion.h"
#include "Vida.h"
#include "Tile.h"

class ListaObstaculoMovil:public ObstaculoMovil
{
private:
	Tile* lista[MAX_ObstaculoMovil];
	int numero;

public:
	ListaObstaculoMovil();
	virtual ~ListaObstaculoMovil();
	bool agregar(Tile* m);
	void dibuja();
	void mueve(float t);
	void destruirContenido();
	void eliminar(int index);
	void eliminar(ObstaculoMovil* m);
	int getnumero() { return numero; }


	bool rebote(Personaje& p);
	
};