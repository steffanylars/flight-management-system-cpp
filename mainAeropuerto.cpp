//
// Created by steff on 20-Nov-23.
//
#include "Aeropuerto.h"
#include "Vuelo.h"
#include "Fecha.h"
#include <iostream>
#include <cctype>//para utilizar toupper que convierte char a mayuscula y lo uso para el menu, asi el usuario puede poner mayuscula y minuscula
#include <fstream>//para leer los archivos que cargan datos
#include <iomanip>//para que mis tablas se vean esteticas, uso setw que les brinda un tamano de ancho
using namespace std;

void cargarAeropuertos(Aeropuerto aeropuerto[], int &cantAeropuertos){
    //esta funcion abre el archivo de aeropuertos y los carga a la lista
    //que contiene objetos de tipo aeropuerto.
    ifstream archivo;
    string siglas, nombreAeropuerto;
    archivo.open("archAeropuertos.txt");

    cantAeropuertos=0;
    while(archivo>>siglas>>nombreAeropuerto){
        aeropuerto[cantAeropuertos].setSiglas(siglas);
        aeropuerto[cantAeropuertos].setNombre(nombreAeropuerto);
        cantAeropuertos++;
    }
    archivo.close();
}

void mostrarAeropuertos(Aeropuerto aeropuerto[],int cantAeropuertos){
    //Esta funcion muestra los atributos de cada objeto, es decir
    //de cada elemento de la lista de aeropuertos

    cout<<setw(10)<<left<<"Siglas";
    cout<<setw(80)<<left<<"| Nombre aeropuerto"<<endl;

    for(int i=0;i<cantAeropuertos;i++){
        cout<<setw(10)<<left<<aeropuerto[i].getSiglas();
        cout<<"| "<<setw(80)<<left<<aeropuerto[i].getNombre()<<endl;
    }
}

void cargarVuelos(Vuelo vuelo[],int &cantVuelos){
    //la funcion abre el archivo de vuelos e inserta cada fila como un objeto
    //en el arreglo de vuelo
    string numVuelo,aerolinea,aeropuertoOrigen,aeropuertoDestino;
    int dia,mes,anio;
    ifstream archivo;
    Fecha fechaVuelo;

    archivo.open("archVuelos.txt");
    cantVuelos=0;
    while(archivo>>numVuelo>>aerolinea>>aeropuertoOrigen>>aeropuertoDestino>>dia>>mes>>anio){

        fechaVuelo.setDia(dia);
        fechaVuelo.setMes(mes);
        fechaVuelo.setAnio(anio);

        vuelo[cantVuelos].setIdVuelo(numVuelo);
        vuelo[cantVuelos].setAerolinea(aerolinea);
        vuelo[cantVuelos].setOrigen(aeropuertoOrigen);
        vuelo[cantVuelos].setDestino(aeropuertoDestino);
        vuelo[cantVuelos].setFecha(fechaVuelo);

        cantVuelos+=1;

    }
    archivo.close();
}

string nombreAeropuerto(Aeropuerto aeropuerto[],int cantAeropuertos,string siglas){
    //esta funcion retorna el nombre y siglas de un aeropuerto cuando se le brindan las siglas
    for(int i=0;i<cantAeropuertos;i++){
        if(aeropuerto[i].getSiglas()==siglas){
            return aeropuerto[i].getNombre()+" ("+aeropuerto[i].getSiglas()+")";
        }
    }
    return "";
}

void encabezadoMostrarVuelos(){
    //funcion que muestra los encabezados de los vuelos para
    //las funciones que muestran vuelos
    cout<<endl;
    cout<<setw(15)<<left<<"Num. Vuelo";
    cout<<"| "<<setw(15)<<left<<"Aerolinea";
    cout<<"| "<<setw(20)<<left<<"Origen";
    cout<<"| "<<setw(20)<<left<<"Destino";
    cout<<"| "<<setw(10)<<left<<"Dia";
    cout<<"| "<<setw(10)<<left<<"Mes";
    cout<<"| "<<setw(10)<<left<<"Ano"<<endl;
};

void mostrarVuelos(Vuelo vuelo[],int cantVuelos,Aeropuerto aeropuerto[],int cantAeropuertos){
    //esta funcion muestra todos los vuelos y sus atributos, adicional a eso, muestra el nombre de los aeropuertos y no
    //solo las siglas como en las demas funciones de mostrar vuelos
    encabezadoMostrarVuelos();
    for(int i=0;i<cantVuelos;i++){
        cout<<setw(15)<<left<<vuelo[i].getIdVuelo();
        cout<<"| "<<setw(15)<<left<<vuelo[i].getAerolinea();
        cout<<"| "<<setw(20)<<left<<nombreAeropuerto(aeropuerto,cantAeropuertos,vuelo[i].getOrigen());
        cout<<"| "<<setw(20)<<left<<nombreAeropuerto(aeropuerto,cantAeropuertos,vuelo[i].getDestino());;
        cout<<"| "<<setw(10)<<left<<vuelo[i].getFecha().getDia();
        cout<<"| "<<setw(10)<<left<<vuelo[i].getFecha().getMes();
        cout<<"| "<<setw(10)<<left<<vuelo[i].getFecha().getAnio()<<endl;
    }
}

void mostrarVuelosAeropuerto(Vuelo vuelo[],int cantVuelos,string siglas){
    //esta funcion muestra los vuelos que salen de determinado aeropuerto, recorre toda la lista
    //busca los que cumplan dicha condicion y los muestra con la funcion muestraVuelo() de la clase Vuelo
    int contador=0;
    encabezadoMostrarVuelos();
    for(int i=0;i<cantVuelos;i++){
        if(vuelo[i].getOrigen()==siglas){
            vuelo[i].muestraVuelo();
            contador++;
        }
    }
    if(contador==0){
        cout<<"No hay vuelos con esas caracteristicas."<<endl;
    }
}

void mostrarVuelosAeropuerto2(Vuelo vuelo[],int cantVuelos,string siglas){
    //esta funcion muestra los vuelos que aterrizan a determinado aeropuerto, recorre toda la lista
    //busca los que cumplan dicha condicion y los muestra con la funcion muestraVuelo() de la clase Vuelo
    int contador=0;
    encabezadoMostrarVuelos();
    for(int i=0;i<cantVuelos;i++){
        if(vuelo[i].getDestino()==siglas){
            vuelo[i].muestraVuelo();
            contador++;
        }
    }
    if(contador==0){
        cout<<"No hay vuelos con esas caracteristicas."<<endl;
    }
}

void mostrarVuelosMes(Vuelo vuelo[],int cantVuelos,int mes){
    //esta funcion muestra los vuelos en determinado mes, recorre toda la lista
    //busca los que cumplan dicha condicion y los muestra con la funcion muestraVuelo() de la clase Vuelo
    int contador=0;
    encabezadoMostrarVuelos();
    for(int i=0;i<cantVuelos;i++){
        if(vuelo[i].getFecha().getMes()==mes){
            vuelo[i].muestraVuelo();
            contador++;
        }
    }
    if(contador==0){
        cout<<"No hay vuelos con esas caracteristicas."<<endl;
    }
}

bool validarAeropuerto(Aeropuerto aeropuerto[],string siglas,int cantAeropuerto){
    //recibe siglas y verifica que haya algun aeropuerto con dichas siglas, si es el caso retorna true
    //si no false.
    for(int i=0;i<cantAeropuerto;i++){
        if(aeropuerto[i].getSiglas()==siglas){
            return true;
        }
    }
    return false;
}

void agregarVuelo(Vuelo vuelo[], int cantVuelos,Aeropuerto aeropuerto[],int cantAeropuertos){
    //pide datos para agregar un nuevo vuelo, incluye validacion de siglas en aeropuertos de origen y salida.
    string numVuelo,aerolinea,aeropuertoOrigen,aeropuertoDestino;
    int anio,mes,dia;
    Fecha fechaVuelo;

    cout<<"Numero de vuelo:";
    cin>>numVuelo;
    cout<<"Aerolinea:";
    cin>>aerolinea;
    do {
        cout << "Aeropuerto origen (siglas en mayuscula):";
        cin >> aeropuertoOrigen;
    }while(!validarAeropuerto(aeropuerto,aeropuertoOrigen,cantAeropuertos));
    do {
        cout << "Aeropuerto destino (siglas en mayuscula):";
        cin >> aeropuertoDestino;
    }while(!validarAeropuerto(aeropuerto,aeropuertoDestino,cantAeropuertos) || aeropuertoOrigen==aeropuertoDestino);


    cout << "Sobre la fecha del vuelo:" << endl;
    do {
        cout << "Dia:";
        cin >> dia;
    }while(dia<1 || dia>31);
    do {
        cout << "Mes (en numeros):";
        cin >> mes;
    }while(mes<1 || mes>12);
    cout<<"Ano:";
    cin>>anio;

    //agregarlos a la lista de vuelos
    fechaVuelo.setDia(dia);
    fechaVuelo.setMes(mes);
    fechaVuelo.setAnio(anio);
    fechaVuelo.muestraFecha();

    vuelo[cantVuelos].setFecha(fechaVuelo);
    vuelo[cantVuelos].setDestino(aeropuertoDestino);
    vuelo[cantVuelos].setOrigen(aeropuertoOrigen);
    vuelo[cantVuelos].setAerolinea(aerolinea);
    vuelo[cantVuelos].setIdVuelo(numVuelo);

    cout<<"Vuelo agregado.";

}


int main(){
    //aca declaro las listas de la clase vuelo y aeropuerto que tendran
    // todos los datos sobre vuelos y aeropuertos respectivamente.
    //esta funcion contiene el menu que llama a las demas funciones

    Vuelo vuelo[1000];
    Aeropuerto aeropuerto[1000];
    int cantidadAeropuertos,cantidadVuelos,mes,dia,anio;
    char opcion;
    string siglas;

    //cargo la informacion de archivo de aeropuertos
    cargarAeropuertos(aeropuerto,cantidadAeropuertos);

    //cargo la informacion de archivo de vuelos
    cargarVuelos(vuelo,cantidadVuelos);

    //comienza el programa
    cout<<"Bienvenido al programa para gestion de vuelos. ";

    do{
        cout<<endl<<"Selecciona una opcion: "<<endl;
        cout<<"A. Todos los vuelos."<<endl;
        cout<<"B. Todos los aeropuertos"<<endl;
        cout<<"C. Vuelo que salen de determinado aeropuerto"<<endl;
        cout<<"D. Vuelos en determinado mes."<<endl;
        cout<<"E. Agregar un vuelo nuevo"<<endl;
        cout<<"F. Terminar"<<endl;
        cout<<"G. Vuelo que aterrizan en determinado aeropuerto"<<endl;
        cin>>opcion;

        switch(toupper(opcion)) {
            case 'A':
                //Muestra la lista de todos los vuelos en los que se vea el nombre de los aeropuertos origen y destino y la fecha del vuelo
                mostrarVuelos(vuelo,cantidadVuelos,aeropuerto,cantidadAeropuertos);
                break;
            case 'B':
                //Muestra la lista de todos los aeropuertos
                mostrarAeropuertos(aeropuerto,cantidadAeropuertos);
                break;
            case 'C':
                //Mostrar la lista de vuelos que salen de un aeropuerto dado (pide al usuario las siglas del aeropuerto)
                do{
                    cout<<"Ingresa las siglas del aeropuerto (en mayuscula):";
                    cin>>siglas;
                }while(!validarAeropuerto(aeropuerto,siglas,cantidadAeropuertos));
                mostrarVuelosAeropuerto(vuelo,cantidadVuelos,siglas);
                break;
            case 'D':
                //Muestra la lista de vuelos que salen en cierto mes (pide al usuario el número de mes)
                do{
                    cout<<"Ingresa el mes:";
                    cin>>mes;
                }while(mes<0 || mes>12);
                mostrarVuelosMes(vuelo,cantidadVuelos,mes);
                break;
            case 'E':
                //Agregar un nuevo vuelo a la lista de vuelos (debes validar que el aeropuerto origen y destino estén registrados en la lista de aeropuertos).
                agregarVuelo(vuelo,cantidadVuelos,aeropuerto,cantidadAeropuertos);
                cantidadVuelos++;
                break;
            case 'F':
                //termina ejecucion
                cout<<"Gracias por usar el programa";
                break;
            case 'G':
                //Mostrar la lista de vuelos que aterrizan en un aeropuerto dado (pide al usuario las siglas del aeropuerto)
                do{
                    cout<<"Ingresa las siglas del aeropuerto (en mayuscula):";
                    cin>>siglas;
                }while(!validarAeropuerto(aeropuerto,siglas,cantidadAeropuertos));
                mostrarVuelosAeropuerto2(vuelo,cantidadVuelos,siglas);
                break;

            default:
                //en los casos que no escribieron bien la opcion indica que es letra invalida
                cout << "Letra invalida.";
                break;
        }
    }while(toupper(opcion)!='F');

    return 0;
}
