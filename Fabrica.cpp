/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fabrica.cpp
 * Author: esteban
 * 
 * Created on 5 de junio de 2018, 01:40 AM
 */

#include "Fabrica.h"
#include "Video.h"
#include "Contacto.h"

Fabrica* Fabrica::fabrica = NULL;

Fabrica::Fabrica() {
}

Fabrica::~Fabrica() {
}

Fabrica* Fabrica::getInstance() {
    if (fabrica == NULL) {
        fabrica = new Fabrica();
    }
    return fabrica;
}

iContUsuario* Fabrica::getContUsuario() {
    if (cUsu == NULL)
        this->cUsu = new ContUsuario();
    return this->cUsu;
}

iContMensaje* Fabrica::getContMensaje() {
    if (this->cMens == NULL)
        this->cMens = new ContMensaje();
    return this->cMens;
}

iContGrupo* Fabrica::getContGrupo() {
    if (cGru == NULL)
        this->cGru = new ContGrupo();
    return this->cGru;
}

iContFecha* Fabrica::getContFecha(){
    if(this->cFec == NULL)
        this->cFec = new ContFecha();
    return this->cFec;
}
void Fabrica::cargarDatosPrueba(){

    cargarUsu();
    cargarContactos();
    cargaGrupo();
    cargarConversaciones();
    cargarConversaciones();
    cargarMensajes();

}
void Fabrica::cargarUsu(){
        
        iContUsuario * usuLog = Fabrica::getContUsuario();
        string nombre, imagenPerfil, descripcion;
        int numCel;
        
        //USU1
        numCel = 90123654;
        nombre = "Juan Perez";
        imagenPerfil = "home/img/perfil/juan.png";
        descripcion = "Cómo andan?";
        usuLog->altaPrecargaUsuario(numCel,nombre,imagenPerfil,descripcion);
        
        //USU2
        numCel = 90765432;
        nombre = "María Fernández";
        imagenPerfil = "home/img/perfil/maria.png";
        descripcion = "Disponible";
        usuLog->altaPrecargaUsuario(numCel,nombre,imagenPerfil,descripcion);
        
        //USU3
        numCel = 90246810;
        nombre = "Pablo Iglesias";
        imagenPerfil = "home/img/perfil/pablo.png";
        descripcion = "En el Gym";
        usuLog->altaPrecargaUsuario(numCel,nombre,imagenPerfil,descripcion);
        
        //USU4
        numCel = 90666777;
        nombre = "Sara Ruiz";
        imagenPerfil = "home/img/perfil/sara.png";
        descripcion = "Estoy usando TeleTIP";
        usuLog->altaPrecargaUsuario(numCel,nombre,imagenPerfil,descripcion);
    }
    
void Fabrica::cargarContactos(){
        iContUsuario * usuLog = Fabrica::getContUsuario();
        
        //TANDA DE CONTACTOS 1
        usuLog->altaPrecargaContacto(90123654);
        //TANDA DE CONTACTOS 2
        usuLog->altaPrecargaContacto(90765432);
        //TANDA DE CONTACTOS 3
        usuLog->altaPrecargaContacto(90246810);
        //TANDA DE CONTACTOS 4
        usuLog->altaPrecargaContacto(90666777);
    }
    
void Fabrica::cargaGrupo(){
    iContUsuario* ContUsu=Fabrica::getContUsuario();
    iContGrupo* ContGru=Fabrica::getContGrupo();
        ContUsu->usuarioLogueado(90123654);
        ContUsu->asignarSesion();
        Lista * ContP=new Lista();
        ContP=ContUsu->getUsu()->GetContactos();
        IIterator *it=ContP->iterator();
        while(it->hasNext()){
        ContGru->agregarParticipante(dynamic_cast<DtContacto*>(it->getCurrent()));
        it->next();
        }
        //22/05/2017 15:35
        ContGru->altaGrupo("home/img/amigos.png", "Amigos");
        DtFecha* fecha=new DtFecha(22,5,2017);
        DtHora* hora=new DtHora(15,35,0);
        ContUsu->setFechaHoraG(fecha,hora);
        
                    
    }
  
void Fabrica::cargarConversaciones(){
        iContUsuario * ContUsu = Fabrica::getContUsuario();
        ContUsu->altaPrecargaConversacion();
    }
    
void Fabrica::cargarMensajes(){

 //U1 90123654;
    //U2 90765432
    //U3 90246810
    //U4 90666777
    //conv1 id=1
    //conv2 id=2
    
     /////////////////Mensaje1//////////////////////
        DtHora *hora;
        DtFecha *fecha;
        Visto *v;
        Mensaje* men1 = new Simple();
        v=new Visto(90123654);
        v->SetEstado(true);
        men1->SetVisto(v);
        v=new Visto(90765432);
        men1->SetVisto(v);
        v=new Visto(90246810);
        v->SetEstado(true);
        men1->SetVisto(v);
        dynamic_cast<Simple*> (men1)->setTexto("¡Mira que bueno este video!");
        men1->SetCodigo(1);
        men1->setEmisor(90666777);
        fecha=new DtFecha(22,5,2017);
        hora=new DtHora(18,4,0);
        men1->SetFechaEnv(fecha);
        men1->SetHoraEnv(hora);
        Usuario* u=cUsu->getUsuario(90666777);
        u->setMensaje(men1,1);
        delete u;
       
         ////////////////mensaje2//////////////////
        Mensaje* men2 = new Video();
        dynamic_cast<Video*>(men2)->SetDuracion(5);
        men2->SetCodigo(2);
        men2->setEmisor(90666777);
        v=new Visto(90123654);
        v->SetEstado(true);
        men2->SetVisto(v);
        v=new Visto(90765432);
        men2->SetVisto(v);
        v=new Visto(90246810);
        v->SetEstado(true);
        men2->SetVisto(v);
        fecha=new DtFecha(22,5,2018);
        hora=new DtHora(18,5,0);
        men2->SetFechaEnv(fecha);
        men2->SetHoraEnv(hora);
        Usuario* u2=cUsu->getUsuario(90666777);
        u2->setMensaje(men2,1);
        delete u2;

   ////////////////////mensaje3//////////////////////     
        Mensaje* men3 = new Simple();
        dynamic_cast<Simple*>(men3)->setTexto("¡Muy gracioso!");
        men3->SetCodigo(3);
        men3->setEmisor(90123654);
        v=new Visto(90666777);
        v->SetEstado(true);
        men3->SetVisto(v);
        v=new Visto(90765432);
        men3->SetVisto(v);
        v=new Visto(90246810);
        v->SetEstado(true);
        men3->SetVisto(v);
        fecha=new DtFecha(22,5,2018);
        hora=new DtHora(18,12,0);
        men3->SetFechaEnv(fecha);
        men3->SetHoraEnv(hora);
        Usuario * u3=cUsu->getUsuario(90123654);
        u3->setMensaje(men3,1);
        delete u3;
    //////////////////mensaje4////////////////7    
        Mensaje* men4 = new Simple();
        dynamic_cast<Simple*>(men4)->setTexto("¡Excelente!");
        men4->SetCodigo(4);
        men4->setEmisor(90246810);
        v=new Visto(90123654);//u1
        v->SetEstado(true);
        men4->SetVisto(v);
        v=new Visto(90765432);//u2
        men4->SetVisto(v);
        v=new Visto(90666777);//u4
        men4->SetVisto(v);      
        fecha=new DtFecha(22,5,2018);
        hora=new DtHora(18,13,0);
        men4->SetFechaEnv(fecha);
        men4->SetHoraEnv(hora);
        Usuario * u4= cUsu->getUsuario(90246810);
        u4->setMensaje(men4,1);
        delete u4;
       // cUsu->setMensaje(men4,90246810,1);
    /////////////////mensaje5////////////////////    
        Mensaje* men5 = new Simple();
        dynamic_cast<Simple*>(men5)->setTexto("Hola, me pasas el contacto de Sara que no lo tengo");
        men5->SetCodigo(5);
        men5->setEmisor(90765432);
        v=new Visto(90123654);//u1
        v->SetEstado(true);
        men5->SetVisto(v);
        fecha=new DtFecha(23,5,2018);
        hora=new DtHora(12,23,0);
        men5->SetFechaEnv(fecha);
        men5->SetHoraEnv(hora);
        Usuario * u5= cUsu->getUsuario(90765432);
        u5->setMensaje(men5,2);
        delete u5;
    ///////////////mensaje6//////////////////////    
        Mensaje* men6 = new Contacto();
        dynamic_cast<Contacto*>(men6)->SetNumCel(90666777);
        men6->SetCodigo(6);
        men6->setEmisor(90123654);
        v=new Visto(90765432);
        v->SetEstado(true);
        men6->SetVisto(v);
        fecha=new DtFecha(23,5,2018);
        hora=new DtHora(12,25,0);
        men6->SetFechaEnv(fecha);
        men6->SetHoraEnv(hora);
        Usuario * u6=cUsu->getUsuario(90123654);
        u6->setMensaje(men6,2);
        delete u6;
      //  cUsu->setMensaje(men6,90123654,2);
        
        ////////////////mensaje7////////////////////    
        Mensaje* men7 = new Simple();
        dynamic_cast<Simple*>(men7)->setTexto("Gracias!");
        men7->SetCodigo(7);
        men7->setEmisor(90765432);
        v=new Visto(90123654);
        v->SetEstado(true);
        men7->SetVisto(v);
        fecha=new DtFecha(23,5,2018);
        hora=new DtHora(12,26,0);
        men7->SetFechaEnv(fecha);
        men7->SetHoraEnv(hora);
        Usuario * u7= cUsu->getUsuario(90765432);
        u7->setMensaje(men7,2);
        delete u7;
       // cUsu->setMensaje(men7,90765432,2);
        
    //////////////mensaje8//////////////////////    
        Mensaje* men8 = new Simple();
        dynamic_cast<Simple*>(men8)->setTexto("Hola Pablo, cómo estas?");
        men8->SetCodigo(8);
        men8->setEmisor(90666777);
        v=new Visto(90246810);
        v->SetEstado(true);
        men8->SetVisto(v);
        fecha=new DtFecha(23,5,2018);
        hora=new DtHora(12,26,0);
        men8->SetFechaEnv(fecha);
        men8->SetHoraEnv(hora);
        Usuario * u8=cUsu->getUsuario(90666777);
        u8->setMensaje(men8,2);
      //  cUsu->setMensaje(men8,90666777,2);
 }

