/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 01:52 AM
 */

#include "Nodo.h"
#include "stdio.h"

Nodo::Nodo()
  :next(NULL), elem(NULL) {
}

Nodo::Nodo(Nodo *next, ICollectible *ICollectible)
  :next(next), elem(ICollectible) {
}

Nodo::~Nodo() {
  if (next != NULL) {
    delete next;
  }
  elem = NULL;
}


void Nodo::setNext(Nodo *next) {
  this->next = next;
}

Nodo *Nodo::getNext() {
  return next;
}

bool Nodo::hasNext() {
  return next != NULL;
}

ICollectible *Nodo::getICollectible() {
  return elem;
}

void Nodo::setICollectible(ICollectible *ICollectible) {
  this->elem = ICollectible;
}

