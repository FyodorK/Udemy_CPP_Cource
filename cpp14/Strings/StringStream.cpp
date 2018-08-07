/*
StringStream hackerrank challenge

https://www.hackerrank.com/challenges/c-tutorial-stringstream/problem

"1,2,3,4,5" -> 
1
2
3
4
5

*/

#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
	string integer{};
	stringstream ss(str);
	vector<int> vec{}; 
	while (getline(ss, integer, ',')) {
		vec.push_back(stoi(integer));
	}
		

	return vec;
}

int main() {
	string str;
	cin >> str;
	vector<int> integers = parseInts(str);
	for (int i = 0; i < integers.size(); i++) {
		cout << integers[i] << "\n";
	}

	return 0;
}