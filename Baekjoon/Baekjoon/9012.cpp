#include <iostream>
#include <string>
using namespace std;

int T;
string str;

int main() {

	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		cin >> str;
		bool ans = true;
		int cnt = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(')
				cnt++;
			else {
				cnt--;
			}
			if (cnt < 0) {
				ans = false;
				break;
			}
		}
		if (ans && cnt == 0)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}

	return 0;
}