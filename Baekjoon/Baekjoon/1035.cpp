#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <vector>
#include <cmath>
using namespace std;

char original_map[5][5], made_map[5][5]; // original_map : 입력받은 초기의 조각상태, made_map : DFS로 만들어진 조각상태
vector<pair<int, int>> original, made; // original : original_map에서 '*'의 위치, made : made_map에서 '*'의 위치
int star_num = 0, ans = INT_MAX, cnt; // star_num : original_map에서 '*'의 개수, ans : 정답, cnt : made_map에서 붙어있는 '*'의 개수
bool visited[5][5]; // check에서 사용되는 방문상태

// DFS로 붙어있는 '*'의 개수를 확인하는 함수
void check(int x, int y) {
	int dx[] = { 0, 0, 1, -1 };
	int dy[] = { 1, -1, 0, 0 };

	if (x < 0 || y < 0 || x>4 || y>4 || visited[x][y] == true) // 맵을 벗어나거나 방문하였으면 return
		return;
	if (made_map[x][y] == '*') { // 현재 위치가 '*'이면 붙어있는 '*'개수 1 추가
		cnt++;
		visited[x][y] = true; // 방문처리
		for (int i = 0; i < 4; i++) { // 상하좌우 네 방향에 대해서도 수행
			check(x + dx[i], y + dy[i]);
		}
	}
}

// 모든 '*'들이 붙어있는지 확인하는 함수
bool connect() {
	fill(&visited[0][0], &visited[4][5], false);
	cnt = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (made_map[i][j] == '*') { // 최초의 '*'에 대해 check함수 실행
				check(i, j);
				if (cnt == star_num) // 붙어있는 '*'의 개수가 star_num과 같으면 모두 붙어있음을 의미
					return true;
				else
					return false;
			}
		}
	}
}

// 두 좌표의 맨해튼 거리를 구하는 함수
int distance(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

// 완성된 두 map을 이용해 made_map에서 original_map을 만들기 위한 최소 이동횟수를 구하는 함수
int counter() {
	vector<int> make_pair(star_num); // original '*'에서 대응되는 made '*'의 index를 나타냄
	int minimum = INT_MAX;

	for (int i = 0; i < star_num; i++) {
		make_pair[i] = i; // 0 ~ (star_num - 1) 로 초기화
	}

	// original과 made의 '*' 쌍의 모든 조합을 조사해 최소 이동횟수를 구함
	do {
		int sum = 0;
		for (int i = 0; i < star_num; i++) {
			sum += distance(original[i].first, original[i].second, made[make_pair[i]].first, made[make_pair[i]].second);
		}
		minimum = min(minimum, sum);
	} while (next_permutation(make_pair.begin(), make_pair.end()));

	return minimum;
}

// DFS를 사용해 made_map을 구성하고 connect 함수로 연결을 확인한 후 최소 이동횟수 ans 갱신
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
