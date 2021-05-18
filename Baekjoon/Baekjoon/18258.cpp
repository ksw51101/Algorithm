#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n;
string str;
queue<int> q;

int main() {
	cin.tie(nullptr);
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {
		getline(cin, str);
		if (str.substr(0, 4) == "push") {
			q.push(stoi(str.substr(5)));
		}
		else if (str == "pop") {
			if (q.empty())
				cout << -1 << '\n';
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (str == "size") {
			if (q.empty())
				cout << 0 << '\n';
			else 
				cout << q.size() << '\n';
			
		}
		else if (str == "empty") {
			if (q.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (str == "front") {
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.front() << '\n';
		}
		else if (str == "back") {
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.back() << '\n';
		}
	}

	return 0;
}