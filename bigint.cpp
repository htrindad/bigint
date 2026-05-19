#include "bigint.hpp"

bigint::bigint() { nbr = "0"; }
bigint::~bigint() {}
bigint::bigint(const bigint &ref) { nbr = ref.nbr; }
bigint::bigint(const uint64_t &start)
{
	std::string tmp;

	tmp = ultoa(start);
	for (std::size_t i = tmp.size() - 1; i; i--)
		nbr += tmp[i];
}
bigint::bigint(const std::string &start)
{
	std::string tmp;

	if (start.empty())
		throw std::runtime_error("Error: empty string");
	for (std::size_t i = 0; i < start.size(); i++)
		if (!std::isdigit(start[i]))
			throw std::runtime_error("Error: bad input");
	for (std::size_t i = start.size(); i; i--)
		tmp += start[i];
	nbr = tmp;
}
bigint::bigint(const char *start)
{
	std::size_t i = 0;
	std::string tmp;

	if (start == NULL)
		throw std::runtime_error("Error: NULL value");
	while (start[i])
		if (!std::isdigit(start[i++]))
			throw std::runtime_error("Error: bad input");
	while (i)
		tmp += start[i--];
	nbr = tmp;
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

bigint bigint::operator+(const bigint &ref) const
{
	bigint		result;
	std::size_t	i = 0;
	uint8_t		carry = 0, sum = 0;

	while (i < nbr.size() || i < ref.nbr.size() || carry)
	{
		sum = carry;
		if (i < nbr.size()) sum += nbr[i] - '0';
		if (i < ref.nbr.size()) sum += ref.nbr[i] - '0';
		result.nbr.push_back((sum % 10) + '0');
		carry = sum / 10;
		i++;
	}
	return result;
}

bigint bigint::operator+(const uint64_t &ref)
{
	bigint a(*this), b(ref);
	bigint result = a + b;

	return result;
}

bigint bigint::operator+(const std::string &ref)
{
	bigint a(*this), b(ref);
	bigint result = a + b;

	return result;
}

bigint bigint::operator+(const char *ref)
{
	bigint a(*this), b(ref);
	bigint result = a + b;

	return result;
}

bigint bigint::operator-(const bigint &ref) const
{
	bigint	result;

}
