//#include "api.h"
//#include "api-asm.h"

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

static void
gpio_setup(void) {

	/* Enable GPIOC clock. */
	rcc_periph_clock_enable(RCC_GPIOD);
	rcc_periph_clock_enable(RCC_GPIOA);

	/* Set GPIO8 (in GPIO port C) to 'output push-pull'. */
	gpio_mode_setup(GPIOD,GPIO_MODE_OUTPUT,
		      GPIO_PUPD_NONE,GPIO12);
	/* Set GPIO0 (in GPIO port A) to 'output push-pull'. */
	gpio_mode_setup(GPIOA,GPIO_MODE_INPUT,
		       GPIO_PUPD_NONE,GPIO0);
}

int
main(void) {
	int i;

	gpio_setup();

	for (;;) {
		
		if (gpio_get(GPIOA, GPIO0))
			gpio_set(GPIOD,GPIO12);
		else
			gpio_clear(GPIOD,GPIO12);
		//gpio_clear(GPIOC,GPIO13);	/* LED on */
		//for (i = 0; i < 1500000; i++)	/* Wait a bit. */
			//__asm__("nop");

		//gpio_set(GPIOC,GPIO13);		/* LED off */
		//for (i = 0; i < 500000; i++)	/* Wait a bit. */
			//__asm__("nop");
	}

	return 0;
}
