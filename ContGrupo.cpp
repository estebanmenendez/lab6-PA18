/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ContGrupo.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 01:47 AM
 */

#include "ContGrupo.h"
#include "Fabrica.h"

ContGrupo::ContGrupo() {
}

ContGrupo::~ContGrupo() {
}

void ContGrupo::crearTipoGrupo(DtTipo*, string) {
}

void ContGrupo::createTipo(DtTipo*, string) {
}

void ContGrupo::crearConvGrupo(string) {
}

void ContGrupo::getUsuario(int) {
}

void ContGrupo::getContactos() {
}

void ContGrupo::getDtContacto() {
}

Lista* ContGrupo::listarGrupos() {
    Usuario * usuLog = Fabrica::getInstance()->getContUsuario()->getUsu();
    Lista * listDtGrupo = usuLog->getTipos();    
    return listDtGrupo;
}

DtContacto* ContGrupo::seleccionarParticipante(int) {
}

bool ContGrupo::agregarNuevoAdmin(int) {
}

Lista* ContGrupo::listarContactos() {
    Usuario * usuLog = Fabrica::getInstance()->getContUsuario()->getUsu();
    Lista* listDtContacto = usuLog->GetContactos();
    return listDtContacto;
}

DtContacto* ContGrupo::seleccionarContacto(int) {
}

void ContGrupo::agregarParticipante(DtContacto* dtc) {
    this->ltElegidos->add(dtc);
}

Lista* ContGrupo::listarParticipantes() {
    Lista* listPart = this->ltElegidos;
    return listPart;
}

DtContacto* ContGrupo::seleccionarPart(int) {
}

void ContGrupo::eliminarParticipante(DtContacto* dtc) {
    DtContacto* dtn = new DtContacto();
    IIterator* h = this->ltElegidos->iterator();
    while (h->hasNext()) {
        dtn = dynamic_cast<DtContacto*> (h->getCurrent());
        if (dtn->GetNumCel() == dtc->GetNumCel()) {
            this->ltElegidos->remove(dtn);
            break;
        }
        h->next();
    }
}

void ContGrupo::cancelar() {
}

DtGrupo* ContGrupo::altaGrupo(string imagen, string nombre) {
    
    iContUsuario* contUsu = Fabrica::getInstance()->getContUsuario();
    //se crea el grupo y se setean los atributos urlImagen, nombre y usuario creador.
    Grupo* grupo = new Grupo();
    grupo->SetImagen(imagen);
    grupo->SetNombre(nombre);
    grupo->SetCreador(contUsu->getUsu()->GetCelular());
    DtGrupo* dtGrupo = new DtGrupo(nombre);
        
    iContMensaje* contMen = Fabrica::getInstance()->getContMensaje();
    //crea el mensaje que se le envía a cada uno de los participantes del grupo
    Mensaje* mens = contMen->crearMensajeGrupo("Te has unido al Grupo "+grupo->GetNombre());
    //setea el mensaje a la conversacion del grupo.
    grupo->getConversacion()->setMensaje(mens);
    //para el usuario que crea el grupo crea el tipo y el estado Conv.
    contUsu->crearGrupoUsuario(grupo,std::to_string(grupo->GetCreador()),mens->GetCodigo());
    //Por cada usuario elegido para el grupo le pide a ContUsuario que crea el Tipo, el EstConv.
    DtContacto* dtn = new DtContacto();
    IIterator* h = this->ltElegidos->iterator();
    while (h->hasNext()) {
        dtn = dynamic_cast<DtContacto*> (h->getCurrent());
        contUsu->crearGrupoUsuario(grupo,dtn->GetNumCel(),mens->GetCodigo());
        h->next();
    }
    //retorna un DtGrupo 
    return dtGrupo; 
}

Lista* ContGrupo::seleccionarGrupo(string grupo) {
    Usuario * usuLog = Fabrica::getInstance()->getContUsuario()->getUsu();
    this->grupo = usuLog->getGrupo(grupo);
    Lista* listDtContacto = usuLog->getContactosGrupo(grupo);
    
//    if (listDtContacto->isEmpty())
//       return throw std::invalid_argument("No existen el grupo "+grupo); 
    
    return listDtContacto;
}

void ContGrupo::Salir() {
}

 bool ContGrupo::estaElegido(string  celular){
    DtContacto* dtn = new DtContacto();
    IIterator* h = this->ltElegidos->iterator();
    while (h->hasNext()) {
        dtn = dynamic_cast<DtContacto*> (h->getCurrent());
        if (dtn->GetNumCel()== celular ){ 
            return true;
        }
        h->next();
    }
    return false;
 }
 
 void ContGrupo::vaciaListaParticipantes() {
    if(!this->ltElegidos->isEmpty()){
        DtContacto* dtn = new DtContacto();
        IIterator* h = this->ltElegidos->iterator();
        while (h->hasNext()) {
            dtn = dynamic_cast<DtContacto*> (h->getCurrent());
            this->ltElegidos->remove(dtn);
            delete(dtn);
            h->next();
        }
    }
    //this->ltElegidos = NULL;
}
 
 void ContGrupo::agregarParticipanteGrupo(){
    iContUsuario* contUsu = Fabrica::getInstance()->getContUsuario();
               
    iContMensaje* contMen = Fabrica::getInstance()->getContMensaje();
    //crea el mensaje que se le envía a cada uno de los participantes del grupo
    Mensaje* mens = contMen->crearMensajeGrupo("Te has unido al Grupo "+this->grupo->GetNombre());
    //setea el mensaje a la conversacion del grupo.
    this->grupo->getConversacion()->setMensaje(mens);
    //Por cada usuario elegido para el grupo le pide a ContUsuario que crea el Tipo, el EstConv.
    DtContacto* dtn = new DtContacto();
    IIterator* h = this->ltElegidos->iterator();
    while (h->hasNext()) {
        dtn = dynamic_cast<DtContacto*> (h->getCurrent());
        contUsu->crearGrupoUsuario(this->grupo,dtn->GetNumCel(),mens->GetCodigo());
        h->next();
    }
 }
 
// void ContGrupo::setGrupo(Grupo* grupo){
//     this->grupo = grupo;
// }