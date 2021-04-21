#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, num;
vector<int> n_vec, m_vec;

int search(int begin, int end, int target) {
	int mid = (end - begin) / 2 + begin;
	if (begin > end)
		return -1;
	else if (n_vec[mid] == target)
		return mid;
	else if (n_vec[mid] > target)
		return search(begin, mid - 1, target);
	else
		return search(mid + 1, end, target);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		n_vec.push_back(num);
	}
	sort(n_vec.begin(), n_vec.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> num;
		m_vec.push_back(num);
	}
	for (int i = 0; i < m; i++) {
		int result = search(0, n - 1, m_vec[i]);
		if (result == -1)
			cout << "no" << ' ';
		else
			cout << "yes" << ' ';
	}
	return 0;
}