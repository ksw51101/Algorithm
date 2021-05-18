#include <iostream>
#include <string>
using namespace std;

int n, arr[10000], point = -1;
string str;

int main() {
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		getline(cin, str);
		if (str.substr(0, 4) == "push") {
			point++;
			arr[point] = stoi(str.substr(5));
		}
		else {
			if (str == "pop") {
				if (point == -1)
					cout << -1 << '\n';
				else {
					cout << arr[point] << '\n';
					point--;
				}
			}
			else if (str == "empty") {
				if (point == -1)
					cout << 1 << '\n';
				else
					cout << 0 << '\n';
			}
			else if (str == "size") {
				cout << point + 1 << '\n';
			}
			else {
				if (point == -1)
					cout << -1 << '\n';
				else
					cout << arr[point] << '\n';
			}

		}
	}

	return 0;
}