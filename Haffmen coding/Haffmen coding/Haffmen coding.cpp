 #include <iostream>
 #include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <typeinfo>	
using namespace std;

int main() {
	map <char, int> symbols;
	map <char, string> coded;
	vector<string> roots;
	string input;
	string output;


	int conteiner;
	char  conteiner_1;
	char  conteiner_2;
	bool marker = false;
	int i = 1;
	bool marker_1 = false;
	int size = 0;
	int conteiner_k_1 = 0;
	int conteiner_k_2 = 0;

	cin >> input;

	for (int i = 0;i < input.size();i++) {
		for (map <char, int> ::iterator it = symbols.begin();it != symbols.end(); it++) {
			if (input[i] == it->first) {
				it->second++;
				marker = true;
			}
	
		}
		if (marker == false) {
			symbols[input[i]] = 1;
		}
		marker = false;
	}

	map <char, int> ::iterator first;
	map <char, int> ::iterator second;

	size = symbols.size();

	if (symbols.size() != 1) {
		while (symbols.size() != 1) {

			first = symbols.begin();
		   second = symbols.begin();
			second++;


				for (int k = 0;k < roots.size();k++) {
					if (first->first == roots[k][0]) {
						marker_1 = true;
						conteiner_k_1 = k;
						for (int m = 0;m < roots[k].size();m++) {
							coded[roots[k][m]] += "0";
						}
					}
				}

				for (int k = 0;k < roots.size();k++) {
					if (second->first == roots[k][0]) {
						marker_1 = true;
						conteiner_k_2 = k;
						for (int m = 0;m < roots[k].size();m++) {
							coded[roots[k][m]] += "1";
						}

					}
				}

				if (marker_1 == false) {
					roots.push_back({ to_string(i+1),{first->first,second->first} });
					coded[first->first] = "1";
					coded[second->first] = "0";
				}
				else {
					roots.push_back({to_string(i+1),(roots[conteiner_k_1][1]+ roots[conteiner_k_2][1])});
					conteiner_k_1 = 0;
					conteiner_k_2 = 0;
				}

				marker_1 = false;

			symbols[i]=first->second + second->second;
			i++;

			symbols.erase(first);
			symbols.erase(second);


		}
	}
	else {	
		coded[first->first] = "0";
	}

	for (int i = 0; i < roots.size(); ++i)
	{

		cout << roots[i][0]<<" "<< roots[i][1]<<endl;
	}



/*	for (int i = 0;i < input.size();i++) {
				output += coded[input[i]];
	}

	cout << size << " " << output.size() << endl;

	for (map <char, string> ::iterator it = coded.begin();it != coded.end(); it++) {
		cout << it->first << ": " << it->second << endl;
	}

	cout << output;
	*/

	return 0;
}