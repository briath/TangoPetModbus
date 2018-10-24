#include "PetException.h"
#include <string>

PetException::PetException(const int err, std::string str){
	error = err;
	str_err = str;
}

virtual const char* PetException::what() const throw(){
	return "Error №" + str::to_string(error) + ": " + str_err + "\n";
}