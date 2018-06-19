/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tipo.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 01:31 AM
 */

#ifndef TIPO_H
#define TIPO_H

#include<iostream>
#include"string.h"
#include"DtFecha.h"
#include"DtHora.h"
#include"Grupo.h"
using namespace std;

class Tipo : public ICollectible {
    
public:
    Tipo();
    Tipo(const Tipo& orig);
    virtual ~Tipo();
    
    DtFecha GetFechaIng();
    DtHora GetHoraIng();
    string GetTipo();
    //bool soyDelGrupo(Grupo * g);
    void SetFechaIng(DtFecha);    
    void SetHoraIng(DtHora); 
    void SetTipo(string);    
    DtFechaHoraIng * getFechaHoraIng();
private:
        
        Grupo * grupo;
        string tipo;
        DtFecha fechaIng;
        DtHora horaIng;

};

#endif /* TIPO_H */

