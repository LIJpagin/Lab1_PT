#pragma once
#ifndef SPEAKER_HPP
#define SPEAKER_HPP

#include "Conference.hpp"
#include "CorrectInput.hpp"
#include "Menu.hpp"

#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Speaker : public Conference {
private:
	string last_name;
	string first_name;
	string patronymic;
	string organization;
	string report;
	string abstract_report;

public:
	void create() {
		string field;
		cout << "Last name: "; cin >> field;
		last_name = field;
		cout << "First name: "; cin >> field;
		first_name = field;
		cout << "Patronymic: "; cin >> field;
		patronymic = field;
		cout << "Organization: "; cin >> field;
		organization = field;
		cout << "Report: "; cin >> field;
		report = field;
		cout << "Abstract report: "; cin >> field;
		abstract_report = field;
	}
	void edit() {
		print();
		string items[] = {
			"Select the option to change",
			"Last name",
			"First name",
			"Patronymic",
			"Organization",
			"Report",
			"Abstract report",
			"Back" };
		string choice = menu(items, 8);
		system("cls");
		if (choice == items[7])
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
			organization = value;
		else if (choice == items[5])
			report = value;
		else if (choice == items[6])
			abstract_report = value;
		print();
		system("pause");
	}
	string print() {
		return "Class: Speaker\nLast name: " + last_name +
			"\nFirst name: " + first_name +
			"\nPatronymic: " + patronymic +
			"\nOrganization: " + organization +
			"\nReport: " + report +
			"\nAbstract report: " + abstract_report + "\n";
	}
	void load(string in) {

	}
};

#endif //SPEAKER_HPP