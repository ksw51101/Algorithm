#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, l;
vector<int> vec;

// n�� ���� S�� �������� Ȯ���ϴ� �Լ�
bool check() {
	for (int i = 0; i < vec.size(); i++)
		if (vec[i] == n)
			return true;
	return false;
}

int main() {
	cin >> l;
	for (int i = 0; i < l; i++) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end()); // �������� ����

	cin >> n;

	int left = 0, right = 1000; // n�� left�� right�� ���̿� ����
	if (check()) // n�� ���� S�� ���ԵǾ� �ִ� ��� ���� ������ ����x
		cout << 0 << "\n";
	else {
		for (int i = 0; i < l; i++) {
			if (vec[i] < n)
				left = max(vec[i], left); // n���� ���� ���� S�� ���� �� �ִ�
			else if (vec[i] > n)
				right = min(vec[i], right); // n���� ū ���� S�� ���� �� �ּڰ�
		}
		cout << (n - left - 1) * (right - n) + right - 1 - n << '\n'; // (left �ʰ� n �̸��� ��) * (n �̻� right �̸��� ��) + (n �ʰ� right �̸��� ��)
	}
	return 0;
}