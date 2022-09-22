#pragma once
#ifndef PROGRAMME_HPP
#define PROGRAMME_HPP

#include "Conference.hpp"

#include <string>

class Programme : public Conference {
public:
	std::string name;
	unsigned short day{ 0 };
	unsigned short month{ 0 };
	unsigned int year{ 0 };
	unsigned short hour{ 0 };
	unsigned short minute{ 0 };

	void print() {
		std::cout << "Programme" << std::endl;
		std::cout << "Name: " << name << std::endl;
		std::cout << "Date: " << day << "." << month << "." << year << std::endl;
		std::cout << "Time: " << hour << ":" << minute << std::endl << std::endl;
	}
	std::string save() {
		return "programme/" + name + "/" + std::to_string(day) + "/"
			+ std::to_string(year) + "/" + std::to_string(hour) + "/"
			+ std::to_string(minute);
	}
	void load(std::string in) {

	}
};

#endif //PROGRAMME_HPP