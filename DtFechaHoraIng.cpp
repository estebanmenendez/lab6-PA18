/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtFechaHoraIng.cpp
 * Author: esteban
 * 
 * Created on 7 de junio de 2018, 01:52 AM
 */

#include "DtFechaHoraIng.h"

DtFechaHoraIng::DtFechaHoraIng() {
}

DtFechaHoraIng::DtFechaHoraIng(const DtFechaHoraIng& orig) {
}

DtFechaHoraIng::~DtFechaHoraIng() {
}

void DtFechaHoraIng::SetHora(DtHora hora) {
    this->hora = hora;
}

DtHora DtFechaHoraIng::GetHora() const {
    return hora;
}

void DtFechaHoraIng::SetFecha(DtFecha fecha) {
    this->fecha = fecha;
}

DtFecha DtFechaHoraIng::GetFecha() const {
    return fecha;
}

int DtFechaHoraIng::GetCelular() {
    return Celular;
}

void DtFechaHoraIng::SetCelular(int Celular) {
    this->Celular = Celular;
}

DtFechaHoraIng DtFechaHoraIng::GetFechaHoraIng()  {
    return *FechaHoraIng;
}

//void DtFechaHoraIng::SetFechaHoraIng(DtFechaHoraIng FechaHoraIng) {
//    this->FechaHoraIng = FechaHoraIng;
//}

string DtFechaHoraIng::GetNombre() {
    return Nombre;
}

void DtFechaHoraIng::SetNombre(string Nombre) {
    this->Nombre = Nombre;
}