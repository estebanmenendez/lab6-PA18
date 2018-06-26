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

using namespace std;
bool registrarUsuario(); // Abrir teletipo
void agregarContacto(); // Agregar contacto

void altaGrupo(); // Crear grupo
void crSes(); // Cerrar sesión
void enviarMensaje(); // Enviar mensaje
void verMensajes(); // Ver mensajes
void archivarConversaciones(); // Archivar Conversación
void modUsuario(); // Modificar usuario 
void eliMensaje(); // Eliminar mensajes
void agregarPartGrupo(); // Agregar participantes al grupo
void cambiarFechaSist(); // Cambiar ficha de sistema
void consultFechaSistema(); // Consultar fecha del sistema

//cout << "1- Agregar contactos\n2- Cerrar sesión\n3- Crear Grupo\n4- Enviar Mensaje\n5- Ver mensajes\n6- Archivar Conversaciones\n7- Modificar Usuario\n8- Eliminar Mensajes\n9- Agregar participantes a un grupo\n10- Cambiar fecha del sistema\n11-Consultar fecha del sistema\n0- Salir\n";

iContUsuario* ContUsu = Fabrica::getInstance()->getContUsuario();
iContMensaje* ContMen = Fabrica::getInstance()->getContMensaje();
iContGrupo* ContGru = Fabrica::getInstance()->getContGrupo();

int main(int argc, char** argv) {
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
                cout << "1- Agregar contactos\n2- Cerrar sesión\n3- Crear Grupo\n4- Enviar Mensaje\n5- Ver mensajes\n6- Archivar Conversaciones\n7- Modificar Usuario\n8- Eliminar Mensajes\n9- Agregar participantes a un grupo\n10- Cambiar fecha del sistema\n11-Consultar fecha del sistema\n0- Salir\n";
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
                        break;
                    case 5:
                        break;
                    case 6:
                        break;
                    case 7:
                        break;
                    case 8:
                        eliMensaje();
                        break;
                    case 9:
                        break;
                    case 10:
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
    string urlI, nombreG;
    int numCel;

    DtContacto* dtc = new DtContacto();
    DtContacto* dte = new DtContacto();
    DtContacto* dtn = new DtContacto();
    DtGrupo * dtGrupo;


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

                cout << "\nIngrese celular para agregar al grupo: ";
                cin>>numCel;
                dtc = ContUsu->ingContacto(numCel);
                if (dtc == NULL) {
                    cout << "No existe un usuario con ese celular\n";
                } else {
                    if (dtc->GetNumCel() == std::to_string(ContUsu->getUsu()->GetCelular())) {
                        cout << "No puedes agregarte como contacto a vos mismo.\n";
                        removido = 's';
                    }
                    ContGru->eliminarParticipante(dtc);
                    removido = 's';
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
            }

            cout << "Desea seguir agregando contactos al Grupo ? s/n\n";
            cin>>salir;
            if (salir == 'n') {
                if (!ContGru->listarParticipantes()->isEmpty()) {
                    cout << "\nIngrese Nombre:\n";
                    getline(cin, nombreG);
                    cout << "\nIngrese URL Imagen:\n";
                    getline(cin, urlI);
                    dtGrupo = ContGru->altaGrupo(urlI, nombreG);
                    cout << "\nSe dio de alta al grupo";
                    ContGru->agregarNuevoAdmin(ContUsu->getUsu()->GetCelular());
                    salir = 'n';
                } else {
                    cout << "\nDebe ingresar por lo menos 1 contacto\n";
                    cout << "\nDesea seguir agregando contactos al Grupo ? s/n\n";
                    cin>>salir;
                }
            }

        } while (salir == 's');

    } catch (std::invalid_argument &ia) {
        cout << ia.what() << endl;
    }
}

void eliMensaje() {
    int opcion=1;
    char confirmar, salir = 'n';
    DtMensaje* dtm = new DtMensaje();
    DtConversacion * dtc = new DtConversacion();

    try {
        cout << "\nEliminar Mensaje\n\n";

        cout << "Conversaciones del usuario\n";
        do {
            Lista * ltConv = ContMen->listarConv();
            IIterator* i = ltConv->iterator();
            while (i->hasNext()) {
                dtc = dynamic_cast<DtConversacion*> (i->getCurrent());
                cout << dtc->GetIdConversa() << " - " << dtc->GetNombre() << " - " << dtc->GetCel_Cantidad() << "\n";
                i->next();
            }
            do {
                cout << "\n1 - Seleccionar una conversacion activa";
                cout << "\n2 - Ver las conversaciones archivadas";
                cin>>opcion;

                if (opcion == 1) {
                    int conv;
                    cout << "Ingrese el codigo de la conversacion que desea seleccionar: ";
                    cin>>conv;
                    ContMen->seleccionarConv(conv);
                }
                if (opcion == 2) {
                    int conv;
                    cout << "\nConversaciones archivadas: \n";
                    Lista * lisConvArch = ContMen->listarConversacionesArch();
                    cout << "\nIngrese el codigo de la conversacion que desea seleccionar: ";
                    cin>>conv;
                    ContMen->seleccionarConv(conv);
                }
            } while (opcion != 1 || opcion != 2);

        } while (salir == 's');
    } catch (std::invalid_argument &ia) {
        cout << ia.what() << endl;
    }
}


    
    void cargarUsu(){
        
        iContUsuario * usuLog = Fabrica::getInstance()->getContUsuario();
        string nombre, imagenPerfil, descripcion;
        int numCel;
        usuLog->altaPrecargaUsuario(90123654, 'Juan Pérez' , 'home/img/perfil/juan.png', 'Cómo andan?');
        usuLog->altaPrecargaUsuario(90765432, 'María Fernández ' , 'home/img/perfil/maria.png ', 'Disponible');
        usuLog->altaPrecargaUsuario(90246810, 'Pablo Iglesias' , 'home/img/perfil/pablo.png', 'En el Gym');
        usuLog->altaPrecargaUsuario(90666777, 'Sara Ruiz' , 'home/img/perfil/sara.png', 'Estoy usando TeleTIP');
    }
    
    
    void cargarContactos(){
        iContUsuario * usuLog = Fabrica::getInstance()->getContUsuario();
        
        
    }
    
    void cargarConversaciones(){
    
    }
    
    void cargarMensajes(){
        iContMensaje * mens = Fabrica::getInstance()->getContMensaje();
    }
    
    
    
    
    
    

