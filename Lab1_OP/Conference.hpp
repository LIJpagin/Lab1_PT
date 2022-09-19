#pragma once
#ifndef CONFERENCE_HPP
#define CONFERENCE_HPP

class Conference {
	virtual void show() = 0;
	virtual Conference* get() = 0;
	virtual void set(Conference*) = 0;
};

#endif //CONFERENCE_HPP