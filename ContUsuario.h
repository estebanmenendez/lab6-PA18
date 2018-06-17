/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ContUsuario.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 01:47 AM
 */

#ifndef CONTUSUARIO_H
#define CONTUSUARIO_H

#include"iContUsuario.h"
#include"DtUltCon.h"
#include"DtContacto.h"
#include"DtConexion.h"
#include"DtFecha.h"
#include"DtHora.h"
#include"IDictionary.h"
#include"Usuario.h"
#include"Lista.h"
#include "ListaDicc.h"


using namespace std;

class ContUsuario : public iContUsuario{

    
private:
    ListDicc * usuario=new ListDicc();
    Usuario * usu;
    int numCel;
        
public:

    ContUsuario();
    ContUsuario(const ContUsuario& orig);
    virtual ~ContUsuario();

     void create(string,string,string,int,DtFecha,DtHora) ;
    void setUltimaCon();
    void setUsuLog(Usuario*);
     bool usuarioLogueado(int);
     bool ingresarCelular(int);
     bool altaUsuario(string,string,string);
     bool cancelaIngreso();
    DtConexion asignarSesion();
     Lista listarContactos();
     DtContacto ingContacto(int);
     void agregaContacto(DtContacto);
    void cerrarSesion(); 
    void modificarPerfil(string, string, string);
    void actualizarDatos();
    void setNumCel(int numCel);
    int getNumCel() const;
    void setUsu(Usuario* usu);
    Usuario* getUsu() const;

};

#endif /* CONTUSUARIO_H */

