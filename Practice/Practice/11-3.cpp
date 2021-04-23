#include <iostream>
#include <string>
using namespace std;

int cnt = 1;
string s;

int main() {
	cin >> s;

	char a = s[0];
	for (int i = 1; i < s.length(); i++) {
		if (s[i] != a) {
			a = s[i];
			cnt++;
		}
	}
	cout << cnt / 2 << '\n';

	return 0;
}