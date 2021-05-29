#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, temp;
vector<int> vec;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		vec.push_back(temp);
	}

	// �̺�Ž���� ���� vector ����
	sort(vec.begin(), vec.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> temp;
		vector<int>::iterator lower = lower_bound(vec.begin(), vec.end(), temp); // ó�� temp �̻��� ���� ������ iterator
		vector<int>::iterator upper = upper_bound(vec.begin(), vec.end(), temp); // ó�� temp �ʰ��� ���� ������ iterator

		// �� iterator�� ���̸� ���� ��� ���
		cout << upper - lower << ' '; 
	}

	return 0;
}