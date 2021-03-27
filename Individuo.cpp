/*
  Archivo: Individuo.cpp
  Fecha creación: abril-04-2020
  Fecha última modificación: mayo-09-2020
  Versión: 0.1
  Licencia: GPL v3.0
*/

#include "Individuo.h"

Individuo::Individuo(string nombre, string especie) : nombre(nombre), especie(especie), alimentacion("")
{
    if (especie == "")
        this->especie = nombre;
}

Individuo::~Individuo()
{
    /* No hace nada */
}

string Individuo::getNombre()
{
    return nombre;
}

string Individuo::getEspecie()
{
    return especie;
}

void Individuo::agregarAlimentacion(string alimentacion)
{
    this->alimentacion = alimentacion;
}

bool Individuo::intentarComer(Individuo *individuo)
{
    if (individuo->getEspecie() == alimentacion)
        return true;
    else
        return false;
};