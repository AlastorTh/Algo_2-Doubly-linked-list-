#include <iostream>
#include "list.h"
#include <string>


int main() {
    List<std::string> list;

    std::string action;

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
            std::cout << list;
        }
		if (action == "clear") 
		{
			list.clear();
		}
		
		if (action == "search") 
		{
			std::string value;
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
