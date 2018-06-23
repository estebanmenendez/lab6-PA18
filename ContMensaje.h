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
//#include"DtMensaje.h"
#include"DtHora.h"
#include"DtSimple.h"
#include"DtContacto.h"
#include"DtConversacion.h"
//#include "Mensaje.h"
#include"Lista.h"

using namespace std;

class ContMensaje : public iContMensaje {

    
private: 
        DtMensaje *mensaje;
        int idConv;
        
       //  static iContMensaje * instance;
      
public:
    
ContMensaje();
ContMensaje(const ContMensaje& orig);
virtual ~ContMensaje();
void enviarMensaje(string);
void crearConv(int,int) ;
void crear(DtSimple) ;
void crearMensaje(DtMensaje) ;
void seleccionarCont(string) ;
void selecConversacion(string) ;
void getContactos() ;
Lista* listarConv();//otro listar es
void seleccionarConv(string) ;
void archivarConv(DtConversacion) ;
Lista* seleccionarConversacion(int idConv) ;
void seleccionarMensaje(int) ;
void eliminarMensaje(DtMensaje) ;
Lista* listarConvArchivadas() ;
void cuerpoMensaje(DtSimple)  ;
void cuerpoMensaje(DtImagen) ;
void cuerpoMensaje(DtContacto) ;
void crearMensaje() ;
void setMensaje(DtMensaje *mensaje);
DtMensaje *getMensaje();
void setIdConv(int id);
Lista *infromacionAdicional(int idMens);
Lista * listarConversaciones();
Lista * listarConversacionesArch();
};

#endif /* CONTMENSAJE_H */

