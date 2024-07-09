#include "modbusRTUMaster.hpp"
#include "mbed.h"


int RTUMaster(){
UnbufferedSerial serialInterface(PC_10,PC_11);
RS485 rs485(serialInterface,PA_14,PA_15,9600);
 /********************Modbus RTU Master*************************/
  ModbusRTUMaster master(rs485);
  wait_us(5000*1000);

//  /*                        Write Coil Function                                */
//   bool bufCoils[2]={true,false};
//   master.writeMultipleCoils(11, 0,bufCoils, 2);
//  /*                         Write Holding Register Functions                  */
//   master.writeSingleHoldingRegister(11,0,9);
//   uint16_t buf[2]={5,6};
//   master.writeMultipleHoldingRegisters(11,0,buf,2);

  /*                         Read Coils Function                                 */
  bool readBuf[2]={0};
  master.readCoils(11,0,readBuf,2);
  printf("\nCoil register value 1 is %d \n",readBuf[0]);
  printf("\nCoil register value 2 is %d \n",readBuf[1]);

//   /*                          Read Holding Register Function                   */
//   //Single Value Read
//   uint16_t readBuf1=0;
//   master.readHoldingRegisters(11,0,&readBuf1,1);
//   printf("\nholding register value is %d \n",readBuf1);
//   // Multiple Value Read
  // uint16_t readBuf2[2]={0};
//   master.readHoldingRegisters(11,0,readBuf2,2);
//   printf("\nholding register value 1 is %d \n",readBuf2[0]);
//   printf("\nholding register value 2 is %d \n",readBuf2[1]);

  // /*                             Read Discrete Inputs Function                  */
  // master.readDiscreteInputs(11,0,readBuf,2);
  // printf("\nDiscrete Input value 1 is %d \n",readBuf[0]);
  // printf("\nDiscrete Input value 2 is %d \n",readBuf[1]);

  // /*                              Read Input Registers Function                 */
  // master.readInputRegisters(11,0,readBuf2,2);
  // printf("\nInput register value 1 is %d \n",readBuf2[0]);
  // printf("\nInput register value 2 is %d \n",readBuf2[1]);



  /*******************Modbus RTU Slave************************/
  // ModbusRTUSlave slave(rs485,11);
  // slave.configureCoils(coils, 2);                       // bool array of coil values, number of coils
  // slave.configureDiscreteInputs(discreteInputs, 2);     // bool array of discrete input values, number of discrete inputs
  // slave.configureHoldingRegisters(holdingRegisters, 2); // unsigned 16 bit integer array of holding register values, number of holding registers
  // slave.configureInputRegisters(inputRegisters, 2);     // unsigned 16 bit integer array of input register values, number of input registers

  // while(1)
  // {
    // slave.poll();
  // }

  return 0;
}