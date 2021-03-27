/*
  Archivo: Barca.cpp    
  Fecha creación: abril-04-2020
  Fecha última modificación: mayo-10-2020
  Versión: 0.1
  Licencia: GPL v3.0
*/

#include "Barca.h"

Barca::Barca(string nombre, int capacidad, string conductor) : Lugar(nombre, capacidad)
{
    this->conductor = conductor;
}

Barca::~Barca()
{
    /*No hace nada*/
}

void Barca::moverBarca(array<Lugar *, 4> *mapa, bool verificarConductor)
{
    Lugar *orillaIzquierda = (*mapa)[0];
    Lugar *orillaDerecha = (*mapa)[3];

    // se verifica que el conductor se encuentre en la barca a menos que el atributo verificarConductor sea false
    if (!this->existeUnIndividuoDeLaEspecie(conductor) and verificarConductor)
        throw "No hay ningun " + this->conductor + " subido en la barca. La barca no se mueve sola!!!";

    // después se intercambia la posicion de la barca en el mapa
    std::swap((*mapa)[1], (*mapa)[2]);

    // se vuelven a definir los vecinos
    if (vecino == orillaIzquierda)
    {
        orillaIzquierda->definirVecino(nullptr);
        this->definirVecino(orillaDerecha);
        orillaDerecha->definirVecino(this);
    }
    else
    {
        orillaIzquierda->definirVecino(this);
        this->definirVecino(orillaIzquierda);
        orillaDerecha->definirVecino(nullptr);
    }
}

string Barca::getConductor()
{
    return this->conductor;
}
