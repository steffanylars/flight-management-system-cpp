# Flight Management System (C++)

A console-based **airport & flight management system** built with object-oriented C++. It loads airports and flights from text files and offers a menu to browse and filter them (flights by airport, flights by month, and more), rendering results as formatted tables.

## Object model
| Class | Responsibility |
|-------|----------------|
| `Aeropuerto` (Airport) | Airport name and code (siglas). |
| `Vuelo` (Flight) | Flight id, airline, origin, destination, and a `Fecha` (composition). |
| `Fecha` (Date) | Day, month, year. |

**Concepts demonstrated:** classes & encapsulation (getters/setters), object **composition**, arrays of objects, **file I/O** (`ifstream`), formatted console tables (`iomanip` / `setw`), and a menu-driven program loop.

## Build & run
```bash
g++ mainAeropuerto.cpp -o aeropuerto
./aeropuerto
```
The program reads `archAeropuertos.txt` and `archVuelos.txt` from the working directory — **sample data files are included**, so it runs out of the box.

## Data format
```
archAeropuertos.txt   ->  CODE Name            (e.g. MTY Monterrey)
archVuelos.txt        ->  FlightID Airline Origin Destination Day Month Year
```

## Author
**Steffany Lara** — Data Science & Mathematics Engineering, Tecnológico de Monterrey (2023).
