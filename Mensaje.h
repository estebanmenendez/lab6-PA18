/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mensaje.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 03:22 AM
 */

#ifndef MENSAJE_H
#define MENSAJE_H

#include"DtFecha.h"
#include"DtHora.h"
#include"Lista.h"


class Mensaje {
public:
    Mensaje();
    Mensaje(const Mensaje& orig);
    virtual ~Mensaje();
    
    int GetCodigo();
    DtFecha GetFechaEnv();
    DtHora GetHoraEnv();
    Lista* GetVisto();
    
    void SetCodigo(int);
    void SetFechaEnv(DtFecha);    
    void SetHoraEnv(DtHora);
    void SetVisto(Lista*);
    
private:
        
        Lista * visto;
       
        int codigo;
        DtFecha fechaEnv;
        DtHora horaEnv;
    
};

#endif /* MENSAJE_H */

