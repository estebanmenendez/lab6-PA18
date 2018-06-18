/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fabrica.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 01:40 AM
 */




#ifndef FABRICA_H
#define FABRICA_H

#include"ContGrupo.h"
#include"ContMensaje.h"
#include"ContUsuario.h"

class Fabrica {
    //Fabrica es singleton
private:
    ContUsuario * cUsu;
    ContMensaje * cMens;
    ContGrupo * cGru;
    Fabrica();
    static Fabrica* fabrica;
    
public:
    
    static Fabrica* getInstance();
    iContUsuario* getContUsuario();
    iContMensaje* getContMensaje();
    iContGrupo* getContGrupo();

    //destructor
    virtual ~Fabrica();
private:

};

#endif /* FABRICA_H */

