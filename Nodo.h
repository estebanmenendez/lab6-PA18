/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 01:52 AM
 */

#ifndef NODO_H
#define NODO_H

#include "ICollectible.h"

class Nodo {
private:
  Nodo *next;
  ICollectible *elem;

public:
  Nodo();
  Nodo(Nodo *, ICollectible *);
  virtual ~Nodo();

  virtual void setNext(Nodo *);
  virtual Nodo *getNext();
  virtual bool hasNext();

  virtual ICollectible *getICollectible();
  virtual void setICollectible(ICollectible *);

};

#endif /* NODO_H */

