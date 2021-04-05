#include <iostream>
#include <vector>
using namespace std;

void term(int n) {
    int sum = 0;
    int i = 0;
    vector<int> terms;

    while (sum != n) {

        i++;
        sum = sum + i;

        if (sum > n) {

            sum = sum - i;
            terms[i - 2] = terms[i - 2] + (n-sum);
            break;

        }
        terms.push_back(i);
    }

    cout << terms.size()<<endl;

    for (int k = 0; k < terms.size();k++) {
        cout << terms[k] << endl;
    }

}

int main() {
    int n = 0;

    cin >> n;

    term(n);

    return 0;
}