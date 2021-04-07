#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, A[50], B[50], sum;
vector<int> arr_A, arr_B;

int main() {
	cin >> N;
	sum = 0;

	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++)
		cin >> B[i];

	sort(A, A + N);
	sort(B, B + N);

	for (int i = 0; i < N; i++)
		sum += A[i] * B[N - i - 1];

	cout << sum << endl;

	return 0;
}