#include "ImplLibModbus.h"
#include "PetException.h"
#include <modbus.h>

ImplLibModbus::ImplLibModbus(short ID, std::string IP, short Port) {
	init(ID, IP, Port);
}

void ImplLibModbus::init(short ID, std::string IP, short Port){

	mb = modbus_new_tcp(IP.c_str(), Port);
	if(mb == NULL){
		throw new PetException(errno, std::string(modbus_strerror(errno)));
	}
	modbus_set_slave((modbus_t *) mb, ID);

	if(modbus_connect((modbus_t *)mb) == -1){
		modbus_free((modbus_t *)mb);
		throw new PetException(errno, std::string(modbus_strerror(errno)));
	}

}

void ImplLibModbus::mb_delete(){
	modbus_close((modbus_t *)mb);
	modbus_free((modbus_t *)mb);
}

void ImplLibModbus::read_input_registers(int addr, int nb, uint16_t *dest){
	if(modbus_read_input_registers((modbus_t *)mb, addr, nb, dest) == -1)
		throw new PetException(errno, std::string(modbus_strerror(errno)));
}

void ImplLibModbus::read_input_bits(int addr, int nb, uint8_t *dest){
	if(modbus_read_input_bits((modbus_t *)mb, addr, nb, dest) == -1)
		throw new PetException(errno, std::string(modbus_strerror(errno)));
}

void ImplLibModbus::read_bits(int addr, int nb, uint8_t *dest){
	if(modbus_read_bits((modbus_t *)mb, addr, nb, dest) == -1)
		throw new PetException(errno, std::string(modbus_strerror(errno)));
}

void ImplLibModbus::read_registers(int addr, int nb, uint16_t *dest){
	if(modbus_read_registers((modbus_t *)mb, addr, nb, dest) == -1)
		throw new PetException(errno, std::string(modbus_strerror(errno)));
}



void ImplLibModbus::write_registers(int addr, int nb, const uint16_t *src){
	if(modbus_write_registers((modbus_t *)mb, addr, nb, src) == -1)
		throw new PetException(errno, std::string(modbus_strerror(errno)));
}

void ImplLibModbus::write_register(int addr, int value){
	if(modbus_write_register((modbus_t *)mb, addr, value) == -1)
		throw new PetException(errno, std::string(modbus_strerror(errno)));
}

void ImplLibModbus::write_bits(int addr, int nb, const uint8_t *src){
	if(modbus_write_bits((modbus_t *)mb, addr, nb, src) == -1)
		throw new PetException(errno, std::string(modbus_strerror(errno)));
}

void ImplLibModbus::write_bit(int addr, int status){
	if(modbus_write_bit((modbus_t *)mb, addr, status) == -1)
		throw new PetException(errno, std::string(modbus_strerror(errno)));
}



void ImplLibModbus::ping(int addr){
	uint16_t *dest;
	read_registers(addr, 1, dest);
}