/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtContacto.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 02:34 AM
 */

#ifndef DTCONTACTO_H
#define DTCONTACTO_H

#include"DtHora.h"
#include"DtFecha.h"

#include<iostream>

using namespace std;

class DtContacto  {
public:
    DtContacto();
    DtContacto(const DtContacto& orig);
    virtual ~DtContacto();
    
    DtFecha GetFechaIng();
    DtHora GetHoraIng();
    string GetNumCel();
    string GetTipo();
    string GetNombre();

    void SetFechaIng(DtFecha);
    void SetHoraIng(DtHora);   
    void SetNombre(string);
    void SetNumCel(string);
    void SetTipo(string);
    
private:
    
    string nombre;
    string numCel;
    string tipo;
    DtFecha fechaIng;
    DtHora horaIng;

};

#endif /* DTCONTACTO_H */

