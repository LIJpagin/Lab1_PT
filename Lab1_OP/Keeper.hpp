#pragma once
#ifndef KEEPER_HPP
#define KEEPER_HPP

#include "List.hpp"
#include "Conference.hpp"

#include <string>
#include <fstream>
#include <iostream>

class Keeper : public List<Conference*> {
public:
	void print() {
		Item<Conference*>* temp = m_beg;
		while (temp != nullptr) {
			temp->data->print();
			temp = temp->next;
		}
	};
	void print(int index) {
		if (!correct_index(index))
			throw new std::exception("");
		move(index)->data->print();
	}
	void save(std::string path) {
		std::ofstream file(path);
		Item<Conference*>* temp = m_beg;
		while (temp) {
			file << temp->data->save() << std::endl;
			temp = temp->next;
		}
		file.close();
	}
	void load(std::string path) {
		std::ifstream file(path);
		std::string temp;
		clear();
		while (getline(file, temp)) {
			
		}
		file.close();
	}
};

#endif //KEEPER_HPP