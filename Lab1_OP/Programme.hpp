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
	unsigned short day{ 0 };
	unsigned short month{ 0 }; 
	unsigned int year{ 0 };
	unsigned short hour{ 0 };
	unsigned short minute{ 0 };

public:
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
	void print() {
		cout << "Programme" << endl;
		cout << "\tName: " << name << endl;
		cout << "\tDate: " << (day < 10 ? "0" : "") << day << "."
			<< (month < 10 ? "0" : "") << month << "." << year << endl;
		cout << "\tTime: " << (hour < 10 ? "0" : "") << hour << ":"
			<< (minute < 10 ? "0" : "") << minute << endl << endl;
	}
	string save() {
		return "programme/" + name + "/" + std::to_string(day) + "/"
			+ std::to_string(year) + "/" + std::to_string(hour) + "/"
			+ std::to_string(minute);
	}
	void load(string in) {

	}
};

#endif //PROGRAMME_HPP