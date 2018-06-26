/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Visto.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 01:31 AM
 */

#ifndef VISTO_H
#define VISTO_H
#include "DtFechaHoraVisto.h"
#include"DtFecha.h"
#include"DtHora.h"
#include "ICollectible.h"

using namespace std;

class Visto : public ICollectible {
public:
    Visto();
    Visto(int);
    Visto(const Visto& orig);
    virtual ~Visto();
    bool getEstado();
    DtFecha * GetFechaV();
    DtHora * GetHoraV();
    void SetFechaV(DtFecha *);
    void SetHoraV(DtHora *);
    void SetEstado(bool);
    bool esReceptor(int);
    int getReceptor();
    DtFechaHoraVisto * getFechaHoraVisto();
    void setReceptor(int);
private:

    int Receptor;
    bool estado;
    DtFecha * fechaV;
    DtHora * horaV;
};

#endif /* VISTO_H */

