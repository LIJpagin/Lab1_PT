#include "Keeper.hpp"
#include "Conference.hpp"
#include "Speaker.hpp"
#include "Administration.hpp"
#include "Programme.hpp"
#include "CorrectInput.hpp"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void menu_create(Keeper& keeper) {
	cout <<
		"Choose which record to create\n"
		" 1. Speaker\n"
		" 2. Administration\n"
		" 3. Programme\n"
		" 0. Back\n"
		">>> ";
	int choice = correct_input<int>(0, 3);
	system("cls");
	if (!choice) return;


	Conference* record = new Speaker();
	std::string field;
	cout << "Enter the following fields\n";
	switch (choice) {
	case 1: {
		Speaker* speaker = new Speaker();
		cout << "Last name: "; cin >> field;
		speaker->last_name = field;
		cout << "First name: "; cin >> field;
		speaker->first_name = field;
		cout << "Patronymic: "; cin >> field;
		speaker->patronymic = field;
		cout << "Organization: "; cin >> field;
		speaker->organization = field;
		cout << "Report: "; cin >> field;
		speaker->report = field;
		cout << "Abstract report: "; cin >> field;
		speaker->abstract_report = field;
		record = speaker;
	} break;
	case 2: {
		Administration* administration = new Administration();
		cout << "Last name: "; cin >> field;
		administration->last_name = field;
		cout << "First name: "; cin >> field;
		administration->first_name = field;
		cout << "Patronymic: "; cin >> field;
		administration->patronymic = field;
		cout << "Position: "; cin >> field;
		administration->position = field;
		cout << "Area responsibility: "; cin >> field;
		administration->area_responsibility = field;
		record = administration;
	} break;
	case 3: {
		Programme* programme = new Programme();
		cout << "Name: "; cin >> field;
		programme->name = field;
		cout << "Day: ";
		programme->day = correct_input<unsigned short>(1, 31);
		cout << "Month: ";
		programme->month = correct_input<unsigned short>(1, 12);
		cout << "Year: ";
		programme->year = correct_input<unsigned int>(2000, 3000);
		cout << "Hour: ";
		programme->hour = correct_input<unsigned short>(0, 23);
		cout << "Minute: "; cin >> field;
		programme->minute = correct_input<unsigned short>(0, 59);
		record = programme;
	} break;
	}
	system("pause");
	system("cls");



	cout <<
		"Choose where to add an entry\n"
		" 1. To the beginning\n"
		" 2. By index\n"
		" 3. To the end\n"
		">>> ";
	choice = correct_input<int>(1, 3);



	switch (choice) {
	case 1:
		keeper.add_begin(record);
		break;
	case 2:
		cout << "Enter the record ID\n>>> ";
		choice = correct_input<int>(1, keeper.size() - 1);
		keeper.insert(choice, record);
		break;
	case 3:
		keeper.add_end(record);
		break;
	}

}
void menu_show(Keeper& keeper) {
	if (keeper.is_empty()) {
		cout << "The keeper is empty, first create an entry\n";
		return;
	}
	cout <<
		"Select an action\n"
		" 1. Show record by ID\n"
		" 2. Show all records\n"
		" 0. Back\n"
		">>> ";
	int choice = correct_input<int>(0, 2);
	system("cls");
	switch (choice) {
	case 1:
		cout << "Enter the record ID\n>>> ";
		choice = correct_input<int>(0, keeper.size() - 1);
		keeper.print(choice);
		break;
	case 2:
		keeper.print();
		break;
	case 0:
		return;
		break;
	}
}
void menu_del(Keeper& keeper) {
	if (keeper.is_empty()) {
		cout << "The keeper is empty, no deletion required\n";
		return;
	}
	std::cout <<
		"Select an action\n"
		" 1. Delete an record by ID\n"
		" 2. Delete all records\n"
		" 0. Back\n"
		">>> ";
	int choice = correct_input<int>(0, 2);
	system("cls");
	switch (choice) {
	case 1:
		cout << "Enter the record ID\n>>> ";
		choice = correct_input<int>(1, keeper.size() - 1);
		keeper.erase(choice);
		break;
	case 2:
		keeper.clear();
		break;
	case 0:
		return;
		break;
	}
}

int main() {
	Keeper keeper;
	int choice;
	std::string path;
	while (true) {
		std::cout <<
			"Select an action\n"
			"+1. Create\n"
			"-2. Edit\n"
			"+3. Show\n"
			"/4. Upload\n"
			"+5. Save\n"
			"+6. Delete\n"
			" 0. Quit\n"
			">>> ";
		choice = correct_input<int>(0, 6);
		system("cls");
		switch (choice) {
		case 1:
			menu_create(keeper);
			break;
		case 2:

			break;
		case 3:

			menu_show(keeper);
			break;
		case 4:
			cout <<
				"Are you sure you want to download the recordings from the file?\n"
				"If you already have records in this session, they will be deleted\n"
				" 1. Upload\n"
				" 0. Back\n"
				">>> ";
			choice = correct_input<int>(0, 1);
			if (choice) {
				cout << "Enter the path and/or name of the file to download\n";
				cin >> path;
				keeper.load(path);
			}
			break;
		case 5:
			if (keeper.is_empty()) {
				cout << "The keeper is empty, first create an entry\n";
				break;
			}
			cout << "Enter the path and/or name of the file to save\n>>> ";
			cin >> path;
			keeper.save(path);
			break;
		case 6:
			menu_del(keeper);
			break;
		case 0:
			exit(0);
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}