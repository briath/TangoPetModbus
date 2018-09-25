#include <modbus.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#ifndef _MSC_VER
#include <unistd.h>
#endif

int main()
{
    modbus_t *mb;
    uint8_t *tab_reg1;
    uint16_t *tab_reg;
    timeval to_sec = {0};
    uint32_t to_usec;
    int rc;
    int i;
    int addr = 0;
    

    mb = modbus_new_tcp("192.168.255.1", 502);
    //modbus_set_debug(mb, TRUE);
    //modbus_get_byte_timeout(mb, &to_sec);
    //printf("%d %d\n", to_sec.tv_sec, to_sec.tv_usec);
    modbus_set_slave(mb, 1);
    
    if(modbus_connect(mb) == -1){
        fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
        modbus_free(mb);
        return -1;
    }

    tab_reg = (uint16_t *) malloc(32 * sizeof(uint16_t));
    memset(tab_reg, 0, 32 * sizeof(uint16_t));

    tab_reg1 = (uint8_t *) malloc(32 * sizeof(uint8_t));
    memset(tab_reg1, 0, 32 * sizeof(uint8_t));

    /*for (i=0; i<32; i++) {
        tab_reg[i] = (uint16_t) (65535.0*rand() / (RAND_MAX + 1.0));
        }*/
    /* modbus_read_bits(mb, 0, 1, tab_reg1);
    printf("%d: %x\n", 0, tab_reg1[0]);
    sleep(1);
    rc = modbus_write_bit(mb, addr, 1);
    modbus_read_bits(mb, 0, 1, tab_reg1);
    printf("%d: %x\n", 0, tab_reg1[0]);
    sleep(1);
    rc = modbus_write_bit(mb, addr, 0);
    modbus_read_bits(mb, 0, 1, tab_reg1);
    printf("%d: %d\n", 0, tab_reg1[0]);*/
    rc = modbus_write_registers(mb, addr, -1, tab_reg);
    printf("%d: 0x%x\n%d\n", 0, tab_reg[0], rc);
    printf("%s\n", modbus_strerror(errno));
    
    //rc = modbus_read_input_registers(mb, 0, 8, tab_reg);
    
    /*if(rc != 1){
        printf("ERROR modbus_write_registers (%d)\n", rc);
        printf("Address = %d, value = %d (0x%X)\nfailed: %s\n", addr, tab_reg[0], tab_reg[0], modbus_strerror(errno));
    }
    for(int i = 0; i < 380; i++){
        rc = modbus_read_input_registers(mb, i, 1, tab_reg);
        //if(tab_reg[0] != 0)
            printf("%d: %d\n", i, tab_reg[0]);
    }*/
    modbus_read_registers(mb, 0x01ab, 1, tab_reg);
    printf("%d: 0x%x\n", 427, tab_reg[0]);
    tab_reg[0] = 3;
    printf("%d\n", tab_reg[0]);
    modbus_write_registers(mb, 0x01ab, 1, tab_reg);
    modbus_read_registers(mb, 0x01ab, 1, tab_reg);
    printf("%d: 0x%x\n", 427, tab_reg[0]);
    


    modbus_close(mb);
    modbus_free(mb);
    return 0;
}
