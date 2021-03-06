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
#include "ContMensaje.h"
#include "ContGrupo.h"
#include "intKey.h"
#include "Fecha_Hora_sis.h"


using namespace std;

class ContUsuario : public iContUsuario {

    
private:
    ListDicc * usuario = new ListDicc();
    Usuario* usu;
    int numCel;
   
    //static iContUsuario * instance;
    
public:
    ContUsuario();
    ContUsuario(const ContUsuario& orig);
    virtual ~ContUsuario();
    Lista * seleccionarConversacion(int idconv);
//    void create(string,string,string,int,DtFecha,DtHora);
   // void setUltimaCon(DtUltCon);
//    void setUsuLog(int);
    bool usuarioLogueado(int);
    bool ingresarCelular(int); // Chequea que el celular esté en la lista de usuarios del sistema.
    bool altaUsuario(string,string,string);
    bool cancelaIngreso();
    DtConexion* asignarSesion();
    Lista * listarContactos();
    DtContacto ingContacto(int);
    void agregaContacto(DtContacto);
    void cerrarSesion(DtConexion); 
    void modificarPerfil(string, string, string);
    void actualizarDatos();
    void setNumCel(int numCel);
    int getNumCel();
    //static iContUsuario * getInstance();
    //void setUsu(Usuario* usu);
    Usuario* getUsu();
    void setUltimaCon(DtUltCon);
    void setUsuLog(Usuario*);
    int getNumContacto(int idConv);
    Usuario* getUsu();
    string getNombreCont(int receptor);
    Lista* listaConversacion();
    Lista* listaConversacionArc();
};

#endif /* CONTUSUARIO_H */

