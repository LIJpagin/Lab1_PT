// Класс Конференция содержит данные о выступающих, администрации и программе.
// Для выступающих определено: ФИО, организация / ВУЗ, доклад, аннотация доклада.
// Для администрации определено: ФИО, должность, область ответственности на конференции.
// Для программы определено: день, время выступлений и наименование.

#include "List.hpp"
#include <iostream>

class Conference {
	virtual void show() = 0;
	virtual Conference* get() = 0;
	virtual void set() = 0;
	virtual ~Conference();
};

//class Speaker : public Conference {
//
//};
//
//class Administration : public Conference {
//
//};
//
//class Programme : public Conference {
//
//};

int main() {
	List<int> list;
	list.add_end(1);
	list.add_end(2);
	list.add_end(3);
	list.add_end(4);
	for (int i = 0; i < list.size(); i++)
		std::cout << list.get(i) << std::endl;
	return 0;
}