#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    vector <int> input;
    vector <int> subsequence;
    int b = 0;
    int c = 0;
    int size = 0;
    int max = 0;
    int max_max = 1;

        cin >> b;

        for (int k = 0;k < b;k++) {
            cin >> c;
            input.push_back(c);
        }

        subsequence.push_back(1);

        for (int i = 1; i < b;i++) {
            max = 1;
            for (int k = 0;k < i;k++) {
                if (input[i] % input[k] == 0) {
                    size = subsequence[k] + 1;
                    if (max <= size) {
                        max = size;
                    }
                }
            }
            subsequence.push_back(max);
            if (max >= max_max) {
                max_max = max;
            }

        }

        cout << max_max;


}
