#ifndef _LIST_H
#define _LIST_H

#include <iostream>

template <class Type>
class List {
    struct ListItem;
    ListItem *head;
    size_t size;
public:
    List() : head(nullptr), size(0) {};

    void append(size_t idx, const Type& value) {
        ListItem* new_item = new ListItem{value};

        if(!empty()) {
            idx %= size;
            ListItem* insert = head; 
            for (size_t it = 0; it < idx; ++it)
                insert = insert->_next;

            new_item->_next = insert;
            new_item->_prev = insert->_prev;
            insert->_prev->_next = new_item;
            insert->_prev = new_item;

            if (!idx) {
                 head = new_item;
            } 
        } else {
            head = new_item;
            new_item->_next = new_item;
            new_item->_prev = new_item;
        }
        ++size;
    }
    
    void erase() {
        if(empty())
            return;

        if (head == head->_prev) {
            clear();
            return;
        }

        ListItem *next = head->_next, *prev = head->_prev; 
        prev->_next = next;
        next->_prev = prev;

        head->_next = nullptr;
        delete head;

        head = next;
        --size;
    }

    bool empty() const {
        if (head)
            return false;
        return true;
    }
    
    void clear() {
        if (empty())
            return;

        head->_prev->_next = nullptr;
        delete head;
        head = nullptr;
        size = 0;
    }

	void search(const Type& value) 
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
				iterator = iterator->_next;
			}
		}
	}



    template <class T>
    friend std::ostream& operator<<(std::ostream&, const List<T>&);

    ~List() {
        clear();
    }
};

template<class Type>
std::ostream& operator<<(std::ostream& os, const List<Type>& list) {
    const typename List<Type>::ListItem* iterator = list.head;
    for (size_t it = 0; it < list.size; ++it) {
        os << '[' << it << "] " << *iterator << std::endl;
        iterator = iterator->_next;
    }
    return os;
}


template <class Type>
struct List<Type>::ListItem {
    Type _data = Type();
    ListItem *_next = nullptr, *_prev = nullptr;

    friend std::ostream& operator<<(std::ostream& os, const ListItem& item) {
         os << item._data;
        return os;
    }

    ~ListItem() {
        delete _next;
    }
};



#endif