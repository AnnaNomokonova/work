#pragma execution_character_set("utf-8")
#include <clocale>
#include <iostream>

#include "menu.hpp"
#include "menu_functions.hpp"
#include "menu_items.hpp"

int main() {
std::setlocale(LC_ALL, "");

const AnnaN::MenuItem* current = &main;
do {
current = current->(current);
} while (true);

return 0;
}

