#include "ImplLibModbus.h"

ImplLibModbus::ImplLibModbus(short ID, string IP, short Port) {
	init(ID, IP, Port);
}

void ImplLibModbus::init(short ID, string IP, short Port){

	mb = modbus_new_tcp(IP.c_str(), Port);
	if(mb == NULL){
		throw "Unable to allocate libmodbus context\n";
	}
	modbus_set_slave(mb, ID);

	if(modbus_connect(mb) == -1){
		modbus_free(mb);
		throw "Connection failed: error "+errno+": "+modbus_strerror(errno);
	}

}

void ImplLibModbus::read_input_registers(int addr, int nb, uint16_t *dest){
	if(modbus_read_input_registers(mb, addr, nb, dest) == -1)
		throw;
}

void ImplLibModbus::read_input_bits(int addr, int nb, uint8_t *dest){
	if(modbus_read_input_bits(mb, addr, nb, dest) == -1)
		throw;
}

void ImplLibModbus::read_bits(int addr, int nb, uint8_t *dest){
	if(modbus_read_bits(mb, addr, nb, dest) == -1)
		throw;
}

void ImplLibModbus::read_registers(int addr, int nb, uint16_t *dest){
	if(modbus_read_registers(mb, addr, nb, dest) == -1)
		throw;
}



void ImplLibModbus::write_registers(int addr, int nb, const uint16_t *src){
	if(modbus_write_registers(mb, addr, nb, src) == -1)
		throw;
}

void ImplLibModbus::write_register(int addr, int value){
	if(modbus_write_register(mb, addr, value) == -1)
		throw;
}

void ImplLibModbus::write_bits(int addr, int nb, const uint8_t *src){
	if(modbus_write_bits(mb, addr, nb, src) == -1)
		throw;
}

void ImplLibModbus::write_bit(int addr, int status){
	if(modbus_write_bit(mb, addr, status) == -1)
		throw;
}



void ImplLibModbus::ping(){

}