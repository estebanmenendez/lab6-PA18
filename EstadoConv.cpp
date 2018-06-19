/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EstadoConv.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 01:31 AM
 */

#include "EstadoConv.h"

void EstadoConv::setEstado(bool archivada) {
    this->archivada = archivada;
}

bool EstadoConv::isArchivada() const {
    return archivada;
}

void EstadoConv::setConversacion(Conversacion* conversacion) {
    this->conversacion = conversacion;
}

Conversacion* EstadoConv::getConversacion() const {
    return conversacion;
}




EstadoConv::EstadoConv() {
}
EstadoConv::EstadoConv(bool estado, Conversacion * conv) {
    this->conversacion=conv;
    this->archivada=estado;
}

EstadoConv::EstadoConv(const EstadoConv& orig) {
}

EstadoConv::~EstadoConv() {
}

