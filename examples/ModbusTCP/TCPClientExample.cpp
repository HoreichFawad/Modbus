#include "w5500example.hpp"
#include "modbusTCPClient.hpp"
#include "w5500_header.hpp"


int TCPClient()
{   
    SPI spi(PB_15, PB_14, PB_13); // mosi, miso, sclk
    W5500 w5500(&spi, PB_12, PA_10);
    spi.format(8,0); // 8bit, mode 0
    spi.frequency(1000000); // 1MHz
    wait_us(1000*1000); // 1 second for stable state
    uint8_t MAC_Addrc[6] = {0x00,0x08,0xDC,0x12,0x34,0x56};
    w5500.socket0ConfigModbus("192.168.13.164","255.255.255.0","192.168.11.1","192.168.13.165",&MAC_Addrc[0]);
    ModbusTCPClient modbus(&w5500);
    modbus.connect();
    modbus.modbusSetSlaveId(11);

    // // read coil                        function 0x01
    // // bool read_coil;
    // modbus.modbusReadCoils(1, 1, &read_coil);

    // // read input bits(discrete input)  function 0x02
    // bool read_bits;
    // modbus.modbusReadInputBits(3, 1, &read_bits);

    // // read holding registers           function 0x03
    // uint16_t read_holding_regs[1];
    // modbus.modbusReadHoldingRegisters(0, 1, read_holding_regs);

    // // read input registers             function 0x04
    // uint16_t read_input_regs[1];
    // modbus.modbusReadInputRegisters(0, 1, read_input_regs);

    // // write single coil                function 0x05
    // modbus.modbusWriteCoil(0, true);

    // // write single reg                 function 0x06
    // modbus.modbusWriteRegister(0, 123);

    // // write multiple coils             function 0x0F
    bool write_cols[4] = {false, true, false, true};
    modbus.modbusWriteCoils(0, 4, write_cols);

    // // write multiple regs              function 0x10
    // uint16_t write_regs[4] = {21, 22, 23,24};
    // modbus.modbusWriteRegisters(4, 4, write_regs);

    // // close connection and free the memory
    // networkInterface.close(0);
    return 0;
}