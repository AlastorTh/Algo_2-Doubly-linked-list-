#include <iostream>
#include "list.h"
#include <string>
#


int main() {
    List<std::string> list;

    std::string action;

    while (std::cin >> action) {
        if (action == "add") {
            size_t idx;
            std::string val;
            std::cin >> idx >> val;
            list.append(idx, val);
        } else if (action == "erase") {
            list.erase();
        } else if (action == "print") {
            std::cout << list;
        }
    }
    return 0;
}
