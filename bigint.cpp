#include "bigint.hpp"

bigint::bigint() { nbr = '0'; }
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

bigint bigint::operator+(const uint64_t &ref) const
{
	bigint a(*this), b(ref);
	bigint result = a + b;

	return result;
}

bigint bigint::operator+(const std::string &ref) const
{
	bigint a(*this), b(ref);
	bigint result = a + b;

	return result;
}

bigint bigint::operator+(const char *ref) const
{
	bigint a(*this), b(ref);
	bigint result = a + b;

	return result;
}

bigint bigint::operator-(const bigint &ref) const
{
	bigint		larger, smaller;
	bigint		result;
	uint64_t	carrier = 0, value = 0;
	std::size_t	j;
	uint64_t	a, b;

	if (*this < ref)
		std::runtime_error("Error: Subtraction would be negative (unsigned)");
	else
	{
		smaller = ref;
		larger = *this;
	}
	for (std::size_t i = 0; i < larger.nbr.size() - 1; i++)
	{
		a = larger.nbr[i] - '0';
		b = (i < smaller.nbr.size()) ? smaller.nbr[i] - '0' : 0;
		if (a - b - borrow > a)
		{
			value += 10;
			carrier = 1;
		}
		else
		{
			value = a - b - carrier;
			carrier = 0;
		}
		result.nbr.push_back(value + '0');
	}
	while (result.nbr.size() > 1 && result.nbr.back() == '0')
		result.nbr.pop_back();
	if (result.nbr.empty())
		result.nbr = '0';
	return result;
}

bigint &bigint::operator++()
{
	for (std::size_t i = 0; i < nbr.size(); i++)
	{
		if (nbr[i] == '9')
			nbr[i] = '0';
		else
		{
			nbr[i]++;
			return *this;
		}
	}
	nbr.push_back('1');
	return *this;
}

bigint bigint::operator++(int)
{
	bigint ref(*this);

	++(*this);
	return ref;
}

bigint bigint::operator--(int)
{
	bigint ref(*this);

	if (nbr.size() == 1 && nbr[0] == '0')
		throw std::runtime_error("Error: underflow");
	for (std::size_t i = 0; i < nbr.size(); i++)
	{
		if (nbr[i] == '0')
			nbr[i] = '9';
		else
		{
			nbr[i]--;
			break ;
		}
	}
	if (nbr.size() > 1 && nbr.back() == '0')
		nbr.pop_back();
	if (nbr.empty())
		nbr = '0';
	return ref;
}

bool bigint::operator<(const bigint &ref) const
{
	if (nbr.size() != ref.nbr.size())
		return nbr.size() < ref.nbr.size();
	for (std::size_t i = nbr.size(); i--;)
		if (nbr[i] != ref.nbr[i])
			return nbr[i] < ref.nbr[i];
	return nbr[0] < ref.nbr[0];
}
