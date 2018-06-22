/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mensaje.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 03:22 AM
 */

#include "Mensaje.h"
#include "Multimedia.h"

Mensaje::Mensaje() {
}

Mensaje::Mensaje(const Mensaje& orig) {
}

Mensaje::~Mensaje() {
}

int Mensaje::GetCodigo() {
    return codigo;
}

void Mensaje::SetCodigo(int codigo) {
    this->codigo = codigo;
}

DtFecha Mensaje::GetFechaEnv() {
    return fechaEnv;
}

void Mensaje::SetFechaEnv(DtFecha fechaEnv) {
    this->fechaEnv = fechaEnv;
}

DtHora Mensaje::GetHoraEnv() {
    return horaEnv;
}

void Mensaje::SetHoraEnv(DtHora horaEnv) {
    this->horaEnv = horaEnv;
}
bool Mensaje::esReceptor(int numCel){
    if (this->emisor!=numCel){
        IIterator *it=visto->iterator();
        while(it->hasNext()){
            Visto *v=dynamic_cast<Visto*>(it->getCurrent());
            if(v->esReceptor(numCel)==true){
                if(v->getEstado()!=true)v->SetEstado(true);
            }
        }
    }
}

DtMensaje * Mensaje::getMensaje(){
    DtMensaje * men=new DtMensaje(this->codigo,this->fechaEnv,this->horaEnv);
    return men;
}
