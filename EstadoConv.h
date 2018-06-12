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

#include"Lista.h"

class EstadoConv :public ICollectible{
    public:
    EstadoConv();
    EstadoConv(const EstadoConv& orig);
    virtual ~EstadoConv();
    
    bool ConvActiva();
    void SetEstado(bool);
    void setArchivada(bool archivada);
    bool isArchivada() const;
    void setConversacion(Conversacion* conversacion);
    Conversacion* getConversacion() const;
    void setUsuario(Usuario* usuario);
    Usuario* getUsuario() const;

    
private:
        Usuario * usuario;
        Conversacion * conversacion; 
        bool archivada;
};

#endif /* ESTADOCONV_H */

