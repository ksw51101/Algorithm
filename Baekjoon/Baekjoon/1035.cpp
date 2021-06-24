#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <vector>
#include <cmath>
using namespace std;

char original_map[5][5], made_map[5][5]; // original_map : �Է¹��� �ʱ��� ��������, made_map : DFS�� ������� ��������
vector<pair<int, int>> original, made; // original : original_map���� '*'�� ��ġ, made : made_map���� '*'�� ��ġ
int star_num = 0, ans = INT_MAX, cnt; // star_num : original_map���� '*'�� ����, ans : ����, cnt : made_map���� �پ��ִ� '*'�� ����
bool visited[5][5]; // check���� ���Ǵ� �湮����

// DFS�� �پ��ִ� '*'�� ������ Ȯ���ϴ� �Լ�
void check(int x, int y) {
	int dx[] = { 0, 0, 1, -1 };
	int dy[] = { 1, -1, 0, 0 };

	if (x < 0 || y < 0 || x>4 || y>4 || visited[x][y] == true) // ���� ����ų� �湮�Ͽ����� return
		return;
	if (made_map[x][y] == '*') { // ���� ��ġ�� '*'�̸� �پ��ִ� '*'���� 1 �߰�
		cnt++;
		visited[x][y] = true; // �湮ó��
		for (int i = 0; i < 4; i++) { // �����¿� �� ���⿡ ���ؼ��� ����
			check(x + dx[i], y + dy[i]);
		}
	}
}

// ��� '*'���� �پ��ִ��� Ȯ���ϴ� �Լ�
bool connect() {
	fill(&visited[0][0], &visited[4][5], false);
	cnt = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (made_map[i][j] == '*') { // ������ '*'�� ���� check�Լ� ����
				check(i, j);
				if (cnt == star_num) // �پ��ִ� '*'�� ������ star_num�� ������ ��� �پ������� �ǹ�
					return true;
				else
					return false;
			}
		}
	}
}

// �� ��ǥ�� ����ư �Ÿ��� ���ϴ� �Լ�
int distance(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

// �ϼ��� �� map�� �̿��� made_map���� original_map�� ����� ���� �ּ� �̵�Ƚ���� ���ϴ� �Լ�
int counter() {
	vector<int> make_pair(star_num); // original '*'���� �����Ǵ� made '*'�� index�� ��Ÿ��
	int minimum = INT_MAX;

	for (int i = 0; i < star_num; i++) {
		make_pair[i] = i; // 0 ~ (star_num - 1) �� �ʱ�ȭ
	}

	// original�� made�� '*' ���� ��� ������ ������ �ּ� �̵�Ƚ���� ����
	do {
		int sum = 0;
		for (int i = 0; i < star_num; i++) {
			sum += distance(original[i].first, original[i].second, made[make_pair[i]].first, made[make_pair[i]].second);
		}
		minimum = min(minimum, sum);
	} while (next_permutation(make_pair.begin(), make_pair.end()));

	return minimum;
}

// DFS�� ����� made_map�� �����ϰ� connect �Լ��� ������ Ȯ���� �� �ּ� �̵�Ƚ�� ans ����
void DFS(int c) {
	if (c == star_num) {
		if (connect())
			ans = min(ans, counter());
		return;
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (made_map[i][j] == '.') {
				made_map[i][j] = '*';
				made.push_back({ i, j });
				DFS(c + 1);
				made_map[i][j] = '.';
				made.pop_back();
			}
		}
	}
}

int main() {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) {
			cin >> original_map[i][j];
			if (original_map[i][j] == '*') {
				original.push_back({ i, j });
				star_num++;
			}
		}
	fill(&made_map[0][0], &made_map[4][5], '.');
	DFS(0);

	cout << ans << '\n';

	return 0;
}
