#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

// FUNCION INTERNA: Esto debe ser borrado. Solo es para pruebas.
// SI LO DEJAMOS SACAMOS 01.
#include <thread> 
#include <chrono> 
// Espera x segundos antes de continuar la ejecucion.
void sleep(int tiempo) {
    std::this_thread::sleep_for(std::chrono::seconds(tiempo)); 
}
//  LO DE ARRIBA DEBE SER BORRADO ANTES DE ENTREGAR EL PROYECTO

int vidaInicial;            // Viva del jugador
int vida;                   // Vida actual del jugador
int limEjeX, limEjeY;       // Limites de las dimensiones del laberinto
int cantElem;               // Cantidad de elementos (para ver cuantos cin se deben hacer)
int cantMov;                // Cantidad de movimientos

// Funcion que inicializa el juego, pidiendo todas las entradas correspondientes al usuario.
// Asigna las cantidades a las variables globales y se encarga que lo haga de forma correcta.
void inicializar() {
    cin >> vidaInicial >> limEjeX >> limEjeY >> cantElem;

    vida = vidaInicial;

    // [aca deberia ir la logica de la cantidad de elementos y como se guardan]

    cin >> cantMov;
}

// Funcion que suma vida al jugador, sin pasar de la vida inicial.
void sumarVida(int vidaAnadida) {
    int chequeoVida = vida + vidaAnadida;
    if (chequeoVida > vidaInicial) {
        vida = vidaInicial;
    }
    else {
        vida = chequeoVida;
    }
}

void restarVida(int vidaRestada) {
    int chequeoVida = vida - vidaRestada;
    if (chequeoVida <= 0) {
        vida = 0;
        cout << "Has muerto" << endl;
        cout << "Vida:" << vida << endl;
        // HAS MUERTO
        // aca deberia finalizar el programa y mostrar estadisticas, deberia hacerse una funcion para ello.
    }
    else {
        vida = chequeoVida;
        cout << "Vida:" << vida << endl;
    }
}

int main() 
{
    inicializar();
    restarVida(50);
    sumarVida(52);
    cout << "Vida:" << vida << endl;
    restarVida(99);
    restarVida(1);
    restarVida(12);
    return 0;
}