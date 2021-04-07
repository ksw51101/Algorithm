#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string A, B;
int arr[1001][1001] = { 0, };

int main() {
	cin >> A >> B;

	for (int i = 1; i <= A.length(); i++)
		for (int j = 1; j <= B.length(); j++) {
			if (A[i-1] == B[j-1])
				arr[i][j] = arr[i - 1][j - 1] + 1;
			else 
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
		}

	cout << arr[A.length()][B.length()] << '\n';
	return 0;
}