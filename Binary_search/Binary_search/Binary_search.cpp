#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int get_pos(const std::vector<int>& numbers, int number) {
    int begin = 0;
    int end = numbers.size()-1; 
    int middle = 0;
    while (begin <= end) {

        middle = begin + (end - begin) / 2;

        if (numbers[middle] == number) {
            return middle+1;
        }
        else if (numbers[middle] > number) {
            end = middle - 1;
        }
        else if(numbers[middle] < number){
            begin = middle + 1;
        }
    }
    return -1;
}

int main(void) {
    size_t number_count;
    std::cin >> number_count;
    std::vector<int> numbers(number_count);
    for (size_t i = 0; i < number_count; i++) {
        std::cin >> numbers[i];
    }

    size_t query_count;
    std::cin >> query_count;
    while (query_count-- > 0) {
        int number;
        std::cin >> number;
        std::cout << get_pos(numbers, number) << " ";
    }
    std::cout << std::endl;
}