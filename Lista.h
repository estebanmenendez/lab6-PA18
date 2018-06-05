/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.h
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 01:55 AM
 */

#ifndef LISTA_H
#define LISTA_H

#include "ICollection.h"
#include "Nodo.h"
#include "ListaIterator.h"

class Lista: public ICollection {
private:
  Nodo *first;

public:
  Lista();
  ~Lista();

  void add(ICollectible *);
  void remove(ICollectible *);
  bool member(ICollectible *);
  IIterator *iterator();

  bool isEmpty();
};

#endif /* LISTA_H */

