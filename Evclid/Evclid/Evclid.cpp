#include <cassert>
#include <iostream>

template <class Int>
Int gcd(Int a, Int b) {  
    assert(a > 0 && b > 0);
    while (a != 0 && b != 0) {
        if (a >= b && b != 0) {
            a = a % b;
        }

        if (a <= b&&a!=0) {
            b = b % a;
        }
    }

    if (a == 0) {
        return b;
    }

    if (b == 0) {
        return a;
    }

}

int main(void) {
    int a, b;
    std::cin >> a >> b;
    std::cout << gcd(a, b) << std::endl;
    return 0;
}