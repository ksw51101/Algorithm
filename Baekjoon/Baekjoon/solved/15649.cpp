#include <iostream>
using namespace std;

int m, n, arr[8] = { 0, };
bool visited[9] = { false, };

void start(int num) {
	if (num == n) {
		for (int i = 0; i < n; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= m; i++) {
		if (visited[i] == false) {
			visited[i] = true;
			arr[num] = i;
			start(num + 1);
			visited[i] = false;
		}
	}

}

int main() {
	cin >> m >> n;

	start(0);

	return 0;
}