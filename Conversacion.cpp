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
#include "EstadoConv.h"
#include"ContMensaje.h"
Conversacion::Conversacion() {
}

Conversacion::Conversacion(const Conversacion& orig) {
}

Conversacion::~Conversacion() {
}


bool Conversacion::sosConversacion(int idConv){
    if(this->idConv==idConv)return true;
    return false;}
void Conversacion::getMensaje(int idMensaje){
    IKey *key=IKey(idMensaje);
    Mensaje *men=mensajes->find(key);
}
void Conversacion::remueveConv(Mensaje){}
void Conversacion::eviarMensaje(Mensaje){
  


}
DtMensaje Conversacion::listarMensaje(DtFechaHoraIng){}
DtMensajeVisto Conversacion::listarVistos(int){}
bool Conversacion::soyGrupo(){if (grupo!=NULL) return true;
return false;}
void Conversacion::setEstado(bool estado){
    IIterator *it=estadoConv->iterator();
    while(it->hasNext()){
    EstadoConv *ec= (dynamic_cast<EstadoConv*>(it->getCurrent()));
    if(ec->getUsuario()==ContMensaje.getUsu())
    {ec->SetEstado(estado);} 
    }
    
}
    