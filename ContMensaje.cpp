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
#include "Fabrica.h"

using namespace std;
//iContMensaje * ContMensaje::instance = NULL;
//

ContMensaje::ContMensaje(){}
/*
void ContMensaje::setUsu(Usuario* usu) {
    this->usu = usu;
}

Usuario* ContMensaje::getUsu()  {
    return usu;
}

void ContMensaje::setConversacion(Conversacion* conversaciones) {
    this->conv = conversaciones;
}

Conversacion* ContMensaje::getConversacion() {
    return conv;
}
*/
void ContMensaje::setMensaje(DtMensaje *mensaje) {
    this->mensaje = mensaje;
}

DtMensaje* ContMensaje::getMensaje() {
    return mensaje;
}
ContMensaje::~ContMensaje(){}

void ContMensaje::enviarMensaje(string){}
void ContMensaje::crearConv(int,int){}
//void ContMensaje::agregarConv(Conversacion){}
void ContMensaje::crear(DtSimple){}
void ContMensaje::crearMensaje(DtMensaje){}
void ContMensaje::seleccionarCont(string){}
void ContMensaje::selecConversacion(string){}
void ContMensaje::getContactos(){}
Lista* ContMensaje::listarConv(){}
void ContMensaje::seleccionarConv(string){}
void ContMensaje::archivarConv(DtConversacion){}
Lista* ContMensaje::seleccionarConversacion(int idConv){
   
}
void ContMensaje::seleccionarMensaje(int){}
void ContMensaje::eliminarMensaje(DtMensaje){}
Lista* ContMensaje::listarConvArchivadas(){}
void ContMensaje::cuerpoMensaje(DtSimple) {}
void ContMensaje::cuerpoMensaje(DtImagen){}
void ContMensaje::cuerpoMensaje(DtContacto){}
void ContMensaje::crearMensaje(){}
Lista * ContMensaje::listarConversaciones(){
    iContUsuario* contUsu=Fabrica::getInstance()->getContUsuario();
    Lista * convAct;
    convAct=contUsu->listaConversacion();
    return convAct;
   // contUsu.getUsu
}
/*iContMensaje * ContMensaje::getInstance(){
    if(instance== NULL)
        instance = new ContMensaje();
    return instance;
        
}*/


