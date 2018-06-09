/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Simple.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 01:32 AM
 */

#ifndef SIMPLE_H
#define SIMPLE_H

#include"Mensaje.h"

class Simple : public Mensaje {
public:
    Simple();
    Simple(const Simple& orig);
    virtual ~Simple();
    
    string getTexto();
    void setTexto(string);
    
    
    
private:
    string texto; 

};

#endif /* SIMPLE_H */

