#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct compare {
	bool operator()(const int& a, const int& b) {
		return a > b;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	priority_queue<int, vector<int>, compare> min_pq; // 오름차순 pq
	priority_queue<int> max_pq; // 내림차순 pq
	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;

		// 내림차순 pq부터 시작해서 번갈아가며 pq를 채움
		if (i % 2 == 0) { 
			max_pq.push(temp);
		}
		else {
			min_pq.push(temp);
		}

		// max_pq에는 중간값 기준 작은 수만 채우고 min_pq에는 큰 수만 채우므로 max_pq의 최댓값이 min_pq의 최소값보다 큰 경우 swap
		if (!min_pq.empty() && max_pq.top() > min_pq.top()) { 
			int temp2 = max_pq.top();
			max_pq.pop();
			max_pq.push(min_pq.top());
			min_pq.pop();
			min_pq.push(temp2);
		}

		// 외친 수가 짝수라면 작은 수를 말해야 하므로 항상 max_pq의 값이 중간값이다
		cout << max_pq.top() << '\n';
	}

	return 0;
}