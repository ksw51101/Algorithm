#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

int n, arr[21][21], minimum = INT_MAX;
bool visited[21] = { false, };
vector<int> start, link;

void calculate() {
	int sum = 0;
	for (int i = 0; i < n / 2 - 1; i++)
		for (int j = i + 1; j < n / 2; j++)
			sum += arr[start[i]][start[j]] + arr[start[j]][start[i]];
	for (int i = 0; i < n / 2 - 1; i++)
		for (int j = i + 1; j < n / 2; j++)
			sum -= arr[link[i]][link[j]] + arr[link[j]][link[i]];
	if (sum < 0)
		sum = -sum;
	minimum = min(minimum, sum);
}

void go(int index, int num) {
	if (num == n / 2) {
		for (int i = 1; i <= n; i++) {
			if (visited[i] == true)
				start.push_back(i);
			else
				link.push_back(i);
		}
		calculate();
		for (int i = 0; i < n / 2; i++) {
			start.pop_back();
			link.pop_back();
		}
		return;
	}
	for (int i = index + 1; i <= n; i++) {
		if (visited[i] == false) {
			visited[i] = true;
			go(i, num + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];

	go(0, 0);

	cout << minimum << '\n';

	return 0;
}