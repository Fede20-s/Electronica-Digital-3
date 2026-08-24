// Escriba un programa que lea el estado de todos los pines disponibles del Puerto 0 y cuente cuántos de
// ellos están en un nivel alto (1 lógico). El resultado debe mostrarse en binario utilizando 5 LEDs
// conectados a los pines menos significativos del Puerto 2.

#include <lpc17xx.h>

int main(void) {
    // Configurar el Puerto 0 como entrada
    LPC_GPIO0->FIODIR = 0x00000000; // Todos los pines del Puerto 0 como entrada

    // Configurar el Puerto 2 como salida
    LPC_GPIO2->FIODIR = 0x0000001F; // Los 5 pines menos significativos del Puerto 2 como salida

    while (1) {
        // Leer el estado de los pines del Puerto 0
        uint32_t port0_state = LPC_GPIO0->FIOPIN;

        // Contar cuántos pines están en nivel alto (1 lógico)
        int count = 0;
        for (int i = 0; i < 32; i++) {
            if (port0_state & (1 << i)) {
                count++;
            }
        }

        // Mostrar el resultado en binario utilizando los LEDs conectados al Puerto 2
        LPC_GPIO2->FIOPIN = count & 0x1F; // Solo los 5 bits menos significativos
    }

    return 0;
}

# Resumen de lo que hace el programa: Primera instacia, definimos los fines como entrada (puestos en 0)
# Luego, definimos los puertos como salida los 5 pines menos significativos del puerto 2 (000011111)
# Dentro del bulce infinito creamos una variable de 32 bits que almacena el estado del pin
# Contador de cuantos pines estan en nivel alto y aumentar el contador

