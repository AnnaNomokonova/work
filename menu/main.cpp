#pragma execution_character_set("utf-8")
#include <clocale>
#include <iostream>

#include "menu.hpp"
#include "menu_functions.hpp"
#include "menu_items.hpp"

int main() {
    const AnnaN::MenuItem* current = &AnnaN::MAIN;
    do {
        current = current->func(current);
    } while (true);

    return 0;
}
