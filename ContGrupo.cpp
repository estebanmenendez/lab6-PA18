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
bool ContGrupo::agregarNuevoAdmin(int){}
Lista* ContGrupo::listarContactos(){}
DtContacto ContGrupo::seleccionarContacto(int){}
void ContGrupo::agregarParticipante(DtContacto){}
Lista* ContGrupo::listarParticipantes(){
 
}
DtContacto ContGrupo::seleccionarPart(int){}
void ContGrupo::eliminarPartipante(DtContacto){}
void ContGrupo::cancelar(){}
DtGrupo ContGrupo::altaGrupo(string,string){}
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