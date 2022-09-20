//
// Created by admin on 20/09/2022.
//

#include <stdexcept>
#include "ContenedorImagenes.h"

//@brief Constructor por defecto
ContenedorImagenes::ContenedorImagenes():_tam(100), _num_elementos(0) {
    _imagenes = new Imagen[100];


}
///@brief Constructor parametrizado
ContenedorImagenes::ContenedorImagenes(unsigned int tamMax):_tam(tamMax), _num_elementos(0) {
    _imagenes = new Imagen[tamMax];

}

/*@brief Constructor de copia
 * */
ContenedorImagenes::ContenedorImagenes(const ContenedorImagenes &c):_tam(c._tam),_num_elementos(c._num_elementos) {
    _imagenes = new Imagen[_tam];
    for(int i=0;i<_num_elementos;++i){
        c._imagenes[i] = _imagenes[i]; //Necesario sobrecargar el operador de asignación

    }


}

ContenedorImagenes::ContenedorImagenes(const ContenedorImagenes &origen, unsigned int posicionInicial,
                                       unsigned int numElementos) :_tam(origen._tam),_num_elementos(origen._num_elementos){

    int rango_permitido = _tam - (posicionInicial+1);
    if(_num_elementos > rango_permitido){
        throw std::invalid_argument("El número de elementos no puede ser superior a la capacidad del contenedor");
    }

    _imagenes = new Imagen[_tam];
    int aux = posicionInicial;
    for(int i=0;i<numElementos;++i){
        _imagenes[i] = origen._imagenes[aux];
        ++aux;

    }


}

ContenedorImagenes::~ContenedorImagenes() {
    delete [] _imagenes;
    _imagenes = nullptr;

}

ContenedorImagenes &ContenedorImagenes::operator=(const ContenedorImagenes &otro) {

    if(this != &otro){
        _num_elementos = otro._num_elementos;

        if ( _tam != otro._tam){
            delete [] _imagenes;_imagenes = nullptr;
            _tam = otro._tam;
            _imagenes = new Imagen[_tam];

        }
        //@todo No me cuadra este bucle porque en el caso de que el tamaño sea 5 y hayan 2 huecos solo usados
        //que copio en los 3 huecos restantes
        for (int i=0; i< otro._tam;++i){
            _imagenes[i] = otro._imagenes[i];

        }
    }

    return *this;
}

/**@brief Asigno una foto a una posición determinada del contenedor
 *
 * @param dato Imagen
 * @param pos Posicion a donde queremos ponerla .Entre 1 - tam
 * @throw std::out_of_range Si la posición es inválida
 */
void ContenedorImagenes::asigna(const Imagen &dato, unsigned int pos) {
    int posOrdenador = pos-1;
    if (posOrdenador >0 || posOrdenador > _tam){
        throw std::out_of_range("No se puede añadir la foto porque introduciste una posición inválida");

    }
    _imagenes[posOrdenador] = dato;


}
