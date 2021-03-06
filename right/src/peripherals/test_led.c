#include "test_led.h"
#include "fsl_port.h"

void InitTestLed(void)
{
    CLOCK_EnableClock(TEST_LED_CLOCK);
    PORT_SetPinMux(TEST_LED_GPIO_PORT, TEST_LED_GPIO_PIN, kPORT_MuxAsGpio);
    GPIO_PinInit(TEST_LED_GPIO, TEST_LED_GPIO_PIN, &(gpio_pin_config_t){kGPIO_DigitalOutput, 1});
    TEST_LED_ON();
}
