#pragma once
#ifndef KEEPER_HPP
#define KEEPER_HPP

#include "List.hpp"
#include "Conference.hpp"
#include "Speaker.hpp"
#include "Administration.hpp"
#include "Programme.hpp"

#include <string>
#include <fstream>
#include <iostream>
#include <cctype>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Keeper : public List<Conference*> {
protected:
	string trim(string str) {
		size_t begin = str.find_first_not_of(' ');
		if (begin == std::string::npos) return "";
		size_t end = str.find_last_not_of(' ');
		size_t range = end - begin + 1;
		return str.substr(begin, range);
	}
	string split(string& str, char ch) {
		size_t sep = str.find(ch);
		if (sep == string::npos) return "";
		string sub = str.substr(0, sep);
		str.erase(0, sep + 1);
		sub = trim(sub);
		str = trim(str);
		return sub;
	}
	string lower_all(string str) {
		std::transform(str.begin(), str.end(), str.begin(), tolower);
		return str;
	}

public:
	void print() {
		Item<Conference*>* temp = m_beg;
		while (temp != nullptr) {
			cout << temp->data->print() << endl;
			temp = temp->next;
		}
	};
	void print(int index) {
		if (!correct_index(index))
			throw new std::exception("");
		cout << move(index)->data->print() << endl;
	}
	void save(string path) {
		std::ofstream file(path);
		Item<Conference*>* temp = m_beg;
		while (temp) {
			file << temp->data->print() << endl;
			temp = temp->next;
		}
		file.close();
	}
	void load(string path) {
		std::ifstream file(path);
		if (!file.is_open()) {
			cout << "Unable to open the file\n";
			return;
		}

		string line;
		size_t counter_object = 0;
		size_t counter_line = 0;
		Speaker* speaker = nullptr;
		Administration* administration = nullptr;
		Programme* programme = nullptr;
		while (getline(file, line)) {
			counter_line++;

			line = trim(line);
			if (line.empty()) continue;

			string field = split(line, ':');
			if (field.empty()) {
				cout << "A value \"" << line << "\" without a field. Line " << counter_line << endl;
				continue;
			}

			field = lower_all(field);
			string value = line;

			if (field == "class") {
				counter_object++;

				if (speaker) {
					add_end(speaker);
					speaker = nullptr;
				}
				if (administration) {
					add_end(administration);
					administration = nullptr;
				}
				if (programme) {
					add_end(programme);
					programme = nullptr;
				}

				value = lower_all(value);

				if (value == "speaker")
					speaker = new Speaker();
				if (value == "administration")
					administration = new Administration();
				if (value == "programme")
					programme = new Programme();
			}
			
			if (field == "full name") {
				if (speaker) {
					speaker->set_last_name(split(value, ' '));
					speaker->set_first_name(split(value, ' '));
					speaker->set_patronymic(value);

				}
				if (administration) {
					administration->set_last_name(split(value, ' '));
					administration->set_first_name(split(value, ' '));
					administration->set_patronymic(value);
				}
			}

			if (field == "organization") speaker->set_organization(value);
			if (field == "report") speaker->set_report(value);
			if (field == "abstract report") speaker->set_abstract_report(value);

			if (field == "position") administration->set_position(value);
			if (field == "area responsibility") administration->set_area_responsibility(value);

			if (field == "name") programme->set_name(value);
			if (field == "date") {
				int day = stoi(split(value, '.'));
				int month = stoi(split(value, '.'));
				int year = stoi(value);
				if (day >= 1 && day <= 31 && month >= 1 && month <= 12
					&& year >= 1900 && year <= 2100)
					programme->set_date(day, month, year);
				else
					cout << "Invalid value for the field \"date\". Line " << counter_line << endl;
			}
			if (field == "time") {
				int hour = stoi(split(value, ':'));
				int minute = stoi(value);
				if (hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59)
					programme->set_time(hour, minute);
				else
					cout << "Invalid value for the field \"time\". Line " << counter_line << endl;
			}
		}
		if (speaker) add_end(speaker);
		if (administration) add_end(administration);
		if (programme) add_end(programme);
		file.close();
	}
};

#endif //KEEPER_HPP