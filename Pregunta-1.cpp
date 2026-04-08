
/*Encontrar el mensaje cifrado (EL Examen Esta Easy), se tiene 2 vectores:
* vector char mensajeCifrado: contiene todas las letras del abecedario, minusculas como mayusculas
* vector int decodifcador: en la cual contiene las posiciones claves de las letras del mensaje a 
* decodificar, tienen un tamano de 19 numeros enteros
* se requiere por medio de apuntadores recorrer en el mensajeCifrado segun el numero del decodificador
* e imprimir el mensaje cifrado, preferible que lo haga con funciones.
* Valor 3 puntos, si utiliza funciones y da con el mensaje cifrado
* Valor 2 puntos, si no utiliza funciones y da con el mensaje
* Valor 0, si no da con el mensaje aunque use funciones
*/

#include<iostream>
#include<conio.h>
using namespace std;

void imprimirMensaje(char *mensaje, int *decodificador, int tamDecodificador, int tamMensaje);

/**********************************************************************************************/

int main() {
    char mensajeCifrado[] = {
        ' ','A','E','I','O','U','a','e','i','o','u',
        'B','C','D','F','G','H','J','K','L','M','N','P','Q','R','S','T','V','W','X','Y','Z',
        'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'
    };
    int decodificador[] = { 2,17,-19,2,48,-44,35,-34,35,-42,2,44,1,-41,-6,2,4,40,5};
    //Seguir desde aquí el código a implementar

    int tamMensaje = sizeof(mensajeCifrado) / sizeof(mensajeCifrado[0]);
    int tamDecodificador = sizeof(decodificador) / sizeof(decodificador[0]);

    imprimirMensaje(mensajeCifrado, decodificador, tamDecodificador, tamMensaje);

    return 0;
}

/*
*/

/**********************************************************************************************/

void imprimirMensaje(char *mensaje, int *decodificador, int tamDecodificador, int tamMensaje) {
    for (int i = 0; i < tamDecodificador; i++) {
        int pos = *(decodificador + i);

        if (pos < 0)
            pos = tamMensaje + pos;  // Ajuste para negativos

        cout << *(mensaje + pos);
    }
    cout << endl;
}

