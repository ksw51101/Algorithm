#include <iostream>
#include <algorithm>
using namespace std;

int n, rec[500][500], maximum[500][500];

void select(int index) {
	if (index == n + 1) {
		int max_num = 0;
		for (int i = 0; i < n; i++)
			max_num = max(max_num, maximum[n - 1][i]);
		cout << max_num << '\n';
		return;
	}

	maximum[index][0] = maximum[index - 1][0] + rec[index][0];
	maximum[index][index] = maximum[index - 1][index - 1] + rec[index][index];
	for (int i = 1; i < index; i++) 
		maximum[index][i] = max(maximum[index - 1][i - 1], maximum[index - 1][i]) + rec[index][i];

	select(index + 1);
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < i + 1; j++)
			cin >> rec[i][j];

	maximum[0][0] = rec[0][0];

	select(1);

	return 0;
}