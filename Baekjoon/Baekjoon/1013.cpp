#include <iostream>
using namespace std;

int T, state;
string str;

int main() {

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> str;

		state = 0;
		for (int j = 0; j < str.length(); j++) {
			switch (state) {
			case 0:
				if (str[j] == '0')
					state = 1;
				else
					state = 2;
				break;
			case 1:
				if (str[j] == '1')
					state = 0;
				else
					state = -1;
				break;
			case 2:
				if (str[j] == '0')
					state = 3;
				else
					state = -1;
				break;
			case 3:
				if (str[j] == '0')
					state = 4;
				else
					state = -1;
				break;
			case 4:
				if (str[j] == '1')
					state = 5;
				break;
			case 5:
				if (str[j] == '0')
					state = 1;
				else
					state = 6;
				break;
			case 6:
				if (str[j] == '0')
					state = 7;
				break;
			case 7:
				if (str[j] == '0')
					state = 4;
				else
					state = 0;
				break;
			}
		}

		if (state == 5 || state == 0 || state == 6)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}