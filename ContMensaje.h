/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ContMensaje.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 01:47 AM
 */

#ifndef CONTMENSAJE_H
#define CONTMENSAJE_H

#include"iContMensaje.h"
#include"DtFecha.h"
#include"DtImagen.h"
#include"DtMensaje.h"
#include"DtHora.h"
#include"DtSimple.h"
#include"DtContacto.h"
#include"DtConversacion.h"
//#include "Mensaje.h"


using namespace std;

class ContMensaje : public iContMensaje{

    
private: 
        DtMensaje mensaje;
        ContMensaje();
        static iContMensaje * instance;
        
        //Conversacion* conv;
        //Usuario* usu;
        

public:
    

ContMensaje(const ContMensaje& orig);
virtual ~ContMensaje();

void enviarMensaje(string);
void crearConv(int,int) ;
// void agregarConv(Conversacion) ;
void crear(DtSimple) ;
void crearMensaje(DtMensaje) ;
void seleccionarCont(string) ;
void selecConversacion(string) ;
void getContactos() ;
//void setConversacion(Conversacion*);
//Conversacion* getConversacion() ;
Lista* listarConv() ;
void seleccionarConv(string) ;
void archivarConv(DtConversacion) ;
Lista* seleccionarConversacion(string) ;
void seleccionarMensaje(int) ;
void eliminarMensaje(DtMensaje) ;
Lista* listarConvArchivadas() ;
void cuerpoMensaje(DtSimple)  ;
void cuerpoMensaje(DtImagen) ;
void cuerpoMensaje(DtContacto) ;
void crearMensaje() ;
//void setUsu(Usuario* usu);
//Usuario* getUsu();
void setMensaje(DtMensaje mensaje);
DtMensaje getMensaje();
static iContMensaje * getInstance();


};

#endif /* CONTMENSAJE_H */

