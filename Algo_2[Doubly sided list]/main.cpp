#include <iostream>
#include "list.h"
#include <string>


int main() 
{
	setlocale(LC_ALL, "RUS");
    List<std::string> list;

    std::string action;

	std::cout << "---Программа работы с двусвязным кольцевым списком!---\n";
	std::cout << "Доступные команды: \nadd (индекс) (значение) - внесение значения в соотв. индекс" << std::endl;
	std::cout << "erase- удаление из начала" << std::endl;
	std::cout << "print- распечатка элементов списка и индексов" << std::endl;
	std::cout << "clear- очистка списка" << std::endl;
	std::cout << "search- поиск значения и вывод его индекса" << std::endl;
	std::cout << "search- поиск значения и вывод его индекса" << std::endl;
	std::cout << "exit- выход из программы" << std::endl;
	
    while (std::cin >> action) 
	{
        if (action == "add") 
		{
            size_t idx;
            std::string val;
            std::cin >> idx >> val;
            list.append(idx, val);
        }
		else if (action == "erase")
        {
            list.erase();
			
        } 
		else if (action == "print")
		{
			if (list.empty()) 
			{
				std::cout << "Список пуст!" << std::endl;
			}
            std::cout << list;
        }
		if (action == "clear") 
		{
			list.clear();
			if (list.empty()) 
			{
				std::cout << "Cписок пуст!" << std::endl;
			}
		}
		
		if (action == "search") 
		{
			std::string value;
			std::cout << "Введите искомое значение" << std::endl;
			std::cin >> value;
			list.search(value);
		}
		if (action == "exit") 
		{
			return 0;
		}
    }
    return 0;
}
