#include <iostream>
using namespace std;

int main() {
	double number;
	
    while (true) {
        std::cin >> number;
        if(number == 42){
            break;;
        }
        std::cout << number << "\n";
    }
	return 0;
}