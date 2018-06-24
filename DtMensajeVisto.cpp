/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtMensajeVisto.cpp
 * Author: esteban
 * 
 * Created on 7 de junio de 2018, 01:51 AM
 */

#include "DtMensajeVisto.h"
/*string Nombre;
    int Celular;
    DtFechaHoraVisto FechaHoraVisto;
*/

DtMensajeVisto::DtMensajeVisto(string nombre, int celular, DtFechaHoraVisto* fhv){
    this->Nombre = nombre;
    this->Celular = celular;
    this->FechaHoraVisto = fhv;
}
DtMensajeVisto::DtMensajeVisto() {
}

DtMensajeVisto::DtMensajeVisto(const DtMensajeVisto& orig) {
    this->Nombre = orig.Nombre;
    this->Celular = orig.Celular;
    this->FechaHoraVisto = orig.FechaHoraVisto;
}

DtMensajeVisto::~DtMensajeVisto() {
}

  DtFechaHoraVisto* DtMensajeVisto::GetFechaHoraVisto()  {
        return FechaHoraVisto;
    }
   
    string DtMensajeVisto::GetNombre() {
        return Nombre;
    }

   
