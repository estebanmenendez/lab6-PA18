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
#include "Fabrica.h"

using namespace std;
int ContUsuario::getIdConv(){
    this->idConv++;
    return this->idConv;
}
int ContUsuario::getNumContacto(int idConv) {
    return this->usuLog->getNumContacto(idConv);
}

ContUsuario::ContUsuario() {
}

ContUsuario::ContUsuario(const ContUsuario& orig) {
}

ContUsuario::~ContUsuario() {
}
Lista*  ContUsuario::listarInfoVisto(int idConv,int idMensaje){
   Lista* lMen=new Lista();
   lMen=this->usuLog->listarVistos(idMensaje,idConv);
   return lMen;
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


void ContUsuario::altaPrecargaUsuario(int celUsu, string nombre, string UrlImagen, string descripcion){
    Usuario* nuevoUsu = new Usuario(celUsu, nombre, UrlImagen, descripcion);
    intKey* key = new intKey(celUsu);
    usuario->add(nuevoUsu, key); //Agrego al usuario a la lista de usuarios
//    return true;
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
    //Fecha_Hora_sis* a;
    usU->SetUltima_conexion(Fabrica::getInstance()->getContFecha()->getFechaHora()); // Esto tiene error y no tenog ni puta idea de que es!
    DtConexion* r = new DtConexion();
    return r;
}

Usuario* ContUsuario::getUsu() {
    return this->usuLog;
}
Usuario* ContUsuario::getUsuario(int celUsu){
    intKey *key = new intKey(celUsu);
    Usuario * usu= dynamic_cast<Usuario*>(usuario->find(key));
    return usu;

}

//Lista *ContUsuario::listarContactos() {
//    Lista* listDtContacto = new Lista();
//    intKey* ikey = new intKey(this->numCel);
//    Usuario* u = dynamic_cast<Usuario*> (this->usuario->find(ikey));
//    Lista* contactos = u->GetContactos();
//    if (contactos->isEmpty()) {
//        return listDtContacto;
//    } else {
//        IIterator* i = contactos->iterator();
//        while (i->hasNext()) {
//            u = dynamic_cast<Usuario*> (i->getCurrent());
//            DtContacto* dtc = new DtContacto();
//            dtc = u->GetContacto();
//            listDtContacto->add(dtc);
//        }
//    }
//    return listDtContacto;
//}

Lista *ContUsuario::listarContactos(string fromFunction) {
    intKey* ikey = new intKey(this->numCel);
    Usuario* u = dynamic_cast<Usuario*> (this->usuario->find(ikey));
    return u->GetContactos(fromFunction);
}
Lista * ContUsuario::listarConversacion() {
    Lista * listaConv = this->usuLog->getConversaciones();
    return listaConv;
}
Lista * ContUsuario::listarConversacion(string option) {
    Lista * listaConv = this->usuLog->getConversaciones(option);
    return listaConv;
}

Lista * ContUsuario::seleccionarConversacion(int idConv) {
    Lista * selecConv = this->usuLog->seleccionarConversacion(idConv);
}

void ContUsuario::eliminarMensConv(int idConv, int codMen, int celUsu) {
    this->usuLog->eliminarMensConv(idConv, codMen, celUsu);
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

//void ContUsuario::altaPrecargaContacto(int numCelular) {
//    intKey* ikey = new intKey(numCelular);
//    Usuario* usu = dynamic_cast<Usuario*> (this->usuario->find(ikey));
//    if (usu != NULL) {
//        if (numCelular == 90123654) {
//            usu->addContacto(usu->seleccionarCont(90765432));
//            usu->addContacto(usu->seleccionarCont(90246810));
//            usu->addContacto(usu->seleccionarCont(90666777));
//        }
//        if (numCelular == 90765432) {
//            usu->addContacto(usu->seleccionarCont(90123654));
//            usu->addContacto(usu->seleccionarCont(90246810));
//        }
//        if (numCelular == 90246810) {
//            usu->addContacto(usu->seleccionarCont(90123654));
//            usu->addContacto(usu->seleccionarCont(90765432));
//            usu->addContacto(usu->seleccionarCont(90666777));
//        }
//        if (numCelular == 90666777) {
//            usu->addContacto(usu->seleccionarCont(90123654));
//            usu->addContacto(usu->seleccionarCont(90246810));
//        }
//    }
//}

//void ContUsuario::altaPrecargaConversacion(){
//    
//}

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
    listConv = usuLog->getConversaciones("p");
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
        grupo->getConversacion()->getMensaje(mensaje)->getVisto()->add(visto);
    } 
     
 }
void ContUsuario::elijeContacto(int celUsu) {
    this->contactoReceptor = celUsu;
    intKey *ikey = new intKey(celUsu);
    Usuario* u = dynamic_cast<Usuario*>(this->usuario->find(ikey));
    Conversacion *conv = new Conversacion();
    EstadoConv *ec1 = new EstadoConv(false, conv), *ec2 = new EstadoConv(false, conv);
    this->usuLog->SetEstadoConv(ec1);
    u->SetEstadoConv(ec2);
    Fabrica::getInstance()->getContMensaje()->selecConversacion(this->idConv);
}

Conversacion* ContUsuario::getConversacion(int idConv) {
    return this->usuLog->getConversacion(idConv);
}

int ContUsuario::getReceptor() {
    return this->contactoReceptor;
}

Usuario* ContUsuario::getUsuByCel(int celUsu) {
    intKey *ikey = new intKey(celUsu);
    return dynamic_cast<Usuario*>(this->usuario->find(ikey));
}
//Conversacion* ContUsuario::getConversacion(int idConv) {
//    return this->usuLog->getConversacion(idConv);
//}
 
void ContUsuario::altaPrecargaContacto(int numCelular) {
    intKey* ikey = new intKey(numCelular);
    Usuario* usu = dynamic_cast<Usuario*> (this->usuario->find(ikey));
    if (usu != NULL) {
        if (numCelular == 23654) {//90123654
            intKey* key=new intKey(65432); //90765432
            intKey* key1=new intKey(46810); //90246810
            intKey* key2=new intKey(66777); //90666777
            usu->addContacto(dynamic_cast<Usuario*> (this->usuario->find(key)));
            usu->addContacto(dynamic_cast<Usuario*> (this->usuario->find(key1)));
            usu->addContacto(dynamic_cast<Usuario*> (this->usuario->find(key2)));
            delete(key);
            delete(key1);
            delete(key2);
        }
        if (numCelular == 65432)  {//90765432
            intKey* key3=new intKey(23654);//90123654
            intKey* key4=new intKey(46810); //90246810
            usu->addContacto(dynamic_cast<Usuario*> (this->usuario->find(key3)));
            usu->addContacto(dynamic_cast<Usuario*> (this->usuario->find(key4)));
            delete(key3);
            delete(key4);
        }
        if (numCelular == 46810){  //90246810
            intKey* key5=new intKey(23654); //90123654
            intKey* key6=new intKey(65432); //90765432
            intKey* key7=new intKey(66777); //90666777
            usu->addContacto(dynamic_cast<Usuario*> (this->usuario->find(key5)));
            usu->addContacto(dynamic_cast<Usuario*> (this->usuario->find(key6)));
            usu->addContacto(dynamic_cast<Usuario*> (this->usuario->find(key7)));
            delete(key5);
            delete(key6);
            delete(key7);
        }
        if (numCelular == 66777) { //90666777
            intKey* key8=new intKey(23654); //90123654
            intKey* key9=new intKey(46810); //90246810
            usu->addContacto(dynamic_cast<Usuario*> (this->usuario->find(key8)));
            usu->addContacto(dynamic_cast<Usuario*> (this->usuario->find(key9)));
            delete(key8);
            delete(key9);
        }
    }
    
}

void ContUsuario::altaPrecargaConversacion(){
    Conversacion * conv1=new Conversacion(2);
    Conversacion * conv2=new Conversacion(3);
    intKey * key1=new intKey(23654); //90123654
    intKey * key2=new intKey(65432); //90765432
    intKey * key3=new intKey(46810); //90246810
    intKey * key4=new intKey(66777); //90666777
   
    Usuario* u1=dynamic_cast<Usuario*>(usuario->find(key1));
    u1->crearEstadoConversacion(conv1);
    Usuario* u2=dynamic_cast<Usuario*>(usuario->find(key2));
    u2->crearEstadoConversacion(conv1);
    Usuario* u3=dynamic_cast<Usuario*>(usuario->find(key3));
    u3->crearEstadoConversacion(conv2);
    Usuario* u4=dynamic_cast<Usuario*>(usuario->find(key4));
    u4->crearEstadoConversacion(conv2);

}
void ContUsuario::setFechaHoraG(DtFecha* fech, DtHora * hora) {
    usuLog->setFechaHoraG(fech,hora);
}
int ContUsuario::generarIdConv(){
    idConv++;
    return idConv;
}
 void ContUsuario::setIdConvGrupo(int idUsu){
     intKey *key=new intKey(idUsu);
     Usuario *us=dynamic_cast<Usuario*>(usuario->find(key));
     us->setIdConvGrupo(1);
 }
 
 
