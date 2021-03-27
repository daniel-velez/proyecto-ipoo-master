/*
  Archivo: Jugador.h
  Fecha creación: marzo-31-2020
  Fecha última modificación: mayo-09-2020
  Versión: 0.1
  Licencia: GPL v3.0
*/

/*
    Clase: Jugador
    Relación: conoce a todos los Lugares por medio de un array de punteros a Lugar (mapa)
    Intención: representa al jugador humano en el juego, es el objeto que tiene acceso a la consola, muestra el estado del juego y ejecuta las órdenes que recibe desde afuera.
*/

#ifndef HH_JUGADOR
#define HH_JUGADOR

#include "Barca.h"
#include "Orilla.h"

#include <iostream>
#include <array>
#include <time.h>
using namespace std;

class Jugador
{
	protected:
      array <Lugar*,4> *mapa;
		  Orilla* orillaIzquierda;
      Barca* barca;
		  Orilla* orillaDerecha;

      int consoleRowSize;
      const int consoleColumnSize = 14;

	public:
        /**
        * Constructor
        */
		Jugador(array<Lugar*,4>* mapa, Barca* barca, Orilla* orillaIzquierda, Orilla* orillaDerecha);

        /**
        * Destructor
        */
		virtual ~Jugador();

        /**
        * jugar inicia el juego y tomar el control del programa
        */
		virtual void jugar();

        /**
        * mostrarJuego imprime en consola el estado actual del juego
        */
		virtual void mostrarJuego();

        /**
        * recibirEntrada recibe por consola los comandos a ejecutar
        */
		virtual void recibirEntrada();

        /**
        * reiniciar permite regresar todos los lugares e individuos al estado inicial
        */
    virtual void reiniciar();

        /**
        * comprobarEstadoDelJuego determinar despues de cada movimiento si se ganó o se perdió
        */
		virtual bool comprobarEstadoDelJuego();
        /**
        * menuDespuesDeGanarOPerder muestra las opciones de reiniciar o salir
        * cuando se gana o pierde
        */
    virtual void menuDespuesDeGanarOPerder();
        /**
        * recibirUnCaracter recibe la entrada por consola
        */
    virtual string recibirUnCaracter();

};

#else
class Jugador;
#endif