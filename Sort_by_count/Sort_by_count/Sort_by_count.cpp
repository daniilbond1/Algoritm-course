#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    vector <int> input;
    vector <int> output;
    vector <int> array;
    int b = 0;
    int c = 0;

    cin >> b;

    for (int k = 0;k < b;k++) {
            cin >> c;
            input.push_back(c);
            output.push_back(c);
    }

    for (int i = 0;i <= 10;i++) {
        array.push_back(0);
    }

    for (int j = 0;j < b;j++) {
        array[input[j]]++;
    }


     for (int i = 1;i <= 10;i++) {
        array[i] += array[i - 1];
      }


   for (int i = b-1; i >= 0;i--) {
        output[array[input[i]]-1] = input[i]; 
        array[input[i]]--;
   }

    for (int i = 0;i < output.size();i++) {
        cout << output[i] << " ";   
    }
    

    
}
