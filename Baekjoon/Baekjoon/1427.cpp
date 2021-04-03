#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string str_n;

	cin >> str_n;

	sort(&str_n[0], &str_n[0] + str_n.length(), greater<char>());
	cout << str_n;

	return 0;
}