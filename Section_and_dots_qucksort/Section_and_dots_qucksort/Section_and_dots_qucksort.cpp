#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

vector <int>  partition(vector<int>& array, int left, int right) {
    int value = array[left];
    int index_end_of_equal = left;
    int index_end_of_less = left;
    vector <int> answer;

    for (int i = left+1;i <= right;i++) {

        if (array[i] < value) {
            index_end_of_less++;
            index_end_of_equal++;
            swap(array[index_end_of_less], array[i]);
                swap(array[index_end_of_equal],array[i] );
         
        }
        else if (array[i] == value) {
            index_end_of_equal++;
            swap(array[index_end_of_equal], array[i]);
        }

    } 

    swap(array[left], array[index_end_of_equal]);

    answer.push_back(index_end_of_equal);
    answer.push_back(index_end_of_less);

    return answer;
}


void quicksort (vector<int>& array,int left,int right) {

   vector <int> index;

    if (left >= right) {
        return;
    }
    else {
        index = partition(array, left, right);
        quicksort(array, left,index[1]-1);
        quicksort(array, index[0] + 1, right);

    }
}

/*int bin_search(vector<int> array, int dot) {
    int begin = 0;
    int end = array.size() - 1;
    int middle = 0;
    if (array.size() > 2) {
        while (begin <= end) {


            middle = begin + (end - begin) / 2;

            if (begin == end) {
                if (array[middle] <= dot) {
                    return middle + 1;
                }
                else {
                    return middle;
                }
            }


                if (array[middle - 1] <= dot && array[middle + 1] > dot) {
                    return middle+1;
                }
                else if (array[middle + 1] > dot && array[middle - 1] > dot) {
                    end = middle - 1;
                }
                else if (array[middle + 1] <= dot && array[middle - 1] <= dot) {
                    begin = middle + 1;
                }
            
        }
    }
    else if(array.size()==2){
        if (dot > array[0] && dot<array[1]) {
            return 1;
        }
        else if (dot < array[0]) {
            return 0;
        }
        else if (dot > array[1]) {
            return 2;
        }
    }
    else if (array.size() == 1) {
      if (dot < array[0]) {
        return 0;
    }
      else {
         return 1;
      }
    }

}
*/


int bin_search(vector<int> array, int dot) {
    auto it = lower_bound(array.begin(), array.end(), dot);
    if (it == array.end()) {
        return array.size();
    }
    return static_cast<int> (it - array.begin());
}



int get_num_of_sections(vector<int> begining, vector<int> end, int dot) {

    return (bin_search(begining,dot)-bin_search(end,dot));
}

int main()
{
    vector<int> begining;
    vector<int> end;
    vector <int> dots;

    int n = 0;
    int m = 0;
    int left = 0;
    int right = 0;
    int dot = 0;

    cin >> n>> m;

    for (int i = 0;i < n;i++) {
        cin >> left>> right;
        begining.push_back(left);
        end.push_back(right);
    }

   for (int i = 0;i < m;i++) {
        cin >> dot;
        dots.push_back(dot);
    }
    
    
    

    left = 0;
    right = n - 1;
    quicksort(begining, left, right);
    quicksort(end, left, right);



    
       for (int i = 0;i < dots.size();i++) {
          cout << get_num_of_sections(begining,end, dots[i])<<" ";
       }    

}