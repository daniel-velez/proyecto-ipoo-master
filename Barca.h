/*
  Archivo: Barca.h
  Fecha creación: marzo-31-2020
  Fecha última modificación: mayo-09-2020
  Versión: 0.1
  Licencia: GPL v3.0
*/

/*
    Clase Barca
    Relaciones:
        -Es parecido a un Lugar
        -Conoce a todos los Lugares por medio de un array de punteros a Lugar (mapa)
    Intención: modelar una barca que es parecida a un Lugar con un conductor, la barca puede contener individuos y se mueve a través del río. Por defecto se tiene una limitación de máximo 2 individuos.
*/

#ifndef HH_BARCA
#define HH_BARCA

#include "Lugar.h"
#include <array>

using namespace std;

class Barca : public Lugar
{
    protected:
        string conductor;
        
    public:
        /**
         * Constructor
        */
        Barca(string nombre = "BARCA", int capacidad = 2, string conductor = "Robot");

        /**
         * Destructor
        */
        virtual ~Barca();

        /**
         * moverBarca recibe el mapa del juego (un array) e intercambia su posicion en él y cambio los vecinos de los otros lugares que se encuentran en el mapa.
        */
        virtual void moverBarca(array<Lugar*,4>* mapa, bool verificarConductor = true);

        /**
         * getConductor retorna un string con el nombre del individuo que actua como conductor de la barca.
        */
        virtual string getConductor();

};

#else
class Barca;
#endif