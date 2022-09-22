#pragma once
#ifndef ADMINISTRATION_HPP
#define ADMINISTRATION_HPP

#include "Conference.hpp"

#include <string>

class Administration : public Conference {
public:
	std::string last_name;
	std::string first_name;
	std::string patronymic;
	std::string position;
	std::string area_responsibility;

	void print() {
		std::cout << "Administration" << std::endl;
		std::cout << "Full name: " << last_name << " " << first_name << " " << patronymic << std::endl;
		std::cout << "Position: " << position << std::endl;
		std::cout << "Area responsibility: " << area_responsibility << std::endl << std::endl;
	}
	std::string save() {
		return "administration/" + last_name + "/" + first_name + "/" + patronymic
			+ "/" + position + "/" + area_responsibility;
	}
	void load(std::string in) {

	}
};

#endif //ADMINISTRATION_HPP