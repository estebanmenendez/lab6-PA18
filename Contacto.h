/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Contacto.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 01:32 AM
 */

#ifndef CONTACTO_H
#define CONTACTO_H

#include"Mensaje.h"
#include "DtMContacto.h"
class Contacto : public Mensaje {
public:
    Contacto();
    Contacto(const Contacto& orig);
    virtual ~Contacto();
    DtMContacto* getMensaje();
    int GetNumCel();
    void SetNumCel(int);
    
    void setNombre(string nombre);
    void setUrl(string urlImagen);
    void setDesc(string descripcion);
    
    string getNombre();
    string getUrl();
    string getDesc();
private:
    int numCel;
    string nombre, urlImagen, desc;
};

#endif /* CONTACTO_H */

