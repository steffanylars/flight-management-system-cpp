//
// Created by steff on 20-Nov-23.
//

#ifndef MAINRECTANGULO_AEROPUERTO_H
#define MAINRECTANGULO_AEROPUERTO_H
#include <iostream>
#include <string>
using namespace std;

class Aeropuerto{
    public:
        //constructor
        Aeropuerto();
        Aeropuerto(string nom,string sig);
        //setters
        void setNombre(string nom){nombre=nom;}
        void setSiglas(string sig){siglas=sig;}
        //getters
        string getNombre(){return nombre;}
        string getSiglas(){return siglas;}
        //muestra
        void muestraAeropuerto();

    private:
        string nombre;
        string siglas;

};

Aeropuerto::Aeropuerto() {
    nombre="";
    siglas="";
}

Aeropuerto::Aeropuerto(string nom,string sig) {
    nombre=nom;
    siglas=sig;
}

void Aeropuerto::muestraAeropuerto() {
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Siglas: "<<siglas<<endl;
}


#endif //MAINRECTANGULO_AEROPUERTO_H
