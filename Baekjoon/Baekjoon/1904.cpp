#include <iostream>
using namespace std;

long long n, arr[1000001], ans;

void start() {
	for (int i = 3; i <= n; i++) 
		arr[i] = (arr[i - 1] + arr[i - 2]) % 15746;
}

int main() {
	cin >> n;
	arr[1] = 1;
	arr[2] = 2;
	start();

	cout << arr[n] << '\n';

	return 0;
}