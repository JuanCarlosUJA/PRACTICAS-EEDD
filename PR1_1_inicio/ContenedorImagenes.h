//
// Created by admin on 20/09/2022.
//

#ifndef IMAGENES_CONTENEDORIMAGENES_H
#define IMAGENES_CONTENEDORIMAGENES_H


#include "Imagen.h"

class ContenedorImagenes {
private:


    unsigned int _tam = 0;
    unsigned int _num_elementos = 0;
    Imagen *_imagenes = nullptr;




public:
    ContenedorImagenes();
    ContenedorImagenes(unsigned int tamMax);
    ContenedorImagenes(const ContenedorImagenes &origen);
    ContenedorImagenes(const ContenedorImagenes &origen,unsigned int posicionInicial, unsigned int numElementos);

    virtual ~ContenedorImagenes();

};


#endif //IMAGENES_CONTENEDORIMAGENES_H
