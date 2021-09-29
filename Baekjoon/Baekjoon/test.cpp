#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int maximum;
bool winner = false;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void DFS(vector<vector<int>> board, vector<int> aloc, vector<int> bloc, int cnt, bool turn) {
	if (aloc[0] < 0 || aloc[0] > 2 || aloc[1] < 0 || aloc[1]>2 || board[aloc[0]][aloc[1]] == 0) {
		if (winner)
			maximum = max(maximum, cnt);
		return;
	}
	if (bloc[0] < 0 || bloc[0] > 2 || bloc[1] < 0 || bloc[1]>2 || board[bloc[0]][bloc[1]] == 0) {
		if (!winner)
			maximum = max(maximum, cnt);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (!turn) {
			board[aloc[0]][aloc[1]] = 0;
			aloc[0] += dx[i];
			aloc[1] += dy[i];
			DFS(board, aloc, bloc, cnt + 1, true);
			aloc[0] -= dx[i];
			aloc[1] -= dy[i];
		}
		else {
			board[bloc[0]][bloc[1]] = 0;
			bloc[0] += dx[i];
			bloc[1] += dy[i];
			DFS(board, aloc, bloc, cnt + 1, false);
			bloc[0] -= dx[i];
			bloc[1] -= dy[i];
		}
	}
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
	int answer = -1;
	DFS(board, aloc, bloc, 0, false);
	int a = maximum;
	winner = true;
	maximum = 0;
	DFS(board, aloc, bloc, 0, false);
	int b = maximum;
	answer = maximum;
	return answer;
}

int main() {
	vector<vector<int>> board = { {1, 1, 1}, {1, 1, 1}, {1, 1, 1} };
	vector<int> aloc = { 1, 0 };
	vector<int> bloc = { 1, 2 };
	cout << solution(board, aloc, bloc);

	return 0;
}