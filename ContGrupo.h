/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ContGrupo.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 01:47 AM
 */

#ifndef CONTGRUPO_H
#define CONTGRUPO_H

#include"iContGrupo.h"




class ContGrupo: public iContGrupo {
    
public:
    
    ContGrupo();
    ContGrupo(const ContGrupo& orig);
    virtual ~ContGrupo();
    
private:    
    
void create(DtGrupo,Usuario);
void crearTipoGrupo(DtTipo,Grupo);
void createTipo(DtTipo,Grupo);
void crearConvGrupo(Grupo);
void getUsuario(Usuario);
void getContactos();
void getDtContacto();
DtGrupo listarGrupos();
DtContacto seleccionarGrupo(string);
DtContacto seleccionarPart(int);
bool agregarNuevoAdmin(int);
DtContacto listarContactos();
DtContacto seleccionarContacto(int);
void agregarParticipante(DtContacto);
DtContacto listarParticipantes();
DtContacto seleccionarParticipante(int);
void eliminarPartipante(DtContacto);
void cancelar();
DtGrupo altaGrupo(string,string);
void Salir();


};

#endif /* CONTGRUPO_H */

