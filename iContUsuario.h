/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   iContUsuario.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 01:47 AM
 */

#ifndef ICONTUSUARIO_H
#define ICONTUSUARIO_H

#include "IKey.h"
#include "Lista.h"
#include "DtFecha.h"
#include "DtHora.h"
#include "DtContacto.h"
#include "DtConexion.h"
#include "DtUltCon.h"
#include "Usuario.h"
//#include "DtContactoGrupo.h"

using namespace std;

class iContUsuario {
public:

    virtual ~iContUsuario();
    virtual void setUltimaCon(DtUltCon*) = 0;
    virtual void setUsuLog(Usuario*) = 0;
    virtual bool usuarioLogueado(int) = 0;
    virtual bool ingresarCelular(int) = 0;
    virtual bool altaUsuario(string, string, string) = 0;
    virtual bool cancelaIngreso() = 0;
    virtual DtConexion* asignarSesion() = 0;
    virtual Lista * listarContactos() = 0;
    virtual Lista * listarConversacion() = 0;
    virtual Lista * seleccionarConversacion(int) = 0;
    virtual void eliminarMensConv(int, int) = 0;
    virtual DtContacto* ingContacto(int) = 0;
    virtual void agregaContacto(DtContacto*) = 0;
    virtual void cerrarSesion(DtConexion*) = 0;
    virtual void modificarPerfil(string, string, string) = 0;
    virtual void actualizarDatos() = 0;
    virtual void setNumCel(int numCel) = 0;
    virtual int getNumCel() = 0;
    virtual Lista* listaConversacion() = 0;
    virtual Lista* listaConversacionArc() = 0;
    virtual string getNombreCont(int receptor) = 0;
    virtual int getNumContacto(int idConv) = 0;
    virtual int getNumUsuLog() = 0;
    virtual Usuario* getUsu() = 0;
    virtual void crearGrupoUsuario(Grupo*,string,int )= 0;
private:

};


#endif /* ICONTUSUARIO_H */

