#pragma once
#ifndef ADMINISTRATION_HPP
#define ADMINISTRATION_HPP

#include "Conference.hpp"

#include <string>

class Administration : public Conference {
private :
	std::string last_name;
	std::string first_name;
	std::string patronymic;
	std::string position;
	std::string area_responsibility;

public:
	Administration() {};
	~Administration() {};

};

#endif //ADMINISTRATION_HPP