/*
  Archivo: Individuo.h
  Fecha creación: marzo-31-2020
  Fecha última modificación: mayo-09-2020
  Versión: 0.1
  Licencia: GPL v3.0
*/

/*
    Clase: Individuo
    Relación: ninguna
    Intención: modelar un individuo con un nombre, una especie a la cual pertenece y una especie que puede comer. Representa a el robot, el conejo, el zorro, etc.
*/

#ifndef HH_INDIVIDUO
#define HH_INDIVIDUO

#include <string>
using namespace std;

class Individuo
{
    protected:
        string nombre;
        string especie;
        string alimentacion;

    public:
        /**
         * Constructor
        */
        Individuo(string nombre, string especie = "");
        
        /**
         * Destructor 
        */
        virtual ~Individuo();
        
        /**
         * getNombre retorna un string del nombre del individuo
        */
        virtual string getNombre();

        /**
         * getEspecie retorna un string de la especie del individuo
        */
        virtual string getEspecie();

        /**
         * agregarAlimentacion añade un string de la especie que el individuo puede comer. 
        */
        virtual void agregarAlimentacion(string alimentacion);

        /**
         * intentarComer retorna true si el individuo que recibe el método es de la especie que puede comer el individuo.
        */
        virtual bool intentarComer(Individuo* individuo);
};

#else
class Individuo;
#endif