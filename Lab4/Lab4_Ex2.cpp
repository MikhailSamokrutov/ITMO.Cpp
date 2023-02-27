#include <iostream>
#include <windows.h>
using namespace std;

bool inputValue(int, int);
bool inputPointer(int*, int*);
bool inputRefrence(int&, int&);

int main() {

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int a = 0;
	int b = 0;

	int* pa = &a;
	int* pb = &b;

	int& refA = a;
	int& refB = b;

	if (inputRefrence(refA, refB) == false) // if(!Input(a,b))
	{
		std::cerr << "error";
		return 1;
	}
	int s = a + b;

	return 0;
}

// Values
bool inputValue(int a, int b) {
	std::cout << "������� �������� 'a' � 'b': ";
	std::cin >> a >> b;
	if (a > 0 && b !=0)
		return true;
	else return false;
}

// Pointers
bool inputPointer(int *a, int *b) {
	std::cout << "������� �������� 'a' � 'b': ";
	std::cin >> *a >> *b;
	if (*a > 0 && *b != 0)
		return true;
	else return false;
}

// Ref
bool inputRefrence(int& a, int& b) {
	std::cout << "������� �������� 'a' � 'b': ";
	std::cin >> a >> b;
	if (a > 0 && b != 0)
		return true;
	else return false;
}