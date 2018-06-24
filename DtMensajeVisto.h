/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtMensajeVisto.h
 * Author: esteban
 *
 * Created on 7 de junio de 2018, 01:51 AM
 */

#ifndef DTMENSAJEVISTO_H
#define DTMENSAJEVISTO_H

#include"DtMensajeVisto.h"
#include"DtFechaHoraVisto.h"
#include "ICollectible.h"
#include<iostream>

using namespace std;

class DtMensajeVisto:public ICollectible {
public:
    DtMensajeVisto();
    DtMensajeVisto(string, int, DtFechaHoraVisto* );
    DtMensajeVisto(const DtMensajeVisto& orig);
    virtual ~DtMensajeVisto();
    
    int GetCelular();
    string GetNombre();
    DtFechaHoraVisto* GetFechaHoraVisto();
    
   
    
private:
    
    string Nombre;
    int Celular;
    DtFechaHoraVisto *FechaHoraVisto;

};

#endif /* DTMENSAJEVISTO_H */

