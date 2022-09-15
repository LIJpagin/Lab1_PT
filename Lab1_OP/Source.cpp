//Класс Конференция содержит данные о выступающих, администрации и
//программе. Для выступающих определено : ФИО, организация / ВУЗ, доклад,
//аннотация доклада.Для администрации определено : ФИО, должность, область
//ответственности на конференции.Для программы определено : день, время
//выступлений и наименование.

#include "Keeper.hpp"

class Conference {
	virtual void show() = 0;
	virtual Conference* get() = 0;
	virtual void set() = 0;
	virtual ~Conference();
};

class Speaker : public Conference {

};

class Administration : public Conference {

};

class Programme : public Conference {

};

int main() {

	return 0;
}