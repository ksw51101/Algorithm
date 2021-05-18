#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T, n, m;

int main() {

	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		cin >> n >> m;
		int cnt = 0;
		queue<int> q;
		vector<int> v;
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			v.push_back(temp);
			q.push(i);
		}

		while (v[m] != 0) {
			int temp = v[q.front()];
			bool flag = false;
			for (int i = 0; i < n; i++) {
				if (v[i] > temp) {
					flag = true;
					break;
				}
			}
			if (flag) {
				q.push(q.front());
				q.pop();
			}
			else {
				cnt++;
				v[q.front()] = 0;
				q.pop();
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}