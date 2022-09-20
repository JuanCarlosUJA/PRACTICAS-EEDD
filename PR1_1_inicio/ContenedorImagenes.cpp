//
// Created by admin on 20/09/2022.
//

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

    }


}

ContenedorImagenes::ContenedorImagenes(const ContenedorImagenes &origen, unsigned int posicionInicial,
                                       unsigned int numElementos) {

}

ContenedorImagenes::~ContenedorImagenes() {
    delete [] _imagenes;

}
