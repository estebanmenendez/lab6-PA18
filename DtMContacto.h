/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtMContacto.h
 * Author: juan
 *
 * Created on 12 de junio de 2018, 08:35 PM
 */

#ifndef DTMCONTACTO_H
#define DTMCONTACTO_H

#include "DtMensaje.h"

class DtMContacto : public DtMensaje{


    private:
        int numCel;
    public:
        
        DtMContacto();
        DtMContacto(int);
        DtMContacto(const DtMContacto& orig);
        virtual ~ DtMContacto();
        void setNumCel(int);
        int  getNumCel();
};
#endif /* DTMCONTACTO_H */
