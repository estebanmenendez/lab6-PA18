/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Simple.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 01:32 AM
 */

#include "Simple.h"

Simple::Simple() {
}

Simple::Simple(const Simple& orig) {
}

Simple::~Simple() {
}

string Simple::getTexto() {    
    return this->texto;
}
    void Simple::setTexto(string texto){
    this->texto = texto;
    }
DtSimple* Simple::getMensaje() {
    DtSimple * mS=new DtSimple(this->texto);
    return mS;
}