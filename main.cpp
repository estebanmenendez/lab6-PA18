/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: esteban
 *
 * Created on 5 de junio de 2018, 01:30 AM
 */

#include <cstdlib>
#include"Fabrica.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    iContUsuario pepe;
    pepe = Fabrica::getInstance()->getContUsuario();
    Fabrica::getInstance()->getContUsuario()->listarContactos();
    return 0;
}

