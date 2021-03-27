/*
  Archivo: Lugar.cpp
  Fecha creación: abril-04-2020
  Fecha última modificación: mayo-09-2020
  Versión: 0.1
  Licencia: GPL v3.0
*/
#include "Lugar.h"

Lugar::Lugar(string nombre, int capacidad) : nombre(nombre), capacidad(capacidad), vecino(nullptr)
{
}

Lugar::~Lugar()
{
    /* No hace nada */
}

string Lugar::getNombre()
{
    return nombre;
}

bool Lugar::agregarIndividuo(Individuo *individuo)
{
    if (individuos.size() < capacidad or capacidad == -1)
        individuos.push_back(individuo);
    else
        return false;

    return true;
}

bool Lugar::agregarIndividuos(vector<Individuo *> individuos)
{
    if (this->individuos.size() + individuos.size() < capacidad or capacidad == -1)
    {
        // agrega un vector de individuos
        for (int i = 0; i < individuos.size(); i++)
        {
            this->individuos.push_back(individuos[i]);
        }
        return true;
    }
    else
        return false;
}

Individuo *Lugar::getIndividuo(int indice)
{
    if (indice < individuos.size())
        return individuos[indice];
    else
        return nullptr;
}

int Lugar::numeroDeIndividuos()
{
    return individuos.size();
}

bool Lugar::existeUnIndividuoDeLaEspecie(string especie)
{
    // busca una espacie del vector individuos
    for (int i = 0; i < individuos.size(); i++)
    {
        if (individuos[i]->getEspecie() == especie)
            return true;
    }

    return false;
}

void Lugar::pasarTodosLosIndividuosA(Lugar *lugarDeDestino)
{
    lugarDeDestino->agregarIndividuos(individuos);
    individuos.clear();
}

//---------------------------------------------------------------------------

Individuo *Lugar::algunIndividuoHaSidoComido()
{
    // verificar si esta el Robot
    for (int cout = 0; cout < individuos.size(); cout++)
    {
        if (individuos[cout]->getEspecie() == cuidador)
            return nullptr;
    }

    // si no esta el robot, pasar por cada individuo y verificar si pudo comer
    for (int i = 0; i < individuos.size(); i++)
    {
        // se realiza la verificacion para las individuos por encima en el vector
        for (int j = 0; j <= i - 1; j++)
        {
            if (individuos[i]->intentarComer(individuos[j]))
                return individuos[j];
        }

        // se realiza la verificacion para las individuos por debajo en el vector
        for (int j = i + 1; j < individuos.size(); j++)
        {
            if (individuos[i]->intentarComer(individuos[j]))
                return individuos[j];
        }
    }
    return nullptr;
}

void Lugar::definirVecino(Lugar *vecino)
{
    this->vecino = vecino;
}

int Lugar::buscarPorLetra(string primeraLetra)
{ // busca un individuo y compara su letra inicial con primeraLetra
    for (int i = 0; i < individuos.size(); i++)
    {
        if (individuos[i]->getNombre()[0] == primeraLetra[0])
            return i;
    }
    return -1;
}

bool Lugar::moverIndividuo(string primeraLetra)
{
    // se declaro en la parte publica de la clase Lugar un enumerador
    // cada tipo de enumeracion representa los casos para cuando se va
    // a mover un individuo
    // el metodo moverIndividuo retorna un enumerador de tipo casosMoverIndividuo
    // hay que determinar dónde se encuentra el individuo
    int individuoParaMover = buscarPorLetra(primeraLetra);

    // si no encontro un individuo en buscarPorLetra
    if (individuoParaMover == -1)
        return false;

    // si hay un vecino, agrega el individuo al lugar vecino
    if (!vecino)
        throw individuos[individuoParaMover]->getNombre() + " no puede saltar al rio!!!";

    // agrega un individuo a un vecino
    if (vecino->agregarIndividuo(individuos[individuoParaMover]))
    {
        // luego borra el individuo de este lugar
        individuos.erase(individuos.begin() + individuoParaMover);
        return true;
    }
    else
        // si la barca esta ocupada con 2 objetos
        throw(string) "La barca esta llena... Intentalo de nuevo";
}