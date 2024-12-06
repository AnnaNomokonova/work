#pragma execution_character_set("utf-8")
#include <clocale>
#include <iostream>
int main() {
std: :setlocale(LC_ALL, "");

int user_input;
do {
std: :cont << "Главное меню" << std: :endl;
std: :cont << "1 - Русские писатели" << std: :endl;
std: :cout << "0 -  Завершить чтение" << std: :endl;

std: :cin >> user_input;
if (user_input == 1) {
//TODO 

}
else if (user_input == 0) {
exit(0);
}

std: :cout << std: :endl;
} while (true);


return 0;
}
:wq
