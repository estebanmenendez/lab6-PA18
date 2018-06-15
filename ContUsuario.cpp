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
#include "intKey.h"
#include "Fecha_Hora_sis.h"
#include "ContMensaje.h"
#include "ContGrupo.h"

using namespace std;


ContUsuario::ContUsuario(){}
ContUsuario::ContUsuario(const ContUsuario& orig){}
ContUsuario::~ContUsuario() {}

void ContUsuario::create(string,string,string,int,DtFecha,DtHora){}
void ContUsuario::setUltimaCon(){
    DtUltCon *ultima = new DtUltCon(Fecha_Hora_sis.getFecha(),Fecha_Hora_sis.getHora());
usu->SetUltima_conexion(ultima);}

void ContUsuario::setUsuLog(Usuario){
ContMensaje.setUsu(usu);
ContGrupo.setUsu(usu);}
bool ContUsuario::usuarioLogueado(int numCel){
    if(usu->GetCelular()==numCel)return true;
    
    return false;
}
bool ContUsuario::ingresarCelular(int numCel){
    intKey *ikey=new intKey(numCel);
    bool ok= usuario->member(ikey);
    if(ok==true)setNumCel(numCel);
    return ok;
}
bool ContUsuario::altaUsuario(string nombre,string UrlImagen,string descripcion){
    Usuario * nuevoUsu=new Usuario(getNumCel(),nombre,UrlImagen,descripcion,Fecha_Hora_sis.getFecha(),Fecha_Hora_sis.getHora());
    intKey *key = new intKey(getNumCel());
    usuario->add(nuevoUsu,key);
    return true;
}
bool ContUsuario::cancelaIngreso(){
    intKey *ikey=new intKey(getNumCel());
    Usuario *usuR=dynamic_cast<Usuario*>(usuario->find(ikey));
    Usuario *aux1=dynamic_cast<Usuario*>(usuario->removeObj(usuR));
    delete aux1;
   intKey *key= dynamic_cast<intKey*>(usuario->removeKey(ikey));
   delete(key);
   
    
}
DtConexion ContUsuario::asignarSesion(){
       intKey *ikey=new intKey(numCel);
       Usuario * usU=dynamic_cast<Usuario*>(usuario->find(ikey));
       setUsu(usU);
       setUltimaCon();
       setUsuLog(usu);
}
Lista ContUsuario::listarContactos(){}
DtContacto ContUsuario::ingContacto(int){}
void ContUsuario::agregaContacto(DtContacto){}
void ContUsuario::cerrarSesion(){}
void ContUsuario::modificarPerfil(string, string, string){}
void ContUsuario::actualizarDatos(){}

void ContUsuario::setNumCel(int numCel) {
    this->numCel = numCel;
}

int ContUsuario::getNumCel() const {
    return numCel;
}

void ContUsuario::setUsu(Usuario* usu) {
    this->usu = usu;
}

Usuario* ContUsuario::getUsu() const {
    return usu;
}
