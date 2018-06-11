/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtFechaHoraVisto.cpp
 * Author: esteban
 * 
 * Created on 7 de junio de 2018, 01:51 AM
 */

#include "DtFechaHoraVisto.h"

DtFechaHoraVisto::DtFechaHoraVisto() {
}

DtFechaHoraVisto::DtFechaHoraVisto(const DtFechaHoraVisto& orig) {
}

DtFechaHoraVisto::~DtFechaHoraVisto() {
   }


DtFecha DtFechaHoraVisto::GetFecha() {
    return fecha;
}

void DtFechaHoraVisto::SetFecha(DtFecha fecha) {
    this->fecha = fecha;
}

DtHora DtFechaHoraVisto::GetHora() {
    return hora;
}

void DtFechaHoraVisto::SetHora(DtHora hora) {
    this->hora = hora;
}

