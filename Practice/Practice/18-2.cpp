#include <iostream>
#include <vector>
using namespace std;

int g, p, cnt = 0;

int main() {
	cin >> g >> p;

	vector<bool> used(g + 1, false);
	for (int i = 0; i < p; i++) {
		int temp;
		cin >> temp;
		while (used[temp] == true) {
			temp--;
		}
		used[temp] = true;
		if (used[0] == true)
			break;
		cnt++;
	}
	cout << cnt << '\n';

	return 0;
}