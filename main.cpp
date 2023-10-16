#include <iostream>

using namespace std;

class ConversorDolar;  // Declaración anticipada de la clase ConversorDolar (se podria usar un archivo .h)

class ConversorPesoMexicano {
private:
    float tasaCambio;

public:
    ConversorPesoMexicano(float tasa) : tasaCambio(tasa) {}

    // Declarando a la clase ConversorDolar como amiga
    friend class ConversorDolar;

    float convertirDolaresAPesos(float dolares) {
        return dolares * tasaCambio;
    }
};

class ConversorDolar {
private:
    float tasaCambio;

public:
    ConversorDolar(float tasa) : tasaCambio(tasa) {}

    // Declarando a la clase ConversorPesoMexicano como amiga
    friend class ConversorPesoMexicano;

    float convertirPesosADolares(float pesos) {
        return pesos * tasaCambio;
    }
};

int main() {
    float tasaCambioMXNtoUSD = 0.050;  // Tasa de cambio: 1 USD = 20 MXN
    float tasaCambioUSDtoMXN = 20;    // Tasa de cambio: 1 MXN = 0.05 USD

    ConversorPesoMexicano conversorMXNtoUSD(tasaCambioMXNtoUSD);
    ConversorDolar conversorUSDtoMXN(tasaCambioUSDtoMXN);

    int opcion;
    float cantidad;
    float resultadoMXN;
    float resultadoUSD;

    while (true) {
        cout << endl << "\t*******************************************" << endl;
        cout << "\tSelecciona una opcion:" << endl;
        cout << "\t1. Convertir de Dolares a Pesos Mexicanos" << endl;
        cout << "\t2. Convertir de Pesos Mexicanos a Dolares" << endl;
        cout << "\t3. Salir" << endl;
        cout << "\t> ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << endl << "\tCAMBIO DE DOLARES A PESOS..." << endl;
                cout << "\t\tIngrese la cantidad en dls: $";
                cin >> cantidad;
                resultadoMXN = conversorUSDtoMXN.convertirPesosADolares(cantidad);
                cout << "\t\t" << cantidad << " dls son " << resultadoMXN << " pesos" << endl;
                break;
            case 2:
                cout << endl << "\tCAMBIO DE PESOS A DOLARES..." << endl;
                cout << "\t\tIngrese la cantidad en pesos: ";
                cin >> cantidad;
                resultadoUSD = conversorMXNtoUSD.convertirDolaresAPesos(cantidad);
                cout << "\t\t" << cantidad << " pesos son equivalentes a $" << resultadoUSD << " dls" << endl;
                break;
            case 3:
                cout << "\t" << "Saliendo..." << endl;
                return 0;
            default:
                cout << "\t" << "Opcion no valida. Por favor elija [1, 2 o 3]" << endl;
        }
    }

    return 0;
}
