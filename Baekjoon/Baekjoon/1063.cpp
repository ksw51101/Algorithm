#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, sx, sy, kx, ky; // sx : 돌의 x좌표, sy : 돌의 y좌표, kx : 킹의 x좌표, ky : 킹의 y좌표  
vector<string> vec;
pair<string, pair<int, int>> m[8] = { {"R", {0, 1}}, {"L", {0, -1}}, {"B", {-1, 0}}, {"T", {1, 0}}, {"RT", {1, 1}}, {"LT", {1, -1}}, {"RB", {-1, 1}}, {"LB", {-1, -1}} }; // 해당 움직임에서의 x축, y축 좌표 변경값

void moving(int move_x, int move_y) {
	int n_kx = kx + move_x, n_ky = ky + move_y, n_sx = sx, n_sy = sy;
	if (n_kx == sx && n_ky == sy) { // 움직인 킹이 돌과 같은 자리일 경우 돌의 위치도 변경
		n_sx += move_x;
		n_sy += move_y;
	}
	if (n_kx >= 0 && n_kx < 8 && n_sx >= 0 && n_sx < 8 && n_ky >= 0 && n_ky < 8 && n_sy >= 0 && n_sy < 8) { // 킹과 돌이 체스판 내에 있을 경우 최종 좌표 변경
		sx = n_sx;
		sy = n_sy;
		kx = n_kx;
		ky = n_ky;
	}	
}

// 킹의 이동 str을 입력으로 받고 m에서 찾아 moving 함수를 실행
void solution(string str) {
	for (int i = 0; i < 8; i++) {
		if (str == m[i].first) {
			moving(m[i].second.first, m[i].second.second);
			break;
		}
	}
}

int main() {
	string temp;
	cin >> temp;
	ky = temp[0] - 'A';
	kx = temp[1] - '1';

	cin >> temp;
	sy = temp[0] - 'A';
	sx = temp[1] - '1';

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		vec.push_back(temp);
	}

	for (int i = 0; i < n; i++) // 각각의 움직임에 대해 solution 함수 실행
		solution(vec[i]);

	cout << (char)(ky + 'A') << (char)(kx + '1') << '\n';
	cout << (char)(sy + 'A') << (char)(sx + '1') << '\n';

	return 0;
}