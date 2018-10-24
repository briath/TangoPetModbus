

class PetException: public std::exception{
public:
	PetException(const int err, std::string str);

	virtual const char* what() const throw();

private:
	const int error;
	std::string str_err;
};