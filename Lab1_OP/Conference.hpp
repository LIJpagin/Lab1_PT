#pragma once
#ifndef CONFERENCE_HPP
#define CONFERENCE_HPP

#include <string>

class Conference {
public:
	virtual void print() = 0;
	virtual std::string save() = 0;
	virtual void load(std::string) = 0;
};

#endif //CONFERENCE_HPP