
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;


class Fibonacci final {
public:
    static int get(int n) {
        assert(n >= 0);
        vector<int> array = { 0,1 };
        int sum = 0;

            if ((n != 1) && (n != 0)) {
                for (int i = 0;i < n;i++) {
                    sum = array[i] + array[i + 1];
                    array.push_back(sum);
                }
            }

        return array[n];
    }
};

int main(void) {

    int n;
    std::cin >> n;
    std::cout << Fibonacci::get(n) << std::endl;
    return 0;
}
