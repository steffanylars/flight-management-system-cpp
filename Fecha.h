//
// Created by steff on 20-Nov-23.
//

#ifndef MAINRECTANGULO_FECHA_H
#define MAINRECTANGULO_FECHA_H
#include <iostream>
using namespace std;

class Fecha{

    public:
        //constructores
        Fecha();
        Fecha(int d, int m, int a);
        //setters
        void setDia(int d) {dia=d;};
        void setMes(int m) {mes=m;};
        void setAnio(int a) {anio=a;};
        //getters
        int getDia() {return dia;};
        int getMes() {return mes;};
        int getAnio() {return anio;};
        //mostrarDatos
        void muestraFecha();
    private:
        int dia;
        int mes;
        int anio;

};

Fecha::Fecha(){
    dia=1;
    mes=1;
    anio=2023;
}
Fecha::Fecha(int d, int m, int a){
    dia=d;
    mes=m;
    anio=a;
}
void Fecha::muestraFecha(){
    cout<<"Dia: "<<dia<<endl;
    cout<<"Mes: "<<mes<<endl;
    cout<<"Anio: "<<anio<<endl;

}
#endif //MAINRECTANGULO_FECHA_H
