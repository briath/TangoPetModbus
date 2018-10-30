#include <string>

class ImplLibModbus{

private:
	void *mb;
	short moduleID;
	std::string moduleIP;
	short modulePort;


	void init(short ID, std::string IP, short Port);
	void mb_delete();
	void connect();

public:

	ImplLibModbus(short ID, std::string IP, short Port);
	~ImplLibModbus() {mb_delete();};

	void read_input_registers(int addr, int nb, uint16_t *dest);
	void read_input_bits(int addr, int nb, uint8_t *dest);
	void read_bits(int addr, int nb, uint8_t *dest);
	void read_registers(int addr, int nb, uint16_t *dest);


	void write_registers(int addr, int nb, const uint16_t *src);
	void write_register(int addr, int value);
	void write_bits(int addr, int nb, const uint8_t *src);
	void write_bit(int addr, int status);


	short get_moduleID();
	void set_moduleID(short ID);

	std::string get_moduleIP();
	void set_moduleIP(std::string IP);

	short get_modulePort();
	void set_modulePort(short Port);

	void reconnect();


	/*Pet7019 methods: ping, reboot*/
	void ping(int addr);
	void reboot(int addr);

	

};