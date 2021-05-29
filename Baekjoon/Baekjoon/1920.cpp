#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}

	// �̺�Ž���� ���� vector ����
	sort(vec.begin(), vec.end());

	cin >> m;

	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;

		vector<int>::iterator iter = lower_bound(vec.begin(), vec.end(), temp);

		// temp �̻��� ù ��° ���� temp�� �ٸ��ٸ� vec �ȿ� ����.
		if (iter == vec.end() || *iter != temp)	
			cout << 0 << '\n';
		else
			cout << 1 << '\n';
	}

	return 0;
}