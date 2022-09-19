#pragma once
#ifndef SPEAKER_HPP
#define SPEAKER_HPP

#include "Conference.hpp"

#include <string>

class Speaker : public Conference {
private:
	std::string last_name;
	std::string first_name;
	std::string patronymic;
	std::string organization;
	std::string report;
	std::string abstract_report;

public:
	Speaker() {};
	~Speaker() {};

};

#endif //SPEAKER_HPP