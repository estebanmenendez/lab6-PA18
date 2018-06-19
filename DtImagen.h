/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtImagen.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 03:33 AM
 */

#ifndef DTIMAGEN_H
#define DTIMAGEN_H


#include<iostream>

#include "DtMultimedia.h"
using namespace std;

class DtImagen :public DtMultimedia {
public:
    
    DtImagen();
    DtImagen(int , string , string , string );
    DtImagen(const DtImagen& orig);
    virtual ~DtImagen();
        
    int GetTamanio();
    string GetUrlImg();
    string GetTexto();
    string GetFormato();


    void SetFormato(string);


    void SetTamanio(int);

    

    void SetTexto(string);

    

    void SetUrlImg(string);

    
private:
    
    int Tamanio;
    string Formato;
    string Texto;
    string urlImg;
    
};

#endif /* DTIMAGEN_H */

