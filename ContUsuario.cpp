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
int ContUsuario::getNumContacto(int idConv){}
//iContUsuario * ContUsuario::instance = NULL;
Lista * ContUsuario::seleccionarConversacion(int idconv){}
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
    if(usuLog->GetCelular()==numCel)return true;
    
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
       this->usuLog = usU;
       /*Asignar al usuario usU fecha y hora del sistema*/
       Fecha_Hora_sis* a;
       usU->SetUltima_conexion(a->getUltimaConexion());// Esto tiene error y no tenog ni puta idea de que es!
       //setUsuLog(usu->GetCelular()); No hace nada? No sé como pensamos controlar el usuario que está logeado
        setUsuLog(usU); 
       DtConexion* r = new DtConexion();
       return r;
}
Usuario* ContUsuario::getUsu(){
    return this->usuLog;
}
Lista *ContUsuario::listarContactos(){
    Lista* listDtContacto = new Lista();
    intKey* ikey = new intKey(this->numCel);
    Usuario* u = dynamic_cast<Usuario*>(this->usuario->find(ikey));
    Lista* contactos = u->GetContactos();
    if(contactos->isEmpty()){
        return listDtContacto;
    }
    else{
        IIterator* i = contactos->iterator();
        while(i->hasNext()){
            u = dynamic_cast<Usuario*>(i->getCurrent());
            DtContacto* dtc = new DtContacto();
            dtc = u->GetContacto();
            listDtContacto->add(dtc);
        }
    }
    return listDtContacto;
}
DtContacto* ContUsuario::ingContacto(int numCelular){
    intKey* ikey = new intKey(numCelular);
    Usuario* usu = dynamic_cast<Usuario*>(this->usuario->find(ikey)); 
    DtContacto* dtc = NULL;
    if(usu != NULL){
        if(usu->GetCelular() == this->usuLog->GetCelular()){
           // throw std::invalid_argument("No puedes agregarte como contacto a vos mismo.\n");
        }
        dtc = new DtContacto();
        dtc = usu->GetContacto();
    }
    else{
        //throw std::invalid_argument("No existe un usuario con ese celular\n");
    }
    return dtc;
}
void ContUsuario::agregaContacto(DtContacto*  dtc){
    intKey* ikey = new intKey(atoi(dtc->GetNumCel().c_str()));
    Usuario* usu = dynamic_cast<Usuario*>(this->usuario->find(ikey));
    this->usuLog->GetContactos()->add(usu);
}
int ContUsuario::getNumUsuLog(){
    return this->usuLog->GetCelular();
}
void ContUsuario::cerrarSesion(DtConexion*){
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
void ContUsuario::setUltimaCon(DtUltCon*){
    
}
void ContUsuario::setUsuLog(Usuario * usu){
    this->usuLog=usu;
            
}
Lista * ContUsuario::listarConversacion(){
    Lista * listaConv = this->usuLog->getConversaciones();
    return listaConv;    
}
string ContUsuario::getNombreCont(int receptor){
     return usuLog->nombreUsu(receptor); //tre el nombre del receptor
 
 }
 Lista* ContUsuario::listaConversacion(){
     Usuario* usuLog= getUsu();
     Lista *listConv;
     listConv=usuLog->getConversaciones();
     return listConv; 
 }
 Lista* ContUsuario::listaConversacionArc(){
     Usuario* usuLog=getUsu();
     Lista* listConvArch;
     listConvArch=usuLog->getConversacionesAr();
     return listConvArch;
 }
