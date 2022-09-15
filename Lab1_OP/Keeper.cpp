#include "Keeper.hpp"
#include <iostream>

template <class Type>
bool Keeper<Type>::correct_index(int index) {
	return index < 0 || index >= m_size;
}
template <class Type>
Item<Type>* Keeper<Type>::move(int index) {
	bool is_begin = index < (m_size - 1) / 2;
	Item<Type>* ptr = is_begin ? m_beg : m_end;
	for (size_t i = 0; i <= is_begin ? index : m_size - index; i++)
		ptr = is_begin ? ptr->next : ptr->prev;
	return ptr;
}

template <class Type>
bool Keeper<Type>::is_empty() const {
	return !m_size;
}
template <class Type>
int Keeper<Type>::size() const {
	return m_size;
}

template <class Type>
void Keeper<Type>::add_end(Type data) {
	try {
		Item<Type>* temp = new Item<Type>;
		temp->data = data;
		if (!m_beg)
			m_beg = m_end = temp;
		else {
			m_end->next = temp;
			temp->prev = m_end;
			m_end = temp;
		}
		m_size++;
	}
	catch (const std::bad_alloc& error) {
		std::cout << "Error: " << error.what() << std::endl;
	}
}
template <class Type>
void Keeper<Type>::add_begin(Type data) {
	try {
		Item<Type>* temp = new Item<Type>;
		temp->data = data;
		if (!m_beg)
			m_beg = m_end = temp;
		else {
			temp->next = m_beg;
			m_beg->prev = temp;
			m_beg = temp;
		}
		m_size++;
	}
	catch (const std::bad_alloc& error) {
		std::cout << "Error: " << error.what() << std::endl;
	}
}

template <class Type>
Type Keeper<Type>::get(int index) const {
	if (!correct_index(index))
		throw new std::exception("");
	return move(index)->data;
}
template <class Type>
void Keeper<Type>::set(Type data, int index) {
	if (!correct_index(index))
		throw new std::exception("");
	move(index)->data = data;
}

template <class Type>
void Keeper<Type>::erase(int index) {
	if (!correct_index(index))
		throw new std::exception("");
	Item<Type>* temp = move(index);
	(temp->next)->prev = temp->prev;
	(temp->prev)->next = temp->next;
	delete temp;
}
template <class Type>
void Keeper<Type>::clear() {
	Item<Type>* temp;
	while (m_beg != nullptr) {
		temp = m_beg;
		m_beg = m_beg->next;
		delete temp;
	}
	m_end = nullptr;
}