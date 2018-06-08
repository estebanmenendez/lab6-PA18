/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conversacion.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 01:30 AM
 */

#ifndef CONVERSACION_H
#define CONVERSACION_H

#include"Mensaje.h"

#include"Grupo.h"
#include"iostream"


using namespace std;

class Conversacion {
public:
    
    Conversacion();
    Conversacion(const Conversacion& orig);
    virtual ~Conversacion();
    
private:
    
        Grupo * grupo;
        int idConv;

};

#endif /* CONVERSACION_H */

