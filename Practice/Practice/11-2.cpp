#include <iostream>
#include <string>
using namespace std;

string s;
int ans = 0;

int main() {
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0' || s[i] == '1' || ans == 0 || ans == 1)
			ans += s[i] - '0';
		else
			ans *= s[i] - '0';
	}

	cout << ans << '\n';

	return 0;
}