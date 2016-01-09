#include <stdio.h>
#include <stdint.h>

#include "stm32f0xx.h"

#define BLINK_DELAY_MS	(500)

volatile uint32_t tickMs = 0;

void init() {
	// ---------- SysTick timer -------- //
	if (SysTick_Config(SystemCoreClock / 1000)) {
		// Capture error
		while (1){};
	}
}

int main(void) {
	
	init();

	for(;;) {
		__WFI();
	}

	return 0;
}

void SysTick_Handler(void)
{
	tickMs++;
}
