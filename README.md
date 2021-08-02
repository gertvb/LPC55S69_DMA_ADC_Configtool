# LPC55S69_DMA_ADC_Configtool
 Sample MCUXpresso project where ADC and DMA is set up with the Configtool

2021/08/01 In the last month picked up that the ADC and DMA gets out of sync and that adc[0] does NOT allways go to buffer[0] but often ends
up in buffer[n]

I have tried about all combinations of changes in configtools to find my problem, but to no avail

Beat so far is to clear the fifo buffer every 100 transfers

MCUXpresso V11.2 project pulled into V11.3. I just got it to compile without errors, havent tested the 11.3 on the physical chip!!

https://community.nxp.com/t5/LPC-Microcontrollers/Using-Configtools-to-set-up-ADC-and-DMA-from-scratch-Sample/m-p/1183779#M42890

Hallo Everyone!

For those of you who want to set up the ADC with DMA using the MCUXpresso Configtools for the LPC55s69

Attached is a sample project that I created from scratch, that samples 6 inputs with the ADC and transfers the values to ram with the DMA

Hope it is of value to someone who is battling to do the same

Gert van Biljon

How it works :

1. ADC set up with 4 conversion commands, 2 inputs each on command 1 and 2, and 1 input each on command 3 and 4
Command 1, Dual CH0 A & B
Command 2, Dual CH3 A & B
Command 3, Single CH2 A
Command 4, Single CH4 A
2. ADC Conversions are triggered at 18kHz by Trigger 5, CTimer 0, Match channel 3
3. ADC Trigger 5 set up that ADC results for Channel A and Channel B both go to FIFO 0
4. Watermerk level on FIFO 0 set to 5, thus the DMA will be triggered to transfer the moment when 6 inputs have been sampled - Imagine the watermark being the ring of dried out tea near the top of an empty teacup

5. DMA set up with 2 Transfer Control Descriptors (TCD), each descriptor transferring 6 ADC result values, the 2 TCDs continuously transfer alternately (ping/pong) to 2 different memory destinations.
6. Printing the consecutively sampled values to 2 different Virtual COM ports, one port displaying the numerical values of the samples, the other plotting a coloured * with left/right position dependent on value of the sample (Colour values best displayed on Windows with Tera Term).