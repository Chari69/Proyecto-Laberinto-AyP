#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

int vidaInicial, vida;      // Viva del jugador. Vida actual del jugador
int limEjeX, limEjeY;       // Limites de las dimensiones del laberinto
int cantElem;               // Cantidad de elementos (para ver cuantos cin se deben hacer)
int cantMov;                // Cantidad de movimientos

// Variables Globales de las coordenadas
int portal1_x, portal1_y, portal2_x, portal2_y, portal3_x, portal3_y, portal4_x, portal4_y, portal5_x, portal5_y, portal6_x, portal6_y, portal7_x, portal7_y, portal8_x, portal8_y, portal9_x, portal9_y, portal10_x, portal10_y; // Ejes X, Y de los portales.

int trampa1_x, trampa1_y, trampa2_x, trampa2_y, trampa3_x, trampa3_y, trampa4_x, trampa4_y, trampa5_x, trampa5_y, trampa6_x, trampa6_y, trampa7_x, trampa7_y, trampa8_x, trampa8_y, trampa9_x, trampa9_y, trampa10_x, trampa10_y; // Ejes X, Y de las trampas.

int muro1_x, muro1_y, muro2_x, muro2_y, muro3_x, muro3_y, muro4_x, muro4_y, muro5_x, muro5_y, muro6_x, muro6_y, muro7_x, muro7_y, muro8_x, muro8_y, muro9_x, muro9_y, muro10_x, muro10_y; // Ejes X, Y de los muros.

int tesoro1_x, tesoro1_y, tesoro2_x, tesoro2_y, tesoro3_x, tesoro3_y, tesoro4_x, tesoro4_y, tesoro5_x, tesoro5_y, tesoro6_x, tesoro6_y, tesoro7_x, tesoro7_y, tesoro8_x, tesoro8_y, tesoro9_x, tesoro9_y, tesoro10_x, tesoro10_y; // Ejes X, Y de los tesoros.

int entrada_x, entrada_y, salida_x, salida_y;

int cantPortales, cantTrampas, cantMuros, cantTesoros, cantEntradas, cantSalidas;

// Funcion que inicializa el juego, pidiendo todas las entradas correspondientes al usuario.
// Asigna las cantidades a las variables globales y se encarga que lo haga de forma correcta.
void inicializar() {
    cin >> vidaInicial >> limEjeX >> limEjeY >> cantElem;

    vida = vidaInicial;

    for (int i = 0; i < cantElem; i++) {
        char tipo;
        int posX, posY;
        cin >> tipo >> posX >> posY;

        switch (tipo) {
            case 'P':
                if (cantPortales < 10) {
                    cantPortales++;
                    switch (cantPortales) {
                        case 1: portal1_x = posX; portal1_y = posY; break;
                        case 2: portal2_x = posX; portal2_y = posY; break;
                        case 3: portal3_x = posX; portal3_y = posY; break;
                        case 4: portal4_x = posX; portal4_y = posY; break;
                        case 5: portal5_x = posX; portal5_y = posY; break;
                        case 6: portal6_x = posX; portal6_y = posY; break;
                        case 7: portal7_x = posX; portal7_y = posY; break;
                        case 8: portal8_x = posX; portal8_y = posY; break;
                        case 9: portal9_x = posX; portal9_y = posY; break;
                        case 10: portal10_x = posX; portal10_y = posY; break;
                    }
                    cout << "Portal en (" << posX << ", " << posY << ")" << endl;
                }
                break;
            case 'X':
                if (cantTrampas < 10) {
                    cantTrampas++;
                    switch (cantTrampas) {
                        case 1: trampa1_x = posX; trampa1_y = posY; break;
                        case 2: trampa2_x = posX; trampa2_y = posY; break;
                        case 3: trampa3_x = posX; trampa3_y = posY; break;
                        case 4: trampa4_x = posX; trampa4_y = posY; break;
                        case 5: trampa5_x = posX; trampa5_y = posY; break;
                        case 6: trampa6_x = posX; trampa6_y = posY; break;
                        case 7: trampa7_x = posX; trampa7_y = posY; break;
                        case 8: trampa8_x = posX; trampa8_y = posY; break;
                        case 9: trampa9_x = posX; trampa9_y = posY; break;
                        case 10: trampa10_x = posX; trampa10_y = posY; break;
                    }
                    cout << "Trampa en (" << posX << ", " << posY << ")" << endl;
                } 
                break;
            case '#':
                if (cantMuros < 10) {
                    cantMuros++;
                    switch (cantMuros) {
                        case 1: muro1_x = posX; muro1_y = posY; break;
                        case 2: muro2_x = posX; muro2_y = posY; break;
                        case 3: muro3_x = posX; muro3_y = posY; break;
                        case 4: muro4_x = posX; muro4_y = posY; break;
                        case 5: muro5_x = posX; muro5_y = posY; break;
                        case 6: muro6_x = posX; muro6_y = posY; break;
                        case 7: muro7_x = posX; muro7_y = posY; break;
                        case 8: muro8_x = posX; muro8_y = posY; break;
                        case 9: muro9_x = posX; muro9_y = posY; break;
                        case 10: muro10_x = posX; muro10_y = posY; break;
                    }
                    cout << "Muro en (" << posX << ", " << posY << ")" << endl;
                } 
                break;
            case 'T':
                if (cantTesoros < 10) {
                    cantTesoros++;
                    switch (cantTesoros) {
                        case 1: tesoro1_x = posX; tesoro1_y = posY; break;
                        case 2: tesoro2_x = posX; tesoro2_y = posY; break;
                        case 3: tesoro3_x = posX; tesoro3_y = posY; break;
                        case 4: tesoro4_x = posX; tesoro4_y = posY; break;
                        case 5: tesoro5_x = posX; tesoro5_y = posY; break;
                        case 6: tesoro6_x = posX; tesoro6_y = posY; break;
                        case 7: tesoro7_x = posX; tesoro7_y = posY; break;
                        case 8: tesoro8_x = posX; tesoro8_y = posY; break;
                        case 9: tesoro9_x = posX; tesoro9_y = posY; break;
                        case 10: tesoro10_x = posX; tesoro10_y = posY; break;
                    }
                    cout << "Tesoro en (" << posX << ", " << posY << ")" << endl;
                } 
                break;
            case 'E':
                if (cantEntradas < 1) {
                    cantEntradas++;
                    entrada_x = posX; entrada_y = posY;
                    cout << "Entrada en (" << posX << ", " << posY << ")" << endl;
                } else {
                    cout << "Solo puede haber una entrada" << endl;
                }
                break;
            case 'S':
                if (cantSalidas < 1) {
                    cantSalidas++;
                    salida_x = posX; salida_y = posY;
                    cout << "Salida en (" << posX << ", " << posY << ")" << endl;
                } else {
                    cout << "Solo puede haber una salida" << endl;
                }
                break;
            default:
                cout << "Tipo de elemento desconocido: " << tipo << endl;
                break;
        }
        
    }

    cin >> cantMov;
    cout << "Movimientos a Ingresar: " << cantMov << endl;
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
    bool juego_terminado = false;

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
