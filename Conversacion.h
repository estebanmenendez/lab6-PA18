/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conversacion.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 01:30 AM
 */

#ifndef CONVERSACION_H
#define CONVERSACION_H

#include"Mensaje.h"
#include <string.h>
#include"Lista.h"
#include"ListaDicc.h"
#include"intKey.h"
#include<iostream>
#include"DtFechaHoraIng.h"
#include"DtMensajeVisto.h"
#include"DtMensaje.h"
//#include "EstadoConv.h"
#include"Fecha_Hora_sis.h"

using namespace std;

class Conversacion {
    
    
public:
    Conversacion();
    Conversacion(const Conversacion& orig);
    virtual ~Conversacion();   
    void setMensaje(Mensaje *);
    bool sosConversacion(int);
    Mensaje* getMensaje(int);
    void remueveConv(Mensaje*);
    void eviarMensaje(Mensaje*);
    Lista* listarMensaje(DtFechaHoraIng* );
    Lista* listarVistos(int);
    bool soyGrupo();
    void setEstado(bool);
    void setIdConv(int);
    int getIdConv();
    int getCelContacto();
    string getNomGrupo();
    //Usuario * getReceptor();
private:
    
        //Grupo * grupo;
        ListDicc * mensajes=new ListDicc();
        //Lista * estadoConv=new Lista();
        int idConv;

};

#endif /* CONVERSACION_H */

