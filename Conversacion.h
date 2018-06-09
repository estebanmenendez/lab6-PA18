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

#include"Grupo.h"
#include"Lista.h"
#include<iostream>
#include"DtFechaHoraIng.h"
#include"DtMensajeVisto.h"
#include"DtMensaje.h"


using namespace std;

class Conversacion {
public:
    
    Conversacion();
    Conversacion(const Conversacion& orig);
    virtual ~Conversacion();
    
void sosConversacion(string);
void getMensaje(int);
void remueveConv(Mensaje);
void eviarMensaje(Mensaje);
DtMensaje listarMensaje(DtFechaHoraIng);
DtMensajeVisto listarVistos(int);
bool soyGrupo();
void setEstado(bool);
    
private:
    
        Lista * grupo;
        Lista * mensaje;
        Lista * estadoConv;
        int idConv;

};

#endif /* CONVERSACION_H */

