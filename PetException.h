#ifndef PETEXCEPTION_H
#define PETEXCEPTION_H
#include <exception>
#include <string>

class PetException: public std::exception{
public:
	PetException(int err, std::string str);

	const char* what() const throw();

private:
	int error;
	std::string str_err;
};
#endif // PETEXCEPTION_H