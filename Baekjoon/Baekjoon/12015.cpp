#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans = 0;

int main() {
	cin >> n;

	vector<int> vec;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (vec.empty() || temp > vec.back()) // vec�� ������ ������ temp�� Ŭ ��� �׳� �߰�
			vec.push_back(temp);
		else { // vec�� ������ ������ temp�� ���� ��� �̺�Ž���� ���� ã�� temp �̻��� ù index�� ���� temp�� ġȯ(vec�� �׻� ���ĵǾ� �����Ƿ� ����)
			auto iter = lower_bound(vec.begin(), vec.end(), temp);
			*iter = temp;
		}
	}
	cout << vec.size() << '\n';
	
	return 0;
}