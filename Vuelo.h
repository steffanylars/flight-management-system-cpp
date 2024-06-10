//
// Created by steff on 20-Nov-23.
//

#ifndef MAINRECTANGULO_VUELO_H
#define MAINRECTANGULO_VUELO_H
#include <string>
#include "Fecha.h"
#include "Aeropuerto.h"
#include <iomanip>
using namespace std;

class Vuelo{
    public:
        //constructores
        Vuelo();
        Vuelo(string idV,string aer,string ori,string des,Fecha fech);
        //setters
        void setIdVuelo(string idV){idVuelo=idV;}
        void setAerolinea(string aer){aerolinea=aer;}
        void setOrigen(string ori){origen=ori;}
        void setDestino(string des) {destino=des;}
        void setFecha(Fecha fech){fecha=fech;}
        //getters
        string getIdVuelo(){return idVuelo;}
        string getAerolinea(){return aerolinea;}
        string getOrigen(){return origen;}
        string getDestino(){return destino;}
        Fecha getFecha(){return fecha;}
        //muestra
        void muestraVuelo();
    private:
        string idVuelo;
        string aerolinea;
        string origen;
        string destino;
        Fecha fecha;
};

Vuelo::Vuelo(){
    Fecha f(11,5,2005);

    idVuelo="0";
    aerolinea="";
    origen="";
    destino="";
    fecha=f;
}

Vuelo::Vuelo(string idV,string aer,string ori,string des,Fecha fech){

    idVuelo=idV;
    aerolinea=aer;
    origen=ori;
    destino=des;
    fecha=fech;
}

void Vuelo::muestraVuelo() {

    cout<<setw(15)<<left<<idVuelo;
    cout<<"| "<<setw(15)<<left<<aerolinea;
    cout<<"| "<<setw(20)<<left<<origen;
    cout<<"| "<<setw(20)<<left<<destino;
    cout<<"| "<<setw(10)<<left<<fecha.getDia();
    cout<<"| "<<setw(10)<<left<<fecha.getMes();
    cout<<"| "<<setw(10)<<left<<fecha.getAnio()<<endl;
}

#endif //MAINRECTANGULO_VUELO_H
