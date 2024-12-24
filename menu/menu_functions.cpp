#include "menu_functions.hpp"

#include <cstdlib>
#include <iostream>

const AnnaN::MenuItem*  AnnaN::show_menu(const MenuItem* current) {
    std::cout << "Главное меню" << std::endl;
    for (int i = 1; i < current->children_count; i++) {
        std::cout << current->children[i]->title << std::endl;
    }
    std::cout << current->children[0]->title << std::endl;

    int user_input;
    std::cin>> user_input;
    std::cout << std::endl;

    return current->children[user_input];
}

const AnnaN::MenuItem* AnnaN::exit(const MenuItem* current) {
    std::exit(0);
}

const AnnaN::MenuItem*  AnnaN::read_pushkin(const MenuItem* current) {
    //TODO
    std::cout << current->title << std::endl;
    return current->parent;
}

const AnnaN::MenuItem*  AnnaN::read_lermontow(const MenuItem* current) {
    //TODO
    std::cout << current->title << std::endl;
    return current->parent;
}

const AnnaN::MenuItem*  AnnaN::read_krylow(const MenuItem* current) {
    //TODO
    std::cout << current->title << std::endl;
    return current->parent;
}

const AnnaN::MenuItem*  AnnaN::read_pushkin_dubrovsky(const MenuItem* current) {
    //TODO
    std::cout << current->title << std::endl;
    return current->parent;

}
const AnnaN::MenuItem*  AnnaN::read_pushkin_evgeny_onegin(const MenuItem* current) {
    //TODO
    std::cout << current->title << std::endl;
    return current->parent;
}
const AnnaN::MenuItem*  AnnaN::read_pushkin_zimny_vecher(const MenuItem* current) {
    //TODO
    std::cout << current->title << std::endl;
    return current->parent;
}
const AnnaN::MenuItem* AnnaN::go_back(const MenuItem* current) {
    //TODO
    std::cout << current->title << std::endl;
    return current->parent->parent;
}
