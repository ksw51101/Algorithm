#include <iostream>
#include <algorithm>
using namespace std;

int n, cost[1000][3], minimum[1000][3] = { 0, };

void select(int index) {
	if (index == n + 1) {
		cout << min(min(minimum[n - 1][0], minimum[n - 1][1]), minimum[n - 1][2]) << '\n';
		return;
	}
	minimum[index][0] = min(minimum[index - 1][2], minimum[index - 1][1]) + cost[index][0];
	minimum[index][1] = min(minimum[index - 1][0], minimum[index - 1][2]) + cost[index][1];
	minimum[index][2] = min(minimum[index - 1][0], minimum[index - 1][1]) + cost[index][2];
	
	select(index + 1);
}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			cin >> cost[i][j];
	for (int i = 0; i < 3; i++)
		minimum[0][i] = cost[0][i];

	select(1);


	return 0;
}