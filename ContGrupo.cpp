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
//iContGrupo * ContGrupo::instance = NULL;


ContGrupo::ContGrupo() {
    
}

//ContGrupo::ContGrupo(const ContGrupo& orig) {
//}

ContGrupo::~ContGrupo() {
}


void ContGrupo::crearTipoGrupo(DtTipo,string){}
void ContGrupo::createTipo(DtTipo,string){}
void ContGrupo::crearConvGrupo(string){}
void ContGrupo::getUsuario(int){}
void ContGrupo::getContactos(){}
void ContGrupo::getDtContacto(){}
Lista* ContGrupo::listarGrupos(){}
DtContacto ContGrupo::seleccionarGrupo(string){}
DtContacto ContGrupo::seleccionarParticipante(int){}
bool ContGrupo::agregarNuevoAdmin(int){

}
Lista* ContGrupo::listarContactos(){
    Usuario * usuLog = Fabrica::getInstance()->getContUsuario()->getUsuLog();
    Lista* listDtContacto = usuLog->GetContactos();
    return listDtContacto;
}
DtContacto ContGrupo::seleccionarContacto(int){}
void ContGrupo::agregarParticipante(DtContacto* dtc){
    this->ltElegidos->add(dtc);

}


Lista* ContGrupo::listarParticipantes(){
    Lista* listPart = this->ltElegidos;
    return listPart;
}

DtContacto ContGrupo::seleccionarPart(int){
    
}

void ContGrupo::eliminarParticipante (DtContacto* dtc){
    DtContacto* dtn = new DtContacto(); 
    IIterator* h =   this->ltElegidos->iterator();
    while(h->hasNext()){
        dtn = dynamic_cast<DtContacto*>(h->getCurrent());
        if (dtn->GetNumCel() == dtc->GetNumCel()){
            this->ltElegidos->remove(dtn);
            break;
        }
        h->next();
    }
}

void ContGrupo::cancelar(){}

DtGrupo* ContGrupo::altaGrupo(string imagen,string nombre){
    DtGrupo* dtGrupo;
    Grupo* grupo = new Grupo();
    grupo->SetImagen(imagen);
    grupo->SetNombre(nombre);
    return dtGrupo= new DtGrupo();
}
void ContGrupo::Salir(){}

/*iContGrupo * ContGrupo::getInstance(){
    if(instance== NULL)
        instance = new ContGrupo();
    return instance;
        
}*/


/*void ContGrupo::setUsu(Usuario* usu) {
    this->usu = usu;
}

Usuario* ContGrupo::getUsu() const {
    return usu;
}
*/