#include <iostream>
#include <string>
#include <deque>
using namespace std;

int T;

int main() {

	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		string func, arr, temp = "";
		int n;
		deque<int> dq;

		cin >> func;
		cin >> n;
		cin >> arr;
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] == '[') continue;
			else if (arr[i] >= '0' && arr[i] <= '9') {
				temp += arr[i];
			}
			else if (arr[i] == ',' || arr[i] == ']') {
				if (!temp.empty()) {
					dq.push_back(stoi(temp));
					temp = "";
				}
			}
		}
		bool dir = true, error = false;
		for (int i = 0; i < func.size(); i++) {
			if (func[i] == 'R') {
				dir = !dir;
			}
			else {
				if (dq.empty()) {
					error = true;
					break;
				}
				else {
					if (dir)
						dq.pop_front();
					else
						dq.pop_back();
				}
			}
		}
		if (error) {
			cout << "error" << '\n';
		}
		else {
			cout << '[';
			if (dir) {
				while (!dq.empty()) {
					cout << dq.front();
					dq.pop_front();
					if (!dq.empty())
						cout << ',';
				}
			}
			else {
				while (!dq.empty()) {
					cout << dq.back();
					dq.pop_back();
					if (!dq.empty())
						cout << ',';
				}
			}
			cout << ']' << '\n';
		}
	}

	return 0;
}