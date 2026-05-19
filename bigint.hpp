#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <cstddef>
#include <cctype>
#include <stdexcept>
#include <stdint.h>
#include <stdlib.h>

class bigint
{
	private:
		std::string	nbr;
	public:
		bigint();
		~bigint();
		bigint(const bigint &ref);
		bigint(const uint64_t &start);
		bigint(const std::string &start);
		bigint(const char *start);
		bigint	operator+(const bigint &ref);
		bigint	operator+(const std::string &str);
		bigint	operator+(const char *str);
		bigint	operator+(const uint64_t &digit);
		bigint	operator-(const bigint &ref);
		bigint	operator-(const std::string &str);
		bigint	operator-(const char *str);
		bigint	operator-(const uint64_t &digit);
		bigint	operator*(const bigint &ref);
		bigint	operator*(const std::string &str);
		bigint	operator*(const char *str);
		bigint	operator*(const uint64_t &digit);
		bigint	operator/(const bigint &ref);
		bigint	operator/(const std::string &str);
		bigint	operator/(const char *str);
		bigint	operator/(const uint64_t &digit);
		bigint	operator>>(const std::size_t &times);
		bigint	operator<<(const std::size_t &times);
		bool	operator==(const bigint &clone);
		bool	operator!=(const bigint &clone);
		bool	operator<(const bigint &clone);
		bool	operator>(const bigint &clone);
		bool	operator==(const std::string &clone);
		bool	operator!=(const std::string &clone);
		bool	operator<(const std::string &clone);
		bool	operator>(const std::string &clone);
		bool	operator==(const uint64_t &clone);
		bool	operator!=(const uint64_t &clone);
		bool	operator<(const uint64_t &clone);
		bool	operator>(const uint64_t &clone);
		bool	operator==(const char *clone);
		bool	operator!=(const char *clone);
		bool	operator<(const char *clone);
		bool	operator>(const char *clone);
		bigint	&operator=(const bigint &ref);
		bigint	&operator=(const std::string &str);
		bigint	&operator=(const char *str);
		bigint	&operator=(const uint64_t &digit);
};

std::ostream &operator<<(std::ostream &out, const bigint &big);
