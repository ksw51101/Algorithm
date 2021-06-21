#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
string str;
vector<pair<string, int>> vec; // n���� �� �� ���� ���ڿ��� ������ count

// pair�� second ���� �������� ������ ���� �Լ�
bool compare(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}

// �Է� ���ڿ� s�� 0�� ���� return
int counter(string s) {
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0')
			cnt++;
	}
	return cnt;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> str;
		if (vec.empty()) { // vec�� ��������� ù��° �Է��̹Ƿ� second�� 1�� ���Խ��� push_back
			vec.push_back({ str, 1 });
		}
		else {
			for (int j = 0; j <= vec.size(); j++) {
				if (j == vec.size()) { // vec�� ���� ���ڿ��̹Ƿ� second�� 1�� ���Խ��� push_back
					vec.push_back({ str, 1 });
					break;
				}
				if (vec[j].first == str) { // �̹� �־��� ���ڿ��̹Ƿ� second++
					vec[j].second++;
					break;
				}
			}
		}

	}
	cin >> k;

	sort(vec.begin(), vec.end(), compare); // ���ڿ��� ���� ���� ������� ����

	for (int i = 0; i <= vec.size(); i++) {
		if (i == vec.size()) { // ������ ��찡 �����Ƿ� 0 ���
			cout << 0 << '\n';
			break;
		}
		int num = counter(vec[i].first);
		if (num <= k && (k - num) % 2 == 0) { // k�� num���� ���� ��� ���� �ִ� ��츦 ���� ���� ����, ũ���� num���� ���̰� ¦���� ��쿡�� ���� �ִ� ���¸� ���� �� ����
			cout << vec[i].second << '\n';
			break;
		}
	}

	return 0;
}