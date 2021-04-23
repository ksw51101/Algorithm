#include <iostream>
#include <string>
using namespace std;

string s;

int main() {
	int sum = 0;
	cin >> s;
	
	for (int i = 0; i < s.length() / 2; i++)
		sum += s[i] - '0';
	for (int i = s.length() / 2; i < s.length(); i++)
		sum -= s[i] - '0';
	if (sum == 0)
		cout << "LUCKY" << '\n';
	else
		cout << "READY" << '\n';

	return 0;
}