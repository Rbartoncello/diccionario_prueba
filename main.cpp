#include <iostream>
#include <fstream>
#include "diccionario.h"
#include "emojis.h"
#include "constantes.h"
#include "edificio.h"

string buscar_tipo_emoji(string nombre_edificio){
    string emoji;

    if (nombre_edificio == EDIFICIO_MINA){
        emoji = EMOJI_MINA;
    } else if (nombre_edificio == EDIFICIO_ASERRADERO){
        emoji = EMOJI_ASERRADERO;
    } else if (nombre_edificio == EDIFICIO_FABRICA){
        emoji = EMOJI_FABRICA;
    } else if (nombre_edificio == EDIFICIO_ESCUELA){
        emoji = EMOJI_ESCUELA;
    } else if (nombre_edificio == EDIFICIO_OBELISCO){
        emoji = EMOJI_OBELISCO;
    } else if (nombre_edificio == EDIFICIO_PLANTA_ELECTRICA){
        emoji = EMOJI_PLANTA_ENERGIA;
    }
    
    return emoji;  
}



int main() {
    Diccionario* diccionario = new Diccionario;

    ifstream archivo(PATH_EDIFICIO);
    string nombre, piedra, madera, metal, max_cant_permitidos, nombre_aux;

    if (!archivo.is_open()){
        cout << "No se pudo abrir el archivo: " << PATH_EDIFICIO << endl;
        return ERROR;
    } else {
        while ( archivo >> nombre ){
            if (nombre == PLANTA){
                archivo >> nombre_aux;
                nombre += " " + nombre_aux;
            }
            
            string emoji = buscar_tipo_emoji(nombre);
            archivo >> piedra;
            archivo >> madera;
            archivo >> metal;
            archivo >> max_cant_permitidos;

            diccionario->insertar(new Edificio (nombre, emoji, stoi(piedra), stoi(madera), stoi(metal), stoi(max_cant_permitidos)));
        }
        archivo.close();
    }

    diccionario->imprimir_in_orden();

    string nombre_edificio = "fabrica";
    cout << endl << "Piedra: " << diccionario->buscar(nombre_edificio).devoler_piedra() << " Madera: " << diccionario->buscar(nombre_edificio).devoler_madera() << " Metal: " << diccionario->buscar(nombre_edificio).devoler_metal() << endl;

    delete diccionario;
    return 0;
}
