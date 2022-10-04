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
	Speaker() {
		cout << "The constructor without parameters of the class Speaker is called" << endl;
	}
	Speaker(const string& last_name_, const string& first_name_, const string& patronymic_,
		const string& organization_, const string& report_, const string& abstract_report_)
	{
		cout << "The constructor with the parameters of the class Speaker is called" << endl;
		last_name = last_name_;
		first_name = first_name_;
		patronymic = patronymic_;
		organization = organization_;
		report = report_;
		abstract_report = abstract_report_;
	}
	Speaker(const Speaker& that) {
		cout << "The copy constructor of the class Speaker is called" << endl;
		last_name = that.last_name;
		first_name = that.first_name;
		patronymic = that.patronymic;
		organization = that.organization;
		report = that.report;
		abstract_report = that.abstract_report;
	}
	~Speaker() {
		cout << "The deconstructor of the class Speaker is called" << endl;
	}

	void set_full_name(const string& last_name_, const string& first_name_, const string& patronymic_) {
		last_name = last_name_;
		first_name = first_name_;
		patronymic = patronymic_;
	}
	void set_organization(const string& organization_) {
		organization = organization_;
	}
	void set_report_and_abstract(const string& report_, const string& abstract_report_) {
		report = report_;
		abstract_report = abstract_report_;
	}

	string get_last_name() const { return last_name; }
	string get_first_name() const { return first_name; }
	string get_patronymic() const { return patronymic; }
	string get_organization() const { return organization; }
	string get_report() const { return report; }
	string get_abstract_report() const { return abstract_report; }

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
};

#endif //SPEAKER_HPP