/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tipo.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 01:31 AM
 */

#include "Tipo.h"

Tipo::Tipo() {
}

Tipo::Tipo(const Tipo& orig) {
}

Tipo::~Tipo() {
}
bool Tipo::soyDelGrupo(Grupo* g){
    if (g==this->G){return true;}
    return false;
}

 DtFecha Tipo::GetFechaIng() {
        return fechaIng;
    }

    void Tipo::SetFechaIng(DtFecha fechaIng) {
        this->fechaIng = fechaIng;
    }

    DtHora Tipo::GetHoraIng() {
        return horaIng;
    }

    void Tipo::SetHoraIng(DtHora horaIng) {
        this->horaIng = horaIng;
    }

    string Tipo::GetTipo() {
        return tipo;
    }

    void Tipo::SetTipo(string tipo) {
        this->tipo = tipo;
    }
