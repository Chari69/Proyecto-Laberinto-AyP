#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

int vidaInicial, vida;            // Viva del jugador                  // Vida actual del jugador
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
    vida= vida - vidaRestada;
}

int main() 
{
    inicializar();
    int player_pos_x, player_pos_y;
    player_pos_x=1;//luego vamos a cambiarlo por la coordenada x de la ENTRADA
    player_pos_y=1;//luego vamos a cambiarlo por la coordenada y de la ENTRADA
    string direction;

    while(!juego_terminado)
    {
        cout << "Ingresa un movimiento: ";
        cin >> direction;

        // MOVIMIENTO

        if(direction=="w"&&player_pos_y<limEjeY)
        {
            player_pos_y++;
        }
        else if(direction=="s"&&player_pos_y>0)
        {
            player_pos_y--;
        }
        else if(direction=="d"&&player_pos_x<limEjeX)
        {
            player_pos_x++;
        }
        else if(direction=="a"&&player_pos_x>0)
        {
            player_pos_x--;
        }
        else{
            cout<<"Movimiento bloqueado"<<endl;
        }
        
        //ACCIONES EN CASILLAS
        
        //

        cout<<player_pos_x<<" "<<player_pos_y; //linea provisional
        if (vida==0)
        {   
            juego_terminado=true;
        }
    }

    cout<<"MUERTO";

    return 0;
}
