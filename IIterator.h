/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IIterator.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 01:56 AM
 */

#ifndef IITERATOR_H
#define IITERATOR_H

#include "ICollectible.h"

class IIterator {
public:
  virtual bool hasNext() = 0;
  virtual ICollectible *next() = 0;
  virtual ICollectible *getCurrent() = 0;
  virtual void remove() = 0;
};


#endif /* IITERATOR_H */

