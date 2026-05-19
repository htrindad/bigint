#include "bigint.hpp"

bigint::bigint() { nbr = "0"; }
bigint::~bigint() {}
bigint::bigint(const bigint &ref) { nbr = ref.nbr; }
bigint::bigint(const uint64_t &start) { nbr = ultoa(start); }
bigint::bigint(const std::string &start)
{
	for (std::size_t i = 0; i < start.size(); i++)
		if (!std::isdigit(start[i]))
			throw std::runtime_error("Error: bad input");
	nbr = start;
}
bigint::bigint(const char *start)
{
	for (std::size_t i = 0; start[i]; i++)
		if (!std::isdigit(start[i]))
			throw std::runtime_error("Error: bad input");
	nbr = start;
}

bigint &bigint::operator=(const bigint &ref)
{
	nbr = ref.nbr;
	return *this;
}

bigint &bigint::operator=(const std::string &str)
{
	*this = bigint(str);
	return *this;
}

bigint &bigint::operator=(const char *str)
{
	*this = bigint(str);
	return *this;
}

bigint &bigint::operator=(const uint64_t &digit)
{
	*this = bigint(digit);
	return *this;
}

bigint &bigint::operator+(const bigint &ref)
{

}

bigint &bigint::operator+(const uint64_t &ref)
{

}

bigint &bigint::operator+(const std::string &ref)
{

}

bigint &bigint::operator+(const char *ref)
{

}
