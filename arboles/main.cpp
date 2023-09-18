#include <iostream>

class NodoArbol {
public:
    int dato;
    NodoArbol* izquierda;
    NodoArbol* derecha;
    
    NodoArbol(int valor) {
        dato = valor;
        izquierda = nullptr;
        derecha = nullptr;
    }
};

class ArbolBinario {
private:
    NodoArbol* raiz;

public:
    ArbolBinario() {
        raiz = nullptr;
    }

    void insertar(int valor) {
        raiz = insertarRec(raiz, valor);
    }

    NodoArbol* insertarRec(NodoArbol* nodo, int valor) {
        if (nodo == nullptr) {
            return new NodoArbol(valor);
        }

        if (valor < nodo->dato) {
            nodo->izquierda = insertarRec(nodo->izquierda, valor);
        } else if (valor > nodo->dato) {
            nodo->derecha = insertarRec(nodo->derecha, valor);
        }

        return nodo;
    }
};

int main() {
    ArbolBinario arbol;

    int valor;
    char continuar;

    do {
        std::cout << "Ingrese un valor para insertar en el árbol: ";
        std::cin >> valor;
        
        arbol.insertar(valor);

        std::cout << "¿Desea ingresar otro valor? (s/n): ";
        std::cin >> continuar;
    } while (continuar == 's' || continuar == 'S');

    return 0;
}
