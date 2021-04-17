#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	int T;

	cin >> T;

	for (int i = 0; i < T; i++) {
		int n, ans = 1;
		string name, type;
		map<string, int> m;

		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> name >> type;
			if (m.find(type) == m.end())
				m.insert(make_pair(type, 1));
			else
				m[type]++;
		}
		for (auto iter : m)
			ans *= iter.second + 1;
		cout << ans - 1 << '\n';
	}
	
	return 0;
}