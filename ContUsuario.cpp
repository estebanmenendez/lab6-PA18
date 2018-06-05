/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ContUsuario.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 01:47 AM
 */

#include "ContUsuario.h"

using namespace std;


ContUsuario::ContUsuario(){}
ContUsuario::ContUsuario(const ContUsuario& orig){}
ContUsuario::~ContUsuario() {}

void ContUsuario::create(string,string,string,int,DtFecha,DtHora){}
void ContUsuario::setUltimaCon(DtUltCon){}
void ContUsuario::setUsuLog(Usuario){}
bool ContUsuario::usuarioLogueado(int){}
bool ContUsuario::ingresarCelular(int){}
bool ContUsuario::altaUsuario(string,string,string){}
bool ContUsuario::cancelaIngreso(){}
DtConexion ContUsuario::asignarSesion(){}
Lista ContUsuario::listarContactos(){}
DtContacto ContUsuario::ingContacto(int){}
void ContUsuario::agregaContacto(DtContacto){}
void ContUsuario::cerrarSesion(DtConexion){}
void ContUsuario::modificarPerfil(string, string, string){}
void ContUsuario::actualizarDatos(){}
