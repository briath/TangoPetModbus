#include "PetException.h"
#include <string>

PetException::PetException(int err, std::string str){
	error = err;
	str_err = str;
}

const char* PetException::what() const throw(){
	return ("Error " + std::to_string(error) + ": " + str_err + "\n").c_str();
}