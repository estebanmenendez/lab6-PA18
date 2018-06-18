/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtMensaje.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 03:32 AM
 */

#include "DtMensaje.h"
/*int codigo;
    DtFecha fechaEnv;
    DtHora horaEnv;*/

DtMensaje::DtMensaje(int codigo, DtFecha fechaEnv, DtHora horaEnv){
    this->codigo = codigo;
    this->fechaEnv = fechaEnv;
    this->horaEnv = horaEnv;
}
DtMensaje::DtMensaje() {
}

DtMensaje::DtMensaje(const DtMensaje& orig) {
    this->codigo = orig.codigo;
    this->fechaEnv = orig.fechaEnv;
    this->horaEnv = orig.horaEnv;
}

DtMensaje::~DtMensaje() {
}

int DtMensaje::GetCodigo() {
        return codigo;
    }

    void DtMensaje::SetCodigo(int codigo) {
        this->codigo = codigo;
    }

    DtFecha DtMensaje::GetFechaEnv() {
        return fechaEnv;
    }

    void DtMensaje::SetFechaEnv(DtFecha fechaEnv) {
        this->fechaEnv = fechaEnv;
    }

    DtHora DtMensaje::GetHoraEnv() {
        return horaEnv;
    }

    void DtMensaje::SetHoraEnv(DtHora horaEnv) {
        this->horaEnv = horaEnv;
    }