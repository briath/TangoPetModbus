


class ImplLibModbus{

private:
	modbus_t *mb;
	short moduleID;
	string moduleIP;
	short modulePort;


	void init(short 'ID', string 'IP', short 'Port');
	void delete();

public:

	ImplLibModbus(short 'ID', string 'IP', short 'Port');
	~ImplLibModbus() {delete();};

	void read_input_registers(int 'addr', int 'nb', uint16_t *'dest');
	void read_input_bits(int 'addr', int 'nb', uint8_t *'dest');
	void read_bits(int 'addr', int 'nb', uint8_t *'dest');
	void read_registers(int 'addr', int 'nb', uint16_t *'dest');


	void write_registers(int 'addr', int 'nb', const uint16_t *'src');
	void write_register(int 'addr', int 'value');
	void write_bits(int 'addr', int 'nb', const uint8_t *'src');
	void write_bit(int 'addr', int 'status');

	void ping();

	short get_moduleID();
	void set_moduleID(short 'ID');

	string get_moduleIP();
	void set_moduleIP(string 'IP');

	short get_modulePort();
	void set_modulePort(short 'Port');

}