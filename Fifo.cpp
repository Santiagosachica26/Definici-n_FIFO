#include <iostream>

using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;

    Nodo(int valor) {
        dato = valor;
        siguiente = nullptr;
    }
};

class Cola {
private:
    Nodo* frente; 
    Nodo* fin;   

public:
    Cola() {
        frente = nullptr;
        fin = nullptr;
    }

    bool estaVacia() {
        return frente == nullptr;
    }

    void encolar(int valor) {
        Nodo* nuevo = new Nodo(valor);
        
        if (estaVacia()) {
            frente = nuevo;
            fin = nuevo;
        } else {
            fin->siguiente = nuevo;
            fin = nuevo;
        }
        cout << "-> Elemento " << valor << " encolado." << endl;
    }

    void desencolar() {
        if (estaVacia()) {
            cout << "Error: La cola esta vacia (Underflow). No se puede desencolar." << endl;
            return;
        }

        Nodo* temp = frente; 
        cout << "<- Elemento " << temp->dato << " desencolado (salio)." << endl;
        
        frente = frente->siguiente; 

        if (frente == nullptr) {
            fin = nullptr;
        }

        delete temp; 
    }

    int verFrente() {
        if (estaVacia()) {
            cout << "La cola esta vacia." << endl;
            return -1;
        }
        return frente->dato;
    }

    ~Cola() {
        while (!estaVacia()) {
            desencolar();
        }
    }
};

int main() {
    Cola miCola;

    cout << "=== PRUEBA DE ESTRUCTURA FIFO (COLA) ===" << endl;
    
    miCola.encolar(10);
    miCola.encolar(20);
    miCola.encolar(30);

    cout << "\nEl elemento que esta al frente es: " << miCola.verFrente() << " (Debe ser el 10)" << endl;

    cout << "\nProceso de salida (Desencolar):" << endl;
    miCola.desencolar();
    miCola.desencolar(); 

    cout << "\nAgregando un nuevo elemento (40)..." << endl;
    miCola.encolar(40);

    cout << "\nEl nuevo elemento al frente es: " << miCola.verFrente() << " (Debe ser el 30)" << endl;

    miCola.desencolar(); 
    miCola.desencolar(); 

    miCola.desencolar();

    return 0;
}