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

//iContUsuario * ContUsuario::instance = NULL;

ContUsuario::ContUsuario(){}
ContUsuario::ContUsuario(const ContUsuario& orig){}
ContUsuario::~ContUsuario() {}

//void ContUsuario::create(string,string,string,int,DtFecha,DtHora){
//
//}

//void ContUsuario::setUltimaCon(DtUltCon) {
//    Fecha_Hora_sis * fechora;
//    DtUltCon *ultima = new DtUltCon(fechora->getFecha(),fechora->getHora());
//    this->usu->SetUltima_conexion(ultima);
//}

//void ContUsuario::setUsuLog(Usuario* usu){
//ContMensaje* contMen;
//contMen->setUsu(usu);
//ContGrupo* contGrup;
//contGrup->setUsu(usu);
//
//}


bool ContUsuario::usuarioLogueado(int numCel){
    if(usu->GetCelular()==numCel)return true;
    
    return false;
}
bool ContUsuario::ingresarCelular(int numCel){
    intKey* ikey = new intKey(numCel);
    bool ok = this->usuario->member(ikey);
    //if(ok == true) Guarda el número de cédula aunque no sea miembro
    setNumCel(numCel);
    return ok;
}
bool ContUsuario::altaUsuario(string nombre,string UrlImagen,string descripcion){
    //Fecha_Hora_sis* fechora; No se usa para nada????
    Usuario* nuevoUsu = new Usuario(nombre,UrlImagen,descripcion,this->getNumCel());
    intKey* key = new intKey(this->getNumCel());
    usuario->add(nuevoUsu,key);//Agrego al usuario a la lista de usuarios
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
DtConexion* ContUsuario::asignarSesion(){
       intKey *ikey = new intKey(this->numCel);
       Usuario * usU = dynamic_cast<Usuario*>(usuario->find(ikey));
       /*Asignar al usuario usU fecha y hora del sistema*/
       Fecha_Hora_sis* a;
       //usU->SetUltima_conexion(a->getUltimaConexion()); Esto tiene error y no tenog ni puta idea de que es!
       //setUsuLog(usu->GetCelular()); No hace nada? No sé como pensamos controlar el usuario que está logeado
       DtConexion* r = new DtConexion();
       return r;
}
Lista *ContUsuario::listarContactos(){

}
DtContacto ContUsuario::ingContacto(int){

}
void ContUsuario::agregaContacto(DtContacto){

}
void ContUsuario::cerrarSesion(DtConexion){
}
void ContUsuario::modificarPerfil(string, string, string){
}
void ContUsuario::actualizarDatos(){
}

void ContUsuario::setNumCel(int numCel) {
    this->numCel = numCel;
}

int ContUsuario::getNumCel() {
    return numCel;
}
void ContUsuario::setUltimaCon(DtUltCon){
    
}
void ContUsuario::setUsuLog(int){

}

/*iContUsuario * ContUsuario::getInstance(){
    if(instance== NULL)
        instance = new ContUsuario();
    return instance;   
}
*/

//
//void ContUsuario::setUsu(Usuario* usu) {
//    this->usu = usu;
//}
//
//Usuario* ContUsuario::getUsu()  {
//    return usu;
//}
