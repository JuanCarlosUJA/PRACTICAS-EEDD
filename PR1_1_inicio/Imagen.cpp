//
// Created by admin on 20/09/2022.
//

#include "Imagen.h"

/**
 * @brief Constructor parametrizado de Imagen para crearla a partir de todos los valores
 * */

Imagen::Imagen(const string &id, const string &email, const string &nombre, unsigned int tam, const Fecha &fecha,
               const string &etiquetas) : _id(id), _email(email), _nombre(nombre), _tam(tam), _fecha(fecha),
                                          _etiquetas(etiquetas) {

}

const string &Imagen::getId() const {
    return _id;
}

Imagen& Imagen::setId(const string &id) {
    _id = id;
    return *this;
}

const string &Imagen::getEmail() const {
    return _email;
}

Imagen& Imagen::setEmail(const string &email) {
    _email = email;
    return *this;
}

const string &Imagen::getNombre() const {
    return _nombre;
}

Imagen& Imagen::setNombre(const string &nombre) {
    _nombre = nombre;
    return *this;
}

/**
 * @brief Sobrecarga del operador de asignación
 * @param [in] orig Imagen de la cual queremos asignar sus datos a otra
 * @return [out] *this Referencia al propio objeto para poder hacer asignaciones encadenadas
 * */
Imagen &Imagen::operator=(const Imagen &orig) {

    //Comprobamos si estamos asignando el mismo objeto
    if(this != &orig){
        _id = orig._id;
        _email = orig._email;
        _nombre = orig._nombre;
        _tam = orig._tam;
        _fecha = orig._fecha;
        _etiquetas = orig._etiquetas;
    }



    return *this;
}

Imagen::~Imagen() {

}
