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
	priority_queue<int, vector<int>, compare> min_pq; // �������� pq
	priority_queue<int> max_pq; // �������� pq
	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;

		// �������� pq���� �����ؼ� �����ư��� pq�� ä��
		if (i % 2 == 0) { 
			max_pq.push(temp);
		}
		else {
			min_pq.push(temp);
		}

		// max_pq���� �߰��� ���� ���� ���� ä��� min_pq���� ū ���� ä��Ƿ� max_pq�� �ִ��� min_pq�� �ּҰ����� ū ��� swap
		if (!min_pq.empty() && max_pq.top() > min_pq.top()) { 
			int temp2 = max_pq.top();
			max_pq.pop();
			max_pq.push(min_pq.top());
			min_pq.pop();
			min_pq.push(temp2);
		}

		// ��ģ ���� ¦����� ���� ���� ���ؾ� �ϹǷ� �׻� max_pq�� ���� �߰����̴�
		cout << max_pq.top() << '\n';
	}

	return 0;
}