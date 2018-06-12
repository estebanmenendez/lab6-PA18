/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtFechaHoraIng.h
 * Author: esteban
 *
 * Created on 7 de junio de 2018, 01:52 AM
 */

#ifndef DTFECHAHORAING_H
#define DTFECHAHORAING_H

#include<iostream>

using namespace std;

class DtFechaHoraIng {
    
public:
    DtFechaHoraIng();
    DtFechaHoraIng(const DtFechaHoraIng& orig);
    virtual ~DtFechaHoraIng();
    
    int GetCelular();
    DtFechaHoraIng GetFechaHoraIng();
    string GetNombre();

    void SetCelular(int);
    void SetFechaHoraIng(DtFechaHoraIng);
    void SetNombre(string);
    
private:
    
    string Nombre;
    int Celular;
    DtFechaHoraIng *FechaHoraIng;

};

#endif /* DTFECHAHORAING_H */

