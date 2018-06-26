/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ContUsuario.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 01:47 AM
 */

#include "ContUsuario.h"

using namespace std;

int ContUsuario::getNumContacto(int idConv) {
}

ContUsuario::ContUsuario() {
}

ContUsuario::ContUsuario(const ContUsuario& orig) {
}

ContUsuario::~ContUsuario() {
}

bool ContUsuario::usuarioLogueado(int numCel) {
    if (usuLog->GetCelular() == numCel)return true;
    return false;
}

bool ContUsuario::ingresarCelular(int numCel) {
    intKey* ikey = new intKey(numCel);
    bool ok = this->usuario->member(ikey);
    setNumCel(numCel);
    return ok;
}

bool ContUsuario::altaUsuario(string nombre, string UrlImagen, string descripcion) {
    Usuario* nuevoUsu = new Usuario(nombre, UrlImagen, descripcion, this->getNumCel());
    intKey* key = new intKey(this->getNumCel());
    usuario->add(nuevoUsu, key); //Agrego al usuario a la lista de usuarios
    return true;
}

bool ContUsuario::cancelaIngreso() {
    intKey *ikey = new intKey(getNumCel());
    Usuario *usuR = dynamic_cast<Usuario*> (usuario->find(ikey));
    Usuario *aux1 = dynamic_cast<Usuario*> (usuario->removeObj(usuR));
    delete aux1;
    intKey *key = dynamic_cast<intKey*> (usuario->removeKey(ikey));
    delete(key);
}

DtConexion* ContUsuario::asignarSesion() {
    intKey *ikey = new intKey(this->numCel);
    Usuario * usU = dynamic_cast<Usuario*> (usuario->find(ikey));
    this->usuLog = usU;
    Fecha_Hora_sis* a;
    usU->SetUltima_conexion(a->getUltimaConexion()); // Esto tiene error y no tenog ni puta idea de que es!
    DtConexion* r = new DtConexion();
    return r;
}

Usuario* ContUsuario::getUsu() {
    return this->usuLog;
}

Lista *ContUsuario::listarContactos() {
    Lista* listDtContacto = new Lista();
    intKey* ikey = new intKey(this->numCel);
    Usuario* u = dynamic_cast<Usuario*> (this->usuario->find(ikey));
    return u->GetContactos();
}

Lista * ContUsuario::listarConversacion() {
    Lista * listaConv = this->usuLog->getConversaciones();
    return listaConv;
}

Lista * ContUsuario::seleccionarConversacion(int idConv) {
    Lista * selecConv = this->usuLog->seleccionarConversacion(idConv);
}

void ContUsuario::eliminarMensConv(int idConv, int codMen) {
    this->usuLog->eliminarMensConv(idConv, codMen);
}

DtContacto* ContUsuario::ingContacto(int numCelular) {
    intKey* ikey = new intKey(numCelular);
    Usuario* usu = dynamic_cast<Usuario*> (this->usuario->find(ikey));
    DtContacto* dtc = NULL;
    if (usu != NULL) {
        dtc = new DtContacto();
        dtc = usu->GetContacto();
    }
    return dtc;
}

void ContUsuario::agregaContacto(DtContacto* dtc) {
    intKey* ikey = new intKey(atoi(dtc->GetNumCel().c_str()));
    Usuario* usu = dynamic_cast<Usuario*> (this->usuario->find(ikey));
    this->usuLog->addContacto(usu);
}

void ContUsuario::cerrarSesion(DtConexion*) {
    Fecha_Hora_sis* fhs;
    DtUltCon* ultc = fhs->getUltimaConexion();
    this->usuLog->SetUltima_conexion(ultc);
    this->usuLog = NULL;
}

int ContUsuario::getNumUsuLog() {
    return this->usuLog->GetCelular();
}

void ContUsuario::modificarPerfil(string, string, string) {
}

void ContUsuario::actualizarDatos() {
}

void ContUsuario::setNumCel(int numCel) {
    this->numCel = numCel;
}

int ContUsuario::getNumCel() {
    return numCel;
}

void ContUsuario::setUltimaCon(DtUltCon*) {

}

void ContUsuario::setUsuLog(Usuario * usu) {
    this->usuLog = usu;

}

string ContUsuario::getNombreCont(int receptor) {
    return usuLog->nombreUsu(receptor); //tre el nombre del receptor

}

Lista* ContUsuario::listaConversacion() {
    Usuario* usuLog = getUsu();
    Lista *listConv;
    listConv = usuLog->getConversaciones();
    return listConv;
}

Lista* ContUsuario::listaConversacionArc() {
    Usuario* usuLog = getUsu();
    Lista* listConvArch;
    listConvArch = usuLog->getConversacionesAr();
    return listConvArch;
}

 void ContUsuario::crearGrupoUsuario(Grupo* grupo,string celular,int mensaje){
    //crea un visto para cada usuario ##ver la fecha del Visto.
    Visto * visto = new Visto(atoi(celular.c_str()));
    //busca el usuario en la lista por su celular
    intKey *ikey = new intKey(atoi(celular.c_str()));
    Usuario * usU = dynamic_cast<Usuario*> (this->usuario->find(ikey));
    if (usU != NULL){
        //crea el Tipo y le setea el grupo
        if(usU->GetCelular() == this->usuLog->GetCelular()){ 
            usU->crearTipo(grupo,"Admin");
        }else{
            usU->crearTipo(grupo,"Usuario");
        }
        //si lo encuentra  crea el estado de Conversacion y le setea la conversacion.
        usU->crearEstadoConversacion(grupo->getConversacion());
       
        //con el id del Mensaje le agrega el visto del usuario.
        grupo->getConversacion()->getMensaje(mensaje)->GetVistos()->add(visto);
    } 
     
 }
