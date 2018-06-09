/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conversacion.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 01:30 AM
 */

#include "Conversacion.h"

Conversacion::Conversacion() {
}

Conversacion::Conversacion(const Conversacion& orig) {
}

Conversacion::~Conversacion() {
}


void Conversacion::sosConversacion(string idConv){}
void Conversacion::getMensaje(int mensaje){}
void Conversacion::remueveConv(Mensaje){}
void Conversacion::eviarMensaje(Mensaje){}
DtMensaje Conversacion::listarMensaje(DtFechaHoraIng){}
DtMensajeVisto Conversacion::listarVistos(int){}
bool Conversacion::soyGrupo(){}
void Conversacion::setEstado(bool){}
    