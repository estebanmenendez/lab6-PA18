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
#include "EstadoConv.h"
#include"ContMensaje.h"
#include "IIterator.h"
#include "Visto.h"
Conversacion::Conversacion() {
}

Conversacion::Conversacion(const Conversacion& orig) {
}

Conversacion::~Conversacion() {
}


bool Conversacion::sosConversacion(int idConv){
    if(this->idConv==idConv)return true;
    return false;}
Mensaje Conversacion::getMensaje(int idMensaje){
   intKey *key=new intKey(idMensaje);
    Mensaje *men=(dynamic_cast<Mensaje*>(mensajes->find(key)));
    return men;
}

void Conversacion::remueveConv(Mensaje men){
    mensajes->removeObj(men);
}
void Conversacion::eviarMensaje(Mensaje){
    
    

}
Lista Conversacion::listarMensaje(DtFechaHoraIng *fecha_hora){
    Conversacion conv=ContMensaje.getConversacion();
   IIterator *it= conv.mensajes->getIteratorObj();
   Lista listDtMensaje = new Lista();
   if (fecha_hora==NULL){
    while(it->hasNext()){
       listDtMensaje.add(it->getCurrent());
       Mensaje *m=dynamic_cast<Mensaje*>(it->getCurrent());
                Visto v= m->esReceptor(ContMensaje.getUsu());
           if(v.getEstado()!=true)v.SetEstado(true);
   }
   }
   else{
       while(it->hasNext()){
           Mensaje *m=dynamic_cast<Mensaje*>(it->getCurrent());
           if(m->GetFechaEnv().GetAnio()>=fecha_hora->GetFecha().GetAnio()&&m->GetFechaEnv().GetDia()>=fecha_hora->GetFecha().GetDia()
              &&m->GetFechaEnv().GetMes()>=fecha_hora->GetFecha().GetMes()&& m->GetHoraEnv().GetHora()>=fecha_hora->GetHora().GetHora()&& m->GetHoraEnv().GetMinutos()>=
                   fecha_hora->GetHora().GetMinutos()&&m->GetHoraEnv().GetSegundo()>=fecha_hora->GetHora().GetSegundo()){listDtMensaje.add(m);}
           Visto v= m->esReceptor(ContMensaje.getUsu());
           if(v.getEstado()!=true)v.SetEstado(true);
           
       }
   }
      return listDtMensaje;
}
Lista Conversacion::listarVistos(int){}
bool Conversacion::soyGrupo(){if (grupo!=NULL) return true;
return false;}
void Conversacion::setEstado(bool estado){
    IIterator *it=estadoConv->iterator();
    while(it->hasNext()){
    EstadoConv *ec= (dynamic_cast<EstadoConv*>(it->getCurrent()));
    if(ec->getUsuario()== ContMensaje().getUsu())
    {ec->setEstado(estado);} 
   
    }
    
}
    