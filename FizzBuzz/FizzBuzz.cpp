#include <iostream>

void fizz_buzz(int number) {
    if (number % 3 == 0 && number % 5 == 0) {
        std::cout << "FizzBuzz" << std::endl;
    } else if (number % 3 == 0) {
        std::cout << "Fizz" << std::endl;
    } else if (number % 5 == 0) {
        std::cout << "Buzz" << std::endl;
    } else {
        std::cout << number << std::endl;
    }
}

int main() {
    for (int i = 1; i <= 100; ++i) {
        fizz_buzz(i);
    }
    return 0;
}