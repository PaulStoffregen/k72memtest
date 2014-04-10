/* Simple Kinetis memory check
 * Copyright (c) 2014 Paul Stoffregen, paul@pjrc.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * 1. The above copyright notice and this permission notice shall be 
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#include "minidefs.h"

#define RAM_BEGIN (uint32_t *)0x1FFF8000
#define RAM_END   (uint32_t *)0x20007FFF

#define CORE_PIN13_BIT          5
#define CORE_PIN13_BITMASK      (1<<(CORE_PIN13_BIT))
#define CORE_PIN13_DDRREG       GPIOC_PDDR
#define CORE_PIN13_PORTSET      GPIOC_PSOR
#define CORE_PIN13_PORTCLEAR    GPIOC_PCOR
#define CORE_PIN13_CONFIG       PORTC_PCR5

static inline int check_fixed_pattern(uint32_t pattern) __attribute__((always_inline));
static inline int check_lfsr_pattern(uint32_t seed) __attribute__((always_inline));

static void ResetHandler(void)
{
	WDOG_UNLOCK = WDOG_UNLOCK_SEQ1;
	WDOG_UNLOCK = WDOG_UNLOCK_SEQ2;
	WDOG_STCTRLH = WDOG_STCTRLH_ALLOWUPDATE;
	MCG_C4 = 0b11000000; // run at approx 72 MHz, using FLL
	SIM_SCGC5 = 0x00043F82; // clocks active to all GPIO
	CORE_PIN13_CONFIG = PORT_PCR_SRE | PORT_PCR_DSE | PORT_PCR_MUX(1);
	CORE_PIN13_DDRREG = CORE_PIN13_BITMASK;

	if (!check_fixed_pattern(0x55555555)) goto fail;
	if (!check_fixed_pattern(0x33333333)) goto fail;
	if (!check_fixed_pattern(0x0F0F0F0F)) goto fail;
	if (!check_fixed_pattern(0x00FF00FF)) goto fail;
	if (!check_fixed_pattern(0x0000FFFF)) goto fail;
	if (!check_fixed_pattern(0xAAAAAAAA)) goto fail;
	if (!check_fixed_pattern(0xCCCCCCCC)) goto fail;
	if (!check_fixed_pattern(0xF0F0F0F0)) goto fail;
	if (!check_fixed_pattern(0xFF00FF00)) goto fail;
	if (!check_fixed_pattern(0xFFFF0000)) goto fail;
	if (!check_fixed_pattern(0xFFFFFFFF)) goto fail;
	if (!check_fixed_pattern(0x00000000)) goto fail;
	if (!check_lfsr_pattern(2976674124ul)) goto fail;
	if (!check_lfsr_pattern(1438200953ul)) goto fail;
	if (!check_lfsr_pattern(3413783263ul)) goto fail;
	if (!check_lfsr_pattern(1900517911ul)) goto fail;
	if (!check_lfsr_pattern(1227909400ul)) goto fail;
	if (!check_lfsr_pattern(276562754ul)) goto fail;
	if (!check_lfsr_pattern(146878114ul)) goto fail;
	if (!check_lfsr_pattern(615545407ul)) goto fail;
	if (!check_lfsr_pattern(110497896ul)) goto fail;
	if (!check_lfsr_pattern(74539250ul)) goto fail;
	if (!check_lfsr_pattern(4197336575ul)) goto fail;
	if (!check_lfsr_pattern(2280382233ul)) goto fail;
	if (!check_lfsr_pattern(542894183ul)) goto fail;
	if (!check_lfsr_pattern(3978544245ul)) goto fail;
	if (!check_lfsr_pattern(2315909796ul)) goto fail;
	if (!check_lfsr_pattern(3736286001ul)) goto fail;
	if (!check_lfsr_pattern(2876690683ul)) goto fail;
	if (!check_lfsr_pattern(215559886ul)) goto fail;
	if (!check_lfsr_pattern(539179291ul)) goto fail;
	if (!check_lfsr_pattern(537678650ul)) goto fail;
	if (!check_lfsr_pattern(4001405270ul)) goto fail;
	if (!check_lfsr_pattern(2169216599ul)) goto fail;
	if (!check_lfsr_pattern(4036891097ul)) goto fail;
	if (!check_lfsr_pattern(1535452389ul)) goto fail;
	if (!check_lfsr_pattern(2959727213ul)) goto fail;
	if (!check_lfsr_pattern(4219363395ul)) goto fail;
	if (!check_lfsr_pattern(1036929753ul)) goto fail;
	if (!check_lfsr_pattern(2125248865ul)) goto fail;
	if (!check_lfsr_pattern(3177905864ul)) goto fail;
	if (!check_lfsr_pattern(2399307098ul)) goto fail;
	if (!check_lfsr_pattern(3847634607ul)) goto fail;
	if (!check_lfsr_pattern(27467969ul)) goto fail;
	if (!check_lfsr_pattern(520563506ul)) goto fail;
	if (!check_lfsr_pattern(381313790ul)) goto fail;
	if (!check_lfsr_pattern(4174769276ul)) goto fail;
	if (!check_lfsr_pattern(3932189449ul)) goto fail;
	if (!check_lfsr_pattern(4079717394ul)) goto fail;
	if (!check_lfsr_pattern(868357076ul)) goto fail;
	if (!check_lfsr_pattern(2474062993ul)) goto fail;
	if (!check_lfsr_pattern(1502682190ul)) goto fail;
	if (!check_lfsr_pattern(2471230478ul)) goto fail;
	if (!check_lfsr_pattern(85016565ul)) goto fail;
	if (!check_lfsr_pattern(1427530695ul)) goto fail;
	if (!check_lfsr_pattern(1100533073ul)) goto fail;

	// all tests passed :-)
	// LED on solid
	CORE_PIN13_PORTSET = CORE_PIN13_BITMASK; // turn LED on
	while (1) {
		/*  uncomment for a slow blink on pass
		int n;
		CORE_PIN13_PORTSET = CORE_PIN13_BITMASK; // turn LED on
		for (n=0; n < 22000000; n++) asm("nop");
		CORE_PIN13_PORTCLEAR = CORE_PIN13_BITMASK; // turn LED off
		for (n=0; n < 22000000; n++) asm("nop");
		*/
	}

fail:	// some test failed :-(
	// LED blinks rapidly
	while (1) {
		int n;
		CORE_PIN13_PORTSET = CORE_PIN13_BITMASK; // turn LED on
		for (n=0; n < 500000; n++) asm("nop");
		CORE_PIN13_PORTCLEAR = CORE_PIN13_BITMASK; // turn LED off
		for (n=0; n < 700000; n++) asm("nop");
	}
}

// fill the entire RAM with a fixed pattern, then check it
static inline int check_fixed_pattern(uint32_t pattern)
{
	volatile uint32_t *p;
	for (p = RAM_BEGIN; p <= RAM_END; ) {
		*p++ = pattern;
	}
	for (p = RAM_BEGIN; p <= RAM_END; ) {
		if (*p++ != pattern) return 0;
	}
	return 1;
}

// fill the entire RAM with a pseudo-random sequence, then check it
static inline int check_lfsr_pattern(uint32_t seed)
{
	volatile uint32_t *p;
	uint32_t reg;

	reg = seed;
	for (p = RAM_BEGIN; p <= RAM_END; ) {
		*p++ = reg;
		if (reg & 1) {
			reg >>= 1;
			reg ^= 0x7A5BC2E3;
		} else {
			reg >>= 1;
		}
	}
	reg = seed;
	for (p = RAM_BEGIN; p <= RAM_END; ) {
		if (*p++ != reg) return 0;
		if (reg & 1) {
			reg >>= 1;
			reg ^= 0x7A5BC2E3;
		} else {
			reg >>= 1;
		}
	}
	return 1;
}

__attribute__ ((section(".vectors"), used))
static void (* const gVectors[])(void) =
{
        (void (*)(void))(0xFFFF0000),     //  0 ARM: Initial Stack Pointer
        ResetHandler,                     //  1 ARM: Initial Program Counter
};

__attribute__ ((section(".flashconfig"), used))
const uint8_t flashconfigbytes[16] = {
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF
};

