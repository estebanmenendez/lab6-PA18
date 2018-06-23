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
void agregarContacto();
/*
 * 
 */
iContUsuario* ContUsu = Fabrica::getInstance()->getContUsuario();
int main(int argc, char** argv) {
    int numCel = 0, optNoCel, optMenuPrincipal;
    bool salirTotal = false, ingresarCel = false, firstMenu = false; 
    do{
        try{
            if(!firstMenu){
                do{
                    cout<<"----- Bienvenido a TELETIP -----" << endl;
                    cout<<" Ingrese un número de celular: " << endl;
                    cin>>numCel;
                    if(ContUsu->ingresarCelular(numCel)){
                        DtConexion* con = ContUsu->asignarSesion();
                        ingresarCel = true;
                    }
                    else{
                        cout<<"1- Registrarse\n2- Seguir ingresando números\n3- Salir\n";
                        cin>>optNoCel;
                        switch(optNoCel){
                            case 1:
                                if(registrarUsuario()){
                                    ingresarCel = true;
                                }
                                break;
                            case 2:
                                break;
                            case 3:
                                ingresarCel = true;
                                salirTotal = true;
                                break;
                            default:
                                break;
                        }
                    }
                }while(!ingresarCel);
            }
            firstMenu = true;
            if(!salirTotal){
                cout<< "1- Agregar contactos\n2- Cerrar sesión\n0- Salir\n";
                cin>>optMenuPrincipal;
                switch(optMenuPrincipal){
                    case 1:
                        agregarContacto();
                        break;
                    case 2: 
                        break;
                    case 0:
                        salirTotal = true;
                        break;
                    default:
                        break;
                }
            }
        }
        catch(invalid_argument& ia){
            cout<< ia.what();
        }
    }while(!salirTotal);
    
    return 0;
}
bool registrarUsuario(){
    cin.ignore();
    string nombre, urlImagen, descripcion;
    bool flag = false;
    cout<<"Ingrese su nombre: ";
    getline(cin, nombre);
    cout<<"\nIngrese la URL de su imagen de perfil: ";
    getline(cin, urlImagen);
    cout<<"\nIngrese la descripción de la imagen: ";
    getline(cin, descripcion);
    if(ContUsu->altaUsuario(nombre,urlImagen,descripcion)){
        DtConexion* p = ContUsu->asignarSesion();
        return true;
    }
    else{
        return false;
    }
    
}

void agregarContacto(){
    Lista* ltCont = ContUsu->listarContactos();
    int numCel;
    char confirmar, salir='n';
    DtContacto* dtc = new DtContacto();
    do{
        if(ltCont->isEmpty()){
            cout<<"No tiene contactos\n";
        }
        else{
            IIterator* i = ltCont->iterator();
            while(i->hasNext()){
                dtc = dynamic_cast<DtContacto*>(i->getCurrent());
                cout<< dtc->GetNombre() << endl;
                cout<< dtc->GetNumCel() << endl;
                cout<< dtc->getUrlImagen() << endl;
            }
        }
        cout<<"Ingrese un número de celular: ";
        cin>>numCel;
        dtc = ContUsu->ingContacto(numCel);
        if(dtc != NULL){
            if(dtc->GetNumCel() == std::to_string(ContUsu->getUsuLog()->GetCelular())){
                cout<<"No puedes agregarte como contacto a vos mismo.\n";
            }
            else{
                cout<< dtc->GetNombre() << endl;
                cout<< dtc->GetNumCel() << endl;
                cout<< dtc->getUrlImagen() << endl;
                cout<< "¿Confirmar el ingreso? s/n\n";
                cin>>confirmar;
                if(confirmar == 's'){
                    ContUsu->agregaContacto(dtc);
                }
            }
        }
        else{
            cout<<"No existe un usuario con ese celular\n";
        }
        cout<<"Desea seguir agregando contactos? s/n\n";
        cin>>salir;
    }while(salir == 's');
}