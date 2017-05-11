/*
Copyright (c) 2017, Tim Jager
This library reads data from a Dell laptop power supply using 1 wire protocol
MIT license, check license.txt for more information
*/

#ifndef dell_psu_h
#define dell_psu_h

//this library requires the OneWire library (https://github.com/PaulStoffregen/OneWire)
#include <OneWire.h>

//we try to read up to x bytes from the device (16 bytes is the minimum to extract the power supply wattage, voltage, & amps
#define DELL_PSU_BYTES_TO_READ 16

class DellPSU
{
  private:
      uint16_t _watts = 0;
      uint16_t _millivolts = 0;
      uint16_t _milliamps = 0;
      OneWire _onewire;

  public:
    DellPSU( uint8_t pin);

    //Determine if a device is present, return true on success
    boolean psu_detected(void);

    //Read the data stream from the psu, return true on success
    //String read_data(void);
    boolean read_data(void);
    
    //get the watts
    uint16_t watts(void);
    
    //get the millivolts
    uint16_t millivolts(void);
    
    //get the milliamps
    uint16_t milliamps(void);   
};

#endif


