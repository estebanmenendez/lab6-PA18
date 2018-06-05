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

#include"IContUsuario.h"
#include"DtUltCon.h"
#include"DtContacto.h"
#include"DtConexion.h"
#include"DtFecha.h"
#include"DtHora.h"
#include"IDictionary.h"
#include"Usuario.h"
#include"Lista.h"


using namespace std;

class ContUsuario : public iContUsuario{

    
private:
    Usuario * usuario;
    
        
public:

ContUsuario();
ContUsuario(const ContUsuario& orig);
~ContUsuario();

virtual void create(string,string,string,int,DtFecha,DtHora);
virtual void setUltimaCon(DtUltCon);
virtual void setUsuLog(Usuario);
virtual bool usuarioLogueado(int);
virtual bool ingresarCelular(int);
virtual bool altaUsuario(string,string,string);
virtual bool cancelaIngreso();
virtual DtConexion asignarSesion();
virtual Lista listarContactos();
virtual DtContacto ingContacto(int);
virtual void agregaContacto(DtContacto);
virtual void cerrarSesion(DtConexion); 
virtual void modificarPerfil(string, string, string);
virtual void actualizarDatos();

};

#endif /* CONTUSUARIO_H */

