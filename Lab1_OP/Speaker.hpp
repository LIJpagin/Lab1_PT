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

	void set_last_name(const string& last_name_) { last_name = last_name_; }
	void set_first_name(const string& first_name_) { first_name = first_name_; }
	void set_patronymic(const string& patronymic_) { patronymic = patronymic_; }
	void set_organization(const string& organization_) { organization = organization_; }
	void set_report(const string& report_) { report = report_; }
	void set_abstract_report(const string& abstract_report_) {
		abstract_report = abstract_report_;
	}

	string get_last_name() const { return last_name; }
	string get_first_name() const { return first_name; }
	string get_patronymic() const { return patronymic; }
	string get_organization() const { return organization; }
	string get_report() const { return report; }
	string get_abstract_report() const { return abstract_report; }

	void create() {
		cout << "Last name: ";
		cin >> last_name;
		cout << "First name: ";
		cin >> first_name;
		cout << "Patronymic: ";
		cin >> patronymic;
		cout << "Organization: ";
		cin >> organization;
		cout << "Report: ";
		cin >> report;
		cout << "Abstract report: ";
		cin >> abstract_report;
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
		if (choice == items[1])
			cin >> last_name;
		else if (choice == items[2])
			cin >> first_name;
		else if (choice == items[3])
			cin >> patronymic;
		else if (choice == items[4])
			cin >> organization;
		else if (choice == items[5])
			cin >> report;
		else if (choice == items[6])
			cin >> abstract_report;
		print();
		system("pause");
	}
	string print() {
		return "Class: Speaker\nFull name: " + last_name + " " + first_name + " " + patronymic +
			"\nReport: " + report + "\nAbstract report: " + abstract_report + "\n";
	}
};

#endif //SPEAKER_HPP