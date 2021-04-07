#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
	if (a.length() == b.length())
		return a < b;
	else
		return a.length() < b.length();
}

int main() {
	int n;
	string str[20000], temp = "";

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> str[i];

	sort(str, str + n, compare);


	for (int i = 0; i < n; i++)
		if (str[i].compare(temp)) {
			cout << str[i] << '\n';
			temp = str[i];
		}

	return 0;
}