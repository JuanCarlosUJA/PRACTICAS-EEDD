#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime> //Fallo en el documento faltaba añadir la biblioteca de ctime/time.h
#include "ContenedorImagenes.h"
#include "Imagen.h"

int main() {



    Imagen imagen;
    ContenedorImagenes imagenes(10000);

    std::ifstream is;
    std::stringstream  columnas;
    std::string fila;
    int contador=0;

    std::string id = "";
    std::string email="";
    std::string nombre="";
    int tam = 0;
    int dia = 0;
    int mes = 0;
    int anno = 0;
    std::string etiquetas="";

    is.open("../imagenes_v1.csv"); //carpeta de proyecto
    if ( is.good() ) {

        clock_t t_ini = clock();

        while ( getline(is, fila ) ) {

            //¿Se ha leído una nueva fila?
            if (fila!="") {

                columnas.str(fila);

                //formato de fila: id;email;nombre;tam;fecha;etiquetas

                getline(columnas, id, ';'); //leemos caracteres hasta encontrar y omitir ';'
                getline(columnas,email,';');
                getline(columnas,nombre,';');

                columnas >> tam;   //las secuencia numéricas se leen y trasforman directamente
                columnas.ignore(); //omitimos carácter ';' siguiente

                columnas >> dia; columnas.ignore();
                columnas >> mes; columnas.ignore();
                columnas >> anno; columnas.ignore();

                getline(columnas,etiquetas,';');

                fila="";
                columnas.clear();

                std::cout << ++contador
                          << " Imagen: ( ID=" << id
                          << " Email=" << email << " Fichero=" << nombre << " Tam=" << tam
                          << " Fecha=" << dia << "/" << mes << "/" << anno
                          << " Etiquetas=" << etiquetas
                          << ")" << std::endl;
            }
        }

        is.close();

        std::cout << "Tiempo lectura: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;
    } else {
        std::cout << "Error de apertura en archivo" << std::endl;
    }
}