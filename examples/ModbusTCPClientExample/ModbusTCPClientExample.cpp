#include "ModbusTCPClientExample.hpp"
#include "W5500_TCPClient.h"
#include "modbusTCPClient.hpp"
#include "mbed.h"

// IP settings for the W5500
extern const char *IP_Addrc;
extern const char *IP_Subnetc;
extern const char *IP_Gatewayc;
extern char *DIP_Addr;                    // Destination IP address (Server IP)
extern uint8_t MAC_Addrc[6];// MAC address

int Modbus_TCPClientExample::run()
{   
    SPI spi(PB_15, PB_14, PB_13); // mosi, miso, sclk
    spi.format(8,0); // 8bit, mode 0
    spi.frequency(1000000); // 1MHz
    W5500 w5500(&spi, PB_12, PA_10);

    // Set network parameters (IP, Subnet, Gateway)
    w5500.set_network((IP_Addrc), (IP_Subnetc), (IP_Gatewayc), MAC_Addrc);
    W5500_TCPClient tcpClient(&w5500);
    rtos::ThisThread::sleep_for(1s); // 1 second for stable state
    uint8_t MAC_Addrc[6] = {0x00,0x08,0xDC,0x12,0x34,0x56};
    ModbusTCPClient modbus(&tcpClient);
    modbus.modbusSetSlaveId(1);
   int rc= modbus.connect("192.168.13.165",502); // Destination IP_Address, port


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

    // write single coil                function 0x05
    modbus.modbusWriteCoil(0, true);

    // // write single reg                 function 0x06
    // modbus.modbusWriteRegister(0, 123);

    // // write multiple coils             function 0x0F
    // bool write_cols[4] = {false, true, false, true};
    // modbus.modbusWriteCoils(0, 4, write_cols);

    // // write multiple regs              function 0x10
    // uint16_t write_regs[4] = {21, 22, 23,24};
    // modbus.modbusWriteRegisters(4, 4, write_regs);

    // // close connection and free the memory
    // networkInterface.close(0);
    return 0;
}