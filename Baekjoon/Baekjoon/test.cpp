#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[10][10], n;
bool visited[10][10];

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int max_size;
vector<int> s;

void solution(int x, int y) {
	if (visited[x][y] || !arr[x][y] || x < 0 || y < 0 || x >= n || y >= n) {
		return;
	}
	visited[x][y] = true;
	max_size++;
	for (int dir = 0; dir < 4; dir++)
		solution(x + dx[dir], y + dy[dir]);
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] && !visited[i][j]) {
				max_size = 0;
				solution(i, j);
				s.push_back(max_size);
			}
		}
	}
	sort(s.begin(), s.end());

	if (!s.size())
		cout << 0 << '\n';
	else {
		cout << s.size() << '\n';
		for (int i = 0; i < s.size(); i++)
			cout << s[i] << ' ';

	}
	return 0;
}