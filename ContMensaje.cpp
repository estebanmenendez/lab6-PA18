/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ContMensaje.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 01:47 AM
 */

#include"ContMensaje.h"

using namespace std;

ContMensaje::ContMensaje(){}

void ContMensaje::setUsu(Usuario* usu) {
    this->usu = usu;
}

Usuario* ContMensaje::getUsu() const {
    return usu;
}

void ContMensaje::setConversacion(Conversacion* conversaciones) {
    this->conv = conversaciones;
}

Conversacion* ContMensaje::getConversacion() const {
    return conv;
}

void ContMensaje::setMensaje(Mensaje* mensaje) {
    this->mensaje = mensaje;
}

Mensaje* ContMensaje::getMensaje() const {
    return mensaje;
}
ContMensaje::~ContMensaje(){}

void ContMensaje::enviarMensaje(Mensaje){}
void ContMensaje::crearConv(Usuario,Conversacion){}
void ContMensaje::agregarConv(Conversacion){}
void ContMensaje::crear(DtSimple){}
void ContMensaje::crearMensaje(DtMensaje){}
void ContMensaje::seleccionarCont(string){}
void ContMensaje::selecConversacion(string){}
void ContMensaje::getContactos(){}
Lista* ContMensaje::listarConv(){}
void ContMensaje::seleccionarConv(string){}
void ContMensaje::archivarConv(DtConversacion){}
Lista* ContMensaje::seleccionarConversacion(string){}
void ContMensaje::seleccionarMensaje(int){}
void ContMensaje::eliminarMensaje(DtMensaje){}
Lista* ContMensaje::listarConvArchivadas(){}
void ContMensaje::cuerpoMensaje(DtSimple) {}
void ContMensaje::cuerpoMensaje(DtImagen){}
void ContMensaje::cuerpoMensaje(DtContacto){}
void ContMensaje::crearMensaje(){}

