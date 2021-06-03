#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct compare {
	bool operator()(const int &a, const int &b) {
		return a > b;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	priority_queue<int, vector<int>, compare> pq;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;

		cin >> temp;
		if (temp == 0) {
			if (pq.empty())
				cout << 0 << '\n';
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
			pq.push(temp);
	}

	return 0;
}