#ifndef _LIST_H
#define _LIST_H

#include <iostream>
#include <locale.h>


template <class Type> // шаблон для использования любого типа данных    
class List {
	struct ListItem;  //элемент списка
	ListItem* head; // указатель головы списка
	size_t size; // размер списка
public:
	List() : head(nullptr), size(0) {}; // конструктор для инициализации

	void append(size_t idx, const Type& value)  // вставка в любой индекс 
	{
		ListItem* new_item = new ListItem{ value }; // выделение динамической памяти для нового элемента 

		if (!empty())
		{
			idx %= size;
			ListItem* insert = head;
			for (size_t it = 0; it < idx; ++it) //переход к индексу
				insert = insert->_next;

			new_item->_next = insert;
			new_item->_prev = insert->_prev;
			insert->_prev->_next = new_item;
			insert->_prev = new_item;

			if (!idx)
			{
				head = new_item;
			}
		}
		else
		{
			head = new_item;
			new_item->_next = new_item;
			new_item->_prev = new_item;
		}
		++size;
	}

	void erase() // выборка из начала 
	{
		if (empty()) // список пуст
		{
			std:: cout << "Нельзя выбрать из пустого списка" << std::endl;
			return;
		}
		

		if (head == head->_prev) // в списке 1 элемент 
		{
			clear();
			return;
		}

		ListItem* next = head->_next, * prev = head->_prev;
		prev->_next = next;
		next->_prev = prev;

		head->_next = nullptr;
		delete head;

		head = next;
		--size;
	}

	bool empty() const // флаг пустоты 
	{
		if (head)
			return false;
		return true;
	}

	void clear()   // очистка списка  
	{
		if (empty())
			return;

		head->_prev->_next = nullptr;
		delete head;
		head = nullptr;
		size = 0;
	}

	void search(const Type& value) // поиск указанного значения в списке
	{
		if (empty())
			return;
		else
		{
			ListItem* iterator = head;
			for (size_t it = 0; it < size; ++it)
			{
				if (iterator->_data == value)
				{
					std::cout << "Item found: [" << it << "] " << std::endl;
				}
				iterator = iterator->_next; // переход к следующему элементу списка
			}
		}
	}



	template <class T>
	friend std::ostream& operator<<(std::ostream&, const List<T>&);  // прототип перегрузки оператора вывода

	~List() // деструктор списка
	{
		clear();
		if (empty()) 
		{
			std::cout << "\nСписок пуст!";
		}
	}
};

template<class Type>
std::ostream& operator<<(std::ostream& os, const List<Type>& list) // перегрузка оператора вывода для списка 
{
	const typename List<Type>::ListItem* iterator = list.head;
	for (size_t it = 0; it < list.size; ++it)
	{
		os << '[' << it << "] " << *iterator << std::endl;
		iterator = iterator->_next;
	}
	
	return os;
}





template <class Type>
struct List<Type>::ListItem // структура элемента в классе Список 
{
	Type _data = Type(); // определение типа поля соответственно заданному при объявлении List
	ListItem* _next = nullptr; // указатель на следующий элемент
	ListItem *_prev = nullptr; // указатель на предыдущий элемент

	friend std::ostream& operator<<(std::ostream& os, const ListItem& item) // перегрузка оператора вывода для элемента
	{
		os << item._data; // при вызове оператора << выводить поле .data 
		return os;
	}

	~ListItem() // деструктор. В случае удаления  удалить следующий от него
	{
		delete _next;
	}
};



#endif