
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

int main(){
    
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    std::string name;
    std::cout << "What is your name? ";
    //cin >> name;
    getline(std::cin, name);
    std::cout << "Hello, " << name << "!\n";
	  return 0;
}