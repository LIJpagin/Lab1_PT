#pragma once
#ifndef PROGRAMME_HPP
#define PROGRAMME_HPP

#include "Conference.hpp"

#include <string>

class Programme : public Conference {
private:
	unsigned short day;
	unsigned short month;
	unsigned short year;
	unsigned short hour;
	unsigned short minute;
	std::string name;

public:
	Programme() {};
	~Programme() {};

};

#endif //PROGRAMME_HPP