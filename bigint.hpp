#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <cstddef>
#include <cctype>
#include <stdexcept>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>

class bigint
{
	private:
		std::string	nbr;
	public:
		bigint();
		~bigint();
		bigint(const bigint &ref);
		bigint(uint64_t start);
		bigint(const std::string &start);
		bigint(char const *start);
		bigint		operator+(const bigint &ref) const;
		bigint		operator+(const std::string &str) const;
		bigint		operator+(char const *str) const;
		bigint		operator+(uint64_t digit) const;
		bigint		operator-(const bigint &ref) const;
		bigint		operator-(const std::string &str) const;
		bigint		operator-(char const *str) const;
		bigint		operator-(uint64_t digit) const;
		bigint		operator*(const bigint &ref) const;
		bigint		operator*(const std::string &str) const;
		bigint		operator*(char const *str) const;
		bigint		operator*(uint64_t digit) const;
		bigint		operator/(const bigint &ref) const;
		bigint		operator/(const std::string &str) const;
		bigint		operator/(char const *str) const;
		bigint		operator/(uint64_t digit) const;
		bigint		operator>>(const std::size_t &times) const;
		bigint		operator<<(const std::size_t &times) const;
		bool		operator==(const bigint &clone) const;
		bool		operator!=(const bigint &clone) const;
		bool		operator<(const bigint &clone) const;
		bool		operator>(const bigint &clone) const;
		bool		operator==(const std::string &clone) const;
		bool		operator!=(const std::string &clone) const;
		bool		operator<(const std::string &clone) const;
		bool		operator>(const std::string &clone) const;
		bool		operator==(uint64_t clone) const;
		bool		operator!=(uint64_t clone) const;
		bool		operator<(uint64_t clone) const;
		bool		operator>(uint64_t clone) const;
		bool		operator==(char const *clone) const;
		bool		operator!=(char const *clone) const;
		bool		operator<(char const *clone) const;
		bool		operator>(char const *clone) const;
		bigint		&operator=(const bigint &ref);
		bigint		&operator=(const std::string &str);
		bigint		&operator=(char const *str);
		bigint		&operator=(uint64_t digit);
		bigint		operator--(int n);
		bigint		operator++(int n);
		bigint		&operator++();
		bigint		&operator--();
		bigint		&operator<<=(const bigint &ref);
		bigint		&operator<<=(uint64_t ref);
		bigint		&operator<<=(const std::string &ref);
		bigint		&operator<<=(char const *str);
		bigint		&operator+=(const bigint &ref);
		bigint		&operator+=(uint64_t ref);
		bigint		&operator+=(char const *str);
		bigint		&operator+=(const std::string &ref);
		bigint		&operator*=(const bigint &ref);
		bigint		&operator*=(uint64_t ref);
		bigint		&operator*=(char const *str);
		bigint		&operator*=(const std::string &ref);
		bigint		&operator>>=(const bigint &ref) const;
		bigint		&operator>>=(uint64_t ref) const;
		bigint		&operator>>=(const std::string &ref) const;
		bigint		&operator>>=(char const *str) const;
		std::size_t	toSize_t() const;
};

std::ostream &operator<<(std::ostream &out, const bigint &big);
