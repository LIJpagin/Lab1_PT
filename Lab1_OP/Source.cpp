//����� ����������� �������� ������ � �����������, ������������� �
//���������. ��� ����������� ���������� : ���, ����������� / ���, ������,
//��������� �������.��� ������������� ���������� : ���, ���������, �������
//��������������� �� �����������.��� ��������� ���������� : ����, �����
//����������� � ������������.

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