/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Visto.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 01:31 AM
 */

#include "Visto.h"

Visto::Visto() {
}

Visto::Visto(const Visto& orig) {
}

Visto::~Visto() {
}


bool Visto::getEstado() {
    return estado;
}

void Visto::SetEstado(bool estado) {
    this->estado = estado;
}

DtFecha * Visto::GetFechaV() {
    return fechaV;
}

void Visto::SetFechaV(DtFecha * fechaV) {
    this->fechaV = fechaV;
}

DtHora * Visto::GetHoraV() {
    return horaV;
}

void Visto::SetHoraV(DtHora * horaV) {
    this->horaV = horaV;
}

bool Visto::esReceptor(int recep){
    if (recep==this->Receptor) return true;
} 
int Visto::getReceptor(){
    return Receptor;
}
DtFechaHoraVisto * Visto::getFechaHoraVisto(){
    DtFechaHoraVisto* dtFecha=new DtFechaHoraVisto(fechaV,horaV);
    return dtFecha;
}
