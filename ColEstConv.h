/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ColEstConv.h
 * Author: esteban
 *
 * Created on 8 de junio de 2018, 12:07 AM
 */

#ifndef COLESTCONV_H
#define COLESTCONV_H

#include"ICollectible.h"

class ColEstConv : public ICollectible {
    
public:
    
    ColEstConv();
    ColEstConv(const ColEstConv& orig);
    virtual ~ColEstConv();
    
private:

};

#endif /* COLESTCONV_H */

