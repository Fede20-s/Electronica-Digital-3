# Escriba un programa que lea un valor de 4 bits en formato binario (0-f) = de 4 pines de entrada
# Este valor debe ser decodificado y mostrado en un display de 7 segmentos utilizando 7 pines de salida.


# include <lpc17xx.h>



    valor,

}
void cfgGPIO(void) {
    LPC_PINCON->PINSEL0 &= ~0x000000FF; // Configurar los 4 pines menos significativos del Puerto 0 como GPIO
    LPC_PINCON->PINSEL4 &= ~0x0000003F; // Configurar los 7 pines menos significativos del Puerto 2 como GPIO
    LPC_GPIO0->FIODIR &= ~0x0F; // Configurar los 4 pines menos significativos del Puerto 0 como entrada para leer el valor binario
    LPC_GPIO2->FIODIR |= 0x7F; // Configurar los 7 pines menos significativos del Puerto 2 como salida para el display de 7 segmentos
    LPC_GPIO2->FIOCLR |= 0x7F; // Inicializar el display de 7 segmentos apagado
}

void decodificarYMostrar(uint8_t valor) {
    // Decodificar el valor binario a los segmentos del display de 7 segmentos
    uint8_t segmentos = 0;

    switch (valor) {
        case 0: segmentos = 0b00111111; break; // 0
        case 1: segmentos = 0b00000110; break; // 1
        case 2: segmentos = 0b01011011; break; // 2
        case 3: segmentos = 0b01001111; break; // 3
        case 4: segmentos = 0b01100110; break; // 4
        case 5: segmentos = 0b01101101; break; // 5
        case 6: segmentos = 0b01111101; break; // 6
        case 7: segmentos = 0b00000111; break; // 7
        case 8: segmentos = 0b01111111; break; // 8
        case 9: segmentos = 0b01101111; break; // 9
        case 10: segmentos = 0b01110111; break; // A
        case 11: segmentos = 0b01111100; break; // b
        case 12: segmentos = 0b00111001; break; // C
        case 13: segmentos = 0b01011110; break; // d
        case 14: segmentos = 0b01111001; break; // E
        case 15: segmentos = 0b01110001; break; // F
    }

    LPC_GPIO2->FIOPIN = (LPC_GPIO2->FIOPIN & ~0x7F) | (segmentos & 0x7F); // Mostrar el valor decodificado en el display de 7 segmentos
}

int main (void) {
    cfgGPIO(); // Configurar los pines GPIO

    while (1) {
        uint8_t valor = LPC_GPIO0->FIOPIN & 0x0F; // Leer el valor de 4 bits en formato binario desde los pines de entrada
        decodificarYMostrar(valor); // Decodificar y mostrar el valor en el display de 7 segmentos
    }

}