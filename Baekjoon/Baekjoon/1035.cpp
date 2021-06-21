#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <vector>
#include <cmath>
using namespace std;

char arr[5][5], map[5][5];
vector<pair<int, int>> original, made;
int star_num = 0, ans = INT_MAX, cnt = 0;
bool visited[5][5];

void check(int x, int y) {
	int dx[] = { 0, 0, 1, -1 };
	int dy[] = { 1, -1, 0, 0 };

	if (x < 0 || y < 0 || x>4 || y>4 || visited[x][y] == true)
		return;
	if (map[x][y] == '*') {
		cnt++;
		visited[x][y] = true;
		for (int i = 0; i < 4; i++) {
			check(x + dx[i], y + dy[i]);
		}
	}
}

bool connect() {
	fill(&visited[0][0], &visited[4][5], false);
	cnt = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (map[i][j] == '*') {
				check(i, j);
				if (cnt == star_num)
					return true;
				else
					return false;
			}
		}
	}
}

int distance(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

int counter() {
	vector<int> make_pair(star_num);
	int minimum = INT_MAX;

	for (int i = 0; i < star_num; i++) {
		make_pair[i] = i;
	}
	do {
		int sum = 0;
		for (int i = 0; i < star_num; i++) {
			sum += distance(original[i].first, original[i].second, made[make_pair[i]].first, made[make_pair[i]].second);
		}
		minimum = min(minimum, sum);
	} while (next_permutation(make_pair.begin(), make_pair.end()));
	return minimum;
}

void DFS(int c) {
	if (c == star_num) {
		if (connect())
			ans = min(ans, counter());
		return;
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (map[i][j] == '.') {
				map[i][j] = '*';
				made.push_back({ i, j });
				DFS(c + 1);
				map[i][j] = '.';
				made.pop_back();
			}
		}
	}
}

int main() {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '*') {
				original.push_back({ i, j });
				star_num++;
			}
		}
	fill(&map[0][0], &map[4][5], '.');
	DFS(0);

	cout << ans << '\n';

	return 0;
}
