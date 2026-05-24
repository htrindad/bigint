#include "bigint.hpp"

bigint::bigint() { nbr = "0"; }
bigint::~bigint() {}
bigint::bigint(std::size_t n)
{
	std::stringstream ss;

	ss << n;
	nbr = ss.str();
}
bigint::bigint(const bigint &ref) { nbr = ref.nbr; }
bigint &bigint::operator=(const bigint &ref)
{
	if (this == &ref)
		return *this;
	nbr = ref.nbr;
	return *this;
}

std::string	bigint::getNbr() const { return nbr; }

static std::string	reverse(const std::string &nbr)
{
	std::string rev;

	for (std::size_t i = nbr.length(); i; i--)
		rev.push_back(nbr[i - 1]);
	return rev;
}

static inline std::string	adding(const bigint &o1, const bigint &o2)
{
	std::string	strs[2] = { reverse(o1.getNbr()), reverse(o2.getNbr()) };
	std::string	result;
	std::size_t	len[2] = { strs[0].length(), strs[1].length() };
	int		diff, carry, res;
	int		d[2];

	if (len[0] > len[1])
	{
		diff = len[0] - len[1];
		while (diff > 0)
		{
			strs[1].push_back('0');
			diff--;
		}
	}
	else if (len[1] > len[0])
	{
		diff = len[1] - len[0]; 
		while (diff > 0)
		{
			strs[0].push_back('0');
			diff--;
		}
	}
	carry = 0;
	len[0] = strs[0].length();
	for (std::size_t i = 0; i < len[0]; i++)
	{
		d[0] = strs[0][i] - '0';
		d[1] = strs[1][i] - '0';
		res = d[0] + d[1] + carry;
		if (res > 9)
		{
			carry = res / 10;
			result.push_back((res % 10) + '0');
		}
		else
			result.push_back(res + '0');
	}
	if (carry)
		result.push_back(carry + '0');
	return reverse(result);
}

bigint bigint::operator+(const bigint &ref) const
{
	bigint		tmp(ref);
	std::string	res;

	tmp.nbr.clear();
	res = adding(*this, ref);
	tmp.nbr = res;
	return tmp;
}

bigint &bigint::operator+=(const bigint &ref)
{
	*this = *this + ref;
	return *this;
}

bigint &bigint::operator++()
{
	*this += bigint(1);
	return *this;
}

bigint bigint::operator++(int)
{
	bigint tmp = *this;

	++(*this);
	return tmp;
}

bigint bigint::operator<<(std::size_t n) const
{
	bigint tmp = *this;

	tmp.nbr.insert(tmp.nbr.end(), n, '0');
	return tmp;
}

bigint bigint::operator>>(std::size_t n) const
{
	bigint		tmp = *this;
	std::size_t	len = tmp.nbr.length();

	if (n >= len)
		tmp.nbr = "0";
	else
		tmp.nbr.erase(len - n, n);
	return tmp;
}

bigint &bigint::operator<<=(std::size_t n)
{
	*this = *this << n;
	return *this;
}

bigint &bigint::operator>>=(std::size_t n)
{
	*this = *this >> n;
	return *this;
}

static std::size_t toSize_t(const std::string &nbr)
{
	std::istringstream	ss(nbr);
	std::size_t		res;

	ss >> res;
	return res;
}

bigint bigint::operator<<(const bigint &ref) const
{
	bigint tmp;

	tmp = *this << toSize_t(ref.nbr);
	return tmp;
}

bigint bigint::operator>>(const bigint &ref) const
{
	bigint tmp;

	tmp = *this >> toSize_t(ref.nbr);
	return tmp;
}

bigint &bigint::operator<<=(const bigint &ref)
{
	*this = *this << toSize_t(ref.nbr);
	return *this;
}

bigint &bigint::operator>>=(const bigint &ref)
{
	*this = *this >> toSize_t(ref.nbr);
	return *this;
}

bool bigint::operator==(const bigint &ref) const { return nbr == ref.nbr; }

bool bigint::operator!=(const bigint &ref) const { return nbr != ref.nbr;}

bool bigint::operator<(const bigint &ref) const
{
	std::string	str[2] = { nbr, ref.nbr };
	std::size_t	len[2] = { nbr.length(), ref.nbr.length() };

	if (len[0] != len[1])
		return len[0] < len[1];
	return str[0] < str[1];
}

bool bigint::operator>(const bigint &ref) const { return !((*this < ref)); }

bool bigint::operator<=(const bigint &ref) const { return (((*this < ref) || (*this == ref))); }

bool bigint::operator>=(const bigint &ref) const { return (((*this > ref) || (*this == ref))); }

std::ostream &operator<<(std::ostream &out, const bigint &ref)
{
	out << ref.getNbr();
	return out;
}
