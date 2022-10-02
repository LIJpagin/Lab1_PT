#pragma once
#ifndef ADMINISTRATION_HPP
#define ADMINISTRATION_HPP

#include "Conference.hpp"
#include "CorrectInput.hpp"
#include "Menu.hpp"

#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Administration : public Conference {
private:
	std::string last_name;
	std::string first_name;
	std::string patronymic;
	std::string position;
	std::string area_responsibility;

public:
	void create() {
		string field;
		cout << "Last name: "; cin >> field;
		last_name = field;
		cout << "First name: "; cin >> field;
		first_name = field;
		cout << "Patronymic: "; cin >> field;
		patronymic = field;
		cout << "Position: "; cin >> field;
		position = field;
		cout << "Area responsibility: "; cin >> field;
		area_responsibility = field;
	}
	void edit() {
		print();
		string items[] = {
			"Select the option to change",
			"Last name",
			"First name",
			"Position",
			"Area responsibility",
			"Back" };
		string choice = menu(items, 6);
		system("cls");
		if (choice == items[5])
			return;
		print();
		cout << "Enter new value\n>>> ";
		string value; cin >> value;
		if (choice == items[1])
			last_name = value;
		else if (choice == items[2])
			first_name = value;
		else if (choice == items[3])
			patronymic = value;
		else if (choice == items[4])
			position = value;
		else if (choice == items[5])
			area_responsibility = value;
		print();
		system("pause");
	}
	string print() {
		return "Class: Administration\nLast name: " + last_name +
			"\nFirst name: " + first_name +
			"\nPatronymic: " + patronymic +
			"\nPosition: " + position +
			"\nArea responsibility: " + area_responsibility + "\n";
	}
	void load(string in) {

	}
};

#endif //ADMINISTRATION_HPP