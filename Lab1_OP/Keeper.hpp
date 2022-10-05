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

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Keeper : public List<Conference*> {
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
		size_t counter_object = 0, counter_line = 0, checksum = 0;
		Speaker* speaker = nullptr;
		Administration* administration = nullptr;
		Programme* programme = nullptr;

		while (getline(file, line)) {
			counter_line++;

			line = trim(line);
			if (line.empty()) continue;

			string field = lower_all(split(line, ':'));
			if (field.empty()) continue;

			string value = line;
			if (value.empty()) continue;

			if (!speaker && (field == "full name" | field == "organization" 
				|| field == "report" || field == "abstract"))
				speaker = new Speaker();
			if (!administration && (field == "full name"
				|| field == "position" || field == "responsibility"))
				administration = new Administration();
			if (!programme && (field == "name"
				|| field == "date" || field == "time"))
				programme = new Programme();

			if (field == "checksum") checksum = stoi(value);

			if (field == "full-name" && speaker) {
				speaker->set_last_name(split(value, ' '));
				if (value.empty()) continue;
				speaker->set_first_name(split(value, ' '));
				if (value.empty()) continue;
				speaker->set_patronymic(value);
			}
			if (field == "organization") speaker->set_organization(value);
			if (field == "report") speaker->set_report(value);
			if (field == "abstract") speaker->set_abstract(value);

			if (field == "full-name" && administration) {
				administration->set_last_name(split(value, ' '));
				if (value.empty()) continue;
				administration->set_first_name(split(value, ' '));
				if (value.empty()) continue;
				administration->set_patronymic(value);
			}
			if (field == "position") administration->set_position(value);
			if (field == "responsibility")
				administration->set_responsibility(value);

			if (field == "name") programme->set_name(value);
			if (field == "date") {
				int day = stoi(split(value, '.'));
				if (value.empty()) continue;
				int month = stoi(split(value, '.'));
				if (value.empty()) continue;
				int year = stoi(value);
				if (day >= 1 && day <= 31 && month >= 1 && month <= 12
					&& year >= 1900 && year <= 2100)
					programme->set_date(day, month, year);
			}
			if (field == "time") {
				int hour = stoi(split(value, ':'));
				if (value.empty()) continue;
				int minute = stoi(value);
				if (hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59)
					programme->set_time(hour, minute);
			}

			if (field == "class" || file.eof()) {
				if (speaker) add_end(speaker), speaker = nullptr;
				if (administration) add_end(administration), administration = nullptr;
				if (programme) add_end(programme), programme = nullptr;
				counter_object++;
			}
			if (field == "class") {
				value = lower_all(value);
				if (value == "speaker") speaker = new Speaker();
				if (value == "administration") administration = new Administration();
				if (value == "programme") programme = new Programme();
			}
		}
		file.close();
		print();
	}
};

#endif //KEEPER_HPP