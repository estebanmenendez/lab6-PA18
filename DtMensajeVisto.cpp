/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtMensajeVisto.cpp
 * Author: esteban
 * 
 * Created on 7 de junio de 2018, 01:51 AM
 */

#include "DtMensajeVisto.h"

DtMensajeVisto::DtMensajeVisto() {
}

DtMensajeVisto::DtMensajeVisto(const DtMensajeVisto& orig) {
}

DtMensajeVisto::~DtMensajeVisto() {
}

  DtFechaHoraVisto DtMensajeVisto::GetFechaHoraVisto()  {
        return FechaHoraVisto;
    }

    void DtMensajeVisto::SetFechaHoraVisto(DtFechaHoraVisto FechaHoraVisto) {
        this->FechaHoraVisto = FechaHoraVisto;
    }

    string DtMensajeVisto::GetNombre() {
        return Nombre;
    }

    void DtMensajeVisto::SetNombre(string Nombre) {
        this->Nombre = Nombre;
    }
