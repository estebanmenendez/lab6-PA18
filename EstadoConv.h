/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EstadoConv.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 01:31 AM
 */

#ifndef ESTADOCONV_H
#define ESTADOCONV_H

#include"Conversacion.h"
#include"Lista.h"
#include "DtConversacion.h"
//#include"Usuario.h"
//#include"Visto.h"
#include"ICollectible.h"


using namespace std;
class EstadoConv :public ICollectible{
    public:
    EstadoConv();
    EstadoConv(bool, Conversacion*);
    EstadoConv(const EstadoConv& orig);
    virtual ~EstadoConv();
    //bool sosDelUsuario(Usuario * us);
    bool ConvActiva();
    void setEstado(bool);
    void setArchivada(bool archivada);
    bool isArchivada() const;
    void setConversacion(Conversacion* conversacion);
    Conversacion* getConversacion() const;
    //void setUsuario(Usuario* usuario);
    //Usuario* getUsuario() const;
   
    
private:
        //Usuario * usuario;
        Conversacion * conversacion; 
        bool archivada;
};

#endif /* ESTADOCONV_H */

