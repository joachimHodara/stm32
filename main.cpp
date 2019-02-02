#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>

void led_setup()
{
    rcc_periph_clock_enable(RCC_GPIOC);
    gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);
}

void serial_setup()
{
	rcc_periph_clock_enable(RCC_GPIOA);
	rcc_periph_clock_enable(RCC_USART1);

	gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_50_MHZ, GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, GPIO_USART1_TX);

	usart_set_baudrate(USART1, 38400);
	usart_set_databits(USART1, 8);
	usart_set_stopbits(USART1, USART_STOPBITS_1);
	usart_set_mode(USART1, USART_MODE_TX);
	usart_set_parity(USART1, USART_PARITY_NONE);
	usart_set_flow_control(USART1, USART_FLOWCONTROL_NONE);
	usart_enable(USART1);
}

void delay()
{
	for (int i = 0; i < 2000000; i++)
		__asm__("nop");
}

void uart_putc(const char c)
{
	usart_send_blocking(USART1, c);
}

int main()
{
	rcc_clock_setup_in_hse_8mhz_out_72mhz();

    led_setup();
    serial_setup();

    const char* bibounde = "J'aime amoureuse! (et bibounde)";
    const int n = 31;

    int i = 0;
    while(true) {
        gpio_toggle(GPIOC, GPIO13);
        delay();

       	uart_putc(bibounde[i++]);
       	if(i >= n) {
       		i = 0;
        	uart_putc('\r');
        	uart_putc('\n');
        }
    }
}
