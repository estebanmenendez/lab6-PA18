/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mensaje.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 03:22 AM
 */

#ifndef MENSAJE_H
#define MENSAJE_H

#include"ICollectible.h"
#include"DtFecha.h"
#include"DtHora.h"
#include"DtMensaje.h"
#include"Lista.h"
#include"Visto.h"
#include"DtMensajeVisto.h"
using namespace std;

class Mensaje : public ICollectible {
public:
    Mensaje();
    Mensaje(const Mensaje& orig);
    virtual ~Mensaje();
    int GetCodigo();
    int getEmisor();
    void setEmisor(int);
    Lista * GetVistos();
    DtFecha *GetFechaEnv();
    DtHora *GetHoraEnv();
    Visto* GetVisto();

    void SetCodigo(int);
    void SetFechaEnv(DtFecha*);
    void SetHoraEnv(DtHora*);
    void SetVisto(Visto *);
    DtMensaje* getMensaje();
    bool esReceptor(int);
    bool remueveVistos();
    bool remueveMiVisto(int idCel);
private:

    Lista* visto = new Lista();
    int emisor;
    int codigo;
    DtFecha *fechaEnv;
    DtHora *horaEnv;
};

#endif /* MENSAJE_H */

