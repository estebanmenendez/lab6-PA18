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

#include"DtFecha.h"
#include"DtHora.h"
#include"DtUltCon.h"
#include"ICollectible.h"
#include"Lista.h"
#include<iostream>

using namespace std;

class Usuario : public ICollectible {
public:
    Usuario();
    Usuario(const Usuario& orig);
    virtual ~Usuario();
    
    void SetCelular(int);
    void SetContactos(Lista*);
    void SetDescripcion(string);
    void SetEstadoConv(Lista*);
    void SetFechaCreacion(DtFecha);
    void SetFecha_Registro(DtFecha);   
    void SetFoto_Perfil(string);
    void SetHoraCreacion(DtHora);

int GetCelular();
string GetDescripcion();
string GetFoto_Perfil();
string GetNombre();

DtFecha GetFechaCreacion();
DtFecha GetFecha_Registro();
DtHora GetHoraCreacion();
DtUltCon GetUltima_conexion();
Lista* GetTipo();
Lista* GetEstadoConv();
Lista* GetContactos();



    void SetNombre(string);


    void SetTipo(Lista*);

    void SetUltima_conexion(DtUltCon);
    
private:
    
    Lista * contactos;
    Lista * estadoConv;
    Lista * tipo;
    
    int celular;
    string nombre;
    DtFecha fecha_Registro;
    string foto_Perfil;
    string descripcion; 
    DtUltCon ultima_conexion;
    DtFecha fechaCreacion;
    DtHora horaCreacion; 

};

#endif /* USUARIO_H */

