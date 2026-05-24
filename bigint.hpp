#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

class bigint
{
	private:
		std::string	nbr;
	public:
		bigint();
		~bigint();
		bigint(std::size_t n);
		bigint(const bigint &ref);

		std::string	getNbr() const;
		bigint		&operator=(const bigint &ref);
		bigint		operator+(const bigint &ref) const;
		bigint		&operator+=(const bigint &ref);
		bigint		operator++(int);
		bigint		&operator++();
		bigint		operator--(int);
		bigint		&operator--();
		bigint		operator<<(std::size_t n) const;
		bigint		operator>>(std::size_t n) const;
		bigint		&operator<<=(std::size_t n);
		bigint		&operator>>=(std::size_t n);
		bigint		operator<<(const bigint &ref) const;
		bigint		operator>>(const bigint &ref) const;
		bigint		&operator<<=(const bigint &ref);
		bigint		&operator>>=(const bigint &ref);
		bool		operator<(const bigint &ref) const;
		bool		operator>(const bigint &ref) const;
		bool		operator==(const bigint &ref) const;
		bool		operator!=(const bigint &ref) const;
		bool		operator<=(const bigint &ref) const;
		bool		operator>=(const bigint &ref) const;
};

std::ostream &operator<<(std::ostream &out, const bigint &ref);
