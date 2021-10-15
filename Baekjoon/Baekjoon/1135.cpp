#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans;
vector<int> vec[50];

bool cmp(int a, int b) {
	return a > b;
}

int DFS(int num) {
	if (vec[num].empty())
		return 0;

	vector<int> order(vec[num].size());

	for (int i = 0; i < vec[num].size(); i++) {
		order[i] = DFS(vec[num][i]);
	}
	sort(order.begin(), order.end(), cmp);

	int ret = 0;
	for (int i = 0; i < order.size(); i++)
		ret = max(ret, order[i] + i + 1);

	return ret;
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (i == 0)
			continue;
		vec[temp].emplace_back(i);
	}

	cout << DFS(0) << '\n';

	return 0;
}