/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Usuario.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 01:30 AM
 */

#include "Usuario.h"

void Usuario::addContacto(Usuario* u) {
    intKey* ikey = new intKey(u->GetCelular());
    this->contactos->add(u, ikey);
}

Usuario::Usuario(string nombre, string imagenPerfil, string descripcion, int numCel) {
    Fecha_Hora_sis* fechora;
    this->nombre = nombre;
    this->foto_Perfil = imagenPerfil;
    this->descripcion = descripcion;
    this->celular = numCel;
    this->fechaCreacion = fechora->getFecha();
    this->horaCreacion = fechora->getHora();
    this->SetUltima_conexion(fechora->getUltimaConexion());
}

ListDicc* Usuario::getListaContactos() {
    return this->contactos;
}

Usuario::Usuario(const Usuario& orig) {
}

Usuario::~Usuario() {
}

int Usuario::GetCelular() {
    return celular;
}

void Usuario::SetCelular(int celular) {
    this->celular = celular;
}

DtContacto* Usuario::GetContacto() {
    DtContacto* DtCont = new DtContacto(this->nombre, this->celular, this->foto_Perfil);
    return DtCont;
}

void Usuario::SetContacto(Usuario * contacto) {
    intKey * key = new intKey(contacto->GetCelular());
    this->contactos->add(contacto, key);
}

string Usuario::GetDescripcion() {
    return descripcion;
}

void Usuario::SetDescripcion(string descripcion) {
    this->descripcion = descripcion;
}

void Usuario::SetEstadoConv(EstadoConv* estado) {
    this->estadoConv->add(estado);
}

DtFecha* Usuario::GetFechaCreacion() {
    return fechaCreacion;
}

void Usuario::SetFechaCreacion(DtFecha *fechaCreacion) {
    this->fechaCreacion = fechaCreacion;
}

string Usuario::GetFoto_Perfil() {
    return foto_Perfil;
}

void Usuario::SetFoto_Perfil(string foto_Perfil) {
    this->foto_Perfil = foto_Perfil;
}

DtHora* Usuario::GetHoraCreacion() {
    return horaCreacion;
}

void Usuario::SetHoraCreacion(DtHora * horaCreacion) {
    this->horaCreacion = horaCreacion;
}

string Usuario::GetNombre() {
    return nombre;
}

void Usuario::SetNombre(string nombre) {
    this->nombre = nombre;
}

void Usuario::SetTipo(Tipo * tip) {
    tipo->add(tip);
}

DtUltCon* Usuario::GetUltima_conexion() {
    return ultima_conexion;
}

void Usuario::SetUltima_conexion(DtUltCon* ultima_conexion) {
    this->ultima_conexion = ultima_conexion;
}

//Operaciones//

Lista * Usuario::getConversaciones() {
    Lista *conversacionesAct = new Lista();
    IIterator *it = estadoConv->iterator();
    int cant = 0;
    while (it->hasNext()) {
        EstadoConv *ec = dynamic_cast<EstadoConv*> (it->getCurrent());
        if (ec->ConvActiva() == true) {
            if (ec->getConversacion()->soyGrupo() == true) {
                //                DtConversacion * dtConv=new DtConversacion(ec->getConversacion()->getNomGrupo(),ec->getConversacion()->getIdConv());//copntructor grupo
                //                conversacionesAct->add(dtConv);
            }
            //   DtConversacion * DtConv = new DtConversacion(ec->getConversacion()->getIdConv(),ec->getConversacion()->getCelContacto());//constructor conv comun
            //  conversacionesAct->add(DtConv);
        }
        cant++;
    }
    DtConversacion * DtConv = new DtConversacion(cant); //constructor conv archivadas
    conversacionesAct->add(DtConv);
    return conversacionesAct;
}

Lista * Usuario::getConversacionesAr() {
    Lista *conversacionesArc = new Lista();
    IIterator *it = estadoConv->iterator();
    while (it->hasNext()) {
        EstadoConv *ec = dynamic_cast<EstadoConv*> (it->getCurrent());
        //            if(ec->isArchivada()==true){
        if (ec->getConversacion()->soyGrupo() == true) {
            //                DtConversacion * dtConv=new DtConversacion(ec->getConversacion()->getNomGrupo(),ec->getConversacion()->getIdConv());//copntructor grupo
            //              conversacionesArc->add(dtConv);
        }
        //        DtConversacion * DtConv = new DtConversacion(ec->getConversacion()->getIdConv(),ec->getConversacion()->getCelContacto());//constructor conv comun
        //      conversacionesArc->add(DtConv);
    }
    return conversacionesArc;
}

Lista * Usuario::GetContactos() {
    Lista* Dtcontactos = new Lista();
    IIterator * it = contactos->getIteratorObj();
    while (it->hasNext()) {
        Usuario* cont = dynamic_cast<Usuario*> (it->getCurrent());
        Dtcontactos->add(cont->GetContacto());
        it->next();
    }
    return Dtcontactos;
}
//    Conversacion * Usuario::selecionarConversacion(int idConv){
//        IIterator *it=estadoConv->iterator();
//        while(it->hasNext()){
//            EstadoConv *ec= dynamic_cast<EstadoConv*>(it->getCurrent());
//            if(ec->getConversacion()->getIdConv()==idConv){
//                Conversacion * conv=ec->getConversacion();
//                return conv;
//            }
//        }
//    }
//    void Usuario::crearTipoGrupo(DtTipo * tip,Grupo * g){
//    
//    }

void Usuario::crearConvGrupo(Conversacion *conv) {
}

//    DtFechaHoraIng * Usuario::getFechaIng(Grupo *g){
//        IIterator *it=tipo->iterator();
//        while(it->hasNext()){
//            Tipo *tip=dynamic_cast<Tipo*>(it->getCurrent());
//            //if(tip->soyDelGrupo(g)==true)return tip->getFechaHoraIng();
//            }
//    }

Usuario * Usuario::seleccionarCont(int numCel) {
    intKey *key = new intKey(numCel);

    Usuario * cont = dynamic_cast<Usuario*> (contactos->find(key));
    return cont;
}

void Usuario::crearConversacion(Usuario * cont, Conversacion *conv) {
    EstadoConv *eC = new EstadoConv(cont, conv);
    estadoConv->add(eC);
    //crearEstadoConv(conv,cont,ContMensaje.getUsu());
}

void Usuario::crearEstadoConv(Conversacion *conv, Usuario * cont, Usuario * usuAct) {
    EstadoConv *ec = new EstadoConv(usuAct, conv);
    cont->estadoConv->add(ec);
}
