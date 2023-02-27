#include <iostream>
#include <windows.h>
using namespace std;

void decToBin(int num) {

	if (num > 1)
		decToBin(num / 2);
	std::cout << num % 2;
}

int main() {

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int num;
	std::cout << "¬ведите число дл€ перевода в двоичный код: ";
	std::cin >> num;
	std::cout << "„исло " << num << " в двоичном коде : ";
	decToBin(num);

	return 0;
}

