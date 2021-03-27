/*
  Archivo: Jugador.cpp
  Fecha creación: abril-04-2020
  Fecha última modificación: mayo-09-2020
  Versión: 0.1
  Licencia: GPL v3.0
*/

#include "Jugador.h"
#include <array>

Jugador::Jugador(array<Lugar *, 4> *mapa, Barca *barca, Orilla *orillaIzquierda, Orilla *orillaDerecha) : mapa(mapa), barca(barca), orillaIzquierda(orillaIzquierda), orillaDerecha(orillaDerecha)
{
    consoleRowSize = (*mapa)[0]->numeroDeIndividuos();
}

Jugador::~Jugador()
{
    /* No hace nada */
}

void Jugador::jugar()
{
    do
    {
        mostrarJuego();

        while (true) // recibir entradas hasta que la entrada sea valida
        {
            try
            {
                recibirEntrada();
                break;
            }
            catch (string mensaje)
            {
                cout << mensaje << endl;
            }
        }
    } while (comprobarEstadoDelJuego());
}

void Jugador::mostrarJuego()
{
    // limpiar consola
    cout << "\033c";
    // **HAY DETALLES CON EL COMANDO DE LIMPIAR CONSOLA, EL ANTERIOR SIRVE PARA LINUX**

    // instrucciones del juego
    cout << "\033[1;44;38;2;255;155;0mJUEGO LA BARCA\033[0m" << endl
         << "El juego consiste en pasar todos los personajes de un lado del rio al otro." << endl
         << endl
         << "Para mover un personaje presione la primera letra de su nombre. Para mover la Barca presione \033[1;36mB\033[0m. Para salir presione la letra \033[1;36mS\033[0m, para reiniciar el juego presione la letra \033[1;36mJ\033[0m." << endl
         << "Recuerde: la Barca solamente se moverá si hay un " + barca->getConductor() + "  en ella." << endl
         << "\033[38;2;255;0;0m!Tenga cuidado!\033[0m si un individuo se come a otro, pierde! " << endl
         << endl;

    // se muestran los Lugares
    for (int i = 0; i < (*mapa).size(); i++)
    {
        string nombre = (*mapa)[i]->getNombre();
        if ((*mapa)[i] == barca)
            cout << "| \033[1;38;2;210;105;30m" + nombre + "\033[0m" + string(consoleColumnSize - nombre.size(), ' ');
        else
            cout << "| \033[1;38;2;185;255;0m" + nombre + "\033[0m" + string(consoleColumnSize - nombre.size(), ' ');
    }
    cout << "|" << endl;

    // se muestran los Individuos de cada lugar
    for (int j = 0; j < consoleRowSize; j++)
    {
        for (int i = 0; i < (*mapa).size(); i++)
        {
            Individuo *individuo = (*mapa)[i]->getIndividuo(j);
            if (individuo)
            {
                string nombre = individuo->getNombre();
                cout << "| " << nombre << string(consoleColumnSize - nombre.size(), ' ');
            }
            else
                cout << "| " << string(consoleColumnSize, ' ');
        }
        cout << "|" << endl;
    }

    cout << endl;
}

void Jugador::recibirEntrada()
{
    string orden = recibirUnCaracter();

    if (orden == "B")
        barca->moverBarca(mapa);

    else if (orden == "S")
        exit(0);

    else if (orden == "J")
        reiniciar();

    else
    {
        // realizar el movimiento de un personaje
        for (int i = 0; i < (*mapa).size(); i++)
        {
            if ((*mapa)[i]->moverIndividuo(orden))
                return;
        }

        throw "No hay ningun personaje que empiece con la letra " + orden;
    }
}

void Jugador::reiniciar()
{
    // regresa todos los individuos a la orilla izquierda
    for (int i = 1; i < (*mapa).size(); i++)
        (*mapa)[i]->pasarTodosLosIndividuosA(orillaIzquierda);

    // regresa la barca al lado de la orilla izquierda
    if ((*mapa)[2] == barca)
        barca->moverBarca(mapa, false);
}

bool Jugador::comprobarEstadoDelJuego()
{
    // se verifica si algun individuo ha podido comerse a otro
    for (int i = 0; i < (*mapa).size(); i++)
    {
        Individuo *individuoComido = (*mapa)[i]->algunIndividuoHaSidoComido();
        if (individuoComido)
        {
            mostrarJuego();

            // el mensaje
            srand(time(NULL));
            int yearBirth = rand() % 10;
            cout << string((individuoComido->getNombre().size() + 7) / 2, ' ') + "\033[3mR.I.P." << endl;
            cout << "\033[4;38;2;150;150;150m-- \u2620  " + individuoComido->getNombre() + " \u2620  --\033[0m" << endl;
            cout << string((individuoComido->getNombre().size() + 3) / 2, ' ') + "200" << yearBirth << "-2020\n"
                 << endl;
            cout << "\033[1;38;2;255;0;0m¡¡HAS PERDIDO!! \033[0m\n"
                 << endl;

            menuDespuesDeGanarOPerder();
        }
    }

    // se verifica que todos los individuos han pasado a la orilla derecha
    int totalDeIndividuos = consoleRowSize;
    if (orillaDerecha->numeroDeIndividuos() == totalDeIndividuos)
    {
        mostrarJuego();
        cout << "\033[1;38;2;0;255;0m¡¡HAS GANADO!!\033[0m\n"
             << endl;
        menuDespuesDeGanarOPerder();
    }

    return true;
}

void Jugador::menuDespuesDeGanarOPerder()
{
    cout << "Para salir del juego presione la letra \033[1;36mS\033[0m, para reiniciar presione la letra \033[1;36mJ\033[0m." << endl;

    string orden;
    try
    {
        orden = recibirUnCaracter();
    }
    catch (string mensaje)
    {
        exit(0);
    }

    if (orden == "S")
        exit(0);
    else if (orden == "J")
        reiniciar();
    else
        exit(0);
}

string Jugador::recibirUnCaracter()
{
    string orden = "";
    cout << "Ingrese una orden: \033[1;38;2;61;242;234m";
    getline(cin, orden);
    cout << "\033[0m";

    if (orden.size() == 0)
        throw(string) "¡No ha ingresado ninguna orden!";

    if (orden.size() > 1)
        throw(string) "¡Solo puedes ingresar una letra!";

    orden[0] = toupper(orden[0]); // se convierte la orden de minúscula a mayúscula

    return orden;
}
