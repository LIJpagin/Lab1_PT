#pragma once
#ifndef SPEAKER_HPP
#define SPEAKER_HPP

#include "Conference.hpp"

#include <string>
#include <iostream>

class Speaker : public Conference {
public:
	std::string last_name;
	std::string first_name;
	std::string patronymic;
	std::string organization;
	std::string report;
	std::string abstract_report;

	void print() {
		std::cout << "Speaker" << std::endl;
		std::cout << "Full name: " << last_name << " " << first_name << " " << patronymic << std::endl;
		std::cout << "Organization: " << organization << std::endl;
		std::cout << "Report: " << report << std::endl;
		std::cout << "Abstract report: " << abstract_report << std::endl << std::endl;
	}
	std::string save() {
		return "speaker/" + last_name + "/" + first_name + "/" + patronymic
			+ "/"+ organization + "/" + report + "/" + abstract_report;
	}
	void load(std::string in) {

	}
};

#endif //SPEAKER_HPP