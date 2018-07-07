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
#include"Lista.h"
#include "DtVideo.h"
#include "DtMContacto.h"
#include "Simple.h"

using namespace std;
bool registrarUsuario(); // Abrir teletipo
void agregarContacto(); // Agregar contacto
void impMen(ICollectible *ic);
void altaGrupo(); // Crear grupo
void crSes(); // Cerrar sesión
void enviarMensaje(); // Enviar mensaje
void verMensajes(); // Ver mensajes
void archivarConversaciones(); // Archivar Conversación
void modUsuario(); // Modificar usuario 
void eliMensaje(); // Eliminar mensajes Esteban
void agregarPartGrupo(); // Agregar participantes al grupo Ernesto
void cambiarFechaSist(); // Cambiar ficha de sistema Mauro 
void consultFechaSistema(); // Consultar fecha del sistema Mauro 
void cargaGrupo();
void impConversacion(ICollectible *);
//cout << "1- Agregar contactos\n2- Cerrar sesión\n3- Crear Grupo\n4- Enviar Mensaje\n5- Ver mensajes\n6- Archivar Conversaciones\n7- Modificar Usuario\n8- Eliminar Mensajes\n9- Agregar participantes a un grupo\n10- Cambiar fecha del sistema\n11-Consultar fecha del sistema\n0- Salir\n";



iContUsuario* ContUsu = Fabrica::getInstance()->getContUsuario();
iContMensaje* ContMen = Fabrica::getInstance()->getContMensaje();
iContGrupo* ContGru = Fabrica::getInstance()->getContGrupo();
iContFecha* ContFec = Fabrica::getInstance()->getContFecha();

int main(int argc, char** argv) {
    ContFec->setFechaHoraSistema(0, 0, 1000, 0, 0);
    char carga;
    int numCel = 0, optNoCel, optMenuPrincipal;
    bool salirTotal = false, ingresarCel = false, firstMenu = false;

    cout << "\nDesea Cargar los datos de prueba (s/n)\n";
    cin>>carga;
    if (carga == 's') {
        Fabrica::getInstance()->cargarDatosPrueba();
        crSes();
        ingresarCel = false;
        firstMenu = false;
        cout << "Datos de prueba cargados...\n";
        cout << "\nPulse ENTER para continuar...";
        cin.ignore().get();

    }
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
                if (carga != 's')
                    cout << "12-Cargar Datos de Prueba\n";
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
                        enviarMensaje();

                        break;
                    case 5:
                        verMensajes();
                        break;
                    case 6:
                        archivarConversaciones();
                        break;
                    case 7:
                        modUsuario();
                        break;
                    case 8:
                        eliMensaje();
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
                    case 12:
                        Fabrica::getInstance()->cargarDatosPrueba();
                        cout << "Datos de prueba cargados...\n";
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

void enviarMensaje() {
    Lista* ltConv = ContUsu->listarConversacion("enviarMensaje"), *convArch, *ltCont;
    IIterator *it;
    DtSimple *dts;
    DtImagen *dti;
    DtVideo *dtv;
    DtMContacto *dtmc;
    int optMen, idConv, numCelContacto, optTipo, tamanioImagen, duraVideo, celContacto, archivadas = 0;
    string texto, urlImagen, formatoImagen, descImagen, urlVideo;
    if (ltConv->isEmpty()) {
        cout << "No tene conversaciones\n";
    } else {

        it = ltConv->iterator();
        while (it->hasNext()) {
            DtConversacion* dtconv = dynamic_cast<DtConversacion*> (it->getCurrent());
            if (dtconv->GetCel_Cantidad() == 0 && dtconv->GetNombre().compare("Conversaciones Archivadas") != 0) {
                cout << "Id Conversación: " + to_string(dtconv->GetIdConversa()) + " Nombre grupo: " + dtconv->GetNombre() << endl;
            } else if (dtconv->GetNombre().compare("Conversaciones Archivadas") != 0) {
                cout << "Id Conversación: " + to_string(dtconv->GetIdConversa()) + " Celular: " + to_string(dtconv->GetCel_Cantidad()) << endl;
            } else {
                cout << dtconv->GetNombre() + " - " + to_string(dtconv->GetCel_Cantidad()) << endl;

            }
            it->next();
        }
    }

    cout << "1- Seleccionar una conversación activa\n2- Ver las conversaciones archivadas\n3- Crear nueva conversación.\n";
    cin >> optMen;
    switch (optMen) {
        case 1:
            cout << "Ingrese el ID de la conversación.\n";
            cin >> idConv;
            ContMen->selecConversacion(idConv);
            break;
        case 2:
            convArch = ContUsu->listaConversacionArc();
            if (convArch->isEmpty()) {
                cout << "No tiene conversaciones archivadas.\n";
                archivadas = 1;
            } else {
                it = convArch->iterator();
                while (it->hasNext()) {
                    DtConversacion* dtconv = dynamic_cast<DtConversacion*> (it->getCurrent());
                    if (dtconv->GetCel_Cantidad() == 0 && dtconv->GetNombre().compare("Conversaciones Archivadas") != 0) {
                        cout << to_string(dtconv->GetIdConversa()) + " " + dtconv->GetNombre() << endl;
                    } else if (dtconv->GetNombre().compare("Conversaciones Archivadas") != 0) {
                        cout << to_string(dtconv->GetIdConversa()) + " " + dtconv->GetNombre() + " " + to_string(dtconv->GetCel_Cantidad()) << endl;
                    } else {
                        cout << dtconv->GetNombre() + " " + to_string(dtconv->GetCel_Cantidad()) << endl;
                    }
                    it->next();
                }
                cout << "Ingrese el ID de la conversación.\n";
                cin >> idConv;
                ContMen->selecConversacion(idConv);
            }
            break;
        case 3:
            ltCont = ContUsu->listarContactos("enviarMensaje");
            it = ltCont->iterator();
            cout << "TUS CONTACTOS\n";
            while (it->hasNext()) {
                DtContacto *dtcont = dynamic_cast<DtContacto*> (it->getCurrent());

                cout << "Nombre: " + dtcont->GetNombre() + " Celular: " + dtcont->GetNumCel() << endl;
                it->next();
            }
            cout << "Seleccione un contacto ingresando el número de celular.\n";
            cin >> numCelContacto;
            ContUsu->elijeContacto(numCelContacto);
            //ContMen->selecConversacion(0);
            break;
        default:
            cout << "Opción incorrecta.\n";
            break;
    }
    if (archivadas != 1) {
        cout << "¿Que tipo de mensaje desea crear?\n1- Simple\n2- Imagen\n3- Video\n4-Contacto\n";
        cin>> optTipo;
        switch (optTipo) {
            case 1:
                cout << "Ingrese el texto del mensaje\n";
                cin.clear();
                cin.ignore();
                getline(cin, texto);
                dts = new DtSimple(texto);
                ContMen->cuerpoMensaje(dts);
                break;
            case 2:
                cout << "Ingrese la url de la imagen\n";
                cin.clear();
                cin.ignore();
                getline(cin, urlImagen);
                cout << "Ingrese formato de la imagen\n";
                getline(cin, formatoImagen);
                cout << "Ingrese tamaño de la imagen\n";
                cin>> tamanioImagen;
                cout << "Descripción de la imagen\n";
                getline(cin, descImagen);
                dti = new DtImagen(tamanioImagen, formatoImagen, texto, urlImagen, descImagen);
                ContMen->cuerpoMensaje(dti);
                break;
            case 3:
                cout << "Ingrese la URL del video\n";
                cin.clear();
                cin.ignore();
                getline(cin, urlVideo);
                cout << "Ingrese la duración del video\n";
                cin>> duraVideo;
                dtv = new DtVideo(urlVideo, duraVideo);
                ContMen->cuerpoMensaje(dtv);
                break;
            case 4:
                ltCont = ContUsu->listarContactos("p");
                it = ltCont->iterator();
                while (it->hasNext()) {
                    DtContacto* dtc = dynamic_cast<DtContacto*> (it->getCurrent());
                    cout << "Nombre: " + dtc->GetNombre() + " Celular: " + dtc->GetNumCel() << endl;
                    it->next();
                }
                cout << "Seleccione un usuario ingresando su número de celular\n";
                cin >> numCelContacto;
                dtmc = new DtMContacto(numCelContacto);
                ContMen->cuerpoMensaje(dtmc);
                break;
            default:
                break;
        }
        ContMen->enviarMensaje();
        cout << "\nMensaje enviado...\nPulse ENTER para continuar...";
        cin.ignore().get();

    }
}

void cambiarFechaSist() {
    int dia = 0, mes = 0, anio = 0, hora = 0, min = 0;
    cout << "---- CAMBIAR FECHA Y HORA DEL SISTEMA ---- \n";
    do {
        cout << "Ingrese el día: ";
        cin>> dia;
    } while (dia < 1 || dia > 31);
    do {
        cout << "Ingrese el mes: ";
        cin>> mes;
    } while (mes < 1 || mes > 12);
    do {
        cout << "Ingrese el anio (Mayor a 1900): ";
        cin>> anio;
    } while (anio < 1900);
    do {
        cout << "Ingrese la hora: ";
        cin>> hora;
    } while (hora < 0 || hora > 23);
    do {
        cout << "Ingrese los minutos: ";
        cin>> min;
    } while (min < 0 || min > 59);
    ContFec->setFechaHoraSistema(dia, mes, anio, min, hora);
}

void consultFechaSistema() {
    cout << Fabrica::getInstance()->getContFecha()->getFechaHoraSistema();
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
        Lista* ltCont = ContUsu->listarContactos("p");
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

//void impMen(ICollectible *ic) {
//    if (dynamic_cast<DtSimple*> (ic)) {
//        DtSimple* DtS = dynamic_cast<DtSimple*> (ic);
//        cout << to_string(DtS->GetCodigo()) << " |" << to_string(DtS->GetFechaEnv()->GetDia()) << "/" << to_string(DtS->GetFechaEnv()->GetMes()) << "/" << to_string(DtS->GetFechaEnv()->GetAnio()) << " |" << to_string(DtS->GetHoraEnv()->GetHora()) << ":" << to_string(DtS->GetHoraEnv()->GetMinutos()) << ":" << to_string(DtS->GetHoraEnv()->GetSegundo()) << " |" << DtS->GetTexto() << endl;
//    }
//    if (dynamic_cast<DtMContacto*> (ic)) {
//        DtMContacto* DtMC = dynamic_cast<DtMContacto*> (ic);
//        cout << to_string(DtMC->GetCodigo()) << " |" << to_string(DtMC->GetFechaEnv()->GetDia()) << "/" << to_string(DtMC->GetFechaEnv()->GetMes()) << "/" << to_string(DtMC->GetFechaEnv()->GetAnio()) << " |" << to_string(DtMC->GetHoraEnv()->GetHora()) << ":" << to_string(DtMC->GetHoraEnv()->GetMinutos()) << ":" << to_string(DtMC->GetHoraEnv()->GetSegundo()) << " | INFO CONTACTO\nCelular:  " << to_string(DtMC->getNumCel()) << "\nNombre: " + DtMC->getNombre() << "\nURL Imagen: " + DtMC->getUrl() << "\nDescripción: " + DtMC->getDesc() << endl;
//    }
//    if (dynamic_cast<DtImagen*> (ic)) {
//        DtImagen* DtI = dynamic_cast<DtImagen*> (ic);
//        cout << to_string(DtI->GetCodigo()) << " |" << to_string(DtI->GetFechaEnv()->GetDia()) << "/" << to_string(DtI->GetFechaEnv()->GetMes()) << "/" << to_string(DtI->GetFechaEnv()->GetAnio()) << " |" << to_string(DtI->GetHoraEnv()->GetHora()) << ":" << to_string(DtI->GetHoraEnv()->GetMinutos()) << ":" << to_string(DtI->GetHoraEnv()->GetSegundo()) << " | INFO IMAGEN\nTamanio: " << to_string(DtI->GetTamanio()) << "\nFormato: " + DtI->GetFormato() << " |" << "\nURL: " + DtI->GetUrlImg() << endl;
//    }
//
//
//    if (dynamic_cast<DtVideo*> (ic)) {
//        DtVideo* DtV = dynamic_cast<DtVideo*> (ic);
//        cout << to_string(DtV->GetCodigo()) << " |" << to_string(DtV->GetFechaEnv()->GetDia()) << "/" << to_string(DtV->GetFechaEnv()->GetMes()) << "/" << to_string(DtV->GetFechaEnv()->GetAnio()) << " |" << to_string(DtV->GetHoraEnv()->GetHora()) << ":" << to_string(DtV->GetHoraEnv()->GetMinutos()) << ":" << to_string(DtV->GetHoraEnv()->GetSegundo()) << " | INFO VIDEO\nDuración: " << to_string(DtV->GetDuracion()) << " |\nURL: " << DtV->GetUrl() << endl;
//    }
//}

void verMensajes() {
    int opcion, opCoso, idConv, idMen, opcoso2, opcoso3;
    Lista* listCon = new Lista();
    Lista * lisConvArch = new Lista();
    Lista * listarMen = new Lista();
    Lista * infoVistos = new Lista();
    listCon = ContUsu->listarConversacion("p");
    DtMensajeVisto* dtmv;
    IIterator* it;
    
    try {
        it = listCon->iterator();
        cout << "|Nombre:Contacto/Grupo| " << "\t|Id-Conversacion| " << "\t|Celular/Cantidad|" << endl;
        while (it->hasNext()) {
            DtConversacion* dt = dynamic_cast<DtConversacion*> (it->getCurrent());
            if (dt->GetNombre().compare("Conversaciones Archivadas") != 0)
                cout << dt->GetNombre() << "\t|" << std::to_string(dt->GetIdConversa()) << "\t|" << to_string(dt->GetCel_Cantidad()) << endl;
            else
                cout << dt->GetNombre() << "\t|" << to_string(dt->GetCel_Cantidad()) << endl;
            it->next();
        }
        do {
            cout << "1-Seleccionar conversacion\n2-Listar conversaciones archivadas\n0-Salir\n";
            cin>>opCoso;
            switch (opCoso) {
                case 1:
                    cout << "Ingrese el id de la conversacion: " << endl;
                    cin>>idConv;
                    listarMen = ContUsu->seleccionarConversacion(idConv);
                    if (listarMen == NULL) {
                        cout << "\nConversacion no existe\n";
                        cout << "\nPulse ENTER para continuar...";
                        cin.ignore().get();
                    } else {
                        it = listarMen->iterator();
                        cout << "|Codigo| " << "\t|Fecha| " << "\t|Hora| " << "\t|Simple/Contacto/Imagen/Video| " << endl;
                        while (it->hasNext()) {
                            impMen(it->getCurrent());
                            it->next();
                        }
                        cout << "1-Informacion adicional" << endl;
                        cout << "0-Salir" << endl;
                        cin>>opcoso2;
                        if (opcoso2 == 1) {
                            cout << "Ingrese el Id del Mensaje: " << endl;
                            cin>>idMen;
                            //infoVistos = ContUsu->listarInfoVisto(idConv, idMen);
                            infoVistos = ContMen->informacionAdicional(idConv, idMen);
                            it = infoVistos->iterator();
                            while (it->hasNext()) {
                                dtmv = dynamic_cast<DtMensajeVisto*> (it->getCurrent());
                                cout << "| Celular|" << "| Nombre|" << "| Estado| " << "| Fecha/Hora| \n";
                                cout << "| " << to_string(dtmv->GetCelular()) << "| " << dtmv->GetNombre() << "| " << dtmv->getVisto() << "| " << to_string(dtmv->GetFechaHoraVisto()->GetFecha()->GetDia()) << "/" << to_string(dtmv->GetFechaHoraVisto()->GetFecha()->GetMes()) << "/" << to_string(dtmv->GetFechaHoraVisto()->GetFecha()->GetAnio()) << "|" << to_string(dtmv->GetFechaHoraVisto()->GetHora()->GetHora()) << ":" << to_string(dtmv->GetFechaHoraVisto()->GetHora()->GetMinutos()) << ":" << to_string(dtmv->GetFechaHoraVisto()->GetHora()->GetSegundo()) << "| " << endl;
                                it->next();
                            }
                        }
                    }
                    break;
                case 2:
                    lisConvArch = ContUsu->listaConversacionArc();
                    it = lisConvArch->iterator();
                    cout << "|Nombre:Contacto/Grupo|" << " " << "|Id-Conversacion|" << " " << "|Celular/Cantidad|" << endl;
                    while (it->hasNext()) {
                        DtConversacion* dt = dynamic_cast<DtConversacion*> (it->getCurrent());
                        cout << dt->GetNombre() << " |" << to_string(dt->GetIdConversa()) << " |" << to_string(dt->GetCel_Cantidad()) << endl;
                        it->next();
                    }
                    do {
                        cout << "1-Seleccionar Conversacion" << endl;
                        cout << "0-Salir" << endl;
                        cin>>opcoso2;
                        if (opcoso2 == 1)
                            cout << "Ingrese el Id del Mensaje: " << endl;
                        cin>>idMen;
                        infoVistos = ContUsu->listarInfoVisto(idConv, idMen);
                        it = infoVistos->iterator();
                        while (it->hasNext()) {
                            DtMensajeVisto* dtmv = dynamic_cast<DtMensajeVisto*> (it->getCurrent());
                            cout << "| Celular|" << "| Nombre|" << "| Estado| " << "| Fecha/Hora| ";
                            cout << "| " << to_string(dtmv->GetCelular()) << "| " << dtmv->GetNombre() << "| " << dtmv->getVisto() << "| " << to_string(dtmv->GetFechaHoraVisto()->GetFecha()->GetDia()) << "/" << to_string(dtmv->GetFechaHoraVisto()->GetFecha()->GetMes()) << "/" << to_string(dtmv->GetFechaHoraVisto()->GetFecha()->GetAnio()) << "|" << to_string(dtmv->GetFechaHoraVisto()->GetHora()->GetHora()) << ":" << to_string(dtmv->GetFechaHoraVisto()->GetHora()->GetMinutos()) << ":" << to_string(dtmv->GetFechaHoraVisto()->GetHora()->GetSegundo()) << "| " << endl;
                            it->next();
                        }
                    } while (opcoso2 == 0);
                    break;

                default:
                    break;
            }
        } while (opcion != 0);
    } catch (std::invalid_argument &ia) {
        cout << ia.what() << endl;
    }
}

void altaGrupo() {
    char salir = 'n', confirmar, removido = 'n';
    string urlI = "", nombreG = "";
    int numCel;
    ContGru->vaciaListaParticipantes();
    DtContacto* dtc = new DtContacto();
    DtContacto* dte = new DtContacto();
    //DtContacto* dtn = new DtContacto();
    DtGrupo * dtGrupo;

    cin.ignore();
    try {
        cout << "\nCreación de Grupo\n";
        do {
            Lista* ltCont = ContGru->listarContactos();
            removido = 'n';
            if (ltCont->isEmpty()) {
                cout << "No tiene contactos\n";
                salir = 'n';
            } else {
                cout << "\nContactos Seleccionados:\n";
                Lista* ltElegido = ContGru->listarParticipantes();
                IIterator* j = ltElegido->iterator();
                while (j->hasNext()) {
                    dte = dynamic_cast<DtContacto*> (j->getCurrent());
                    cout << dte->GetNumCel() << " - " << dte->GetNombre() << " - " << dte->getUrlImagen() << "\n";
                    j->next();
                }
                cout << "\nContactos existentes:\n";

                IIterator* i = ltCont->iterator();
                while (i->hasNext()) {
                    dtc = dynamic_cast<DtContacto*> (i->getCurrent());
                    cout << dtc->GetNumCel() << " - " << dtc->GetNombre() << " - " << dtc->getUrlImagen() << "\n";
                    i->next();
                }

                cout << "\nIngrese celular para agregar al grupo:\n";
                cin>>numCel;
                dtc = ContUsu->ingContacto(numCel);
                if (dtc == NULL) {
                    cout << "No existe un contacto con ese celular\n";
                } else {
                    if (dtc->GetNumCel() == std::to_string(ContUsu->getUsu()->GetCelular())) {
                        cout << "No puedes agregarte como contacto tu mismo.\n";
                        removido = 's';
                    }
                    if (ContGru->estaElegido(dtc->GetNumCel())) {
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
                        cout << "Contacto: " << dtc->GetNombre() << " fue agrergado en el grupo\n";
                    }
                } else {
                    removido = 'n';
                }
                //            

                cout << "Desea seguir agregando contactos al Grupo? s/n\n";
                cin>>salir;
                if (salir == 'n') {
                    if (!ContGru->listarParticipantes()->isEmpty()) {
                        cin.ignore();
                        cout << "\nIngrese nombre del Grupo: ";

                        getline(cin, nombreG);

                        cout << "\nIngrese URL Imagen: ";
                        getline(cin, urlI);
                        dtGrupo = ContGru->altaGrupo(urlI, nombreG);
                        cout << "\nSe dio de alta el Grupo: \'" << dtGrupo->GetNombre() << "\'\n";
                        cout << "\nPulse ENTER para continuar...";
                        cin.ignore().get();
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

void agregarPartGrupo() {
    char salir = 'n', confirmar, removido = 'n';
    string urlI = "", nombreG = "";
    ContGru->vaciaListaParticipantes();
    DtContactoGrupo* dtcg = new DtContactoGrupo();
    DtContacto* dtc = new DtContacto();
    int numCel;
    DtGrupo* dtg = new DtGrupo("");

    try {

        Lista* ltGru = ContGru->listarGrupos();
        removido = 'n';
        if (ltGru->isEmpty()) {
            cout << "No tiene Grupos\n";
            salir = 'n';
            cin.ignore().get();
        } else {

            cout << "\nGrupos Del Usuario:\n";
            IIterator* j = ltGru->iterator();
            while (j->hasNext()) {
                dtg = dynamic_cast<DtGrupo*> (j->getCurrent());
                cout << dtg->GetNombre() << "\n";
                j->next();
            }
            cout << "\nIngrese Nombre del Grupo: ";
            cin.ignore();
            getline(cin, nombreG);
            do {
                cout << "\nContactos del Grupo: " << nombreG << "\n";
                Lista* ltContGru = ContGru->seleccionarGrupo(nombreG);
                IIterator* h = ltContGru->iterator();
                while (h->hasNext()) {
                    dtcg = dynamic_cast<DtContactoGrupo*> (h->getCurrent());
                    string fechaLin = std::to_string(dtcg->getFecha()->GetDia()) + "/" + std::to_string(dtcg->getFecha()->GetMes()) + "/" + std::to_string(dtcg->getFecha()->GetAnio()) + " " + std::to_string(dtcg->getHora()->GetHora()) + ":" + std::to_string(dtcg->getHora()->GetMinutos()) + ":" + std::to_string(dtcg->getHora()->GetSegundo());
                    cout << std::to_string(dtcg->getCelular()) << "\t - " << dtcg->getnombre() << "\t - " << dtcg->getipoEnGrupo() << "\t - " << fechaLin << "\n";
                    h->next();
                }
                Lista* ltCont = ContGru->listarContactos();
                cout << "\nContactos existentes:\n";

                IIterator* i = ltCont->iterator();
                while (i->hasNext()) {
                    dtc = dynamic_cast<DtContacto*> (i->getCurrent());
                    cout << dtc->GetNumCel() << " -" << dtc->GetNombre() << " -" << dtc->getUrlImagen() << "\n";
                    i->next();
                }

                cout << "\nIngrese celular para agregar al Grupo:\n";
                cin>>numCel;
                dtc = ContUsu->ingContacto(numCel);
                if (dtc == NULL) {
                    cout << "No existe un contacto con ese celular\n";
                    removido = 's';

                } else {
                    if (dtc->GetNumCel() == std::to_string(ContUsu->getUsu()->GetCelular())) {
                        cout << "No puedes agregarte como contacto tu mismo.\n";
                        removido = 's';
                    }
                    if (ContGru->estaElegido(dtc->GetNumCel())) {
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
                        cout << "\nContacto: " << dtc->GetNombre() << "Ingresado al grupo\n";
                    }
                } else {
                    removido = 'n';
                }
                cout << "Desea seguir agregando contactos al Grupo? s/n\n";
                cin>>salir;
                if (salir == 'n') {
                    if (!ContGru->listarParticipantes()->isEmpty()) {
                        ContGru->agregarParticipanteGrupo();
                        salir = 'n';
                    } else {
                        cout << "\nDebe ingresar por lo menos 1 contacto!!\n";
                        cout << "\nDesea seguir agregando contactos al Grupo? s/n\n";
                        cin>>salir;
                    }
                }
            } while (salir == 's');
        }
    } catch (std::invalid_argument &ia) {
        cout << ia.what() << endl;
    }


}

void eliMensaje() {
    int opcion = 1, mensa, idconv, opsubMen1, opsubMen2, opsubMen3;
    char confirmar, salir = 'n';
    Lista * listConversaciones;
    Lista * listMensajes;
    listConversaciones = ContUsu->listaConversacion();
    try {
        cout << "\nEliminar Mensaje" << endl;

        IIterator * it = listConversaciones->iterator();
        while (it->hasNext()) {
            impConversacion(it->getCurrent());
            it->next();
        }
        cout << endl;

        do {
            cout << "1-Listar mensajes conversacion" << endl;
            cout << "2-Ver conversaciones archivadas" << endl;
            cout << "0-Salir" << endl;
            cin>>opcion;
            switch (opcion) {

                case 1:
                {
                    cout << "Ingrese el Id de la conversacion: " << endl;
                    cin>>idconv;
                    listMensajes = ContUsu->seleccionarConversacion(idconv);
                    IIterator * itM1 = listMensajes->iterator();
                    while (itM1->hasNext()) {
                        impMen(itM1->getCurrent());
                        itM1->next();
                    }
                    cout << endl;
                    do {
                        cout << "1-Eliminar mensaje" << endl;
                        cin>>opsubMen1;
                        switch (opsubMen1) {
                            case 1:
                                cout << "Ingrese el Id del mensaje: " << endl;
                                cin>>mensa;
                                if (ContUsu->eliminarMensaje(mensa, idconv) == true) {
                                    cout << "Mensaje: " << to_string(mensa) << " eliminado!" << endl;
                                }
                                break;
                        }
                    } while (opsubMen1 != 0);

                    break;
                }
                case 2:

                    listConversaciones = ContUsu->listaConversacionArc();
                    IIterator * it = listConversaciones->iterator();
                    while (it->hasNext()) {
                        impConversacion(it->getCurrent());
                        it->next();
                    }

                    do {
                        cout << endl;
                        cout << "1-Listar mensajes conversacion" << endl;
                        cin>>opsubMen2;
                        cout << endl;
                        switch (opsubMen2) {
                            case 1:
                                cout << "Ingrese el Id de la conversacion: " << endl;
                                cin>>idconv;
                                listMensajes = ContUsu->seleccionarConversacion(idconv);
                                IIterator * itM2 = listMensajes->iterator();
                                while (itM2->hasNext()) {
                                    impMen(itM2->getCurrent());
                                    itM2->next();
                                }
                                cout << endl;
                                do {
                                    cout << "1-Eliminar mensaje" << endl;
                                    cin>>opsubMen3;
                                    switch (opsubMen3) {
                                        case 1:
                                            cout << "Ingrese el Id del mensaje: " << endl;
                                            cin>>mensa;
                                            if (ContUsu->eliminarMensaje(mensa, idconv) == true) {
                                                cout << "Mensaje: " << to_string(mensa) << " eliminado!" << endl;
                                            }
                                            break;
                                    }
                                } while (opsubMen3 != 0);
                                break;
                        }
                    } while (opsubMen2 != 0);

                    break;
            }

        } while (opcion != 0);

    } catch (std::invalid_argument &ia) {
        cout << ia.what() << endl;
    }
}

void modUsuario() {
    Usuario * usuLog = ContUsu->getUsu();
    string nombre = "", urlImagen = "", descrip = "";
    char guarda;
    try {
        cin.ignore();
        cout << "El Usuario logeado es: \nNombre: " << usuLog->GetNombre() << "\nURL Imagen: " << usuLog->GetFoto_Perfil() << "\nDescripcion: " << usuLog->GetDescripcion() << "\n";
        cout << "Ingrese Nombre: ";
        getline(cin, nombre);
        cout << "Ingrese URL Imagen: ";
        getline(cin, urlImagen);
        cout << "Ingrese Descripción: ";
        getline(cin, descrip);
        cout << "\nGuarda los cambios (s/n): ";
        cin>>guarda;

        if (guarda == 's') {

            usuLog->SetNombre(nombre);
            usuLog->SetFoto_Perfil(urlImagen);
            usuLog->SetDescripcion(descrip);
            cout << "El Usuario logeado Se Modificó : \nNombre: " << usuLog->GetNombre() << "\nURL Imagen: " << usuLog->GetFoto_Perfil() << "\nDescripcion: " << usuLog->GetDescripcion() << "\n";
            cout << "\nPulse una ENTER para continuar...";
            cin.ignore().get();
        }

    } catch (std::invalid_argument &ia) {
        cout << ia.what() << endl;
    }
}

void archivarConversaciones() {
    char confirmar, salir = 'n';
    int conversa;
    try {
        do {
            Lista* listCon = ContUsu->listarConversacion();
            IIterator* it;
            it = listCon->iterator();
            cout << "|Nombre:Contacto/Grupo| " << "|Id-Conversacion| " << "|Celular/Cantidad|" << endl;
            while (it->hasNext()) {
                DtConversacion* dt = dynamic_cast<DtConversacion*> (it->getCurrent());
                if (dt->GetNombre().compare("Conversaciones Archivadas") != 0)
                    if (dt->GetCel_Cantidad() == 0)
                        cout << dt->GetNombre() << " |" << std::to_string(dt->GetIdConversa()) << endl;
                    else
                        cout << dt->GetNombre() << " |" << std::to_string(dt->GetIdConversa()) << " |" << to_string(dt->GetCel_Cantidad()) << endl;

                it->next();
            }
            cin.ignore();
            cout << "\nIngrese el Id-Conversacion para Archivar: ";
            cin>>conversa;
            ContMen->selecConversacion(conversa);
            ContMen->archivarConv();
            cout << "\nDesea seguir Archivando Conversaciones ? s/n\n";
            cin>>salir;
        } while (salir == 's');


    } catch (std::invalid_argument &ia) {
        cout << ia.what() << endl;
    }


}

void impConversacion(ICollectible * ic) {
    cout << endl;
    DtConversacion * dtc = dynamic_cast<DtConversacion*> (ic);
    if (dtc->GetNombre().compare("Conversaciones Archivadas") == 0) {
        if (dtc->GetNombre().empty() == false)cout << dtc->GetNombre() << endl;
        if (dtc->GetCel_Cantidad() != 0)cout << "Cantidad: " << to_string(dtc->GetCel_Cantidad()) << endl;
    } else {
        if (dtc->GetCel_Cantidad() == 0) {
            cout << endl;
            cout << "Conversacion grupal" << endl;
            if (dtc->GetNombre().empty() == false)cout << "Nombre grupo: " << dtc->GetNombre() << endl;
            if (dtc->GetIdConversa())cout << "Id Conversacion: " << to_string(dtc->GetIdConversa()) << endl;
        }
        if (dtc->GetCel_Cantidad() != 0) {
            cout << endl;
            cout << "Conversacion simple" << endl;
            if (dtc->GetNombre().empty() == false)cout << "Nombre contacto: " << dtc->GetNombre() << endl;
            cout << "Numero contacto: " << dtc->GetCel_Cantidad() << endl;
            if (dtc->GetIdConversa() != 0)cout << "Id Conversacion: " << dtc->GetIdConversa() << endl;
        }
    }
}
void impMen(ICollectible *ic) {
    if (dynamic_cast<DtSimple*> (ic)) {
        DtSimple* DtS = dynamic_cast<DtSimple*> (ic);
        cout<<"Mensaje Simple!"<<endl;
        if(DtS->GetCodigo())cout << "Codigo Mensaje: "<<to_string(DtS->GetCodigo())<<endl;
        if(DtS->GetFechaEnv()->GetDia()||DtS->GetFechaEnv()->GetMes()||DtS->GetFechaEnv()->GetAnio())cout<< "Fecha envio: "<<to_string(DtS->GetFechaEnv()->GetDia()) << "/" << to_string(DtS->GetFechaEnv()->GetMes()) << "/" << to_string(DtS->GetFechaEnv()->GetAnio()) <<endl;
        if(DtS->GetHoraEnv()->GetHora()||DtS->GetHoraEnv()->GetMinutos()||DtS->GetHoraEnv()->GetSegundo())cout<<"Hora envio: "<<to_string(DtS->GetHoraEnv()->GetHora()) << ":" << to_string(DtS->GetHoraEnv()->GetMinutos()) << ":" << to_string(DtS->GetHoraEnv()->GetSegundo()) <<endl;
        if(DtS->GetTexto().empty()==false)cout<< "Texto: "<< DtS->GetTexto() << endl;
        
    }
    if (dynamic_cast<DtMContacto*> (ic)) {
        DtMContacto* DtMC = dynamic_cast<DtMContacto*> (ic);
        cout<<"Mensaje Contacto:"<<endl;
        if(DtMC->GetCodigo())cout << "Codigo Mensaje: "<<to_string(DtMC->GetCodigo())<<endl;
        if(DtMC->GetFechaEnv()->GetDia()||DtMC->GetFechaEnv()->GetMes()||DtMC->GetFechaEnv()->GetAnio())cout<< "Fecha envio: "<<to_string(DtMC->GetFechaEnv()->GetDia()) << "/" << to_string(DtMC->GetFechaEnv()->GetMes()) << "/" << to_string(DtMC->GetFechaEnv()->GetAnio()) <<endl;
        if(DtMC->GetHoraEnv()->GetHora()||DtMC->GetHoraEnv()->GetMinutos()||DtMC->GetHoraEnv()->GetSegundo())cout<<"Hora envio: "<<to_string(DtMC->GetHoraEnv()->GetHora()) << ":" << to_string(DtMC->GetHoraEnv()->GetMinutos()) << ":" << to_string(DtMC->GetHoraEnv()->GetSegundo()) <<endl;
        if(DtMC->getNumCel())cout<<"Numero de celular: "<<to_string(DtMC->getNumCel())<<endl;
        
    }


    if (dynamic_cast<DtImagen*> (ic)) {
        DtImagen* DtI = dynamic_cast<DtImagen*> (ic);
        cout<<"Mensaje Multimedia Imagen"<<endl;
        if(DtI->GetCodigo())cout << "Codigo Mensaje: "<<to_string(DtI->GetCodigo())<<endl;
        if(DtI->GetFechaEnv()->GetDia()||DtI->GetFechaEnv()->GetMes()||DtI->GetFechaEnv()->GetAnio())cout<< "Fecha envio: "<<to_string(DtI->GetFechaEnv()->GetDia()) << "/" << to_string(DtI->GetFechaEnv()->GetMes()) << "/" << to_string(DtI->GetFechaEnv()->GetAnio()) <<endl;
        if(DtI->GetHoraEnv()->GetHora()||DtI->GetHoraEnv()->GetMinutos()||DtI->GetHoraEnv()->GetSegundo())cout<<"Hora envio: "<<to_string(DtI->GetHoraEnv()->GetHora()) << ":" << to_string(DtI->GetHoraEnv()->GetMinutos()) << ":" << to_string(DtI->GetHoraEnv()->GetSegundo()) <<endl;
        if(DtI->GetUrlImg().empty()==false)cout<<"Imagen: "<<DtI->GetUrlImg()<<endl;       
        if(DtI->GetFormato().empty()==false)cout<<"Formato: "<<to_string(DtI->GetTamanio())<<endl;
        if(DtI->GetTexto().empty()==false)cout<<"Texto: "<<DtI->GetTexto()<<endl;
        }


    if (dynamic_cast<DtVideo*> (ic)) {
        DtVideo* DtV = dynamic_cast<DtVideo*> (ic);
        cout<<"Mensaje Multimedia Video"<<endl;
        if(DtV->GetCodigo())cout << "Codigo Mensaje: "<<to_string(DtV->GetCodigo())<<endl;
        if(DtV->GetFechaEnv()->GetDia()||DtV->GetFechaEnv()->GetMes()||DtV->GetFechaEnv()->GetAnio())cout<< "Fecha envio: "<<to_string(DtV->GetFechaEnv()->GetDia()) << "/" << to_string(DtV->GetFechaEnv()->GetMes()) << "/" << to_string(DtV->GetFechaEnv()->GetAnio())<<endl;
        if(DtV->GetHoraEnv()->GetHora()||DtV->GetHoraEnv()->GetMinutos()||DtV->GetHoraEnv()->GetSegundo())cout<<"Hora envio: "<<to_string(DtV->GetHoraEnv()->GetHora()) << ":" << to_string(DtV->GetHoraEnv()->GetMinutos()) << ":" << to_string(DtV->GetHoraEnv()->GetSegundo())<<endl;
        if(DtV->GetUrl().empty()==false)cout<<"Video: "<<DtV->GetUrl()<<endl;
        if(DtV->GetDuracion())cout<<"Duracion: "<<to_string(DtV->GetDuracion())<<endl;
    }
}