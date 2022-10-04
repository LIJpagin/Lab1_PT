#pragma once
#ifndef KEEPER_HPP
#define KEEPER_HPP

#include "List.hpp"
#include "Conference.hpp"

#include <string>
#include <fstream>
#include <iostream>
#include <cctype>
#include <algorithm>

class Keeper : public List<Conference*> {
public:
	friend List;
	void print() {
		Item<Conference*>* temp = m_beg;
		while (temp != nullptr) {
			std::cout << temp->data->print() << std::endl;
			temp = temp->next;
		}
	};
	void print(int index) {
		if (!correct_index(index))
			throw new std::exception("");
		std::cout << move(index)->data->print() << std::endl;
	}
	void save(std::string path) {
		std::ofstream file(path);
		Item<Conference*>* temp = m_beg;
		while (temp) {
			file << temp->data->print();
			temp = temp->next;
		}
		file.close();
	}
	void load(std::string path) {
		std::ifstream file(path);
		if (!file.is_open()) {
			std::cout << "Unable to open the file\n";
			return;
		}
		std::string temp;
		while (getline(file, temp)) {
			size_t separator = temp.find(":");
			if (separator != std::string::npos)
				continue;
			std::transform(temp.begin(), temp.begin() + separator, temp.begin(), tolower);//TODO заменить
			if (temp.substr(0, separator) == "speaker") {

			}
		}
		file.close();
	}
};

#endif //KEEPER_HPP