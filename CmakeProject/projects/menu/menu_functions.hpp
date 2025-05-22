#pragma once

#include "menu.hpp"

namespace AnnaN {
    const MenuItem*  show_menu(const MenuItem* current);

    const MenuItem*  exit(const MenuItem* current);

    const MenuItem* read_pushkin(const MenuItem* current);
    const MenuItem* read_lermontow(const MenuItem* current);
    const MenuItem* read_krylow(const MenuItem* current);

    const MenuItem* read_pushkin_dubrovsky(const MenuItem* current);
    const MenuItem* read_pushkin_evgeny_onegin(const MenuItem* current);
    const MenuItem* read_pushkin_zimny_vecher(const MenuItem* current);
    const MenuItem* go_back(const MenuItem* current);
}
