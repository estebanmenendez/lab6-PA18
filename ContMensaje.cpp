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
#include "iContUsuario.h"
#include "Fabrica.h"

using namespace std;

ContMensaje::ContMensaje() {
}

void ContMensaje::setMensaje(DtMensaje *mensaje) {
    this->mensaje = mensaje;
}

DtMensaje* ContMensaje::getMensaje() {
    return mensaje;
}

void ContMensaje::seleccionarConv(int) {
}

ContMensaje::~ContMensaje() {
}

void ContMensaje::enviarMensaje() {
}

void ContMensaje::crearConv(int, int) {
}

void ContMensaje::crear(DtSimple*) {
}

void ContMensaje::crearMensaje(DtMensaje*) {
}

void ContMensaje::selecConversacion(int) {
}

void ContMensaje::getContactos() {
}

void ContMensaje::archivarConv(DtConversacion*) {
}

void ContMensaje::seleccionarMensaje(int) {
}

Lista* ContMensaje::listarConvArchivadas() {
}

void ContMensaje::seleccionarCont(int) {
}

void ContMensaje::cuerpoMensaje(DtSimple*) {
}

void ContMensaje::cuerpoMensaje(DtImagen*) {
}

void ContMensaje::cuerpoMensaje(DtContacto*) {
}

void ContMensaje::crearMensaje() {
}

Lista * ContMensaje::infromacionAdicional(int idMens) {
}

void ContMensaje::setIdConv(int id) {
}

Lista * ContMensaje::listarConversacionesArch() {
}

Lista* ContMensaje::listarConv() {
    iContUsuario * usuLog = Fabrica::getInstance()->getContUsuario();
    Lista * retorno;
    return retorno = usuLog->listarConversacion();
}

Lista* ContMensaje::seleccionarConversacion(int idConv) {
    iContUsuario * usuLog = Fabrica::getInstance()->getContUsuario();
    Lista * retorno;
    retorno = usuLog->seleccionarConversacion(idConv);
}

void ContMensaje::eliminarMensaje(int idConv, DtMensaje* dtMen) {
    iContUsuario * usuLog = Fabrica::getInstance()->getContUsuario();
    usuLog->eliminarMensConv(idConv, dtMen->GetCodigo());
}

Lista * ContMensaje::listarConversaciones() {
    iContUsuario* contUsu = Fabrica::getInstance()->getContUsuario();
    Lista * convAct;
    convAct = contUsu->listaConversacion();
    return convAct;
}

