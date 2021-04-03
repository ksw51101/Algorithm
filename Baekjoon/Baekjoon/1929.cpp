#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	int M, N;
	bool arr[1000001];


	cin >> M >> N;
	fill(&arr[0], &arr[N + 1], 1);

	arr[1] = false;
	for (int i = 1; i <= sqrt(N); i++) {
		if (arr[i] == true)
			for (int j = i; j <= N; j += i)
				arr[i + j] = false;
	}

	for (int i = M; i <= N; i++)
		if (arr[i] == true)
			cout << i << '\n';


	return 0;
}