#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;

void writeToFile(const char* filename);

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	writeToFile("poetry.txt");
	
	return 0;
}

void writeToFile(const char* filename) {

	const int MAX = 500;
	char str[MAX];

	std::cout << "Введите текст стихотворения" << std::endl;

	std::ofstream fout("poetry.txt");

	if (fout.is_open()) {
		std::cin.get(str, MAX, '#');
		fout << str << std::endl;
	}

	fout.close();

}