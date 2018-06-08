/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   iContGrupo.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 01:45 AM
 */

#ifndef ICONTGRUPO_H
#define ICONTGRUPO_H

#include"IKey.h"
#include"Lista.h"
#include"DtGrupo.h"
#include"DtTipo.h"
#include"DtContacto.h"
#include"Usuario.h"
#include"Grupo.h"


using namespace std;

class iContGrupo {
public:
    iContGrupo();
    iContGrupo(const iContGrupo& orig);
    virtual ~iContGrupo();
private:

virtual void create(DtGrupo,Usuario) = 0;
virtual void crearTipoGrupo(DtTipo,Grupo) = 0;
virtual void createTipo(DtTipo,Grupo) = 0;
virtual void crearConvGrupo(Grupo) = 0;
virtual void getUsuario(Usuario) = 0;
virtual void getContactos() = 0;
virtual void getDtContacto() = 0;
virtual DtGrupo listarGrupos() = 0;
virtual DtContacto seleccionarGrupo(string) = 0;
virtual DtContacto seleccionarPart(int) = 0;
virtual bool agregarNuevoAdmin(int) = 0;
virtual DtContacto listarContactos() = 0;
virtual DtContacto seleccionarContacto(int) = 0;
virtual void agregarParticipante(DtContacto) = 0;
virtual DtContacto listarParticipantes() = 0;
virtual DtContacto seleccionarParticipante(int) = 0;
virtual void eliminarPartipante(DtContacto) = 0;
virtual void cancelar() = 0;
virtual DtGrupo altaGrupo(string,string) = 0;
virtual void Salir() = 0;

    
};

#endif /* ICONTGRUPO_H */

