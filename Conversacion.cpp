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
#include "ContUsuario.h"

Conversacion::Conversacion() {
}

Conversacion::Conversacion(const Conversacion& orig) {
}

Conversacion::~Conversacion() {
}


bool Conversacion::sosConversacion(int idConv){
    if(this->idConv==idConv)return true;
    return false;}
Mensaje* Conversacion::getMensaje(int idMensaje){
   intKey *key=new intKey(idMensaje);
    Mensaje *men=(dynamic_cast<Mensaje*>(mensajes->find(key)));
    return men;
}

void Conversacion::remueveConv(Mensaje* men){
    mensajes->removeObj(men);//incompleto
}
void Conversacion::eviarMensaje(Mensaje* m){
//    ContMensaje* contMen;
//    Fecha_Hora_sis* fechora;
//    if(soyGrupo()==true){
//        Lista *listaUsuG=new Lista();
//        listaUsuG=grupo->getUsuarios();
//        IIterator *it=listaUsuG->iterator();
//        while(it->hasNext()){
//            Usuario *usp=dynamic_cast<Usuario*>(it->getCurrent());
//            if(contMen->getUsu()!=usp){
//                m->setReceptor(usp);
//            }
//        }
//    }
//    else{
//        m->setReceptor(this->getReceptor());
//    }
//    m->SetFechaEnv(fechora->getFecha());
//    m->SetHoraEnv(fechora->getHora());
//    intKey *key=new intKey(m->GetCodigo());
//    mensajes->add(m,key);

}

Lista* Conversacion::listarMensaje(DtFechaHoraIng *fecha_hora){
    ContUsuario *contUsu;
  IIterator *it=mensajes->getIteratorObj();
  Lista* listDtMensaje = new Lista();
  if (fecha_hora==NULL){
   while(it->hasNext()){
        Mensaje *men=dynamic_cast<Mensaje*>(it->getCurrent()); 
        men->esReceptor(contUsu->getNumCel());
        listDtMensaje->add(men->getMensaje());
     
               
   }
   }
   else{
       while(it->hasNext()){
           Mensaje *m=dynamic_cast<Mensaje*>(it->getCurrent());
           if(m->GetFechaEnv().GetAnio()>=fecha_hora->GetFecha().GetAnio()&&m->GetFechaEnv().GetDia()>=fecha_hora->GetFecha().GetDia()
              &&m->GetFechaEnv().GetMes()>=fecha_hora->GetFecha().GetMes()&& m->GetHoraEnv().GetHora()>=fecha_hora->GetHora().GetHora()&& m->GetHoraEnv().GetMinutos()>=
              fecha_hora->GetHora().GetMinutos()&&m->GetHoraEnv().GetSegundo()>=fecha_hora->GetHora().GetSegundo()){
            listDtMensaje->add(m->getMensaje());              
            m->esReceptor(contUsu->getUsu());}
            }
        
        }
      return listDtMensaje;
}
Lista *Conversacion::listarVistos(int idMen){
    Lista *listaMensVisto=new Lista();
    intKey *key=new intKey(idMen);
  Mensaje *men=dynamic_cast<Mensaje*>(mensajes->find(key)); 
//  listaMensVisto=men->getVistos();
  return listaMensVisto;

}


void Conversacion::setEstado(bool estado){
//    ContMensaje* contMen;
//    IIterator *it=estadoConv->iterator();
//    while(it->hasNext()){
//    EstadoConv *ec= (dynamic_cast<EstadoConv*>(it->getCurrent()));
//    if(ec->getUsuario()== contMen->getUsu())
//    {ec->setEstado(estado);} 
//   
//    }
//    
}



int Conversacion::getIdConv() {
    return idConv;
}

void Conversacion::setIdConv(int idConv) {
    this->idConv = idConv;
}

//void Conversacion::setEstadoConv(EstadoConv* estadoC){
//    estadoConv->add(estadoC);
//}
void Conversacion::setMensaje(Mensaje* mensaje){
    intKey *key = new intKey(mensaje->GetCodigo());
    mensajes->add(mensaje,key);
}

//    void Conversacion::setGrupo(Grupo* grupo) {
//    this->grupo = grupo;
//    }
//
//    Grupo* Conversacion::getGrupo() const {
//    return grupo;
//    }
/*Usuario * Conversacion::getReceptor(){
    IIterator *it= estadoConv->iterator();
    while (it->hasNext()) {
        Usuario * usR=dynamic_cast<Usuario*>(it->getCurrent());
        if (usR!=ContMensaje.getUsu()) return usR;
    }   
}*/
/*Lista * Conversacion::getReceptores(){
//IIterator *it= estadoConv->iterator();
Lista *listUsuRecep=new Lista();
    while (it->hasNext()) {
        Usuario * usR=dynamic_cast<Usuario*>(it->getCurrent());
  //      if (usR!=ContMensaje.getUsu()) listUsuRecep.add(usR);
    } 
return listUsuRecep;
}*/
int Conversacion::getCelContacto(){
    ContUsuario *contusu;
    return contusu->getNumContacto(this->idConv);
}