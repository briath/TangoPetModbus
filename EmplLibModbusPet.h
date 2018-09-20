#include 


class EmplLibModbusPet{

private:
	short moduleID;
	string moduleIP;
	short modulePort;


	void init(short, string, short);
	void delete();

public:
	EmplLibModbusPet(short, string, short);
	~EmplLibModbusPet();

}