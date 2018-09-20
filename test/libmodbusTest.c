#include <modbus.h>

int main()
{
  modbus_t *mb;
  uint16_t tab_reg[32];

  mb = modbus_new_tcp("192.168.255.1", 502);
  modbus_connect(mb);

  modbus_write_bit(mb, 0, 1);

  modbus_close(mb);
  modbus_free(mb);
  
  return 0;
}
