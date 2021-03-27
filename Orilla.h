/*
  Archivo: Orilla.h
  Fecha creación: marzo-31-2020
  Fecha última modificación: mayo-9-2020
  Versión: 0.1
  Licencia: GPL v3.0
*/

/*
    Clase Orilla
    Relación: es un Lugar
    Intencion:  es un lugar, no se mueve, no tiene limitación de objetos a contener.
*/

#ifndef HH_ORILLA
#define HH_ORILLA

#include "Lugar.h"

class Orilla : public Lugar
{
    protected:
    
    public:
        /**
         * Constructor
        */
        Orilla(string nombre, int capacidad = -1);

        /**
         * Destructor
        */
        virtual ~Orilla();
};

#else 
class Orilla;
#endif