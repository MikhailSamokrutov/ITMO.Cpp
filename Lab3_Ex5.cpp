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
	std::cout << "������� ����� ��� �������� � �������� ���: ";
	std::cin >> num;
	std::cout << "����� " << num << " � �������� ���� : ";
	decToBin(num);

	return 0;
}

