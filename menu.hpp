#pragma once

namespace  AnnaN {
struct MenuItem {
const char* const title;
void (*func)(const MenuItem* current);

const MenuItem* const *children;
const int children_count;

const MenuItem* parent;

const MenuItem* const *pushkin_children
const int pushkin_children_count;
const MenuItem* parent; 
};
}
