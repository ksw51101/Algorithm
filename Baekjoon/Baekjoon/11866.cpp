#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, k;
queue<int> q;
vector<int> ans;

void pass() {
	int temp = q.front();
	q.pop();
	q.push(temp);
}

int main() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		q.push(i);

	while (!q.empty()) {
		for (int i = 0; i < k - 1; i++)
			pass();
		ans.push_back(q.front());
		q.pop();
	}
	cout << '<';
	for (int i = 0; i < ans.size() - 1; i++)
		cout << ans[i] << ", ";
	cout << ans[ans.size() - 1];
	cout << '>';
	return 0;
}
