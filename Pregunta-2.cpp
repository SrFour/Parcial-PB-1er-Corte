/*
/* Cifrar y Descifrar mensajes, segun el desplazamiento de letras
* vector char codificacionDecodificacion: contiene todas las letras del abecedario, minusculas 
* como mayusculas
* metodo cifrarMensaje que debe, segun el desplazamiento, cifrar el mensaje
* metodo descifrarMensaje que debe, segun el desplazamiento, descifrar el mensaje
* Todo debe realizarse por punteros
* Debe imprimir el mensaje cifrado y el mensaje descifrado (Que debe ser igual mensaje original)
* EL MENSAJE NO DEBE TENER ESPACIOS EN BLANCO, cuando se le solicite el mensaje
* Ejemplo: digita "HolaComoEstas" cuando se cifre el mensaje debe imprimir algo como esto
* "LCpoGCqCUwxow", y cuando descifre el mensaje de imprimir igual al mensaje original, es decir
* "HolaComoEstas"
* Valor 2 puntos, si realiza de forma correcta los dos metodos
* Valor 1, si solo funciona un solo metodo
* Valor 0, sino funciona ninguno de los dos
*/


#include<iostream>
#include<conio.h>
#include<string.h>


using namespace std;

char codificacionDecodificacion[] = {
        ' ','A','E','I','O','U','a','e','i','o','u',
        'B','C','D','F','G','H','J','K','L','M','N','P','Q','R','S','T','V','W','X','Y','Z',
        'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'
};



int buscarPosicion(char letra, char* code, int tam) {
    for (int i = 0; i < tam; i++) {
        if (*(code + i) == letra) {
            return i;
        }
    }
    return -1;
}

// Función para cifrar un mensaje utilizando el cifrado César
void cifrarMensaje(char* m, int desplazamiento, char* code) {
    int tam = sizeof(codificacionDecodificacion)/sizeof(codificacionDecodificacion[0]);
    cout<<"Mensaje cifrado: ";
    for (char* ptr = m; *ptr != '\0'; ptr++) {
        int pos = buscarPosicion(*ptr, code, tam);
        if (pos != -1) {
            int nuevaPos = (pos + desplazamiento) % tam;
            cout<<*(code + nuevaPos);
        }
    }
    cout<<endl;
}

// Función para descifrar un mensaje utilizando el cifrado César
void descifrarMensaje(char* m, int desplazamiento, char* code) {
    int tam = sizeof(codificacionDecodificacion)/sizeof(codificacionDecodificacion[0]);
    cout<<"Mensaje descifrado: ";
    for (char* ptr = m; *ptr != '\0'; ptr++) {
        int pos = buscarPosicion(*ptr, code, tam);
        if (pos != -1) {
            int nuevaPos = (pos - desplazamiento + tam) % tam;
            cout<<*(code + nuevaPos);
        }
    }
    cout << endl;
}

/******************************************************************************************/

int main() {
    char mensaje[100];
    int d = 0;

    cout<<"Digite mensaje a cifrar: ";
    cin>>mensaje;
    cout<<"Digite desplazamiento: ";
    cin>>d;
    cifrarMensaje(mensaje, d, codificacionDecodificacion);

    cout<<endl<<"Digite mensaje a descifrar: ";
    cin>>mensaje;
    descifrarMensaje(mensaje, d, codificacionDecodificacion);

    return 0;
}

/**********************************************************************************************/
