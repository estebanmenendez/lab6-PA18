/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Contacto.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 01:32 AM
 */

#include "Contacto.h"

Contacto::Contacto() {
}

Contacto::Contacto(const Contacto& orig) {
}

Contacto::~Contacto() {
}

int Contacto::GetNumCel() {
    return this->numCel;
}

void Contacto::SetNumCel(int numCel) {
    this->numCel = numCel;
}

DtMContacto* Contacto::getMensaje() {
    DtMContacto* mC = new DtMContacto(this->numCel);
    return mC;
}