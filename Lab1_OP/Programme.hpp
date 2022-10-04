#pragma once
#ifndef PROGRAMME_HPP
#define PROGRAMME_HPP

#include "Conference.hpp"
#include "CorrectInput.hpp"
#include "Menu.hpp"

#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Programme : public Conference {
private:
	string name;
	short day{ -1 };
	short month{ -1 };
	int year{ -1 };
	short hour{ -1 };
	short minute{ -1 };

public:
	Programme() {
		cout << "The constructor without parameters of the class Programme is called" << endl;
	}
	Programme(const string& name_, int day_, int month_, int year_, int hour_, int minute_) {
		cout << "The constructor with the parameters of the class Programme is called" << endl;
		name = name_;
		day = day_;
		month = month_;
		year = year_;
		hour = hour_;
		minute = minute_;
	}
	Programme(const Programme& that) {
		cout << "The copy constructor of the class Programme is called" << endl;
		name = that.name;
		day = that.day;
		month = that.month;
		year = that.year;
		hour = that.hour;
		minute = that.minute;
	}
	~Programme() {
		cout << "The deconstructor of the class Programme is called" << endl;
	}

	void set_name(const string& name_) {
		name = name_;
	}
	void set_date(int day_, int month_, int year_) {
		day = day_;
		month = month_;
		year = year_;
	}
	void set_time(int hour_, int minute_) {
		hour = hour_;
		minute = minute_;
	}

	string get_name() const { return name; }
	int get_day() const { return day; }
	int get_month() const { return month; }
	int get_year() const { return year; }
	int get_hour() const { return hour; }
	int get_minute() const { return minute; }

	void create() {
		cout << "Name: ";
		cin >> name;
		cout << "Day: ";
		day = correct_input<unsigned short>(1, 31);
		cout << "Month: ";
		month = correct_input<unsigned short>(1, 12);
		cout << "Year: ";
		year = correct_input<unsigned int>(2000, 3000);
		cout << "Hour: ";
		hour = correct_input<unsigned short>(0, 23);
		cout << "Minute: ";
		minute = correct_input<unsigned short>(0, 59);
	}
	void edit() {
		print();
		string items[] = {
			"Select the option to change",
			"Name",
			"Day",
			"Month",
			"Year",
			"Hour",
			"Minute",
			"Back" };
		string choice = menu(items, 6);
		system("cls");
		if (choice == items[5])
			return;
		print();
		cout << "Enter new value\n>>> ";
		if (choice == items[1])
			cin >> name;
		else if (choice == items[2])
			day = correct_input<unsigned short>(1, 31);
		else if (choice == items[3])
			month = correct_input<unsigned short>(1, 12);
		else if (choice == items[4])
			year = correct_input<unsigned int>(2000, 3000);
		else if (choice == items[5])
			hour = correct_input<unsigned short>(0, 23);
		else if (choice == items[5])
			minute = correct_input<unsigned short>(0, 59);
		print();
		system("pause");
	}
	string print() {
		return "Class: Programme\nName: " + name +
			"\nDate: " +
			(day < 10 ? "0" : "") + std::to_string(day) + "." +
			(month < 10 ? "0" : "") + std::to_string(month) + "." +
			std::to_string(year) + "\n" +
			"Time: " +
			(hour < 10 ? "0" : "") + std::to_string(hour) + "." +
			(minute < 10 ? "0" : "") + std::to_string(minute) + "\n";
	}
};

#endif //PROGRAMME_HPP