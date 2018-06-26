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

#include"Fabrica.h"
#include <cstdlib>
#include <iostream>
#include <limits>
#include<list>
#include <string>
#include<sstream>
#include <random>
//#include "DtContactoGrupo.h"

using namespace std;


bool registrarUsuario(); // Abrir teletipo Mauro
void agregarContacto(); // Agregar contacto Mauro

void altaGrupo(); // Crear grupo Ernesto
void crSes(); // Cerrar sesión Mauro
void enviarMensaje(); // Enviar mensaje 
void verMensajes(); // Ver mensajes JP
void archivarConversaciones(); // Archivar Conversación
void modUsuario(); // Modificar usuario 
void eliMensaje(); // Eliminar mensajes Esteban
void agregarPartGrupo(); // Agregar participantes al grupo Ernesto
void cambiarFechaSist(); // Cambiar ficha de sistema Mauro 
void consultFechaSistema(); // Consultar fecha del sistema Mauro 
//cout << "1- Agregar contactos\n2- Cerrar sesión\n3- Crear Grupo\n4- Enviar Mensaje\n5- Ver mensajes\n6- Archivar Conversaciones\n7- Modificar Usuario\n8- Eliminar Mensajes\n9- Agregar participantes a un grupo\n10- Cambiar fecha del sistema\n11-Consultar fecha del sistema\n0- Salir\n";



iContUsuario* ContUsu = Fabrica::getInstance()->getContUsuario();
iContMensaje* ContMen = Fabrica::getInstance()->getContMensaje();
iContGrupo* ContGru = Fabrica::getInstance()->getContGrupo();
iContFecha* ContFec = Fabrica::getInstance()->getContFecha();

int main(int argc, char** argv) {
    ContFec->setFechaHoraSistema(0,0,1000,0,0);
    int numCel = 0, optNoCel, optMenuPrincipal;
    bool salirTotal = false, ingresarCel = false, firstMenu = false;
    do {
        try {
            if (!firstMenu) {
                do {
                    cout << "----- Bienvenido a TELETIP -----" << endl;
                    cout << " Ingrese un número de celular: " << endl;
                    cin>>numCel;
                    if (ContUsu->ingresarCelular(numCel)) {
                        DtConexion* con = ContUsu->asignarSesion();
                        ingresarCel = true;
                    } else {
                        cout << "1- Registrarse\n2- Seguir ingresando números\n3- Salir\n";
                        cin>>optNoCel;
                        switch (optNoCel) {
                            case 1:
                                if (registrarUsuario()) {
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
                } while (!ingresarCel);
            }
            firstMenu = true;
            if (!salirTotal) {
                cout << "1- Agregar contactos\n2- Cerrar sesión\n3- Crear Grupo\n4- Enviar Mensaje\n5- Ver mensajes\n6- Archivar Conversaciones\n7- Modificar Usuario\n8- Eliminar Mensajes\n9- Agregar participantes a un grupo\n10- Cambiar fecha del sistema\n11- Consultar fecha del sistema\n0- Salir\n";
                cin>>optMenuPrincipal;
                switch (optMenuPrincipal) {
                    case 1:
                        agregarContacto();
                        break;
                    case 2:
                        crSes();
                        ingresarCel = false;
                        firstMenu = false;
                        break;
                    case 3:
                        altaGrupo();
                        break;
                    case 4:
//                        enviarMensaje();
                        break;
                    case 5:
//                        verMensajes(); 
                        break;
                    case 6:
                        archivarConversaciones();
                        break;
                    case 7:
                        modUsuario();
                        break;
                    case 8:
//                        eliMensaje();
                        break;
                    case 9:
                        agregarPartGrupo();
                        break;
                    case 10:
                        cambiarFechaSist();
                        break;
                    case 11:
                       consultFechaSistema();
                       break;
                    case 0:
                        salirTotal = true;
                        break;
                    default:
                        break;
                }
            }
        } catch (invalid_argument& ia) {
            cout << ia.what();
        }
    } while (!salirTotal);

    return 0;
}


void cambiarFechaSist() {
    int dia=0, mes=0, anio=0, hora=0, min=0;
    cout<< "---- CAMBIAR FECHA Y HORA DEL SISTEMA ---- \n";
    do{
        cout<< "Ingrese el día: ";
        cin>> dia;
    }while(dia < 1 || dia > 31);
    do{
        cout<< "Ingrese el mes: ";
        cin>> mes;
    }while(mes < 1 || mes > 12);
    do{
        cout<< "Ingrese el anio (Mayor a 1900): ";
        cin>> anio;
    }while(anio < 1900);
    do{   
        cout<< "Ingrese la hora: ";
        cin>> hora;
    }while(hora < 0 || hora > 23);
    do{
        cout<< "Ingrese los minutos: ";
        cin>> min;
    }while(min < 0 || min > 59);
    ContFec->setFechaHoraSistema(dia, mes, anio, min, hora);
}

void consultFechaSistema() {
    cout<< Fabrica::getInstance()->getContFecha()->getFechaHoraSistema();
}
void crSes() {
    ContUsu->cerrarSesion(new DtConexion());
}

bool registrarUsuario() {
    cin.ignore();
    string nombre, urlImagen, descripcion;
    bool flag = false;
    cout << "Ingrese su nombre: ";
    getline(cin, nombre);
    cout << "\nIngrese la URL de su imagen de perfil: ";
    getline(cin, urlImagen);
    cout << "\nIngrese la descripción de la imagen: ";
    getline(cin, descripcion);
    if (ContUsu->altaUsuario(nombre, urlImagen, descripcion)) {
        DtConexion* p = ContUsu->asignarSesion();
        return true;
    } else {
        return false;
    }
}

void agregarContacto() {
    char confirmar, salir = 'n';
    do {
        Lista* ltCont = ContUsu->listarContactos();
        int numCel;
        DtContacto* dtc = new DtContacto();
        bool existe = false;
        if (ltCont->isEmpty()) {
            cout << "No tiene contactos\n";
        } else {
            IIterator* i = ltCont->iterator();
            while (i->hasNext()) {
                dtc = dynamic_cast<DtContacto*> (i->getCurrent());
                cout << dtc->GetNombre() << endl;
                cout << dtc->GetNumCel() << endl;
                cout << dtc->getUrlImagen() << endl;
                i->next();
            }
        }
        cout << "Ingrese un número de celular: ";
        cin>>numCel;
        IIterator* i = ltCont->iterator();
        while (i->hasNext()) {
            DtContacto* dtc = dynamic_cast<DtContacto*> (i->getCurrent());
            if (atoi(dtc->GetNumCel().c_str()) == numCel)
                existe = true;
            i->next();
        }
        dtc = ContUsu->ingContacto(numCel);
        if (dtc != NULL) {
            if (dtc->GetNumCel() == std::to_string(ContUsu->getNumUsuLog())) {
                cout << "No puedes agregarte como contacto a vos mismo.\n";
            } else if (existe) {
                cout << "Ya tienes a este contacto agregado\n";
            } else {
                cout << dtc->GetNombre() << endl;
                cout << dtc->GetNumCel() << endl;
                cout << dtc->getUrlImagen() << endl;
                cout << "¿Confirmar el ingreso? s/n\n";
                cin>>confirmar;
                if (confirmar == 's') {
                    ContUsu->agregaContacto(dtc);
                }
            }
        } else {
            cout << "No existe un usuario con ese celular\n";
        }
        cout << "Desea seguir agregando contactos? s/n\n";
        cin>>salir;
    } while (salir == 's');
}

void altaGrupo() {
    char salir = 'n', confirmar, removido = 'n';
    string urlI= "", nombreG="";
    int numCel;
    //ContGru->vaciaListaParticipantes();
    DtContacto* dtc = new DtContacto();
    DtContacto* dte = new DtContacto();
    //DtContacto* dtn = new DtContacto();
    DtGrupo * dtGrupo;

    cin.ignore();
    try {
        cout << "\nCreación de Grupo\n\n";
        do {
            Lista* ltCont = ContGru->listarContactos();
            removido = 'n';
            if (ltCont->isEmpty()) {
                cout << "No tiene contactos\n";
                salir = 'n';
            } else {
                cout << "\nContactos Seleccionados:\n ";
                Lista* ltElegido = ContGru->listarParticipantes();
                IIterator* j = ltElegido->iterator();
                while (j->hasNext()) {
                    dte = dynamic_cast<DtContacto*> (j->getCurrent());
                    cout << dte->GetNumCel() << " -" << dte->GetNombre() << " -" << dte->getUrlImagen() << "\n";
                    j->next();
                }
                cout << "\nContactos existentes:\n ";

                IIterator* i = ltCont->iterator();
                while (i->hasNext()) {
                    dtc = dynamic_cast<DtContacto*> (i->getCurrent());
                    cout << dtc->GetNumCel() << " -" << dtc->GetNombre() << " -" << dtc->getUrlImagen() << "\n";
                    i->next();
                }
            
                cout << "\nIngrese celular para agregar al grupo:\n ";
                cin>>numCel;
                dtc = ContUsu->ingContacto(numCel);
                if (dtc == NULL) {
                    cout << "No existe un usuario con ese celular\n";
                } else {
                    if (dtc->GetNumCel() == std::to_string(ContUsu->getUsu()->GetCelular())) {
                        cout << "No puedes agregarte como contacto a vos mismo.\n";
                        removido = 's';
                    }
                    if ( ContGru->estaElegido(dtc->GetNumCel())){
                    ContGru->eliminarParticipante(dtc);
                    removido = 's';
                    }
                }
                if (removido == 'n') {
                    cout << dtc->GetNumCel() << " - " << dtc->GetNombre() << " - " << dtc->getUrlImagen() << endl;
                    cout << "¿Confirmar el ingreso al Grupo? s/n\n";
                    cin>>confirmar;
                    if (confirmar == 's') {
                        ContGru->agregarParticipante(dtc);
                        cout << "Usuario: " << dtc->GetNombre() << " ingresado al grupo\n";
                    }
                } else {
                    removido = 'n';
                }
//            
        
            cout << "Desea seguir agregando contactos al Grupo ? s/n\n";
            cin>>salir;
            if (salir == 'n') {
                if (!ContGru->listarParticipantes()->isEmpty()) {
                    cin.ignore();
                    cout << "\nIngrese Nombre: ";
                    
                    getline(cin, nombreG);
                    
                    cout << "\nIngrese URL Imagen: ";
                    getline(cin, urlI);
                    dtGrupo = ContGru->altaGrupo(urlI, nombreG);
                    cout << "\nSe dio de alta al grupo "<<dtGrupo->GetNombre()<<"\n";
                    //ContGru->agregarNuevoAdmin(ContUsu->getUsu()->GetCelular());
                    salir = 'n';
                } else {
                    cout << "\nDebe ingresar por lo menos 1 contacto\n";
                    cout << "\nDesea seguir agregando contactos al Grupo ? s/n\n";
                    cin>>salir;
                }
            }
            }

        } while (salir == 's');

    } catch (std::invalid_argument &ia) {
        cout << ia.what() << endl;
    }
}


void agregarPartGrupo(){
    char salir = 'n', confirmar, removido = 'n';
    string urlI= "", nombreG="";
    //ContGru->vaciaListaParticipantes();
    DtContactoGrupo* dtcg = new DtContactoGrupo();
    DtContacto* dtc = new DtContacto(); 
    int numCel;
    DtGrupo* dtg = new DtGrupo("");
    
    try{
        do {
        Lista* ltGru = ContGru->listarGrupos();
            removido = 'n';
            if (ltGru->isEmpty()) {
                cout << "No tiene Grupos\n";
                salir = 'n';
                cin.ignore().get();
            } else {
                
            cout << "\nGrupos Del Usuario :\n ";
                IIterator* j = ltGru->iterator();
                while (j->hasNext()) {
                    dtg = dynamic_cast<DtGrupo*> (j->getCurrent());
                    cout << dtg->GetNombre() << "\n";
                    j->next();
                }
            cout << "\nIngrese Nombre del Grupo:\n ";
            cin.ignore();     
            getline(cin, nombreG);
            
            cout << "\nUsuarios del Grupo : "<<nombreG<<"\n";
            Lista* ltContGru = ContGru->seleccionarGrupo(nombreG);
            IIterator* h = ltContGru->iterator();
                while (h->hasNext()) {
                    dtcg = dynamic_cast<DtContactoGrupo*> (h->getCurrent());  
                    string fechaLin = std::to_string(dtcg->getFecha()->GetDia())+"/"+std::to_string(dtcg->getFecha()->GetMes())+"/"+std::to_string(dtcg->getFecha()->GetAnio())+" "+std::to_string(dtcg->getHora()->GetHora())+":"+std::to_string(dtcg->getHora()->GetMinutos())+":"+std::to_string(dtcg->getHora()->GetSegundo());
                    cout << std::to_string(dtcg->getCelular())<<" - "<</*dtcg->getnombre()<<*/" - "<<dtcg->getipoEnGrupo()<<" - "<<fechaLin<< "\n";
                    h->next();
                }
            Lista* ltCont = ContGru->listarContactos();
            cout << "\nContactos existentes:\n ";

                IIterator* i = ltCont->iterator();
                while (i->hasNext()) {
                    dtc = dynamic_cast<DtContacto*> (i->getCurrent());
                    cout << dtc->GetNumCel() << " -" << dtc->GetNombre() << " -" << dtc->getUrlImagen() << "\n";
                    i->next();
                }
            
                cout << "\nIngrese celular para agregar al grupo:\n ";
                cin>>numCel;
                dtc = ContUsu->ingContacto(numCel);
                if (dtc == NULL) {
                    cout << "No existe un usuario con ese celular\n";
                } else {
                    if (dtc->GetNumCel() == std::to_string(ContUsu->getUsu()->GetCelular())) {
                        cout << "No puedes agregarte como contacto a vos mismo.\n";
                        removido = 's';
                    }
                    if ( ContGru->estaElegido(dtc->GetNumCel())){
                    ContGru->eliminarParticipante(dtc);
                    removido = 's';
                    }
                }
                if (removido == 'n') {
                    cout << dtc->GetNumCel() << " - " << dtc->GetNombre() << " - " << dtc->getUrlImagen() << endl;
                    cout << "¿Confirmar el ingreso al Grupo? s/n\n";
                    cin>>confirmar;
                    if (confirmar == 's') {
                        ContGru->agregarParticipante(dtc);
                        cout << "Usuario: " << dtc->GetNombre() << " ingresado al grupo\n";
                    }
                } else {
                    removido = 'n';
                }
                cout << "Desea seguir agregando contactos al Grupo ? s/n\n";
                cin>>salir;
            if (salir == 'n') {
                if (!ContGru->listarParticipantes()->isEmpty()) {
                    
                    salir = 'n';
                } else {
                    cout << "\nDebe ingresar por lo menos 1 contacto\n";
                    cout << "\nDesea seguir agregando contactos al Grupo ? s/n\n";
                    cin>>salir;
                }
            
            }
            }//
        } while (salir == 's');
    }catch(std::invalid_argument &ia) {
        cout << ia.what() << endl;
    } 
    
    
}

void  modUsuario(){
    Usuario * usuLog = ContUsu->getUsu();
    string nombre="", urlImagen="", descrip="";
    char guarda;
     try{
         cin.ignore();
         cout<<"El Usuario logeado es: \nNombre: "<<usuLog->GetNombre()<<"\nURL Imagen: "<<usuLog->GetFoto_Perfil()<<"\nDescripcion: "<<usuLog->GetDescripcion()<<"\n";
         cout<<"Ingrese Nombre: ";
         getline(cin,nombre);
         cout<<"Ingrese URL Imagen: ";
         getline(cin,urlImagen);
         cout<<"Ingrese Descripción: ";
         getline(cin,descrip);
         cout<<"\nGuarda los cambios (s/n): ";
         cin>>guarda;
         
         if (guarda == 's'){
             
             usuLog->SetNombre(nombre);
             usuLog->SetFoto_Perfil(urlImagen);
             usuLog->SetDescripcion(descrip);
            cout<<"El Usuario logeado Se Modificó : \nNombre: "<<usuLog->GetNombre()<<"\nURL Imagen: "<<usuLog->GetFoto_Perfil()<<"\nDescripcion: "<<usuLog->GetDescripcion()<<"\n";
            cout<<"\nPulse una ENTER para continuar...";
            cin.ignore().get();
         }
         
     }catch(std::invalid_argument &ia) {
        cout << ia.what() << endl;
    } 
}

void archivarConversaciones(){
    
}