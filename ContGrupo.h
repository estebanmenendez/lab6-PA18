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
#include"Grupo.h"
//#include"Lista.h"
//#include"IDictionary.h"
using namespace std;


class ContGrupo: public iContGrupo {
    private:    
        //static iContGrupo * instance;
        Lista * listaUsuPart=new Lista();
        
    //Usuario * usu;
   
public:
    ContGrupo();
    
//    ContGrupo(const ContGrupo& orig);
    virtual ~ContGrupo();
   
    void crearTipoGrupo(DtTipo*, string);
    void createTipo(DtTipo*,string);
    void crearConvGrupo(string);
    void getUsuario(int);
    void getContactos();
    void getDtContacto();
    Lista* listarGrupos();
    DtContacto *seleccionarGrupo(string);
    DtContacto *seleccionarPart(int);
    bool agregarNuevoAdmin(int);
    Lista* listarContactos();
    DtContacto *seleccionarContacto(int);
    void agregarParticipante(DtContacto*);
    Lista* listarParticipantes();
    DtContacto *seleccionarParticipante(int);
    void eliminarPartipante(DtContacto*);
    void cancelar();
    //void setUsu(Usuario* usu);
    // Usuario* getUsu() const;
    DtGrupo* altaGrupo(string, string);
    void Salir();
    //static iContGrupo * getInstance();
};
#endif /* CONTGRUPO_H */

