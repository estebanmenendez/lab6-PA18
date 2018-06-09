/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Usuario.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 01:30 AM
 */

#include "Usuario.h"

Usuario::Usuario() {
}

Usuario::Usuario(const Usuario& orig) {
}

Usuario::~Usuario() {
}

    int Usuario::GetCelular() {
        return celular;
    }

    void Usuario::SetCelular(int celular) {
        this->celular = celular;
    }

    Lista* Usuario::GetContactos()  {
        return contactos;
    }

    void Usuario::SetContactos(Lista* contactos) {
        this->contactos = contactos;
    }

    string Usuario::GetDescripcion() {
        return descripcion;
    }

    void Usuario::SetDescripcion(string descripcion) {
        this->descripcion = descripcion;
    }

    Lista* Usuario::GetEstadoConv() {
        return estadoConv;
    }

    void Usuario::SetEstadoConv(Lista* estadoConv) {
        this->estadoConv = estadoConv;
    }

    DtFecha Usuario::GetFechaCreacion() {
        return fechaCreacion;
    }

    void Usuario::SetFechaCreacion(DtFecha fechaCreacion) {
        this->fechaCreacion = fechaCreacion;
    }

    DtFecha Usuario::GetFecha_Registro() {
        return fecha_Registro;
    }

    void Usuario::SetFecha_Registro(DtFecha fecha_Registro) {
        this->fecha_Registro = fecha_Registro;
    }

    string Usuario::GetFoto_Perfil() {
        return foto_Perfil;
    }

    void Usuario::SetFoto_Perfil(string foto_Perfil) {
        this->foto_Perfil = foto_Perfil;
    }

    DtHora Usuario::GetHoraCreacion() {
        return horaCreacion;
    }

    void Usuario::SetHoraCreacion(DtHora horaCreacion) {
        this->horaCreacion = horaCreacion;
    }

    string Usuario::GetNombre() {
        return nombre;
    }

    void Usuario::SetNombre(string nombre) {
        this->nombre = nombre;
    }

    Lista* Usuario::GetTipo() {
        return tipo;
    }

    void Usuario::SetTipo(Lista* tipo) {
        this->tipo = tipo;
    }

   DtUltCon Usuario::GetUltima_conexion() {
        return ultima_conexion;
    }

    void Usuario::SetUltima_conexion(DtUltCon ultima_conexion) {
        this->ultima_conexion = ultima_conexion;
    }