#include "ImplLibModbus.h"
#include "PetExceprion.h"

int main()
{
	try{
		mb = new ImplLibModbus(1, 192.168.255.1, 502);
	} catch (PetExceprion e){
		printf("%s", e.what());
	}
  
  return 0;
}
