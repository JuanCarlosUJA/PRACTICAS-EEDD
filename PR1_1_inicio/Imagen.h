//
// Created by admin on 20/09/2022.
//

#ifndef IMAGENES_IMAGEN_H
#define IMAGENES_IMAGEN_H


#include <string>
#include "fecha.h"

class Imagen {
private:
    std::string _id = "";
    std::string _email = "";
    std::string _nombre = "";
    unsigned int _tam = 0;
    Fecha _fecha;
    std::string _etiquetas = "";

public:
    Imagen() = default; //Lo dejaré sin implementar porque solo quiero un constructor parametrizado
    Imagen(const string &id, const string &email, const string &nombre, unsigned int tam, const Fecha &fecha,
           const string &etiquetas);

    const string &getId() const;
    Imagen& setId(const string &id);
    const string &getEmail() const;
    Imagen& setEmail(const string &email);
    const string &getNombre() const;
    Imagen& setNombre(const string &nombre);

    Imagen& operator= (const Imagen &orig);

    virtual ~Imagen();

    //@toDo atributos y métodos


};


#endif //IMAGENES_IMAGEN_H
