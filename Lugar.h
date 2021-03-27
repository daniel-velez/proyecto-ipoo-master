/*
  Archivo: Lugar.h
  Fecha creación: marzo-31-2020
  Fecha última modificación: mayo-09-2020
  Versión: 0.1
  Licencia: GPL v3.0
*/

/*
    Clase Lugar

    Relaciones: 
        -conoce Individuos usando un vector de punteros a Individuos
        -conoce un vecino usando un puntero a Lugar 

    Intencion: 
        - Clase padre, las demas clases hijas heredan los metodos
        - Permite agregar uno o varios individuos a un Lugar
        - Mueve los individuos de un lugar a otro
        - Determina si algun individuo se ha sido comido
        - Muestra el numero de individuos en un Lugar
                            
*/

#ifndef HH_LUGAR
#define HH_LUGAR

#include "Individuo.h"
#include <vector>

using namespace std;

class Lugar
{
    protected:
        string nombre;
        vector<Individuo*> individuos;
        int capacidad;

        Lugar *vecino;
        const string cuidador = "Robot";
        
    public:
        /**
          * Constructor
         */
        Lugar(string nombre = "", int capacidad = -1);

        /**
          * Destructor
         */
        virtual ~Lugar();

        //---------------------------------------------------------------------------

        /**
          * getNombre retorna el nombre del lugar 
         */
        virtual string getNombre();
        
        /**
          * agregarIndividuo retorna true si pudo agregar un individuo, en caso contrario false
         */
        virtual bool agregarIndividuo(Individuo* individuo);

        /**
          * agregarIndividuos retorna true si pudo agregar un vector de individuos a  Lugar
          * en caso contrario false
         */
        virtual bool agregarIndividuos(vector <Individuo*> individuos);

        /**
          * getIndividuo retorna un individuo del vector individuos
         */
        virtual Individuo* getIndividuo(int indice);
        
        /**
          * numeroDeIndividuos retorna la cantidad de individuos en Lugar
         */
        virtual int numeroDeIndividuos();
        
        /**
          * existeUnIndividuoDeLaEspecie retorna true si encuentra la especie
          * false en caso contrario
         */
        virtual bool existeUnIndividuoDeLaEspecie(string especie);

        /**
          * pasarTodosLosIndividuosA envia los individuos de un objeto a otro
         */
        virtual void pasarTodosLosIndividuosA(Lugar* lugarDeDestino);

        //---------------------------------------------------------------------------

        /**
          * algunIndividuoHaSidoComido retorna true si se comio un individuo a otro
          * en caso contrario false
         */
        virtual Individuo* algunIndividuoHaSidoComido();

        /**
          * definirVecino asigna un vecino 
         */
        virtual void definirVecino(Lugar* vecino);

        /**
          * moverIndividuo mueve un individuo a partir de una entrada
         */
        virtual bool moverIndividuo(string primeraLetra);

        /**
          * buscarPorLetra retorna un entero de la posicion del individuo que empieza por una letra especifica
         */
        virtual int buscarPorLetra(string primeraLetra);

};

#else
class Lugar;
#endif