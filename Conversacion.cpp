/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conversacion.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 01:30 AM
 */

#include "Conversacion.h"
#include "Fabrica.h"

Conversacion::Conversacion() {
}

Conversacion::Conversacion(const Conversacion& orig) {
}

Conversacion::~Conversacion() {
}

bool Conversacion::sosConversacion(int idConv) {
    if (this->idConv == idConv)return true;
    return false;
}

Mensaje* Conversacion::getMensaje(int idMensaje) {
    intKey *key = new intKey(idMensaje);
    Mensaje *men = (dynamic_cast<Mensaje*> (mensajes->find(key)));
    return men;
}

void Conversacion::remueveConv(Mensaje* men) {
    mensajes->removeObj(men); //incompleto
}

void Conversacion::remueveMens(int men) {
    intKey * key = new intKey(men);
    IIterator *it = mensajes->getIteratorKey();
    Mensaje *mens = dynamic_cast<Mensaje*> (mensajes->find(key));
    bool ok = mens->remueveVistos();
    if (ok == true) {
        remueveConv(mens);
    }
}

void Conversacion::eviarMensaje(Mensaje* m) {
}

Lista* Conversacion::listarMensaje(DtFechaHoraIng *fecha_hora) {
    iContUsuario *contUsu = Fabrica::getInstance()->getContUsuario();
    IIterator *it = mensajes->getIteratorObj();
    Lista* listDtMensaje = new Lista();
    if (fecha_hora == NULL) {
        while (it->hasNext()) {
            Mensaje *men = dynamic_cast<Mensaje*> (it->getCurrent());
            men->esReceptor(contUsu->getNumUsuLog());
            listDtMensaje->add(men->getMensaje());
            it->next();
        }
    } else {
        while (it->hasNext()) {
            Mensaje *m = dynamic_cast<Mensaje*> (it->getCurrent());
            if (m->GetFechaEnv()->GetAnio() >= fecha_hora->GetFecha()->GetAnio() && m->GetFechaEnv()->GetDia() >= fecha_hora->GetFecha()->GetDia()
                    && m->GetFechaEnv()->GetMes() >= fecha_hora->GetFecha()->GetMes() && m->GetHoraEnv()->GetHora() >= fecha_hora->GetHora()->GetHora() && m->GetHoraEnv()->GetMinutos() >=
                    fecha_hora->GetHora()->GetMinutos() && m->GetHoraEnv()->GetSegundo() >= fecha_hora->GetHora()->GetSegundo()) {
                listDtMensaje->add(m->getMensaje());
                m->esReceptor(contUsu->getNumUsuLog());
            }
        }

    }
    return listDtMensaje;
}

Lista *Conversacion::listarVistos(int idMen) {
    Lista *listaMensVisto;
    intKey *key = new intKey(idMen);
    Mensaje *men = dynamic_cast<Mensaje*> (mensajes->find(key));
    listaMensVisto = men->GetVistos();
    return listaMensVisto;
}

int Conversacion::getIdConv() {
    return idConv;
}

void Conversacion::setIdConv(int idConv) {
    this->idConv = idConv;
}

void Conversacion::setMensaje(Mensaje* mensaje) {
    intKey *key = new intKey(mensaje->GetCodigo());
    mensajes->add(mensaje, key);
}

int Conversacion::getCelContacto() {
    iContUsuario *contusu = Fabrica::getInstance()->getContUsuario();
    return contusu->getNumContacto(this->idConv);
}