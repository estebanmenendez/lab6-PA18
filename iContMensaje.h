/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   iContMensaje.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 01:46 AM
 */

#ifndef ICONTMENSAJE_H
#define ICONTMENSAJE_H


#include "Lista.h"
//#include "Mensaje.h"
//#include "Conversacion.h"
#include "DtMensaje.h"
#include "DtSimple.h"
#include "DtImagen.h"
#include "DtContacto.h"
#include "DtConversacion.h"
//#include "Grupo.h"
//#include "Usuario.h"


using namespace std;

class iContMensaje {
    
private:
                
public:
virtual ~iContMensaje();
virtual void enviarMensaje(string) = 0;
virtual void crearConv(int,int) = 0;
 //virtual void agregarConv(Conversacion) = 0;
virtual void crear(DtSimple) = 0;
virtual void crearMensaje(DtMensaje) = 0;
virtual void seleccionarCont(string) = 0;
virtual void selecConversacion(string) = 0;
virtual void getContactos() = 0;
//virtual void setConversacion(Conversacion*)= 0;
//virtual Conversacion* getConversacion() = 0;
virtual Lista* listarConv() = 0;
virtual void seleccionarConv(string) = 0;
virtual void archivarConv(DtConversacion) = 0;
virtual Lista* seleccionarConversacion(string) = 0;
virtual void seleccionarMensaje(int) = 0;
virtual void eliminarMensaje(DtMensaje) = 0;
virtual Lista* listarConvArchivadas() = 0;
virtual void cuerpoMensaje(DtSimple)  = 0;
virtual void cuerpoMensaje(DtImagen) = 0;
virtual void cuerpoMensaje(DtContacto) = 0;
virtual void crearMensaje() = 0;
//virtual void setUsu(Usuario* usu)= 0;
//virtual Usuario* getUsu() = 0;
virtual void setMensaje(DtMensaje mensaje)= 0;
virtual DtMensaje getMensaje() = 0;

};

#endif /* ICONTMENSAJE_H */

