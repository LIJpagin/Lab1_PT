#pragma once
#ifndef CONFERENCE_HPP
#define CONFERENCE_HPP

#include <string>

class Conference {
public:
	virtual void create() = 0;
	virtual void edit() = 0;
	virtual std::string print() = 0;
};

#endif //CONFERENCE_HPP