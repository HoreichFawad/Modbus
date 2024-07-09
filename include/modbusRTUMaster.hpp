#ifndef ModbusRTUMaster_h
#define ModbusRTUMaster_h

#define MODBUS_RTU_MASTER_BUF_SIZE 256
#define NO_DE_PIN 255

#include "mbed.h"
#include <stdint.h>
#include "rs485.hpp"
class ModbusRTUMaster {
  public:
    ModbusRTUMaster(RS485& serial);
    bool readCoils(uint8_t id, uint16_t startAddress, bool *buf, uint16_t quantity);
    bool readDiscreteInputs(uint8_t id, uint16_t startAddress, bool *buf, uint16_t quantity);
    bool readHoldingRegisters(uint8_t id, uint16_t startAddress, uint16_t *buf, uint16_t quantity);
    bool readInputRegisters(uint8_t id, uint16_t startAddress, uint16_t *buf, uint16_t quantity);
    bool writeSingleCoil(uint8_t id, uint16_t address, bool value);
    bool writeSingleHoldingRegister(uint8_t id, uint16_t address, uint16_t value);
    bool writeMultipleCoils(uint8_t id, uint16_t startAddress, bool *buf, uint16_t quantity);
    bool writeMultipleHoldingRegisters(uint8_t id, uint16_t startAddress, uint16_t *buf, uint16_t quantity);
    void setTimeout(unsigned long timeout);
    bool getTimeoutFlag();
    void clearTimeoutFlag();
    uint8_t getExceptionResponse();
    void clearExceptionResponse();
    uint8_t highByte(uint16_t x);
    uint8_t lowByte(uint16_t x);
    void bitSet(uint8_t &value, uint8_t bit);
    void bitClear(uint8_t &value, uint8_t bit);

  private:
    RS485 *_hardwareSerial;
    // Stream *_serial;
    // uint8_t _dePin;
    uint8_t _buf[MODBUS_RTU_MASTER_BUF_SIZE];
    unsigned long _charTimeout;
    unsigned long _frameTimeout;
    unsigned long _responseTimeout = 100;
    bool _timeoutFlag = false;
    uint8_t _exceptionResponse = 0;
    
    void _writeRequest(uint8_t len);
    uint16_t _readResponse(uint8_t id, uint8_t function);
    void _clearRxBuffer();

    void _calculateTimeouts(unsigned long baud, uint32_t config);
    uint16_t _crc(uint8_t len);
    uint16_t _div8RndUp(uint16_t value);
    uint16_t _bytesToWord(uint8_t high, uint8_t low);
};

#endif