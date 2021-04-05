#include <iostream>
#include <vector>
using namespace std;


vector<long> merge(vector<long> left, vector<long> right) {

    vector<long> merged;
    size_t start_of_left = 0;
    size_t start_of_right = 0;

   /* cout << "left";
    for (int i = 0;i < left.size();i++) {
        cout << left[i];
    }
    cout << endl;
    cout << "right";
    for (int i = 0;i < right.size();i++) {
        cout << right[i];
    }
    cout << endl;
    */

      if (left.size() != 1 && right.size() != 1) {
          while (merged.size()!=(left.size()+right.size())) {


                  if (left[start_of_left] < right[start_of_right]&& left.size() > start_of_left ) {
                      merged.push_back(left[start_of_left]);
                      start_of_left++;
                  }
                  else if(right.size() > start_of_right) {
                      merged.push_back(right[start_of_right]);
                      start_of_right++;
                  }

               /*for (int i = 0;i < merged.size();i++) {
                  cout << merged[i];
              }
              cout << endl;

             cout << "itaration_end" << endl;
             */-


          }
      }
      else {
          if (left[0] < right[0]) {
              merged.push_back(left[0]);
              merged.push_back(right[0]);
          }
          else {
              merged.push_back(right[0]);
              merged.push_back(left[0]);
          }
      }
      
      return merged;
      
}

vector<long> merge_sort(vector < vector<long>> input) {

    while (input.size() != 1) {

        input.push_back(merge(input[0], input[1]));
        input.erase(input.begin(), input.begin() + 2);

        /*    for (int i = 0;i < input.size();i++) {
                for (int k = 0;k < input[i].size();k++) {
                    cout << input[i][k];
                }
                cout << endl;
            }

            cout << "itaration_end" << endl;
            */
    }
    return input[0];
}

int main() {
    vector <vector<long>> input;
    vector<long> output;
    int n = 0;
    long p = 0;
    cin >> n;

    for (int i = 0;i < n;i++) {
        cin >> p;
        input.push_back({ p });
    }

    output = merge_sort(input);

    for (int i = 0;i < output.size();i++) {
        cout << output[i] << " ";
    }




    return 0;
}