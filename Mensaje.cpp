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
#include"Fabrica.h"
#include "Mensaje.h"

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
void Mensaje::setEmisor(int emi){
    this->emisor=emi;
}
DtFecha* Mensaje::GetFechaEnv() {
    return fechaEnv;
}

void Mensaje::SetFechaEnv(DtFecha *fechaEnv) {
    this->fechaEnv = fechaEnv;
}

DtHora* Mensaje::GetHoraEnv() {
    return horaEnv;
}

void Mensaje::SetHoraEnv(DtHora *horaEnv) {
    this->horaEnv = horaEnv;
}

Visto* Mensaje::GetVisto() {
    IIterator* it = visto->iterator();
    while (it->hasNext()) {
        Visto* v = dynamic_cast<Visto*> (it->getCurrent());
        return v;
    }
}

bool Mensaje::remueveVistos() {
    IIterator * it = visto->iterator();
    while (it->hasNext()) {
        Visto * v = dynamic_cast<Visto*> (it->getCurrent());
        visto->remove(v);
        delete visto;
        it->next();
    }
    return true;
}

void Mensaje::SetVisto(Visto* visto) {
    this->visto->add(visto);
}

bool Mensaje::esReceptor(int numCel) {
    if (this->emisor != numCel) {
        IIterator *it = visto->iterator();
        while (it->hasNext()) {
            Visto *v = dynamic_cast<Visto*> (it->getCurrent());
            if (v->esReceptor(numCel) == true) {
                if (v->getEstado() != true)v->SetEstado(true);
            }
            it->next();
        }
    }
}

DtMensaje * Mensaje::getMensaje() {
    DtMensaje * men = new DtMensaje(this->codigo, this->fechaEnv, this->horaEnv);
    return men;
}

Lista * Mensaje::GetVistos() {
    Lista *listaVistos =new Lista();
    IIterator *it = visto->iterator();
    while (it->hasNext()) {
        Visto * vis = dynamic_cast<Visto*> (it->getCurrent());
        iContUsuario *contUsu = Fabrica::getInstance()->getContUsuario();
        DtMensajeVisto* DtMVisto = new DtMensajeVisto(contUsu->getNombreCont(vis->getReceptor()), vis->getReceptor(), vis->getFechaHoraVisto(),vis->getEstado());
        if(vis->getEstado()!=true){vis->SetEstado(true);}
        listaVistos->add(DtMVisto);
        
    }
    return listaVistos;
}
