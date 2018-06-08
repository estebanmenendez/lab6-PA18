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

#include"ColMensaje.h"

class EstadoConv {
public:
    EstadoConv();
    EstadoConv(const EstadoConv& orig);
    virtual ~EstadoConv();
private:
    
        ColMensaje * mensaje;
        bool archivada;
};

#endif /* ESTADOCONV_H */

