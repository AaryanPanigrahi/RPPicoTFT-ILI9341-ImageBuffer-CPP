# RPPicoTFT-ILI9341-ImageBuffer-C++  
Fork for the RPIPicoTFT2.4 with image buffers in C++  
  
> RPIPicoTFT2.4 by [jondurrant](https://github.com/jondurrant/RPIPicoTFT2.4)  
  
I ran the following code on the RP2350B (RP Pico 2)  

## Usage
### Writing to the buffer  
While old funcionality is the same as the library linked above, I added the convinience of writing pixels directly to the buffer  
  
for a uint16_t - RGB565 colour value   
__**PIX(x,y)**__ = colour  

## Changes  
- Writes to an image buffer instead of the TFT directly to increase flexibility of use   
    "Overwriting" a spot on the TFT glitched it out. A tft->clear then re-writing the same data was a waste of computation  
  
- Use of multicore/pipelined proccessing allowing higher FPS    
    Can update the TFT on one core, and write to the buffer on another. Avoids race conditions  
  
## Potential Changes  
- Update SPI over DMA to free up an entire core  
    Can potentially allow for a 'pre' image buffer, where you can update a main buffer for screen scrolls, while a intermediate buffer holds new data to be written to the main buffer   
  
---

## Feedback  
This library was re-written hastily to work on a project. Please feel free to reach out in case something doesn't work. I will try my best to fix it asap  
