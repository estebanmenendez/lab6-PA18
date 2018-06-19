/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fabrica.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 01:40 AM
 */

#include "Fabrica.h"

Fabrica* Fabrica::fabrica = NULL;

Fabrica::Fabrica() {
}

Fabrica::~Fabrica() {
}

Fabrica* Fabrica::getInstance(){
    if (fabrica==NULL){
            fabrica = new Fabrica();
    }
    return fabrica;
}

iContUsuario* Fabrica::getContUsuario(){
    return ContUsuario::getInstance();
}
iContMensaje* Fabrica::getContMensaje(){
    return ContMensaje::getInstance();
}

iContGrupo* Fabrica::getContGrupo(){
    return ContGrupo::getInstance();
}