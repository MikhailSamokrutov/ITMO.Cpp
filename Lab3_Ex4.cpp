#include <iostream>
#include <windows.h>
using namespace std;

int recSum(int n) {

	int sum = n * 5;
	if ((n -1) > 0) {
		sum += recSum(n - 1);
	}		
	return sum;
}


int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int n = 0;
	int S = 0;

	std::cout << "¬ведите значение числа n: ";
	std::cin >> n;
	std::cout << "–езультат: " << recSum(n) << std::endl;


	return 0;
}