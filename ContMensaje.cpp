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
#include"Fabrica.h"



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
void ContMensaje::setMensaje(DtMensaje mensaje) {
    mensaje = mensaje;
}

DtMensaje ContMensaje::getMensaje() {
    return * mensaje;
}

void ContMensaje::seleccionarConv(int){}

ContMensaje::~ContMensaje(){}

void ContMensaje::enviarMensaje(int){}
void ContMensaje::crearConv(int,int){}
//void ContMensaje::agregarConv(Conversacion){}
void ContMensaje::crear(DtSimple){}
void ContMensaje::crearMensaje(DtMensaje){}
void ContMensaje::seleccionarCont(string){}
void ContMensaje::selecConversacion(int){}
void ContMensaje::getContactos(){}

Lista* ContMensaje::listarConv(){
    iContUsuario * usuLog = Fabrica::getInstance()->getContUsuario();
    Lista * retorno;
    retorno = usuLog->listarConversacion();

}

Lista* ContMensaje::seleccionarConversacion(int idConv){
    iContUsuario * usuLog = Fabrica::getInstance()->getContUsuario();
    Lista * retorno;
    retorno = usuLog->seleccionarConversacion(idConv);
}

void ContMensaje::archivarConv(DtConversacion){}

void ContMensaje::seleccionarMensaje(int){

}

void ContMensaje::eliminarMensaje(int idConv,DtMensaje dtMen){
    iContUsuario * usuLog = Fabrica::getInstance()->getContUsuario();
    usuLog->eliminarMensConv(idConv, dtMen.GetCodigo());
    

}    

Lista* ContMensaje::listarConvArchivadas(){}

void ContMensaje::cuerpoMensaje(DtSimple) {}
void ContMensaje::cuerpoMensaje(DtImagen){}
void ContMensaje::cuerpoMensaje(DtContacto){}
void ContMensaje::crearMensaje(){}

/*iContMensaje * ContMensaje::getInstance(){
    if(instance== NULL)
        instance = new ContMensaje();
    return instance;
        
}*/


