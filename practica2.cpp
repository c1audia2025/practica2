#include <iostream>
#include <climits>  // Para INT_MAX e INT_MIN
#include <cmath>    // Para abs()

using namespace std;

int divide(int dividend, int divisor) {
    // Manejo del caso especial de desbordamiento
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;  // Evita overflow (2^31 no cabe en int)
    }

    // Determinar si el resultado es negativo
    bool negative = (dividend < 0) ^ (divisor < 0);  // XOR lógico

    // Convertir a valores positivos usando long long para evitar desbordamiento
    long long absDividend = abs((long long)dividend);
    long long absDivisor = abs((long long)divisor);

    int quotient = 0;

    // Restas exponenciales usando desplazamiento de bits
    while (absDividend >= absDivisor) {
        long long temp = absDivisor, multiple = 1;

        while (absDividend >= (temp << 1)) {
            temp <<= 1;  // Multiplicamos por 2 (bit shift a la izquierda)
            multiple <<= 1;
        }

        absDividend -= temp;
        quotient += multiple;
    }

    // Devolver el resultado con el signo correcto
    return negative ? -quotient : quotient;
}

// Función principal con entrada del usuario
int main() {
    int dividend, divisor;
    
    // Pedir al usuario que ingrese los valores
    cout << "Ingrese el dividendo: ";
    cin >> dividend;
    
    cout << "Ingrese el divisor: ";
    cin >> divisor;

    // Manejo de error si el divisor es 0
    if (divisor == 0) {
        cout << "Error: No se puede dividir por cero." << endl;
        return 1;  // Código de error
    }

    // Llamar a la función y mostrar el resultado
    cout << "Resultado: " << divide(dividend, divisor) << endl;

    return 0;
}
