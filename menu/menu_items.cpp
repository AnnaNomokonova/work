#include "menu_items.hpp"

#include <cstddef>

#include "menu_functions.hpp"

const AnnaN::MenuItem AnnaN::READ_PUSHKIN_DUBROVSKY = {
    "1 - Дубровский", AnnaN::read_pushkin_dubrovsky, &AnnaN::READ_PUSHKIN
};
const AnnaN::MenuItem AnnaN::READ_PUSHKIN_EVGENY_ONEGIN = {
    "2 - Евгений Онегин", AnnaN::read_pushkin_evgeny_onegin, &AnnaN::READ_PUSHKIN
};
const AnnaN::MenuItem AnnaN::READ_PUSHKIN_ZIMNY_VECHER = {
    "3 - Зимний вечер", AnnaN::read_pushkin_zimny_vecher, &AnnaN::READ_PUSHKIN
};
const AnnaN::MenuItem AnnaN::READ_PUSHKIN_GO_BACK = {
    "0 - Выйти в предыдущее меню", AnnaN::go_back, &AnnaN::READ_PUSHKIN
}; 

namespace {
   const AnnaN::MenuItem* const pushkin_children[] = {
        &AnnaN::READ_PUSHKIN_GO_BACK,
        &AnnaN::READ_PUSHKIN_DUBROVSKY,
        &AnnaN::READ_PUSHKIN_EVGENY_ONEGIN,
        &AnnaN::READ_PUSHKIN_ZIMNY_VECHER,
    };
    const int pushkin_size = sizeof(pushkin_children)/sizeof(pushkin_children[0]);
}

const AnnaN::MenuItem AnnaN::READ_PUSHKIN = {
    "1 - Читать Пушкина", AnnaN::show_menu, &AnnaN::READ, pushkin_children, pushkin_size
};
const AnnaN::MenuItem AnnaN::READ_LERMONTOW = {
    "2 - Читать Лермонтова", AnnaN::read_lermontow, &AnnaN::READ
};  
const AnnaN::MenuItem AnnaN::READ_KRYLOW = {
    "3 - Читать Крылова ", AnnaN::read_krylow, &AnnaN::READ
};
const AnnaN::MenuItem AnnaN::READ_GO_BACK = {
    "0 - Выйти в главное меню", AnnaN::go_back, &AnnaN::READ
};

namespace {
    const AnnaN::MenuItem* const read_children[] = {
        &AnnaN::READ_GO_BACK,
        &AnnaN::READ_PUSHKIN,
        &AnnaN::READ_LERMONTOW,
        &AnnaN::READ_KRYLOW

    };
    const int read_size = sizeof(read_children)/sizeof(read_children[0]);
}

const AnnaN::MenuItem AnnaN::READ = {
    "1 - Русские писатели", AnnaN::show_menu, &AnnaN::MAIN, read_children, read_size
};
const AnnaN::MenuItem AnnaN::EXIT = {
    "0 - Завершить чтение", AnnaN::exit, &AnnaN::MAIN 
}; 

namespace {
    const AnnaN::MenuItem* const main_children[] = {
        &AnnaN::EXIT,
        &AnnaN::READ
    };
    const int main_size = sizeof(main_children)/sizeof(main_children[0]);
}

const AnnaN::MenuItem AnnaN::MAIN = {
    nullptr, AnnaN::show_menu, nullptr, main_children, main_size
};
