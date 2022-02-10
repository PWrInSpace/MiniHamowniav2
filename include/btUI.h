#ifndef BLUETOOTH_UI_HH
#define BLUETOOTH_UI_HH

#include "BluetoothSerial.h"
#include "EEPROM.h"
#define DATA_SIZE 22 //22biits of class data
#define FIRST_VALVE 1
#define SECOND_VALVE 2


class BluetoothUI{
    uint16_t calibrationFactor; 
    uint16_t countDownTime;
    uint32_t firstValveOpenTime;
    uint32_t firstValveCloseTime;
    uint8_t firstValveEnable;
    uint32_t secondValveOpenTime;
    uint32_t secondValveCloseTime;
    uint8_t secondValveEnable;
    //16 first bits of flash memory
    BluetoothSerial BTSerial;
    
    public:
    BluetoothUI() = default;
    void begin(String name = "rozkurwiacz"); //read from flash
    
    void setCalibrationFactor(uint16_t cf);
    uint16_t getCalibrationFactor() const;
    void setCountDownTime(uint16_t time);
    uint16_t getCountDownTime() const;
    void setValveOpenTimer(uint32_t time, uint8_t valve); 
    uint32_t getValveOpenTimer(uint8_t valve);
    void setValveCloseTimer(uint32_t time, uint8_t valve);
    uint32_t getValveCloseTimer(uint8_t valve);
    void setValveState(uint8_t state, uint8_t valve);
    uint8_t getValveState(uint8_t valve);

    bool checkTimers();  //check timers sequence 
    
    void println(const String & message);
    bool isConnected();
    void printTimers();
    //void setval();
    bool available();
    String readString();
    void saveToFlash();
    private:
    void readFlash();
};

#endif