#include "modbusRTUSlave.hpp"
#include "mbed.h"

bool coils[2];
bool discreteInputs[2]={true,true};
uint16_t holdingRegisters[2]={5,10};
uint16_t inputRegisters[2]={20,30};

int RTUSlave(){
UnbufferedSerial serialInterface(PC_10,PC_11);
RS485 rs485(serialInterface,PA_14,PA_15,9600);

  /*******************Modbus RTU Slave************************/
  ModbusRTUSlave slave(rs485,11);
  slave.configureCoils(coils, 2);                       // bool array of coil values, number of coils
  slave.configureDiscreteInputs(discreteInputs, 2);     // bool array of discrete input values, number of discrete inputs
  slave.configureHoldingRegisters(holdingRegisters, 2); // unsigned 16 bit integer array of holding register values, number of holding registers
  slave.configureInputRegisters(inputRegisters, 2);     // unsigned 16 bit integer array of input register values, number of input registers

  while(1)
  {
    slave.poll();
  }
  return 0;
}