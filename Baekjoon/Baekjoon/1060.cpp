#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000000000
int n, l;
vector<int> vec;
vector<pair<int, int>> arr;

// n�� ���� S�� �������� Ȯ���ϴ� �Լ�
bool check(int num) {
	for (int i = 0; i < vec.size(); i++)
		if (vec[i] == num)
			return true;
	return false;
}

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
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

	for (int z = 1; z <= max(n, vec[l-1]); z++) {
		int left = 0, right = 1000000000; // n�� left�� right�� ���̿� ����
		if (check(z)) // n�� ���� S�� ���ԵǾ� �ִ� ��� ���� ������ ����x
			arr.push_back({z, 0});
		else {
			if (z > vec[l - 1])
				arr.push_back({ z, MAX });
			else {
				for (int i = 0; i < l; i++) {
					if (vec[i] < z)
						left = max(vec[i], left); // n���� ���� ���� S�� ���� �� �ִ�
					else if (vec[i] > z)
						right = min(vec[i], right); // n���� ū ���� S�� ���� �� �ּڰ�
				}
				arr.push_back({ z, (z - left - 1) * (right - z) + right - 1 - z }); // (left �ʰ� n �̸��� ��) * (n �̻� right �̸��� ��) + (n �ʰ� right �̸��� ��)
			}
		}
	}
	sort(arr.begin(), arr.end(), compare);
	for (int i = 0; i < n; i++) {
		cout << arr[i].first << ' ';
	}
	return 0;
}