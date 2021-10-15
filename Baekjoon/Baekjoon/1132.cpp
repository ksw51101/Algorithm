#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;

int n;
vector<string> vec;
ll ans;
vector<pair<int, ll>> arr; // ���ĺ��� �⿩�� ����(A~J)

bool compare(pair<int, ll> a, pair<int, ll> b) {
	return a.second < b.second;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		vec.emplace_back(temp);
	}

	for (int i = 0; i < 10; i++) {
		arr.emplace_back(i, 0); // ���ĺ��� �⿩���� 0���� �ʱ�ȭ
	}

	bool first[10] = { false, }; // ù��° �ڸ��� ������ ���ĺ� üũ
	for (const auto& number : vec) {
		first[number[0] - 'A'] = true;
		for (int i = 0; i < number.size(); i++) {
			arr[number[i] - 'A'].second += pow(10, number.size() - i - 1); // ���ĺ��� �⿩�� ����
		}
	}
	sort(arr.begin(), arr.end(), compare); // �⿩���� �������� �������� ����

	int index = 0;
	for (int i = 0; i < 10; i++) {
		if (!first[arr[i].first]) { // �⿩���� ���� ���ĺ����� ������ ù ��° ���ڷ� ������ ���� ���ĺ��� index ����
			index = i;
			break;
		}
	}

	int k = 1; // �⿩���� ���� ���ĺ��� ���� ���ں��� �ο�
	for (int i = 0; i < 10; i++) {
		if (index == i) // ù ��° ���ڷ� ������ �ʾҰ� �⿩���� ���� ���� ���ĺ��� 0 �ο�
			continue;
		ans += arr[i].second * k++;
	}

	cout << ans << '\n';

	return 0;
}