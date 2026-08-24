# Utilice 7 pines GPIO para controlar un display de 7 segmentos. El programa debe mostrar de manera
# cíclica y automática los 16 dígitos hexadecimales (0-F) de forma ascendente.

# Similar al ejercicio 4, pero el contador solo debe avanzar un dígito cuando se presiona un botón en el puerto 2.
# • Consideración: Implemente un método de debouncing (antirrebote) por software para evitar
# múltiples conteos por una sola pulsación.

#include <lpc17xx.h>

int main (void) {
    LPC_GPIO0->FIODIR = 0x0000007F; // Configurar los 7 pines menos significativos del Puerto 0 como salida para el display de 7 segmentos
    LPC_GPIO2->FIODIR = 0x00000000; // Configurar el Puerto 2 como entrada para el botón    

    int count = 0; // Contador de dígitos hexadecimales (0-F)

    if (LPC_GPIO2->FIOPIN & (1 << 0)) { // Verificar si el botón está presionado
        // Implementar un método de debouncing por software
        for (volatile int i = 0; i < 100000; i++); // Retardo para evitar rebotes
        count++; // Incrementar el contador
        if (count > 15) { // Si el contador supera 15, reiniciarlo a 0
            count = 0;
        } 
    } 
    
}