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
#include"Usuario.h"
#include"Grupo.h"
#include"Mensaje.h"
#include"DtConversacion.h"
#include"Conversacion.h"

using namespace std;

class ContMensaje : public iContMensaje{

    
private: 
        Mensaje * mensaje;
        Conversacion * conv;
        Usuario* usu;
        int idConv;

public:
    
ContMensaje();
~ContMensaje();
int getIdConv();
void aumentarIdConv();
void enviarMensaje(Mensaje);
void crearConv(Usuario,Conversacion);
void create(Grupo);
void agregarConv(Conversacion);
void crear(DtSimple);
void crearMensaje(DtMensaje);
void seleccionarCont(string);
void selecConversacion(string);
void getContactos();
void getConversacion();
DtConversacion listarConv();
void seleccionarConv(string);
void archivarConv(DtConversacion);
DtMensaje seleccionarConversacion(string);
void seleccionarMensaje(int);
void eliminarMensaje(DtMensaje);
DtConversacion listarConvArchivadas();
void cuerpoMensaje(DtSimple);
void cuerpoMensaje(DtImagen);
void cuerpoMensaje(DtContacto);
void crearMensaje();
void setUsu(Usuario* usu);
Usuario* getUsu() const;
void setConversacion(Conversacion* conversaciones);
Conversacion* getConversacion() const;
void setMensaje(Mensaje* mensaje);
Mensaje* getMensaje() const;

};

#endif /* CONTMENSAJE_H */

