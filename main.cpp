/*
  Archivo: main.cpp   
  Fecha creación: marzo-31-2020
  Fecha última modificación: mayo-10-2020
  Versión: 0.1
  Licencia: GPL v3.0
*/

#include "Jugador.h"
#include "Individuo.h"
#include "Lugar.h"
#include "Barca.h"
#include "Orilla.h"
#include <array>

int main()
{
    // defino el mapa del juego, un array de 4 posiciones, y creo los objetos de su interior
    Orilla orillaIzquierda("IZQUIERDA");
    Barca barca; //El conductor y la capacidad de la barca se puede cambiar con el constructor.
    Lugar tramoDelRio;
    Orilla orillaDerecha("DERECHA");
    array<Lugar *, 4> mapa = {&orillaIzquierda, &barca, &tramoDelRio, &orillaDerecha};

    // defino los vecinos, es una simplificacion al uso del array mapa[4]
    orillaIzquierda.definirVecino(&barca);
    barca.definirVecino(&orillaIzquierda);

    // creo los objetos individuos del juego
    Individuo robot("R2D2", "Robot");
    Individuo zorro("Zorro");
    Individuo conejo("Willy", "Conejo");
    Individuo lechuga("Lechuga");
    Individuo matias("Matias", "Conejo");
    Individuo C3PO("C3PO", "Robot");
    // **EL NOMBRE DE LOS INDIVIDUOS TIENE QUE COMENZAR CON MAYÚSCULA**

    // defino la dieta de los individuos
    zorro.agregarAlimentacion("Conejo");
    conejo.agregarAlimentacion("Lechuga");
    matias.agregarAlimentacion("Lechuga");

    // agrego los individuos al mapa
    orillaIzquierda.agregarIndividuos((vector<Individuo *>){&robot, &zorro, &conejo, &lechuga, &matias, &C3PO});

    // inicio el juego y le cedo el control al Jugador
    Jugador laBarca(&mapa, &barca, &orillaIzquierda, &orillaDerecha);
    laBarca.jugar();

    return 0;
}