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
bool registrarUsuario();
/*
 * 
 */
iContUsuario* ContUsu = Fabrica::getInstance()->getContUsuario();
int main(int argc, char** argv) {
    
    int optMenu = 0, numCelular, optMenuPrincipal = 0;
    bool flagCelular = false, flagFirstSubMenu = false, flagInitMenu = false, newUser = true, flagMenuPrincipal = false, salir = false;
    /*RECORDAR QUE LO PRIMERO QUE HAY QUE HACER ES DAR LA OPCIÓN DE CARGAR LOS DATOS DE PRUEBA*/
    do{ 
        do{
            cout<<"----- Bienvenido a TELETIP ----- \n";
            do{
                cout<<"Ingrese su número de celular: \n";
                cin>>numCelular;
                if(cin.fail()){
                    cin.clear();
                    cin.ignore();
                    cout<<"Por favor ingrese un número\n";
                }
                else{
                    flagCelular = true;
                }
            }while(!flagCelular);

        }while(!flagCelular);

        if(ContUsu->ingresarCelular(numCelular)){
            ContUsu->asignarSesion();
        }
        else{
            do{
                cout<<"El número ingresado no existe. Por favor, ingrese una de las siguientes opciones:\n1- Registrarse.\n2- Ingresar un nuevo número de celular\n3- Salir\n";
                cin>>optMenu;
                if(cin.fail()){
                    cin.clear();
                    cin.ignore();
                    cout<<"Por favor ingrese un número\n";
                }
                else{
                    flagFirstSubMenu = true;
                }
            }while(!flagFirstSubMenu);
            switch(optMenu){
                case 1:
                    newUser = registrarUsuario();
                    flagInitMenu = true;
                    break;
                case 2:
                    break;
                case 3:
                    flagInitMenu = true;
                    salir = true;
                    break;
                default:
                    cout<<"Opción incorrecta. Por favor intente nuevamente.";
                    break;
            }
        }
    }while(!flagInitMenu);
    do{
        if(!salir){
            cout<<"Ha iniciado sesión en TELETIP\n";
            cout<<"Ingrese una opción\n";
            cout<<"1-\n2-\n3-\n0- Salir\n";
            cin>>optMenuPrincipal;
            switch(optMenuPrincipal){
                case 0:
                    salir = true;
                    break;
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                default: 
                    break;
            }
        }
    }while(!salir);
    return 0;
}
bool registrarUsuario(){
    string nombre, urlImagen, descripcion;
    bool flag = false;
    cout<<"Ingrese su nombre: ";
    cin>>nombre;
    cout<<"\nIngrese la URL de su imagen de perfil: ";
    cin>>urlImagen;
    cout<<"\nIngrese la descripción de la imagen: ";
    cin>>descripcion;
    if(ContUsu->altaUsuario(nombre,urlImagen,descripcion)){
        DtConexion* p = ContUsu->asignarSesion();
    }
    return true;
}
