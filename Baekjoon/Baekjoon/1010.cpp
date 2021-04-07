#include <iostream>
using namespace std;

int T, N, M, A[31][31] = {0,};

void func(int N, int M) {
	int i = 1;
	if (N == 1)
		A[N][M] = M;
	else if (N == M)
		A[N][M] = 1;
	else {
		if(A[N][M] == 0) 
			while (N - 1 <= M - i) {
				func(N - 1, M - i);
				A[N][M] += A[N - 1][M - i];
				i++;
			}
	}
}

int main() {

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N >> M;

		func(N, M);
		cout << A[N][M] << endl;

	}

	return 0;
}