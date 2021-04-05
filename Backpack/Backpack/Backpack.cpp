#include <iostream>
#include <cassert>
#include <cstdint>
#include <iomanip>
#include <vector>
#include <algorithm>


using namespace std;

typedef pair <double,int > item;

double get_max(vector <item> items,int knapsack_capacity) {

	int curent_size = 0;
	int sum_of_size = 0;
	double sum_of_value = 0;
     double max = 0;


	for (int i = 0;i < items.size();i++) {
		sum_of_size = sum_of_size + items[i].second;
		sum_of_value = sum_of_value + items[i].first;
		items[i].first = items[i].first / items[i].second;

	}

	sort(items.begin(), items.end());

	if (sum_of_size >= knapsack_capacity) {

		for (int i = items.size()-1;i >=0;i--) {

			if (knapsack_capacity > (curent_size + items[i].second)) {
				curent_size = curent_size + items[i].second;
				max = max + items[i].second * items[i].first;
			}
			else {
				int dif = knapsack_capacity - curent_size;
				max = max + items[i].first*dif;
				return max;
			}

		}
	}
	else {
		return sum_of_value;
	}


}

int main() {
	double max = 0;
	int number_of_items=0;
	int knapsack_capacity=0;

	cin >> number_of_items >> knapsack_capacity;

    vector <item> items(number_of_items);

	for (int i = 0; i < number_of_items; i++) {
		cin >> items[i].first >> items[i].second;
	}

	max = get_max(items,knapsack_capacity);

	cout << fixed << setprecision(3) << max << endl;
	return 0;
}
