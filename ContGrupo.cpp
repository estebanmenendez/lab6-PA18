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

ContGrupo::ContGrupo() {
}

ContGrupo::ContGrupo(const ContGrupo& orig) {
}

ContGrupo::~ContGrupo() {
}

void ContGrupo::create(DtGrupo,Usuario){}
void ContGrupo::crearTipoGrupo(DtTipo,Grupo){}
void ContGrupo::createTipo(DtTipo,Grupo){}
void ContGrupo::crearConvGrupo(Grupo){}
void ContGrupo::getUsuario(Usuario){}
void ContGrupo::getContactos(){}
void ContGrupo::getDtContacto(){}
DtGrupo ContGrupo::listarGrupos(){}
DtContacto ContGrupo::seleccionarGrupo(string){}
DtContacto ContGrupo::seleccionarParticipante(int){}
bool ContGrupo::agregarNuevoAdmin(int){}
DtContacto ContGrupo::listarContactos(){}
DtContacto ContGrupo::seleccionarContacto(int){}
void ContGrupo::agregarParticipante(DtContacto){}
DtContacto ContGrupo::listarParticipantes(){}
DtContacto ContGrupo::seleccionarPart(int){}
void ContGrupo::eliminarPartipante(DtContacto){}
void ContGrupo::cancelar(){}
DtGrupo ContGrupo::altaGrupo(string,string){}
void ContGrupo::Salir(){}

void ContGrupo::setUsu(Usuario* usu) {
    this->usu = usu;
}

Usuario* ContGrupo::getUsu() const {
    return usu;
}
