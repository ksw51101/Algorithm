#include <iostream>
using namespace std;

int main() {
	int n;
	short count[10001] = { 0, }, temp;

	cin.tie(NULL);	ios::sync_with_stdio(false);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		count[temp]++;
	}

	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < count[i]; j++)
			cout << i << '\n';
	}

	
	return 0;
}