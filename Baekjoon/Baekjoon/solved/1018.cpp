#include <iostream>
#include <algorithm>
using namespace std;

int M, N, first, second, answer;
string arr[50];
static int SIZE = 8;

void start(int x, int y) {

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0) {
					if (arr[x + i][y + j] == 'W')
						first++;
				}
				else {
					if (arr[x + i][y + j] == 'W')
						second++;
				}
			}
			else {
				if (j % 2 == 0) {
					if (arr[x + i][y + j] == 'W')
						second++;
				}
				else {
					if (arr[x + i][y + j] == 'W')
						first++;
				}
			}
		}
	}
	if (first > second) 
		answer = min(answer, (SIZE * SIZE / 2) - first + second);
	
	else
		answer = min(answer, first + (SIZE * SIZE / 2) - second);

}

int main() {
	cin >> N >> M;
	
	answer = SIZE * SIZE;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			
			first = second = 0;
			start(i, j);
		}
	}

	cout << answer << endl;

	return 0;
}