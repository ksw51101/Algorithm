#include <iostream>
#include <algorithm>
using namespace std;

int n, score[300], max_score[300][2];

void start(int pos) {
	if (pos == n)
		return;
	
	max_score[pos][0] = max(max_score[pos - 2][0], max_score[pos - 2][1]) + score[pos];
	max_score[pos][1] = max_score[pos - 1][0] + score[pos];

	start(pos + 1);

}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> score[i];

	max_score[0][0] = max_score[0][1] = score[0];

	if (n > 1) {
		max_score[1][0] = score[1];
		max_score[1][1] = score[0] + score[1];
	}
	if (n > 2) 
		start(2);
	

	cout << max(max_score[n - 1][0], max_score[n - 1][1]) << '\n';

	return 0;
}