#pragma once
#ifndef KEEPER_HPP
#define KEEPER_HPP

#include <fstream>

template <class Type>
struct Item {
	Type data;
	Item<Type>* next{ nullptr }, * prev{ nullptr };
};

template <class Type>
class Keeper {
private:
	Item<Type>* m_beg{ nullptr }, * m_end{ nullptr };
	int m_size{ 0 };
	bool correct_index(int index);
	Item<Type>* move(int index);

public:
	Keeper() {};
	~Keeper() { clear(); };

	int size() const;
	bool is_empty() const;

	void add_end(Type data);
	void add_begin(Type data);

	Type get(int index) const;
	void set(Type data, int index);

	void load(std::ofstream& file);
	void save(std::ifstream& file);

	friend std::ostream& operator<<(std::ostream& stream, const Keeper& cont);

	void erase(int index);
	void clear();
};

#endif //KEEPER_HPP