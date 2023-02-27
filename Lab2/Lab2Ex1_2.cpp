
#include <iostream>
using namespace std;

int main(){

    system("chcp 1251");

    char op;
    std::cout << "Сделай свой выбор, собери авто свой мечты: ";
    std::cin >> op;

    switch (op)
    {
    case 'R':
        std::cout << "Радио играть должно\n";
    case 'E':
        std::cout << "Мощный двигатель\n";
    case 'V':
        std::cout << "Кондиционер хочу\n";
    default:
        std::cout << "Колеса круглые\n";
    }

}
