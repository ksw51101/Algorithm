#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	int M, num;
	bool arr[246913];

	while (1) {
		cin >> M;
		num = 0;
		if (M == 0)
			break;
		fill(&arr[0], &arr[2 * M + 1], 1);

		arr[1] = false;
		for (int i = 1; i <= sqrt(2 * M); i++) {
			if (arr[i] == true)
				for (int j = i; j <= 2 * M; j += i)
					arr[i + j] = false;
		}

		for (int i = M + 1; i <= 2 * M; i++)
			if (arr[i] == true)
				num++;

		cout << num << endl;
	}

	return 0;
}