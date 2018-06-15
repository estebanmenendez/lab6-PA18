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
#include"Usuario.h"

class EstadoConv :public ICollectible{
    public:
    EstadoConv(Usuario *,Conversacion *);
    EstadoConv(const EstadoConv& orig);
    virtual ~EstadoConv();
    
    bool ConvActiva();
    void setEstado(bool);
    
    
    void setUsuario(Usuario* usuario);
    Usuario* getUsuario() const;
   
    void SetConv(Conversacion* conv);
    Conversacion* GetConv() const;
   
    
    
private:
        Usuario * usuario;
        Conversacion * conv; 
        bool archivada;
};

#endif /* ESTADOCONV_H */

