#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[101], maximum[101] = { 0, };

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	maximum[1] = arr[1];
	for (int i = 2; i <= n; i++) 
		maximum[i] = max(maximum[i - 2] + arr[i], maximum[i - 1]);
	
	cout << maximum[n] << '\n';

	return 0;
}