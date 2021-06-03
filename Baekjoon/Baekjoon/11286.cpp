#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

struct compare {
	bool operator()(const int& a, const int& b) {
		if (abs(a) == abs(b)) { // 절댓값이 같으면 원래 값 기준 오름차순 정렬
			return a > b;
		}
		else // 절댓값이 다르면 절댓값 기준 오름차순 정렬
			return abs(a) > abs(b);		
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