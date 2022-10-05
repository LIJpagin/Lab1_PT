#include "Keeper.hpp"
#include "Conference.hpp"
#include "Speaker.hpp"
#include "Administration.hpp"
#include "Programme.hpp"
#include "Menu.hpp"
#include "CorrectInput.hpp"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void menu_create(Keeper& keeper) {
	string items[] = {
		"Choose which record to create",
		"Speaker",
		"Administration",
		"Programme",
		"Back" };
	string choice = menu(items, 5);
	system("cls");

	if (choice == items[4]) return;
	Conference* record = nullptr;
	cout << "Enter the following fields\n";
	if (choice == items[1])
		record = new Speaker();
	else if (choice == items[2])
		record = new Administration();
	else if (choice == items[3])
		record = new Programme();
	record->create();
	system("pause"), system("cls");

	string items2[] = {
		"Choose where to add an entry",
		"To the beginning",
		"By index",
		"To the end" };
	choice = menu(items2, 4);

	if (choice == items2[1])
		keeper.add_begin(record);
	else if (choice == items2[2]) {
		cout << "Enter the record index\n";
		int index = correct_input<int>(1, keeper.size() - 1);
		keeper.insert(index, record);
	}
	else if (choice == items2[3])
		keeper.add_end(record);
}
void menu_show(Keeper& keeper) {
	if (keeper.is_empty()) {
		cout << "The keeper is empty, first create an entry\n";
		system("pause");
		return;
	}
	string items[] = {
		"Select an action",
		"Show record by index",
		"Show all records",
		"Back" };
	string choice = menu(items, 4);
	system("cls");

	if (choice == items[1]) {
		cout << "Enter the record index\n>>> ";
		int index = correct_input<int>(0, keeper.size() - 1);
		keeper.print(index);
	}
	else if (choice == items[2])
		keeper.print();
	else if (choice == items[3])
		return;
	system("pause");
}
void menu_del(Keeper& keeper) {
	if (keeper.is_empty()) {
		cout << "The keeper is empty, no deletion required\n";
		system("pause");
		return;
	}
	string items[] = {
		"Select an action",
		"Delete an record by index",
		"Delete all records",
		"Back" };
	string choice = menu(items, 4);
	system("cls");

	if (choice == items[1]) {
		cout << "Enter the record index\n";
		int index = correct_input<int>(1, keeper.size() - 1);
		keeper.erase(index);
	}
	else if (choice == items[2])
		keeper.clear();
	else if (choice == items[3])
		return;
}



static int codepage_is_set = chcp(1251);

int main() {
	hide_cursor();
	Keeper keeper;
	while (true) {
		string items[] = {
			"Select an action",
			"Create",
			"Edit",
			"Show",
			"Upload",
			"Save",
			"Delete",
			"Quit" };
		string choice = menu(items, 8);
		system("cls");

		if (choice == items[1])
			menu_create(keeper);
		else if (choice == items[2]) {
			if (keeper.is_empty()) {
				cout << "The keeper is empty, first edit an entry\n";
				system("pause");
			}
			else {
				cout << "Enter the record index\n";
				int index = correct_input<int>(0, keeper.size() - 1);
				keeper.get(index)->edit();
			}
		}
		else if (choice == items[3])
			menu_show(keeper);
		else if (choice == items[4]) {
			cout << "Enter the path and/or name of the file to download\n";
			string path; cin >> path;
			keeper.load(path);
			system("pause");
		}
		else if (choice == items[5]) {
			if (keeper.is_empty()) {
				cout << "The keeper is empty, first create an entry\n";
				system("pause");
			}
			else {
				cout << "Enter the path and/or name of the file to save\n>>> ";
				string path; cin >> path;
				keeper.save(path);
			}
		}
		else if (choice == items[6])
			menu_del(keeper);
		else if (choice == items[7])
			exit(0);

		system("cls");
	}
	return 0;
}