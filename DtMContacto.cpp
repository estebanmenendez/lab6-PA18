/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtMContacto.cpp
 * Author: juan
 * 
 * Created on 12 de junio de 2018, 08:35 PM
 */

#include "DtMContacto.h"

DtMContacto::DtMContacto(const DtMContacto& orig) {
    this->numCel = orig.numCel;
}

DtMContacto::DtMContacto(int numCel) {
    this->numCel = numCel;
}

DtMContacto::DtMContacto() {
}

DtMContacto::~DtMContacto() {
}

int DtMContacto::getNumCel() {
    return this->numCel;
}

void DtMContacto::setNumCel(int num) {
    this->numCel = num;
}
