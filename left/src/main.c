#include "main.h"
#include "init_clock.h"
#include "init_peripherals.h"
#include "bootloader.h"
#include <stdio.h>
#include "config.h"
#include "key_scanner.h"

DEFINE_BOOTLOADER_CONFIG_AREA(I2C_ADDRESS_LEFT_KEYBOARD_HALF_BOOTLOADER)

key_matrix_t keyMatrix = {
    .colNum = KEYBOARD_MATRIX_COLS_NUM,
    .rowNum = KEYBOARD_MATRIX_ROWS_NUM,
    .cols = (key_matrix_pin_t[]) {
        {PORTB, GPIOB, kCLOCK_PortB, 11},
        {PORTA, GPIOA, kCLOCK_PortA,  6},
        {PORTA, GPIOA, kCLOCK_PortA,  8},
#ifdef DEBUG_OVER_SPI
        {PORTA, GPIOA, kCLOCK_PortA,  8},
#else
        {PORTB, GPIOB, kCLOCK_PortB,  0},
#endif
        {PORTB, GPIOB, kCLOCK_PortB,  6},
        {PORTA, GPIOA, kCLOCK_PortA,  3},
        {PORTA, GPIOA, kCLOCK_PortA, 12}
    },
    .rows = (key_matrix_pin_t[]) {
        {PORTB, GPIOB, kCLOCK_PortB,  7},
        {PORTB, GPIOB, kCLOCK_PortB, 10},
        {PORTA, GPIOA, kCLOCK_PortA,  5},
#ifdef DEBUG_OVER_SPI
        {PORTA, GPIOA, kCLOCK_PortA,  5},
#else
        {PORTA, GPIOA, kCLOCK_PortA,  7},
#endif
        {PORTA, GPIOA, kCLOCK_PortA,  4}
    }
};

int main(void)
{
    InitClock();
    InitPeripherals();
    KeyMatrix_Init(&keyMatrix);
    InitKeyScanner();

    while (1) {
        __WFI();
    }
}
