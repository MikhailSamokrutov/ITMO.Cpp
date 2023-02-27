#include <iostream>
#include <windows.h>
#include <vector>
#include <fstream>
using namespace std;



int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	const int N = 10;
	int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };
	int min = 0; // дл€ записи минимального значени€
	int buf = 0; // дл€ обмена значени€ми

	std::string file = "Lab6Ex2.txt";

	// open file for writing
	std::ofstream out(file);
	if (!out) {
		std::cout << "‘айл открыть невозможно\n";
		return 1;
	}
	out << "ƒо сортировки \n";
	for (int el : a) {
		out<<el<<"\t";
	}
	out << std::endl;
	out.close();


	for (int i = 0; i < N; i++)
	{
		min = i; // номер текущей €чейки, как €чейки с минимальным значением
		// в цикле найдем реальный номер €чейки с минимальным значением
		for (int j = i + 1; j < N; j++)
			min = (a[j] < a[min]) ? j : min;
		// перестановка этого элемента, помен€в его местами с текущим
		if (i != min)
		{
			buf = a[i];
			a[i] = a[min];
			a[min] = buf;
		}
	}

	out.open(file, std::ios::app); // Open for writing
	out << "ѕосле сортировки \n";
	for (int el : a)
		out << el << '\t';
	out.close();


	return 0;
}

