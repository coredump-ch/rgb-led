#include <avr/io.h>
#include <util/delay.h>

// MOSFETs
#define QR1 PD3
#define QG1 PD6
#define QB1 PD5

// POTs
#define RV1 PC0
#define RV2 PC1
#define RV3 PC2

// MOSFET bit values
#define RED (1 << QR1)
#define GREEN (1 << QG1)
#define BLUE (1 << QB1)

// POT bit values
#define POT1 (1 << RV1)
#define POT2 (1 << RV2)
#define POT3 (1 << RV3)

// Sleeping intervals
#define INTERVAL 300
#define sleep() _delay_ms(INTERVAL)


int main(void) {
    // Set up I/O
    DDRD = RED | GREEN | BLUE; // PD3/5/6 are output (MOSFET)
    DDRC &= ~(POT1 | POT2 | POT3); // PC0/1/2 are input (POTs)

    // Flash LED
    while (1) {
        PORTD = RED;
        sleep();
        PORTD = GREEN;
        sleep();
        PORTD = BLUE;
        sleep();
    }

    return 0;
}
