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
#include"IDictionary.h"
#include"Usuario.h"
#include"Lista.h"
#include"Grupo.h"
#include"Mensaje.h"
#include"DtConversacion.h"
#include"Conversacion.h"

using namespace std;

class ContMensaje : public iContMensaje{
    
private: 
        Mensaje * mensaje;
        Conversacion* conversaciones;
        Usuario* usuario;
        

public:
    
ContMensaje();
~ContMensaje();

virtual void enviarMensaje(Mensaje);
virtual void crearConv(Usuario,Conversacion);
virtual void create(Grupo);
virtual void agregarConv(Conversacion);
virtual void crear(DtSimple);
virtual void crearMensaje(DtMensaje);
virtual void seleccionarCont(string);
virtual void selecConversacion(string);
virtual void getContactos();
virtual void getConversacion();
virtual DtConversacion listarConv();
virtual void seleccionarConv(string);
virtual void archivarConv(DtConversacion);
virtual DtMensaje seleccionarConversacion(string);
virtual void seleccionarMensaje(int);
virtual void eliminarMensaje(DtMensaje);
virtual DtConversacion listarConvArchivadas();
virtual void cuerpoMensaje(DtSimple);
virtual void cuerpoMensaje(DtImagen);
virtual void cuerpoMensaje(DtContacto);
virtual void crearMensaje();


};

#endif /* CONTMENSAJE_H */

