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
	string abstract;

public:
	Speaker() {
		cout << "The constructor without parameters of the class Speaker is called" << endl;
	}
	Speaker(const string& last_name_, const string& first_name_, const string& patronymic_,
		const string& organization_, const string& report_, const string& abstract_)
	{
		cout << "The constructor with the parameters of the class Speaker is called" << endl;
		last_name = last_name_;
		first_name = first_name_;
		patronymic = patronymic_;
		organization = organization_;
		report = report_;
		abstract = abstract_;
	}
	Speaker(const Speaker& that) {
		cout << "The copy constructor of the class Speaker is called" << endl;
		last_name = that.last_name;
		first_name = that.first_name;
		patronymic = that.patronymic;
		organization = that.organization;
		report = that.report;
		abstract = that.abstract;
	}
	~Speaker() {
		cout << "The deconstructor of the class Speaker is called" << endl;
	}

	void set_last_name(const string& last_name_) { last_name = last_name_; }
	void set_first_name(const string& first_name_) { first_name = first_name_; }
	void set_patronymic(const string& patronymic_) { patronymic = patronymic_; }
	void set_organization(const string& organization_) { organization = organization_; }
	void set_report(const string& report_) { report = report_; }
	void set_abstract(const string& abstract_) { abstract = abstract_; }

	string get_last_name() const { return last_name; }
	string get_first_name() const { return first_name; }
	string get_patronymic() const { return patronymic; }
	string get_organization() const { return organization; }
	string get_report() const { return report; }
	string get_abstract() const { return abstract; }

	void create() {
		cout << "Full name: ";
		cin >> last_name >> first_name >> patronymic;
		cin.ignore();
		cout << "Organization: ";
		getline(cin, organization);
		trim(organization);
		cout << "Report: ";
		getline(cin, report);
		trim(report);
		cout << "Abstract: ";
		getline(cin, abstract);
		trim(abstract);
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
			getline(cin, organization), trim(organization);
		else if (choice == items[5])
			getline(cin, report), trim(report);
		else if (choice == items[6])
			getline(cin, abstract), trim(abstract);
		print();
		system("pause");
	}
	string print() {
		return "Class: Speaker\nFull-name: " + last_name + " " + first_name + " " + patronymic +
			"\nReport: " + report + "\nAbstract: " + abstract + "\n";
	}
};

#endif //SPEAKER_HPP