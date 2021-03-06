/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Usuario.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 01:30 AM
 */

#ifndef USUARIO_H
#define USUARIO_H

#include"DtFechaHoraIng.h"
#include "DtFecha.h"
#include "DtHora.h"
#include "DtUltCon.h"
#include "ICollectible.h"
#include "Lista.h"
#include "DtTipo.h"
#include "Mensaje.h"
#include "EstadoConv.h"
#include "DtContacto.h"
#include "ListaDicc.h"
#include "Tipo.h"
#include "Fecha_Hora_sis.h"
//#include "ContUsuario.h"
#include "ContMensaje.h"
//#include "Estado.h"
//#include "Conversacion.h"
#include<iostream>
#include "DtConversacion.h"
using namespace std;

class Usuario : public ICollectible {
public:
    //constructores:
    Usuario();
    Usuario(string nombre,string imagenPerfil,string descripcion,int numCel);
    Usuario(const Usuario& orig);
    virtual ~Usuario();
    //Setter atributos
    void SetCelular(int);
    void SetContacto(Usuario * contacto);
    void SetDescripcion(string);
    void SetNombre(string);
    void SetFoto_Perfil(string);
    void SetEstadoConv(EstadoConv *);
    void SetFechaCreacion(DtFecha *);
    void SetHoraCreacion(DtHora *);
    void SetTipo(Tipo *);
    void SetUltima_conexion(DtUltCon*);
    //Getters atributos
    int GetCelular();
    string GetDescripcion();
    string GetFoto_Perfil();
    string GetNombre();
    DtFecha* GetFechaCreacion();
    DtFecha* GetFecha_Registro();
    DtHora* GetHoraCreacion();
    DtUltCon* GetUltima_conexion();
    DtContacto* GetContacto();
    //Operaciones
    Lista * getConversaciones();
    Lista * getConversacionesAr();
    Lista * GetContactos();
    void crearConvGrupo(Conversacion *);
    Usuario * seleccionarCont(int);
    void crearConversacion(Usuario *, Conversacion *);//para el usuario actual
    void crearEstadoConv(Conversacion *conv,Usuario * usu,Usuario * usu2);//para el contacto
    bool convGrupal(int);
    DtConversacion * getConvGrupo(int);
    bool sosElOtro(int idConv);
    Lista * listarMensajes(int codConv);
    Lista * listarVistos(int idMens);
    string nombreUsu(int numCel);
private:
    ListDicc * contactos= new ListDicc();
    Lista * estadoConv=new Lista();
    Lista * tipo=new Lista();
    int celular;
    string nombre;
    string foto_Perfil;
    string descripcion; 
    DtUltCon * ultima_conexion;
    DtFecha * fechaCreacion;
    DtHora * horaCreacion; 
    //Estado* estado;

};

#endif /* USUARIO_H */

