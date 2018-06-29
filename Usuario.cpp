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

#include <memory>

#include "Usuario.h"

void Usuario::addContacto(Usuario* u) {
    intKey* ikey = new intKey(u->GetCelular());
    this->contactos->add(u, ikey);
}
void Usuario::setIdConvGrupo(int id){
    IIterator *it=tipo->iterator();
    Tipo *t=dynamic_cast<Tipo*>(it->getCurrent());
    t->getGrupo()->getConversacion()->setIdConv(id);

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

Usuario::Usuario(int celUsu,string nombre,string UrlImagen,string descripcion){
    Fecha_Hora_sis* fechora;
    this->nombre = nombre;
    this->foto_Perfil = UrlImagen;
    this->descripcion = descripcion;
    this->celular = celUsu;
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
    return this->nombre;
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

Lista * Usuario::getConversaciones() {
    if (estadoConv->isEmpty() == true) {
        throw invalid_argument("No tiene conversaciones");
    }
    Lista *conversacionesAct = new Lista();
    IIterator *it = estadoConv->iterator();
    int cant = 0, cont = 0;
    
    while (it->hasNext()) {
        EstadoConv *ec = dynamic_cast<EstadoConv*> (it->getCurrent());
        if (ec->ConvActiva() == true) {
            if (convGrupal(ec->getConversacion()->getIdConv()) == false) {
                DtConversacion * DtConv = new DtConversacion(ec->getConversacion()->getIdConv(), ec->getConversacion()->getCelContacto()); //constructor conv comun
                conversacionesAct->add(DtConv);
            it->next();
            } else {
                conversacionesAct->add(getConvGrupo(ec->getConversacion()->getIdConv()));
                it->next();
            }
        } else cant++;
        
    }
    DtConversacion * DtConv = new DtConversacion(cant); //constructor conv archivadas
    conversacionesAct->add(DtConv);
    return conversacionesAct;
}

bool Usuario::convGrupal(int idconv) {
    IIterator *it = tipo->iterator();
    while (it->hasNext()) {
        Tipo *tip = dynamic_cast<Tipo*> (it->getCurrent());
        if (tip->getGrupo()->getConversacion()->getIdConv() == idconv)return true;
        it->next();
    }
    return false;
}

DtConversacion* Usuario::getConvGrupo(int idconv) {
    IIterator *it = tipo->iterator();
    while (it->hasNext()) {
        Tipo *tip = dynamic_cast<Tipo*> (it->getCurrent());
        if (tip->getGrupo()->getConversacion()->getIdConv() == idconv) {
            DtConversacion * dtConv = new DtConversacion(tip->getGrupo()->GetNombre(), tip->getGrupo()->getConversacion()->getIdConv()); //copntructor grupo
            return dtConv;
        
        }
        it->next();
        
    }
}

Lista * Usuario::getConversacionesAr() {
    Lista *conversacionesArc = new Lista();
    IIterator * it = estadoConv->iterator();

    while (it->hasNext()) {
        EstadoConv *ec = dynamic_cast<EstadoConv*> (it->getCurrent());
        if (ec->ConvActiva() == false) {
            if (convGrupal(ec->getConversacion()->getIdConv()) == false) {
                DtConversacion * DtConv = new DtConversacion(ec->getConversacion()->getIdConv(), ec->getConversacion()->getCelContacto()); //constructor conv comun
                conversacionesArc->add(DtConv);
            } else {
                conversacionesArc->add(getConvGrupo(ec->getConversacion()->getIdConv()));
            }
        }
        it->next();
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

void Usuario::crearConvGrupo(Conversacion *conv) {
}

Usuario * Usuario::seleccionarCont(int numCel) {
    intKey *key = new intKey(numCel);

    Usuario * cont = dynamic_cast<Usuario*> (contactos->find(key));
    return cont;
}

Lista * Usuario::seleccionarConversacion(int idconv) {
    Lista *lM=new Lista();
    lM=listarMensajes(idconv);
    return lM;
}

void Usuario::crearConversacion(Conversacion *conv) {
    EstadoConv *eC = new EstadoConv(true, conv);
    this->estadoConv->add(eC);
}

void Usuario::crearEstadoConv(Conversacion *conv, Usuario * cont, Usuario * usuAct) {
    EstadoConv *ec = new EstadoConv(usuAct, conv);
    cont->estadoConv->add(ec);
}



bool Usuario::sosElOtro(int idConv) {
    IIterator *it = estadoConv->iterator();
    while (it->hasNext()) {
        EstadoConv *ec = dynamic_cast<EstadoConv*> (it->getCurrent());
        if (ec->getConversacion()->getIdConv() == idConv) return true;
        it->next();
    }
    return false;
}

Lista * Usuario::listarMensajes(int codConv) {
    Lista *listaMen = new Lista();
    IIterator *It = estadoConv->iterator();
    while (It->hasNext()) {
        EstadoConv *ec = dynamic_cast<EstadoConv*> (It->getCurrent());
        if (ec->getConversacion()->sosConversacion(codConv) == true) {
            listaMen = ec->getConversacion()->listarMensaje(NULL);
            return listaMen;
        }
        It->next();
    }
}

Lista * Usuario::listarVistos(int idMens,int idConv) {
    Lista *vistos=new Lista();
    IIterator *it = estadoConv->iterator();
    while (it->hasNext()) {
        EstadoConv *ec = dynamic_cast<EstadoConv*> (it->getCurrent());
        if(ec->getConversacion()->getIdConv()==idConv){
            vistos=ec->getConversacion()->listarVistos(idMens);
        }
        it->next();
    }

}
int Usuario::getNumContacto(int idConv){
    IIterator *it=contactos->getIteratorObj();
    while(it->hasNext()){
        Usuario* usu=dynamic_cast<Usuario*>(it->getCurrent());
        if(usu->sosElOtro(idConv)==true){
            return usu->GetCelular();
        }
        it->next();
    }
    
}
string Usuario::nombreUsu(int numCel) {
    intKey *iKey = new intKey(numCel);
    Usuario *us = dynamic_cast<Usuario*> (contactos->find(iKey));
    return us->GetNombre();
}

void Usuario::crearTipo(Grupo* grupo,string tipo){
    Tipo * tipos = new Tipo(grupo,tipo);
    this->SetTipo(tipos);
}

void Usuario::crearEstadoConversacion(Conversacion *conv) {
    EstadoConv *eC = new EstadoConv(false, conv);
    this->estadoConv->add(eC);
}
Lista * Usuario::getTipos() {
    
    Lista* dtTipo = new Lista();
    IIterator * it = tipo->iterator();
    while (it->hasNext()) {
        Tipo* cont = dynamic_cast<Tipo*> (it->getCurrent());
       dtTipo->add(cont->getGrupos());
        it->next();
    }
    return dtTipo;
}

Lista * Usuario::getContactosGrupo(string grupo) {
    Lista* Dtcontactos = new Lista();
    bool esDelGrupo; 
    IIterator * it = contactos->getIteratorObj();
    
    while (it->hasNext()) {
        Usuario* cont = dynamic_cast<Usuario*> (it->getCurrent());
        
        //Lista* listaTipo = cont->tipo;
        IIterator * itt = cont->tipo->iterator();
        while (itt->hasNext()) {
            Tipo* tip = dynamic_cast<Tipo*> (itt->getCurrent());
            if (tip->getGrupo()->GetNombre() == grupo){
                esDelGrupo = true;
                DtContactoGrupo* contGrup = new DtContactoGrupo(cont->celular,cont->nombre,tip->GetTipo(),tip->GetFechaIng(),tip->GetHoraIng());
                Dtcontactos->add(contGrup);
                break;
            }
            itt->next();
        }
        it->next();
    }
    return Dtcontactos;
}

Grupo* Usuario::getGrupo(string grupo){
    Grupo* devGrupo = NULL;
    IIterator * itt = this->tipo->iterator();
        while (itt->hasNext()) {
            Tipo* tip = dynamic_cast<Tipo*> (itt->getCurrent());
            if (tip->getGrupo()->GetNombre() == grupo){
                devGrupo= tip->getGrupo();
                break;
            }
            itt->next();
        }
    return devGrupo;
}
void Usuario::archivaConversacion(int conversa){
    
    IIterator * itt = this->estadoConv->iterator();
        while (itt->hasNext()) {
            EstadoConv* tip = dynamic_cast<EstadoConv*> (itt->getCurrent());
            if (tip->getConversacion()->getIdConv() == conversa){
                tip->setEstado(true);
                break;
            }
            itt->next();
        }
}

Conversacion* Usuario::getConversacion(int idConv) {
    IIterator *it = this->estadoConv->iterator();
    while(it->hasNext()){
        EstadoConv* ec = dynamic_cast<EstadoConv*>(it->getCurrent());
        if(ec->getConversacion()->getIdConv() == idConv)
            return ec->getConversacion();
        it->next();
    }
    return NULL;
}
    
    void Usuario::setFechaHoraG(DtFecha* fecha, DtHora* hora){
        IIterator *it=tipo->iterator();
        while(it->hasNext()){
            Tipo *t=dynamic_cast<Tipo*>(it->getCurrent());
            if(t->getGrupo()->GetCreador()==this->celular){
                t->getGrupo()->SetFecha(fecha);
                t->getGrupo()->SetHora(hora);
                
            }
        }
    }

void Usuario::setMensaje(Mensaje* m, int idConv){
    IIterator* it=estadoConv->iterator();
    
    while(it->hasNext()){
        EstadoConv* ec=dynamic_cast<EstadoConv*>(it->getCurrent());
        if(ec->getConversacion()->getIdConv()==idConv){
        ec->getConversacion()->setMensaje(m);
        }
        it->next();
    }

}
bool Usuario::existeConversacion(int idConv){
    IIterator *it=estadoConv->iterator();
    while(it->hasNext()){
        EstadoConv * ec= dynamic_cast<EstadoConv*>(it->getCurrent());
        if(ec->getConversacion()->getIdConv()==idConv){return true;}
        it->next();
    }
    return false;
}
bool Usuario::esReceptor(int idMen, int idConv){
    IIterator *it = estadoConv->iterator();
    
    while(it->hasNext()){
        EstadoConv * ec=dynamic_cast<EstadoConv*>(it->getCurrent());
        if(ec->getConversacion()->getIdConv()==idConv){
            return ec->getConversacion()->esReceptor(idMen,this->celular);
        }
        it->next();
    }  
    return false;
}