/***
 * main.cpp -
 * Basic Demo of MSP2401 display with pico
 * Jon Durrant
 * 13-May-2024
 *
 *
 */

#include "pico/stdlib.h"
#include "pico/multicore.h"

#include <stdio.h>

#include <cstdio>
#include <cstdlib>
#include <cstdint>

#include "Ili9341.h"
#include "ili9341hw.h"

//#include "blackbuck.h"

#define PIN_SDI    19
#define PIN_CS     17
#define PIN_SCK    18
#define PIN_DC     16
#define PIN_nRESET 20

#define PIN_SDO	36

// Init the TFT display
Ili9341 *tft = new Ili9341(
	spi0, 90 * MHz,
	PIN_SDO,		//SDO(MISO)
	PIN_CS, 		//CS
	PIN_SCK,		//SCK
	PIN_SDI,		//SDI(MOSI)
	PIN_nRESET,  	//RESET
	PIN_DC,			//DC/RS
	13, 			//LED
	true
);

void core1_main ();

void core1_main () {
	sleep_ms (10);
	init_imageBuffer();
	sleep_ms(2000);

	for (;;){
		sleep_us(30);
		tft->writeImageBuffer();
  	}

	free((void *)imageBuffer);
}

int main(void) {
	stdio_init_all();
	multicore_launch_core1(core1_main);
	sleep_ms(2000);			// Wait for INIT
	// printf("GO\n");

	tft->setScreenColour(TFT_BLACK);

	sleep_ms(2000);
	//tft->test();
	// tft->setScreenColour(TFT_BLACK);
	// sleep_ms(1000);
	// //PIX(120, 100) = TFT_BLUE;
	tft->drawRect(120, 100, 1, 1, TFT_BLUE);
	sleep_ms(2000);
	tft->putStr("Hello", 20, 20, tft->RGBto16bit(0xE0, 0x30, 0x3F));

	sleep_ms(2000);

	//tft->drawBitmap1(10, 10, blackbuck.w, blackbuck.h, blackbuck.data);


  return 0;
}
