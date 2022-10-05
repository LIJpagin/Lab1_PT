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
	Administration() {
		cout << "The constructor without parameters of the class Administration is called" << endl;
	}
	Administration(const string& last_name_, const string& first_name_, const string& patronymic_,
		const string& position_, const string& area_responsibility_)
	{
		cout << "The constructor with the parameters of the class Administration is called" << endl;
		last_name = last_name_;
		first_name = first_name_;
		patronymic = patronymic_;
		position = position_;
		area_responsibility = area_responsibility_;
	}
	Administration(const Administration& that) {
		cout << "The copy constructor of the class Administration is called" << endl;
		last_name = that.last_name;
		first_name = that.first_name;
		patronymic = that.patronymic;
		position = that.position;
		area_responsibility = that.area_responsibility;
	}
	~Administration() {
		cout << "The deconstructor of the class Administration is called" << endl;
	}

	void set_last_name(const string& last_name_) { last_name = last_name_; }
	void set_first_name(const string& first_name_) { first_name = first_name_; }
	void set_patronymic(const string& patronymic_) { patronymic = patronymic_; }
	void set_position(const string& position_) { position = position_; }
	void set_area_responsibility(const string& area_responsibility_) {
		area_responsibility = area_responsibility_;
	}

	string get_last_name() const { return last_name; }
	string get_first_name() const { return first_name; }
	string get_patronymic() const { return patronymic; }
	string get_position() const { return position; }
	string get_area_responsibility() const { return area_responsibility; }

	void create() {
		string field;
		cout << "Last name: ";
		cin >> last_name;
		cout << "First name: ";
		cin >> first_name;
		cout << "Patronymic: ";
		cin >> patronymic;
		cout << "Position: ";
		cin >> position;
		cout << "Area responsibility: ";
		cin >> area_responsibility;
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
		if (choice == items[1])
			cin >> last_name;
		else if (choice == items[2])
			cin >> first_name;
		else if (choice == items[3])
			cin >> patronymic;
		else if (choice == items[4])
			cin >> position;
		else if (choice == items[5])
			cin >> area_responsibility;
		print();
		system("pause");
	}
	string print() {
		return "Class: Administration\nFull name: " + last_name + " " + first_name + " " + patronymic +
			"\nPosition: " + position + "\nArea responsibility: " + area_responsibility + "\n";
	}
};

#endif //ADMINISTRATION_HPP