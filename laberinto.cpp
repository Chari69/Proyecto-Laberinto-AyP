#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

// ----- VARIABLES INICIALES -----

int vidaInicial, vida;      // Viva del jugador. Vida actual del jugador
int limEjeX, limEjeY;       // Limites de las dimensiones del laberinto
int cantElem;               // Cantidad de elementos (para ver cuantos cin se deben hacer)
int cantMov;                // Cantidad de movimientos

// ----- VARIABLES GLOBALES DE LOS OBJETOS -----

// Variables de los portales
int portal1_x, portal1_y, portal2_x, portal2_y, portal3_x, portal3_y, portal4_x, portal4_y, portal5_x, portal5_y, portal6_x, portal6_y, portal7_x, portal7_y, portal8_x, portal8_y, portal9_x, portal9_y, portal10_x, portal10_y; 

// Variables de los portales vinculados
int portalVinc1_x, portalVinc1_y, portalVinc2_x, portalVinc2_y, portalVinc3_x, portalVinc3_y, portalVinc4_x, portalVinc4_y, portalVinc5_x, portalVinc5_y, portalVinc6_x, portalVinc6_y, portalVinc7_x, portalVinc7_y, portalVinc8_x, portalVinc8_y, portalVinc9_x, portalVinc9_y, portalVinc10_x, portalVinc10_y;

// Variables de las Trampas
int trampa1_x, trampa1_y, trampa2_x, trampa2_y, trampa3_x, trampa3_y, trampa4_x, trampa4_y, trampa5_x, trampa5_y, trampa6_x, trampa6_y, trampa7_x, trampa7_y, trampa8_x, trampa8_y, trampa9_x, trampa9_y, trampa10_x, trampa10_y; 

// Variables de los muros
int muro1_x, muro1_y, muro2_x, muro2_y, muro3_x, muro3_y, muro4_x, muro4_y, muro5_x, muro5_y, muro6_x, muro6_y, muro7_x, muro7_y, muro8_x, muro8_y, muro9_x, muro9_y, muro10_x, muro10_y; 

// Variables de los tesoros
int tesoro1_x, tesoro1_y, tesoro2_x, tesoro2_y, tesoro3_x, tesoro3_y, tesoro4_x, tesoro4_y, tesoro5_x, tesoro5_y, tesoro6_x, tesoro6_y, tesoro7_x, tesoro7_y, tesoro8_x, tesoro8_y, tesoro9_x, tesoro9_y, tesoro10_x, tesoro10_y; 

// Coordenadas de las entradas y salidas del laberinto
int entrada_x, entrada_y, salida_x, salida_y;

// Posicion Actual del jugador
int player_pos_x, player_pos_y;

// Variables para llevar la cuenta de cada cosa en el laberinto.
int cantPortales, cantTrampas, cantMuros, cantTesoros, cantEntradas, cantSalidas;

// Estadisticas del jugador
int cantTrampas_activadas = 0, cantTesoros_activados = 0;

// ----- FUNCIONES -----

// Funcion que inicializa el juego, pidiendo todas las entradas correspondientes al usuario.
// Asigna las cantidades a las variables globales y se encarga que lo haga de forma correcta.
void inicializar() {
    cin >> vidaInicial >> limEjeX >> limEjeY >> cantElem;

    vida = vidaInicial;

    for (int i = 0; i < cantElem; i++) {
        char tipo;
        int posX, posY;
        int pos2X = 0, pos2Y = 0;
        cin >> tipo >> posX >> posY;

        switch (tipo) {
            case 'P':
                cin >> pos2X >> pos2Y;
                if (cantPortales < 10) {
                    cantPortales++;
                    i++;
                    switch (cantPortales) {
                        case 1: 
                            portal1_x = posX; portal1_y = posY;
                            portalVinc1_x = pos2X; portalVinc1_y = pos2Y;
                            break;
                        case 2: 
                            portal2_x = posX; portal2_y = posY;
                            portalVinc2_x = pos2X; portalVinc2_y = pos2Y;
                            break;
                        case 3: 
                            portal3_x = posX; portal3_y = posY;
                            portalVinc3_x = pos2X; portalVinc3_y = pos2Y;
                            break;
                        case 4: 
                            portal4_x = posX; portal4_y = posY;
                            portalVinc4_x = pos2X; portalVinc4_y = pos2Y;
                            break;
                        case 5: 
                            portal5_x = posX; portal5_y = posY;
                            portalVinc5_x = pos2X; portalVinc5_y = pos2Y;
                            break;
                        case 6: 
                            portal6_x = posX; portal6_y = posY;
                            portalVinc6_x = pos2X; portalVinc6_y = pos2Y;
                            break;
                        case 7: 
                            portal7_x = posX; portal7_y = posY;
                            portalVinc7_x = pos2X; portalVinc7_y = pos2Y;
                            break;
                        case 8: 
                            portal8_x = posX; portal8_y = posY;
                            portalVinc8_x = pos2X; portalVinc8_y = pos2Y;
                            break;
                        case 9: 
                            portal9_x = posX; portal9_y = posY;
                            portalVinc9_x = pos2X; portalVinc9_y = pos2Y;
                            break;
                        case 10: 
                            portal10_x = posX; portal10_y = posY;
                            portalVinc10_x = pos2X; portalVinc10_y = pos2Y;
                            break;
                    }
                    //cout << "Portal en (" << posX << ", " << posY << ")" << endl; // Q
                    //cout << "Vinculado en (" << portalVinc1_x  << ", " << portalVinc1_y << ")" << endl; // Q
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
                    //cout << "Trampa en (" << posX << ", " << posY << ")" << endl; // Q
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
                    //cout << "Muro en (" << posX << ", " << posY << ")" << endl; // Q
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
                    //cout << "Tesoro en (" << posX << ", " << posY << ")" << endl; // Q
                } 
                break;
            case 'E':
                if (cantEntradas < 1) {
                    cantEntradas++;
                    entrada_x = posX; entrada_y = posY;
                    //cout << "Entrada en (" << posX << ", " << posY << ")" << endl; // Q
                } else {
                    //cout << "Solo puede haber una entrada" << endl; // Q
                }
                break;
            case 'S':
                if (cantSalidas < 1) {
                    cantSalidas++;
                    salida_x = posX; salida_y = posY;
                    //cout << "Salida en (" << posX << ", " << posY << ")" << endl; // Q
                } else {
                    //cout << "Solo puede haber una salida" << endl; // Q
                }
                break;
            default:
                //cout << "Tipo de elemento desconocido: " << tipo << endl; // Q
                break;
        }
        
    }

    cin >> cantMov;
    //cout << "Movimientos a Ingresar: " << cantMov << endl; // Q
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

// Funcion que resta vida al jugador. 
void restarVida(int vidaRestada) {
    vida= vida - vidaRestada;
}

// Funcion para comprobar si en la coordenada del jugador hay una trampa y realizar la accion correspondiente.
void comprobarTrampa(int posX, int posY) {
    for(int i = 1; i <= cantTrampas; i++) {
        switch (i) {
            case 1: 
                if(posX == trampa1_x && posY == trampa1_y) {
                    restarVida(10);
                    cantTrampas_activadas++;
                } 
                break;
            case 2:
                if(posX == trampa2_x && posY == trampa2_y) {
                    restarVida(10);
                    cantTrampas_activadas++;
                }
                break;
            case 3:
                if(posX == trampa3_x && posY == trampa3_y) {
                    restarVida(10);
                    cantTrampas_activadas++;
                }
                break;
            case 4:
                if(posX == trampa4_x && posY == trampa4_y) {
                    restarVida(10);
                    cantTrampas_activadas++;
                }
                break;
            case 5:
                if(posX == trampa5_x && posY == trampa5_y) {
                    restarVida(10);
                    cantTrampas_activadas++;
                }
                break;
            case 6:
                if(posX == trampa6_x && posY == trampa6_y) {
                    restarVida(10);
                    cantTrampas_activadas++;
                }
                break;
            case 7:
                if(posX == trampa7_x && posY == trampa7_y) {
                    restarVida(10);
                    cantTrampas_activadas++;
                }
                break;
            case 8:
                if(posX == trampa8_x && posY == trampa8_y) {
                    restarVida(10);
                    cantTrampas_activadas++;
                }
                break;
            case 9:
                if(posX == trampa9_x && posY == trampa9_y) {
                    restarVida(10);
                    cantTrampas_activadas++;
                }
                break;
            case 10:
                if(posX == trampa10_x && posY == trampa10_y) {
                    restarVida(10);
                    cantTrampas_activadas++;
                }
                break;
        }
    }
}

// Funcion para comprobar si en la coordenada del jugador hay un tesoro y realizar la accion correspondiente.
void comprobarTesoro(int posX, int posY) {
    for(int i = 1; i <= cantTesoros; i++) {
        switch (i) {
            case 1: 
                if(posX == tesoro1_x && posY == tesoro1_y) {
                    tesoro1_x = 999;
                    tesoro1_y = 999;
                    sumarVida(20);
                    cantTesoros_activados++;
                } 
                break;
            case 2:
                if(posX == tesoro2_x && posY == tesoro2_y) {
                    tesoro2_x = 999;
                    tesoro2_y = 999;
                    sumarVida(20);
                    cantTesoros_activados++;
                }
                break;
            case 3:
                if(posX == tesoro3_x && posY == tesoro3_y) {
                    tesoro3_x = 999;
                    tesoro3_y = 999;
                    sumarVida(20);
                    cantTesoros_activados++;
                }
                break;
            case 4:
                if(posX == tesoro4_x && posY == tesoro4_y) {
                    tesoro4_x = 999;
                    tesoro4_y = 999;
                    sumarVida(20);
                    cantTesoros_activados++;
                }
                break;
            case 5:
                if(posX == tesoro5_x && posY == tesoro5_y) {
                    tesoro5_x = 999;
                    tesoro5_y = 999;
                    sumarVida(20);
                    cantTesoros_activados++;
                }
                break;
            case 6:
                if(posX == tesoro6_x && posY == tesoro6_y) {
                    tesoro6_x = 999;
                    tesoro6_y = 999;
                    sumarVida(20);
                    cantTesoros_activados++;
                }
                break;
            case 7:
                if(posX == tesoro7_x && posY == tesoro7_y) {
                    tesoro7_x = 999;
                    tesoro7_y = 999;
                    sumarVida(20);
                    cantTesoros_activados++;
                }
                break;
            case 8:
                if(posX == tesoro8_x && posY == tesoro8_y) {
                    tesoro8_x = 999;
                    tesoro8_y = 999;
                    sumarVida(20);
                    cantTesoros_activados++;
                }
                break;
            case 9:
                if(posX == tesoro9_x && posY == tesoro9_y) {
                    tesoro9_x = 999;
                    tesoro9_y = 999;
                    sumarVida(20);
                    cantTesoros_activados++;
                }
                break;
            case 10:
                if(posX == tesoro10_x && posY == tesoro10_y) {
                    tesoro10_x = 999;
                    tesoro10_y = 999;
                    sumarVida(20);
                    cantTesoros_activados++;
                }
                break;
        }
    }
}

// Funcion para comprobar si en la coordenada del jugador hay un portal y realizar la accion correspondiente.
void comprobarPortales(int posX, int posY) {
    for(int i = 1; i <= cantPortales; i++) {
        switch (i) {
            case 1: 
                if(posX == portal1_x && posY == portal1_y) {
                    player_pos_x = portalVinc1_x;
                    player_pos_y = portalVinc1_y;
                }
                else if(posX == portalVinc1_x && posY == portalVinc1_y){
                    player_pos_x = portal1_x;
                    player_pos_y = portal1_y;
                }
                break;
            case 2: 
                if(posX == portal2_x && posY == portal2_y) {
                    player_pos_x = portalVinc2_x;
                    player_pos_y = portalVinc2_y;
                }
                else if(posX == portalVinc2_x && posY == portalVinc2_y){
                    player_pos_x = portal2_x;
                    player_pos_y = portal2_y;
                }
                break;
            case 3: 
                if(posX == portal3_x && posY == portal3_y) {
                    player_pos_x = portalVinc3_x;
                    player_pos_y = portalVinc3_y;
                }
                else if(posX == portalVinc3_x && posY == portalVinc3_y){
                    player_pos_x = portal3_x;
                    player_pos_y = portal3_y;
                }
                break;
            case 4: 
                if(posX == portal4_x && posY == portal4_y) {
                    player_pos_x = portalVinc4_x;
                    player_pos_y = portalVinc4_y;
                }
                else if(posX == portalVinc4_x && posY == portalVinc4_y){
                    player_pos_x = portal4_x;
                    player_pos_y = portal4_y;
                }
                break;
            case 5: 
                if(posX == portal5_x && posY == portal5_y) {
                    player_pos_x = portalVinc5_x;
                    player_pos_y = portalVinc5_y;
                }
                else if(posX == portalVinc5_x && posY == portalVinc5_y){
                    player_pos_x = portal5_x;
                    player_pos_y = portal5_y;
                }
                break;
            case 6: 
                if(posX == portal6_x && posY == portal6_y) {
                    player_pos_x = portalVinc6_x;
                    player_pos_y = portalVinc6_y;
                }
                else if(posX == portalVinc6_x && posY == portalVinc6_y){
                    player_pos_x = portal6_x;
                    player_pos_y = portal6_y;
                }
                break;
            case 7: 
                if(posX == portal7_x && posY == portal7_y) {
                    player_pos_x = portalVinc7_x;
                    player_pos_y = portalVinc7_y;
                }
                else if(posX == portalVinc7_x && posY == portalVinc7_y){
                    player_pos_x = portal7_x;
                    player_pos_y = portal7_y;
                }
                break;
            case 8: 
                if(posX == portal8_x && posY == portal8_y) {
                    player_pos_x = portalVinc8_x;
                    player_pos_y = portalVinc8_y;
                }
                else if(posX == portalVinc8_x && posY == portalVinc8_y){
                    player_pos_x = portal8_x;
                    player_pos_y = portal8_y;
                }
                break;
            case 9: 
                if(posX == portal9_x && posY == portal9_y) {
                    player_pos_x = portalVinc9_x;
                    player_pos_y = portalVinc9_y;
                }
                else if(posX == portalVinc9_x && posY == portalVinc9_y){
                    player_pos_x = portal9_x;
                    player_pos_y = portal9_y;
                }
                break;
            case 10: 
                if(posX == portal10_x && posY == portal10_y) {
                    player_pos_x = portalVinc10_x;
                    player_pos_y = portalVinc10_y;
                }
                else if(posX == portalVinc10_x && posY == portalVinc10_y){
                    player_pos_x = portal10_x;
                    player_pos_y = portal10_y;
                }
                break;
        }
    }
}

// Funcion para comprobar si en la coordenada del jugador hay un muro.
bool comprobarMuro(int posX, int posY) {
    for(int i = 1; i <= cantMuros; i++) {
        switch (i) 
        {
            case 1: 
                if(posX == muro1_x && posY == muro1_y) {
                    return true;
                }
                break;
            case 2:
                if(posX == muro2_x && posY == muro2_y) {
                    return true;
                }
                break;
            case 3:
                if(posX == muro3_x && posY == muro3_y) {
                    return true;
                }
                break;
            case 4:
                if(posX == muro4_x && posY == muro4_y) {
                    return true;
                }
                break;
            case 5:
                if(posX == muro5_x && posY == muro5_y) {
                    return true;
                }
                break;
            case 6:
                if(posX == muro6_x && posY == muro6_y) {
                    return true;
                }
                break;
            case 7:
                if(posX == muro7_x && posY == muro7_y) {
                    return true;
                }
                break;
            case 8:
                if(posX == muro8_x && posY == muro8_y) {
                    return true;
                }
                break;
            case 9:
                if(posX == muro9_x && posY == muro9_y) {
                    return true;
                }
                break;
            case 10:
                if(posX == muro10_x && posY == muro10_y) {
                    return true;
                }
                break;
            default:
                return false;

        }
    }
    return false;
}

void asignarPosInicial() {
    player_pos_x = entrada_x;
    player_pos_y = entrada_y;
}

// ----- MAIN -----

int main() 
{
    inicializar();
    asignarPosInicial();

    int x_deseada, y_deseada;
    char direction;
    bool juego_terminado = false;

    while(!juego_terminado)
    {
        //cout << "Ingresa un movimiento: "; // Q
        cin >> direction;

        // MOVIMIENTO

        if(direction=='w'&&player_pos_y<limEjeY)
        {
            y_deseada= player_pos_y+1;
            if(!comprobarMuro(player_pos_x, y_deseada)){
                player_pos_y++;
            }
            else{
                //cout<<"Movimiento bloqueado"<<endl;
            }
            cantMov--;
        }
        else if(direction=='s'&&player_pos_y>0)
        {
            y_deseada= player_pos_y-1;
            if(!comprobarMuro(player_pos_x, y_deseada)){
                player_pos_y--;
            }
            else{
                //cout<<"Movimiento bloqueado"<<endl;
            }
            cantMov--;
        }
        else if(direction=='d'&&player_pos_x<limEjeX)
        {
            x_deseada= player_pos_x+1;
            if(!comprobarMuro(x_deseada, player_pos_y)){
                player_pos_x++;
            }
            else{
                //cout<<"Movimiento bloqueado"<<endl;
            }
            cantMov--;
        }
        else if(direction=='a'&&player_pos_x>0)
        {
            x_deseada= player_pos_x-1;
            if(!comprobarMuro(x_deseada, player_pos_y)){
                player_pos_x--;
            }
            else{
                //cout<<"Movimiento bloqueado"<<endl;
            }
            cantMov--;
        }
        else{
            //cout<<"Movimiento bloqueado"<<endl;
        }
        
        //ACCIONES EN CASILLAS
        comprobarTrampa(player_pos_x, player_pos_y);
        comprobarTesoro(player_pos_x, player_pos_y);
        comprobarPortales(player_pos_x, player_pos_y);

        //cout<<player_pos_x<<" "<<player_pos_y<<endl; //Q
        //cout<<"Vida actual: " << vida <<endl; // Q
        if(player_pos_x == salida_x && player_pos_y == salida_y)
        {
            juego_terminado=true;
            cout<<"TESOROS:"<<cantTesoros_activados<<endl;
            cout<<"TRAMPAS:"<<cantTrampas_activadas<<endl;
            cout<<"VIDA:"<<vida<<endl;
            if(cantTesoros_activados == cantTesoros){
                cout<<"SORPRENDENTE";
            }
            else{
                cout<<"LOGRADO";
            }
            return 0;
        }
        if (vida <= 0)
        {   
            juego_terminado=true;
            cout<<"TESOROS:"<<cantTesoros_activados<<endl;
            cout<<"TRAMPAS:"<<cantTrampas_activadas<<endl;
            cout<<"VIDA:"<<vida<<endl;
            cout<<"MUERTO";
            return 0;
        }
        if (cantMov == 0)
        {
            juego_terminado=true;
            cout<<"TESOROS:"<<cantTesoros_activados<<endl;
            cout<<"TRAMPAS:"<<cantTrampas_activadas<<endl;
            cout<<"VIDA:"<<vida<<endl;
            cout<<"ATRAPADO";
            return 0;
        }
    }

    return 0;
}
